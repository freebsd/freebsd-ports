#!/bin/sh
#
# $FreeBSD$
#

set -e

lspfiles=$(find "$@" -type f \( -name \*.lsp -or -name \*.LSP \))
spefiles=$(find "$@" -type f \( -name \*.spe -or -name \*.SPE \))

for fn in ${lspfiles} ${spefiles}; do
	lcfn=$(echo "${fn}" | tr '[A-Z]' '[a-z]')
	if [ "${fn}" != "${lcfn}" ]; then
	        fixuplist="${fixuplist}s|${fn}|${lcfn}|;"
		#echo "${fn} -> ${lcfn}"
		mkdir -p $(dirname "${lcfn}")
		mv -i "${fn}" "${lcfn}"
	fi
done

for fn in $(echo "${lspfiles}" | tr '[A-Z]' '[a-z]'); do
	mv -f "${fn}" "${fn}.orig"
	sed -e "${fixuplist}" "${fn}.orig" >"${fn}"
done
