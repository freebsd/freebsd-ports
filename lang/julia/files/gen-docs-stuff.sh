#!/bin/sh
# Génère, pour le port FreeBSD lang/julia, les distfiles nécessaires à la cible "docs" :
#   - le GH_TUPLE des paquets Julia de deps/jlutilities/documenter/Manifest.toml
#   - les MASTER_SITES et répertoires des artifacts binaires des paquets _jll
#   - le hash actuel du registre General
#
# Usage : gen-gh-tuple.sh <tag ou branche de Julia> [arch]
#   ex.  : gen-gh-tuple.sh v1.13.3
#          gen-gh-tuple.sh release-1.14 aarch64
# Dépendances : python3 (>= 3.11, pour tomllib), git, curl
set -e
JV=${1:?usage: $0 <tag Julia, ex. v1.13.3> [arch]}
ARCH=${2:-x86_64}
REG=https://raw.githubusercontent.com/JuliaRegistries/General/master
TMP=$(mktemp -d); trap 'rm -rf "$TMP"' EXIT
PYTHON=python3.12

curl -sfL "https://raw.githubusercontent.com/JuliaLang/julia/$JV/deps/jlutilities/documenter/Manifest.toml" \
  -o "$TMP/Manifest.toml" || { echo "Manifest introuvable pour $JV" >&2; exit 1; }

# Seuls les paquets avec git-tree-sha1 viennent du registre (les autres sont des stdlibs)
${PYTHON} - "$TMP/Manifest.toml" > "$TMP/pkgs" <<'EOF'
import sys, tomllib
m = tomllib.load(open(sys.argv[1], "rb"))
for n, v in sorted(m["deps"].items(), key=lambda x: x[0].lower()):
    v = v[0]
    if "git-tree-sha1" in v:
        print(n, v["version"], v["git-tree-sha1"])
EOF

: > "$TMP/tuple"; : > "$TMP/sites"; : > "$TMP/arts"
while read -r n ver tree; do
  case $n in *_jll) sub="jll/"; tag="${n%_jll}-v$ver";; *) sub=""; tag="v$ver";; esac
  first=$(printf %s "$n" | cut -c1)
  url=$(curl -sfL "$REG/$sub$first/$n/Package.toml" | sed -n 's/^repo = "\(.*\)"/\1/p')
  [ -n "$url" ] || { echo "ERREUR : dépôt introuvable pour $n" >&2; exit 1; }
  acct=$(echo "$url" | sed -E 's#https://github.com/([^/]+)/([^/]+)\.git#\1#')
  proj=$(echo "$url" | sed -E 's#https://github.com/([^/]+)/([^/]+)\.git#\2#')
  group=$(echo "$n" | tr -d '_' | tr 'A-Z' 'a-z')
  d="$TMP/repo"; rm -rf "$d"
  git clone -q --bare --filter=blob:none "$url" "$d"
  # Le tag doit pointer sur l'arbre attendu, sinon on cherche le commit correspondant
  if [ "$(git -C "$d" rev-parse -q --verify "refs/tags/$tag^{tree}" 2>/dev/null)" = "$tree" ]; then
    ref=$tag
  else
    ref=$(git -C "$d" log --all --format='%H %T' | awk -v t="$tree" '$2==t{print $1; exit}')
    [ -n "$ref" ] || { echo "ERREUR : arbre $tree introuvable pour $n" >&2; exit 1; }
  fi
  printf '\t%s:%s:%s:%s\n' "$acct" "$proj" "$ref" "$group" >> "$TMP/tuple"

  # Artifacts binaires des _jll pour FreeBSD/$ARCH
  case $n in *_jll)
    git -C "$d" show "$ref:Artifacts.toml" > "$TMP/Artifacts.toml" 2>/dev/null || continue
    ${PYTHON} - "$TMP/Artifacts.toml" "$ARCH" "af$(echo "${n%_jll}" | tr -d '_' | tr 'A-Z' 'a-z')" \
      >> "$TMP/arts" <<'EOF'
import sys, tomllib
d = tomllib.load(open(sys.argv[1], "rb"))
for name, lst in d.items():
    lst = lst if isinstance(lst, list) else [lst]
    for a in lst:
        if a.get("os") == "freebsd" and a.get("arch") == sys.argv[2] and "download" in a:
            u = a["download"][0]["url"]
            print(sys.argv[3], u.rsplit("/", 1)[0] + "/", u.rsplit("/", 1)[1], a["git-tree-sha1"])
            break
EOF
  ;; esac
done < "$TMP/pkgs"

echo "# --- Paquets Julia ($JV) ---"
printf 'GH_TUPLE='
sed '$!s/$/ \\/' "$TMP/tuple"

echo
echo "# --- Artifacts FreeBSD/$ARCH (MASTER_SITES) ---"
awk '{printf "\t\t%s:%s%s\n", $2, $1, (NR<n ? " \\" : "")}' n="$(wc -l < "$TMP/arts")" "$TMP/arts"
echo
echo "# --- Artifacts : fichier -> répertoire deps/jlutilities/depot/artifacts/<hash> ---"
awk '{printf "#   %-12s %s -> %s\n", $1, $3, $4}' "$TMP/arts"

echo
echo "# --- Registre General ---"
r=$(curl -sfL https://pkg.julialang.org/registries | grep 23338594-aafe-5451-b93e-139f81909106 | head -1)
if [ -n "$r" ]; then
  echo "JPKGUUID=	23338594-aafe-5451-b93e-139f81909106"
  echo "JPKGHASH=	${r##*/}"
else
  echo "# (pkg.julialang.org injoignable : lancez 'curl -sL https://pkg.julialang.org/registries')"
fi
