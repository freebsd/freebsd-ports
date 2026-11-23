#!/bin/sh
#
# emulate pnpm install with nodeLinker=isolated
#
# Usage: pnpm-install-isolated.sh [-p project_root] [-n] [-d name@version]... [-r name@version]... <name> <version> <src_dir>
#   -n  don't create symlink to top-level node_modules/<name>
#   -d  make symlinks to dependency modules the specified package depends on
#   -r  make symlinks from dependent modules the specified package is depended on

set -eu
set -o pipefail

project_root=.
top_level=1
deps=
rdeps=
while getopts "p:nd:r:" opt; do
    case ${opt} in
        p)
            project_root=${OPTARG}
            ;;
        n)
            top_level=0
            ;;
        d)
            deps="${deps}${OPTARG}
"
            ;;
        r)
            rdeps="${rdeps}${OPTARG}
"
            ;;
        *)
            exit 1
            ;;
    esac
done
shift $((OPTIND - 1))

[ $# -eq 3 ] || { echo "Usage: ${0##*/} [-p project_root] [-n] [-d name@version]... [-r name@version]... <name> <version> <src_dir>" >&2; exit 1; }
name=$1
version=$2
src=$3
[ -d "${src}" ] || { echo "error: src_dir not found: ${src}" >&2; exit 1; }

nm=$project_root/node_modules

# @scope/name -> @scope+name
encode() { printf '%s' "$1" | sed 's|/|+|g'; }

split() {
    pn=${1%@*}
    pv=${1##*@}
    if [ -z "$pn" ] || [ "$pn" = "$1" ]; then
        echo "error: name@version expected: $1" >&2; exit 1
    fi
    pd=$(encode "$pn")@$pv
    [ -d "$nm/.pnpm/$pd/node_modules/$pn" ] || { echo "error: not installed: $1" >&2; exit 1; }
}

mklink() {
    mkdir -p "$(dirname "$2")"
    rm -f "$2"
    ln -s "$1" "$2"
}

vdir=$(encode "$name")@$version
pkg=$nm/.pnpm/${vdir}/node_modules/${name}

scope=
case ${name} in
    */*)
        scope=../
        ;;
esac

# -d
while IFS= read -r dep; do
    [ -n "${dep}" ] || continue
    split "${dep}"
    up=../../
    case ${pn} in
        */*)
            up=../../../
            ;;
    esac
    mklink "${up}${pd}/node_modules/${pn}" "${nm}/.pnpm/${vdir}/node_modules/${pn}"
done <<EOF
$deps
EOF

# -r
while IFS= read -r rdep; do
    [ -n "${rdep}" ] || continue
    split "${rdep}"
    mklink "../../${scope}${vdir}/node_modules/${name}" "${nm}/.pnpm/${pd}/node_modules/${name}"
done <<EOF
$rdeps
EOF

rm -rf "${pkg}"
mkdir -p "${pkg}"
cp -R "${src}"/. "${pkg}"/

# hoist: .pnpm/node_modules/<name>
mklink "../${scope}${vdir}/node_modules/${name}" "${nm}/.pnpm/node_modules/${name}"

# top level: node_modules/<name>
if [ "${top_level}" -eq 1 ]; then
    mklink "${scope}.pnpm/${vdir}/node_modules/${name}" "${nm}/${name}"
fi
