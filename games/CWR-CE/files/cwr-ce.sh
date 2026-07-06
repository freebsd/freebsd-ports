#!/bin/sh
# cwr-ce — launcher for PoseidonGame (Arma: Cold War Assault Remastered CE).
#
# Resolves the data root (from $CWR_DATA or the default per-user path),
# verifies a minimal sentinel file exists, then execs PoseidonGame with
# -C <data-root> and forwards any remaining arguments.

set -u

DATA_ROOT="${CWR_DATA:-${HOME}/.local/share/CWR/base}"
# The Steam Demo ships bin/CONFIG.BIN (uppercase); an overlay-installed layout
# may lowercase it. Accept either — the engine itself is case-insensitive.
if [ -f "${DATA_ROOT}/bin/config.bin" ] || [ -f "${DATA_ROOT}/bin/CONFIG.BIN" ]; then
	:
else
	cat >&2 <<EOF
cwr-ce: CWR-CE data set not found under: ${DATA_ROOT}
        (missing: bin/config.bin or bin/CONFIG.BIN)

The engine binaries alone are not enough — you must install a data root
first. Obtain the Steam "Arma: Cold War Assault Remastered Demo" (free)
and optionally the retail 2001 game from GOG:

    https://store.steampowered.com/app/4819000/
    https://www.gog.com/game/arma_cold_war_assault

Then populate the data root with the install helper shipped by this port:

    install-cwr-data --help

By default the helper installs into \$HOME/.local/share/CWR/base. To use a
different location, set \$CWR_DATA before launching:

    export CWR_DATA=/path/to/data-root
    cwr-ce

EOF
	exit 1
fi

exec PoseidonGame -C "${DATA_ROOT}" "$@"
