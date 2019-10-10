#!/bin/sh
#
# $FreeBSD$
#
# Distributed under the BSD 2-clause Simplified License.
#

PATH=/bin:/usr/bin

[ $# -eq 0 ] && {
	echo 1>&2 "Usage: ${0##*/} <deb-file> [<deb-file> ...]";
	exit 1;
}

for i in "$@"; do
	[ "${i##*.}" != "deb" ] && {
		echo "${0##*/}: ignoring '$i' (not a .deb)";
		continue;
	}

	for file in `tar tf "$i"`; do
		[ "${file%%.*}" = "data" ] && {
			tar xOf "${i}" "${file}" > "${i%%.deb}.${file#data.}"
		}
	done
done

