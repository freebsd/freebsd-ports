#!/bin/sh
# Version 0.2
# This script is public domain, for any given public, in every type of domain.
# onatan@gmail.com 

usage(){
	echo "$0 [/usr/ports]"
	echo "Locates identical pkg-descr files"
	exit 1
}

DIR=${1-/usr/ports}
[ -d ${DIR} ] || usage

find ${DIR}/ -name pkg-descr -exec md5 -r {} \; 2>/dev/null | 	\
	sort | 							\
	xargs -L 9999999999 |					\
	awk '							\
		{ size=split($0,arr," ") }			\
		{ for (i=1; i<size; ++i) 			\
			if ( arr[i] == arr[i+2] )		\
				print arr[i+1] " == " arr[i+3]	\
			}					\
		'
