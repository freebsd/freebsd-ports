#!/bin/sh
# install-cwr-data.sh — populate a CWR-CE data root from:
# the Steam Demo (default):
# https://store.steampowered.com/app/4819000/Arma_Cold_War_Assault_Remastered_Demo/
# and optionally overlay 2001 retail (GOG) content on top:
# https://www.gog.com/game/arma_cold_war_assault
#
# The Poseidon engine reads its data root from $CWD or --work-dir and expects
# (case-sensitive on POSIX — FindBank/unixPath translates path separators only):
#   <root>/dta/        (lowercase)
#   <root>/addons/     (lowercase)
#   <root>/bin/        (lowercase, holds config.bin/resource.bin/stringtable.csv)
#   <root>/Campaigns/  (PascalCase)
#   <root>/Worlds/     <root>/Missions/   <root>/MPMissions/
#   <root>/Templates/  <root>/SPTemplates/
#   <root>/fonts/      (cwr_*.ttf — only ships with the Remaster Demo)
#
# Per CWR-CE upstream: the binaries are not drop-in compatible with the original
# 2001 retail folder. The supported layout is "Remaster Demo as base + retail
# AddOns/DTA/Campaigns/Missions overlaid on top".
#
# Config merge (bin/CONFIG.BIN):
#   The Steam Demo's bin/CONFIG.BIN is the *sole* engine config authority — no
#   .pbo under dta/ contains a config.bin, they are pure asset archives. The
#   demo config carries the CWR-CE remaster additions (CfgLandscapeSky, sky
#   models, fonts, CfgLanguages) that a plain retail BIN/config.bin would
#   regress, which is why the demo BIN is kept as base and the retail BIN is
#   NOT overlaid wholesale.
#
#   However, the demo config is a strict subset of the retail one:
#     - CfgVehicles: retail defines ~110 classes the demo omits — Cobra/Mi24/
#       Mi17 (helicopters), A10 (jet), M1Abrams/T80 (tanks), Skoda/Cessna
#       (civilians), the SoldierG* resistance roster, reammo boxes, targets,
#       props, wrecks — everything retail campaigns and missions reference.
#     - CfgVoice: retail defines Dan/Greg/John/Peter (the classic ARMA:CWA
#       voice actors); the demo only ships Adam. CfgHQIdentities entries in
#       the demo config still reference speaker="Dan"/"Greg", so any radio
#       message crashes on class lookup without the merge.
#     - CfgGroups: retail group compositions that place the missing vehicles.
#
#   With --gog, this script performs a class-level *additive* merge via
#   'PoseidonTools config merge': base = demo CONFIG.BIN (kept verbatim),
#   overlay = retail BIN/CONFIG.BIN (adds missing subclasses only, never
#   overwrites the remaster-specific tweaks). Without this step the engine
#   crashes the first time a retail mission references an unknown class.

set -eu

usage()
{
    cat >&2 <<EOF
Usage: $0 [options] <demo.zip>

Installs the Steam "Arma: Cold War Assault Remastered Demo" zip into a data
root the engine can run from. The retail (GOG) game can additionally be
overlaid on top to enable the full islands and campaign.

Arguments:
  <demo.zip>            Path to the zipped Steam Demo install folder.
                        Optional if --gog is provided AND --dest already
                        holds a previous demo install.

Options:
  -g, --gog <file>      Path to setup_arma_cold_war_assault_*.exe (GOG retail
                        installer). Its AddOns/DTA/Campaigns/Missions/... are
                        overlaid on top of the demo base. Requires innoextract.
      --dest <dir>      Destination data root (default: \$HOME/.local/share/CWR/base).
      --force           Overwrite a non-empty destination.
      --keep-temp       Leave the unpacked staging directory in place.
  -h, --help            Show this help.

Examples:
  $0 ~/Arma\\ Cold\\ War\\ Assault\\ Demo.zip
  $0 ~/demo.zip --gog ~/setup_arma_cold_war_assault_1.0_36421.exe
  $0 --gog ~/setup.exe --force      # overlay GOG onto an existing demo install

Required tools: unzip (always), innoextract (only when --gog is used).

How to produce <demo.zip> from a Windows machine running Steam:
  1. In Steam, install "Arma: Cold War Assault Remastered Demo" (free,
     app 4819000).
  2. Right-click the title in your Library -> Manage -> Browse local files.
     That opens the install folder (e.g.
     C:\\Program Files (x86)\\Steam\\steamapps\\common\\Arma Cold War Assault Demo).
  3. In Explorer, right-click that folder ->
     "Send to" -> "Compressed (zipped) folder",
     or "Compress to" -> "ZIP file" (Windows 11).
  4. Copy the resulting .zip to this machine (scp, USB stick, ...) and pass
     its path to this script.
EOF
    exit 1
}

DEST="${HOME}/.local/share/CWR/base"
FORCE=0
KEEP_TEMP=0
DEMO_ZIP=
GOG_EXE=

while [ $# -gt 0 ]; do
    case "$1" in
        -g|--gog)      [ $# -ge 2 ] || usage; GOG_EXE="$2"; shift 2 ;;
        --dest)        [ $# -ge 2 ] || usage; DEST="$2"; shift 2 ;;
        --force)       FORCE=1; shift ;;
        --keep-temp)   KEEP_TEMP=1; shift ;;
        -h|--help)     usage ;;
        --)            shift; break ;;
        -*)            echo "unknown option: $1" >&2; usage ;;
        *)             [ -z "$DEMO_ZIP" ] || usage; DEMO_ZIP="$1"; shift ;;
    esac
done

# Either the demo zip or a pre-existing dest+gog combination must be present.
if [ -z "$DEMO_ZIP" ] && [ -z "$GOG_EXE" ]; then
    usage
fi
if [ -n "$DEMO_ZIP" ] && [ ! -f "$DEMO_ZIP" ]; then
    echo "demo zip not found: $DEMO_ZIP" >&2; exit 1
fi
if [ -n "$GOG_EXE" ] && [ ! -f "$GOG_EXE" ]; then
    echo "GOG installer not found: $GOG_EXE" >&2; exit 1
fi

# Detect the host package manager once and remember the install command.
# pkg(8) on FreeBSD is checked first because that is the primary platform for
# this script; the others are best-effort for Linux distros that happen to
# ship the same tools.
detect_pkg_install()
{
    if command -v pkg >/dev/null 2>&1; then
        echo "sudo pkg install -y"; return
    fi
    if command -v apt-get >/dev/null 2>&1; then
        echo "sudo apt-get install -y"; return
    fi
    if command -v dnf >/dev/null 2>&1; then
        echo "sudo dnf install -y"; return
    fi
    if command -v pacman >/dev/null 2>&1; then
        echo "sudo pacman -S --noconfirm"; return
    fi
    return 1
}

# Ensure $1 is on PATH. If missing, offer to install it via the host package
# manager (same package name, which holds for unzip/innoextract on all targets
# above). Aborts the script if the user declines or the install fails.
require_tool()
{
    name="$1"
    command -v "$name" >/dev/null 2>&1 && return 0

    install_cmd="$(detect_pkg_install || true)"
    if [ -z "$install_cmd" ]; then
        echo "'$name' is required but not found, and no supported package manager" >&2
        echo "was detected. Install '$name' manually and rerun." >&2
        exit 1
    fi

    printf "'%s' is required but missing. Install it with '%s %s'? [Y/n] " \
        "$name" "$install_cmd" "$name"
    # Read from the controlling terminal so piped invocations still prompt.
    if [ -r /dev/tty ]; then
        read -r reply </dev/tty || reply=n
    else
        read -r reply || reply=n
    fi
    case "$reply" in
        ""|y|Y|yes|YES) ;;
        *) echo "aborted." >&2; exit 1 ;;
    esac

    # shellcheck disable=SC2086
    $install_cmd "$name" || {
        echo "package install failed; aborting." >&2; exit 1; }
    command -v "$name" >/dev/null 2>&1 || {
        echo "'$name' still not on PATH after install; aborting." >&2; exit 1; }
}

# Tool checks scoped to what we actually need this invocation.
if [ -n "$DEMO_ZIP" ]; then
    require_tool unzip
fi
if [ -n "$GOG_EXE" ]; then
    require_tool innoextract
fi

# Non-empty dest is only acceptable when we're explicitly overlaying GOG onto
# an existing demo, or the caller passed --force.
if [ "$FORCE" -ne 1 ] && [ -d "$DEST" ] && [ -n "$(ls -A "$DEST" 2>/dev/null || true)" ]; then
    if [ -n "$DEMO_ZIP" ]; then
        echo "destination is not empty: $DEST (use --force to overwrite)" >&2
        exit 1
    fi
    # GOG-only run with existing dest: treat as an overlay; require the demo
    # base to be present, otherwise the engine would still fail on fonts/.
    if [ ! -d "$DEST/fonts" ] || [ ! -d "$DEST/bin" ]; then
        echo "destination exists but does not look like a demo install: $DEST" >&2
        echo "(missing fonts/ or bin/ — install the demo first, or pass <demo.zip>)" >&2
        exit 1
    fi
fi
mkdir -p "$DEST"

TMP="$(mktemp -d -t cwr-data.XXXXXX)"
cleanup()
{
    if [ "$KEEP_TEMP" -ne 1 ]; then
        rm -rf "$TMP"
    else
        echo "staging left at: $TMP"
    fi
}
trap cleanup EXIT INT TERM

# Locate a directory under $1 case-insensitively (handles both GOG's "DTA"/
# "AddOns" and the demo's "DTA"/"AddOns" without coupling to either).
locate_dir()
{
    base="$1"; needle="$2"
    [ -d "$base" ] || return 1
    lc_needle="$(printf '%s' "$needle" | tr '[:upper:]' '[:lower:]')"
    for entry in "$base"/*; do
        [ -d "$entry" ] || continue
        lc_name="$(printf '%s' "$(basename "$entry")" | tr '[:upper:]' '[:lower:]')"
        if [ "$lc_name" = "$lc_needle" ]; then
            printf '%s\n' "$entry"
            return 0
        fi
    done
    return 1
}

# Copy a source tree on top of $DEST. Destination name fixed by the caller so
# we can lowercase DTA/AddOns/BIN regardless of source casing.
install_dir()
{
    src="$1"; dest_name="$2"
    [ -d "$src" ] || return 0
    echo "    -> $dest_name/"
    mkdir -p "$DEST/$dest_name"
    cp -R "$src/." "$DEST/$dest_name/"
}

# ---------------------------------------------------------------------------
# Phase 1: Steam Demo (base)
# ---------------------------------------------------------------------------
if [ -n "$DEMO_ZIP" ]; then
    echo "==> unpacking demo: $(basename "$DEMO_ZIP")"
    DEMO_STAGE="$TMP/demo"
    mkdir -p "$DEMO_STAGE"
    unzip -q "$DEMO_ZIP" -d "$DEMO_STAGE"

    # Steam-shipped zips usually wrap everything in a single top-level folder
    # ("Arma Cold War Assault Demo/"). If there is exactly one such directory,
    # descend into it. Otherwise assume the zip was made from inside the dir.
    DEMO_SRC="$DEMO_STAGE"
    entries=0
    only_dir=
    for e in "$DEMO_STAGE"/*; do
        entries=$((entries + 1))
        [ -d "$e" ] && only_dir="$e"
    done
    if [ "$entries" -eq 1 ] && [ -n "$only_dir" ]; then
        DEMO_SRC="$only_dir"
    fi

    # Lowercase the three engine-literal dirs.
    for pair in "DTA dta" "AddOns addons" "BIN bin"; do
        src_name="${pair% *}"; dst_name="${pair#* }"
        src="$(locate_dir "$DEMO_SRC" "$src_name" || true)"
        if [ -n "$src" ]; then
            install_dir "$src" "$dst_name"
        fi
    done

    # Strip Windows-only payload from bin/ if present.
    find "$DEST/bin" -type f \( -iname '*.dll' -o -iname '*.exe' \) -delete 2>/dev/null || true

    # Preserve every other top-level directory verbatim (engine reads each by
    # exact name). Covers Campaigns/, Worlds/, Missions/, MPMissions/,
    # Templates/, SPTemplates/, fonts/, demo/, dtaExt/, Music/, …
    for entry in "$DEMO_SRC"/*; do
        [ -d "$entry" ] || continue
        name="$(basename "$entry")"
        case "$(printf '%s' "$name" | tr '[:upper:]' '[:lower:]')" in
            dta|addons|bin) continue ;;
        esac
        install_dir "$entry" "$name"
    done

    # Loose top-level data files (config.cfg-style metadata). Drop Windows
    # binaries and license blurbs.
    for f in "$DEMO_SRC"/*; do
        [ -f "$f" ] || continue
        name="$(basename "$f")"
        case "$name" in
            *.exe|*.dll|*.url|*.ico|*.pdf|*.txt) continue ;;
            PoseidonGameDemo|PoseidonGameDemo.*) continue ;;
        esac
        echo "    -> $name"
        cp "$f" "$DEST/$name"
    done
fi

# ---------------------------------------------------------------------------
# Phase 2: GOG retail overlay (optional)
# ---------------------------------------------------------------------------
# Per CWR-CE issue #29 the supported merge is: demo as base + retail's
# AddOns/DTA/Campaigns/Missions/Worlds/Templates overlaid. The retail BIN/ is
# NOT copied wholesale — it would replace CWR-CE's remaster-aware config
# (fonts, sky models, CfgLandscapeSky) — but its class definitions ARE merged
# class-by-class into the demo config, see the header comment and Phase 3.
if [ -n "$GOG_EXE" ]; then
    echo "==> extracting GOG installer: $(basename "$GOG_EXE")"
    GOG_STAGE="$TMP/gog"
    mkdir -p "$GOG_STAGE"
    innoextract --silent --gog -d "$GOG_STAGE" "$GOG_EXE"

    # Most GOG bundles drop payload at the extraction root; some create app/
    # holding only GOG metadata. Pick whichever actually has DTA/AddOns/BIN.
    GOG_SRC=
    for candidate in "$GOG_STAGE" "$GOG_STAGE/app"; do
        for d in DTA dta AddOns addons; do
            if [ -d "$candidate/$d" ]; then
                GOG_SRC="$candidate"; break 2
            fi
        done
    done
    [ -n "$GOG_SRC" ] || { echo "no game data found under $GOG_STAGE" >&2; exit 2; }

    echo "==> overlaying retail content onto $DEST"
    # Lowercased dirs (overlay merges file-by-file via cp -R).
    for pair in "DTA dta" "AddOns addons"; do
        src_name="${pair% *}"; dst_name="${pair#* }"
        src="$(locate_dir "$GOG_SRC" "$src_name" || true)"
        if [ -n "$src" ]; then
            install_dir "$src" "$dst_name"
        fi
    done

    # PascalCase content dirs — engine reads literal names. NOT BIN/ — that
    # dir is handled by the config-merge phase below, not a plain cp.
    for d in Campaigns Worlds Missions MPMissions Templates SPTemplates; do
        src="$(locate_dir "$GOG_SRC" "$d" || true)"
        [ -n "$src" ] || continue
        name="$(basename "$src")"
        install_dir "$src" "$name"
    done

    # -----------------------------------------------------------------------
    # Phase 3: merge retail CfgVehicles/CfgVoice/CfgGroups into demo CONFIG.BIN
    # -----------------------------------------------------------------------
    # 'PoseidonTools config merge base overlay -o out' walks the overlay
    # class tree and *adds* any subclass the base lacks, without touching
    # entries the base already defines. That gives us:
    #   - all retail vehicles, weapons, ammo the campaigns/missions need,
    #   - the Dan/Greg/John/Peter CfgVoice classes referenced by
    #     CfgHQIdentities (radio messages crash without them),
    # while preserving CWR-CE's remaster-only additions (CfgLandscapeSky,
    # CfgLanguages, remaster sky/font entries) that a wholesale copy of the
    # retail config would silently drop.
    GOG_BIN_SRC="$(locate_dir "$GOG_SRC" "BIN" || true)"
    if [ -n "$GOG_BIN_SRC" ] && [ -f "$GOG_BIN_SRC/CONFIG.BIN" ] \
        && [ -f "$DEST/bin/CONFIG.BIN" ] \
        && command -v PoseidonTools >/dev/null 2>&1; then
        echo "==> merging retail class definitions into demo CONFIG.BIN"
        cp "$DEST/bin/CONFIG.BIN" "$DEST/bin/CONFIG.BIN.demo-orig"
        PoseidonTools config merge \
            "$DEST/bin/CONFIG.BIN.demo-orig" \
            "$GOG_BIN_SRC/CONFIG.BIN" \
            -o "$DEST/bin/CONFIG.BIN"
    elif [ -n "$GOG_BIN_SRC" ] && [ -f "$GOG_BIN_SRC/CONFIG.BIN" ]; then
        echo "WARNING: PoseidonTools not on PATH; skipping config merge." >&2
        echo "  Retail missions will crash on missing vehicle/voice classes" >&2
        echo "  until you run:" >&2
        echo "    PoseidonTools config merge $DEST/bin/CONFIG.BIN \\" >&2
        echo "        $GOG_BIN_SRC/CONFIG.BIN -o $DEST/bin/CONFIG.BIN.new" >&2
    fi
fi

cat <<EOF

Done. Data root: $DEST

Run the game from that directory:
    cd "$DEST" && PoseidonGame
or pass it via --work-dir:
    PoseidonGame --work-dir "$DEST"
    PoseidonServer --work-dir "$DEST"

EOF
