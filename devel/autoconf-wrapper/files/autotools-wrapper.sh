#!/bin/sh
#-
# Copyright (c) 2007 Dag-Erling Smørgrav
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer
#    in this position and unchanged.
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

bindir=%%PREFIX%%/bin
tool=$(basename $0)

error() {
	echo "$@" 1>&2
	exit 1
}

# Verify that the requested tool is one we know about
case ${tool} in
%%TOOLS_CASE%%)
	;;
*)
	error "${tool}: unknown tool"
	;;
esac

if [ -n "${AUTOTOOLS_DEBUG}" -a -n "${%%TOOL%%_VERSION}" ] ; then
	echo "Requested ${tool} version ${%%TOOL%%_VERSION}" 1>&2
fi

#
# Identify available versions.
#
# The double sort is necessary to correctly identify 1.10 as newer
# than 1.9.
#
# Note that it is conceivable that version A.BC of the requested tool
# is present both as "toolABC" and as "tool-A.BC".  We take no special
# measures to handle this case.
#
/usr/bin/find ${bindir}/ -name "${tool}*[0-9]" | /usr/bin/sed -E \
    -e "s@^.*/${tool}-([0-9])\\.([0-9]+)\$@\1 \2 \1.\2@" | \
    /usr/bin/sort -n -k1 | /usr/bin/sort -n -s -k2 | {
while read maj min suffix ; do
	selected_version=$suffix
	if [ -n "${%%TOOL%%_VERSION}" -a \
	    "x${%%TOOL%%_VERSION}" = x${selected_version} ] ; then
		break
	fi
done

if [ -z "${selected_version}" ] ; then
	error "${tool}: not installed"
fi

if [ -n "${%%TOOL%%_VERSION}" -a \
    "x${%%TOOL%%_VERSION}" != x${selected_version} ] ; then
	error "${tool}: required version" \
	    "${%%TOOL%%_VERSION} not found"
fi

if [ -n "${AUTOTOOLS_DEBUG}" ] ; then
	echo "Selecting ${tool} version ${selected_version}" \
	    "(${bindir}/${tool}-${selected_version})" 1>&2
fi

exec ${bindir}/${tool}-${selected_version} "$@"
}
