#!/bin/sh -

PATH=/usr/bin

off=0
strlen=0

if [ $# -eq 0 -a ! -t 0 ]; then
	file=/dev/stdin
elif [ $# -eq 1 ]; then
	file=$1
else
	echo Usage: ${0##*/} [file]
	echo converts OpenVMS variable-length record format to unix text format
	exit 0
fi

while true; do
	off=$((${off} + ${strlen}))
	# read in 1-byte units
	set -- $(od -An -tu1 -j${off} -N2 ${file})
	# EoF
	[ -z "${1}" -o -z "${2}" ] && break
	# assume little-endian, it's OpenVMS format
	strlen=$(($2 * 256 + $1))
	# print newline for zero-size records, as info-zip does
	[ ${strlen} -eq 0 ] && echo
	off=$((${off} + 2))
	hexdump -s ${off} -n ${strlen} -e '"'%.${strlen}s'"''"\n"' ${file}
	# align 2
	[ $((${strlen} % 2)) -ne 0 ] && off=$((${off} + 1))
done
