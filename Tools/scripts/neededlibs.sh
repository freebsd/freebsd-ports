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
# The purpose of this script is to find as much dependencies of a binary
# as possible. A dependecy is for example a library which is directly
# referenced in the binary.
#

# XXX: it doesn't handle calls to dlopen() or the corresponding libltdl
# function. I don't know if this is needed to detect references to stuff
# which can be added as LIB_DEPENDS.

if [ -z "$1" ]; then
	echo "Usage: $0 binary_file ..."
	exit 2
fi

for i in "$@"; do
	kind=$(file -bi "$i")

	case "${kind}" in
	application/x-executable*|application/x-sharedlib*)
		# ok, fall through
		;;
	*)
		# not ok, go to next one
		shift
		continue
		;;
	esac

	objdump -x "$i" | awk '/NEEDED/ {print $2}'
	shift
done | sort -u
