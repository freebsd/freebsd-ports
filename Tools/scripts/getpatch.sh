#!/bin/sh

# Copyright (c) 2015 Rodrigo Osorio
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
# 
# $FreeBSD$
#
# MAINTAINER=   rodrigo@FreeBSD.org
#

XML_URL='https://bugs.freebsd.org/bugzilla/show_bug.cgi?ctype=xml&id='
GET_URL='https://bz-attachments.freebsd.org/attachment.cgi?id='

TEMP_DIR=
PR_DIR=
deprecate=0
build_path=1
verbose=0

usage() {
	echo "usage: getpatch [-dp] tknum tknum ..."
	echo " -d : download deprecate patches too"
	echo " -p : store the patches in the current dir, instead of the dedicated bug id directory"
	echo "use the GETPATCH_DIR variable to define the root location for the downloaded patches"
	echo
	exit 1
}

die() {
	echo $@
	erase_env
	exit 1
}

build_env() {
	if [ -z ${TEMP_DIR} ]; then
		TEMP_DIR=`mktemp -d -t 'getpatch'`
	fi	
}

erase_env() {
	if [ -n ${TEMP_DIR} ]; then
		rm -rf ${TEMP_DIR}  >/dev/null 2>&1
	fi
}

getpatch() {
	echo -n " + attachment ${2}-${3} "
	if [ $deprecate -eq 1 ] || [ "$1" != "1" ]; then
		if  [ ! -f "${PR_DIR}${2}-${3}" ]; then
			echo -n "download "
			fetch --no-verify-peer -o "${PR_DIR}${2}-${3}" "${GET_URL}${2}" > /dev/null 2>&1
			if [ $? -ne 0 ]; then
				echo "error"
				die "Unable to download ${GET_URL}${2}"
			fi
			echo "success"
		else
			echo "is present, skip"
		fi
	else
		echo "is obsolete, skip"
	fi
}

parse_and_fetch(){

	for patchline in `awk '
		/<\/attachment>/                { IN_ATTACH=0;
						  printf "%d>%s>%s\n",obsolete, patchid, patchname ;
						}
		/isobsolete/ || /ispatch/ && IN_ATTACH == 1 {
						  gsub(/^[ \t]+|[ \t]+$|"/, "");
						  split($0,val,"=");
						  if(val[1] == "isobsolete")
							obsolete = val[2];
						}
		( /<filename>/ || /<attachid>/ )  && IN_ATTACH == 1 {
						  gsub(/^[ \t]+|[ \t]+$/, "");
						  gsub(/[<]/, ">");
						  split($0,val,">");
						  if(val[2] == "filename")
							patchname=val[3];
						  else if(val[2] == "attachid")
							patchid=val[3];
						}
		/<attachment/                   { IN_ATTACH=1;
						  obsolete = 0;
						  patchid = "";
						  patchname = "";
						}
	' $1  `  ; do
		getpatch `echo $patchline | tr ">" " "`
	done
}

get_list_of_patches() {
	## Get xml file
	PR_ID=$1
	echo "Bug ID: $1"
	build_env
	fetch --no-verify-peer -o "${TEMP_DIR}/my${1}.xml" "${XML_URL}${1}" > /dev/null 2>&1
	if [ $? -ne 0 ]; then
		die "Can't upload ${XML_URL}${1}"
	fi
	## Search for error
	error_msg=`grep "bug error=" "${TEMP_DIR}/my${1}.xml"`
	if [ -n "${error_msg}" ]; then
		echo "  !! Can't recover the bug attachements : " "`echo "${error_msg}" | cut -d '"' -f 2`  !!"
		return 1
	fi

	PR_DIR=${GETPATCH_DIR%%/}
	if [ ${build_path} == 1 ]; then
		PR_DIR=${PR_DIR}/${PR_ID}/
	fi
	
 	if [ ! -d ${PR_DIR} ]; then
		mkdir -p ${PR_DIR}
		if [ $? != 0 ]; then
			die "Can't create ${PR_DIR} directory"
		fi
	fi

	parse_and_fetch "${TEMP_DIR}/my${1}.xml"
	echo -n " >> Patches stored in "
	realpath ${PR_DIR}
		
}

trap "die 'Interruption caught, exit'" 2 3 6 9 14 15

if [ -z ${GETPATCH_DIR} ]; then
	GETPATCH_DIR='.'
fi



while getopts ":pd" arg; do
	case "$arg" in
	d ) deprecate=1		;;
	p ) build_path=0	;;
	* ) usage 		;;
	esac
	shift
done
	
if [ "$#" -eq 0 ]; then
	usage
	exit 1
fi

for arg in "$@"; do
	if [ -z "`echo "${arg}"  | sed 's/[0-9]//g'`" ]; then
		get_list_of_patches ${arg}
	else
		echo "Error: ${arg} isn't a valid PR number"
		exit 1
	fi
done
erase_env
