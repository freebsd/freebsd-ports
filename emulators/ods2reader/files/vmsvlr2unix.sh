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
	strlen=$(hexdump -s ${off} -n 2 -e '"%u"' ${file})
	# EoF
	[ -z ${strlen} ] && break
	# print newline for zero-size records, as info-zip does
	[ ${strlen} -eq 0 ] && echo
	off=$((${off} + 2))
	hexdump -s ${off} -n ${strlen} -e '1000/1 "%c""\n"' ${file}
	# align 2
	[ $((${strlen} % 2)) -ne 0 ] && off=$((${off} + 1))
done
