#! /bin/sh
# $FreeBSD$
# Maintainer: portmgr@FreeBSD.org
#
# This script will find all ELF files in STAGEDIR and then strip and move
# the symbols to LOCALBASE/lib/debug/<original path>.
# For example:
# /var/qmail/bin/qmaild -> /usr/local/lib/debug/var/qmail/bin/qmaild.debug
# /usr/local/bin/ssh    -> /usr/local/lib/debug/usr/local/bin/ssh.debug
LIB_DIR_PREFIX="${LOCALBASE}/lib/debug"

msg() {
        echo "====> $*"
}

msg "Finding symbols"

# Find all ELF files
ELF_FILES=$(mktemp -t elf_files)
find ${STAGEDIR} -type f ! -name '*.a' \
    -exec /usr/bin/readelf -S /dev/null {} + 2>/dev/null | awk ' \
    /File:/ {sub(/File: /, "", $0); file=$0}
    /[[:space:]]\.debug_info[[:space:]]*PROGBITS/ {print file}' \
    > ${ELF_FILES}

# Create all of the /usr/local/lib/* dirs
lib_dir="${STAGEDIR}${LIB_DIR_PREFIX}"
sed -e "s,^${STAGEDIR}/,${lib_dir}/," -e 's,/[^/]*$,,' \
    ${ELF_FILES} | sort -u | xargs mkdir -p

while read -r staged_elf_file; do
	elf_file_name="${staged_elf_file##*/}"
	lib_dir_dest="${lib_dir}/${staged_elf_file#${STAGEDIR}/}"
	# Strip off filename
	lib_dir_dest="${lib_dir_dest%/*}"
	# Save symbols to f.debug
	debug_file_name="${lib_dir_dest}/${elf_file_name}.debug"
	objcopy --only-keep-debug "${staged_elf_file}" "${debug_file_name}"
	# Strip and add a reference to f.debug for finding the symbols.
	objcopy --strip-debug --strip-unneeded \
	    --add-gnu-debuglink="${debug_file_name}" "${staged_elf_file}"
	msg "Saved symbols for ${staged_elf_file}"
	echo "${debug_file_name#${STAGEDIR}}" >&3
done < ${ELF_FILES} 3>> ${TMPPLIST}

# Need @dir entries if PREFIX != LOCALBASE
if [ "${PREFIX}" != "${LOCALBASE}" ] && [ -d "${lib_dir}" ]; then
	find -sd "${lib_dir}" -type d | sed -e "s,^${STAGEDIR},," \
	    -e 's,^,@dir ,' \
	    >> ${TMPPLIST}
fi

rm -f ${ELF_FILES}
