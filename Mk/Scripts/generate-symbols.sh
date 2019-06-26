#! /bin/sh
# $FreeBSD$
# Maintainer: portmgr@FreeBSD.org

msg() {
        echo "====> $*"
}

msg "Finding symbols"

# Find all ELF files, strip them, and move symbols to PREFIX/usr/lib/debug/ORIG_PATH
ELF_FILES=$(mktemp -t elf_files)
find ${STAGEDIR} -type f \
    -exec /usr/bin/readelf -S {} + 2>/dev/null | awk ' \
    /File:/ {sub(/File: /, "", $0); file=$0}
    /[[:space:]]\.debug_info[[:space:]]*PROGBITS/ {print file}' \
    > ${ELF_FILES}

# Create all of the /usr/local/lib/* dirs
lib_dir="${STAGEDIR}.debug${PREFIX}/lib/debug"
sed -e "s,^${STAGEDIR}${PREFIX}/,${lib_dir}/," -e 's,/[^/]*$,,' \
    ${ELF_FILES} | sort -u | xargs mkdir -p

while read -r staged_elf_file; do
	elf_file_name="${staged_elf_file##*/}"
	lib_dir_dest="${lib_dir}/${staged_elf_file#${STAGEDIR}${PREFIX}/}"
	# Strip off filename
	lib_dir_dest="${lib_dir_dest%/*}"
	# Save symbols to f.debug
	objcopy --only-keep-debug "${staged_elf_file}" \
	    "${lib_dir_dest}/${elf_file_name}.debug"
	# Strip and add a reference to f.debug for finding the symbols.
	objcopy --strip-debug --strip-unneeded \
	    --add-gnu-debuglink="${lib_dir_dest}/${elf_file_name}.debug" \
	    "${staged_elf_file}"
	msg "Saved symbols for ${staged_elf_file}"
done < ${ELF_FILES}

rm -f ${ELF_FILES}
