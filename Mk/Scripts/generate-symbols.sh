#! /bin/sh
# $FreeBSD$
# Maintainer: portmgr@FreeBSD.org

msg() {
        echo "====> $@"
}

msg "Finding symbols"

# Find all ELF files, strip them, and move symbols to PREFIX/usr/lib/debug/ORIG_PATH
ELF_FILES=$(mktemp -t elf_files)
LF=$(printf '\nX')
LF=${LF%X}
find ${STAGEDIR} -type f \
    -exec /usr/bin/file -nNF "${LF}" {} + | while read f; do
	read output
	case "${output}" in
	ELF\ *\ executable,\ *FreeBSD*,\ not\ stripped*|\
	ELF\ *\ shared\ object,\ *FreeBSD*,\ not\ stripped*)
		echo "${f}"
		;;
	esac
done > ${ELF_FILES}

# Create all of the /usr/local/lib/* dirs
lib_dir="${STAGEDIR}.debug${PREFIX}/lib/debug"
sed -e "s,^${STAGEDIR}${PREFIX}/,${lib_dir}/," -e 's,/[^/]*$,,' \
    ${ELF_FILES} | sort -u | xargs mkdir -p

while read staged_elf_file; do
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
