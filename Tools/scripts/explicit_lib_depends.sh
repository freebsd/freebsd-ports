#!/bin/sh

#
# Copyright (C) 2007 Alexander Leidinger <netchild@FreeBSD.org>.
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
# THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
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
# The purpose of this script is to give the real dependency list of a
# currently installed port.
#

print_usage() {
	echo "Usage: $0 [-b base ...] port_name ..."
	echo "Example: $0 -b /usr/local -b /space/porttest gnome-vfs-2.18.1_2"
}

args=$(getopt b:h $@)
if [ $? -ne 0 ]; then
	print_usage
	exit 2
fi

set -- ${args}
for arg; do
	case "${arg}" in
	-b)
		bases="${bases} -b $2"
		shift; shift
		;;
	-h)
		print_usage
		exit 0
		;;
	--)
		shift
		break
		;;
	esac
done

if [ -z "$1" ]; then
	print_usage
	exit 2
fi

if [ -z "${PORTSDIR}" ]; then
	PORTSDIR=$(make -f /etc/make.conf -V PORTSDIR)
fi

if [ -z "${PORTSDIR}" -o ! -d "${PORTSDIR}" ]; then
	PORTSDIR=/usr/ports
fi

if [ -z "${PKG_DBDIR} ]; then
	PKG_DBDIR=$(make -f /etc/make.conf -V PKG_DBDIR)
fi

if [ -z "${PKG_DBDIR} -o ! -d "${PKG_DBDIR}" ]; then
	PKG_DBDIR=/var/db/pkg
fi

for i in $@; do
	if [ -d "${i}" ]; then
		current_port="${i}"
	else
		if [ -d "${PKG_DBDIR}/${i}" ]; then
			current_port="${PKG_DBDIR}/${i}"
		fi
	fi

	if [ ! -f ${current_port}/+CONTENTS ]; then
		echo $i is not a valid port
		continue
	fi

	myorigin=$(awk -F : '/@comment ORIGIN:/ {print $2}' \
		${current_port}/+CONTENTS)

	awk '
		/^@cwd / {
			CWD=$2;
			if (CWD == ".") {
				exit 0;
			}
		}

		/^s*bin\// {
			printf "%s/%s\n", CWD, $1;
		}

		/^lib\// {
			printf "%s/%s\n", CWD, $1;
		}
	' < ${current_port}/+CONTENTS | \
		xargs ${PORTSDIR}/Tools/scripts/neededlibs.sh | \
		xargs ${PORTSDIR}/Tools/scripts/resolveportsfromlibs.sh ${bases} | \
		egrep -v "${myorigin}\$"
 
done | sort -u
