#!/bin/sh -e
#
# Copyright (c) 2003-2004 Oliver Eikemeier. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
#  1. Redistributions of source code must retain the above copyright notice
#     this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# 3. Neither the name of the author nor the names of its contributors may be
#    used to endorse or promote products derived from this software without
#    specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
# INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
# AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# $FreeBSD$
#
# MAINTAINER=	eik@FreeBSD.org
#
# PKGORIGIN connects packaged or installed ports to the directory they
# originally came from. Although often overlooked, they are extremly
# important for tools like pkg_version or portupgrade to work correctly.
# Wrong PKGORIGINs are usually caused by a wrong order of CATEGORIES
# after a repocopy.
#
# This tool checks all ports in the ports tree (even those not connected
# to the build) for a wrong PKGORIGIN. Run this tool periodically and
# after every repocopy and correct errors immediately.
#
# Usage:
#   [env PORTSDIR=/usr/ports] chkorigin.sh [category ...]
#

opt_verbose=false
opt_quiet=false

while getopts vq opt; do
        case "$opt" in
        q)
                opt_quiet=true;;
        v)
                opt_verbose=true;;
        ?)
                echo "Usage: $0 [-qv] [category ...]"
                exit 2;;
        esac
done

shift $((${OPTIND}-1))

rc=0

$opt_quiet || echo "checking categories for ports with a wrong PKGORIGIN"

cd "${PORTSDIR:=/usr/ports}"
if [ $# -gt 0 ]; then
    CATEGORIES=`echo $@`
else
    CATEGORIES=`echo [a-z]*`
fi

for category in ${CATEGORIES}; do
    if [ ! -d "${PORTSDIR}/${category}" ]; then continue; fi
    case "${category}" in
        CVS) continue ;;
        Mk) continue ;;
        Templates) continue ;;
        Tools) continue ;;
        distfiles) continue ;;
        packages) continue ;;
    esac

    $opt_quiet || echo "==> ${category}"

    cd "${PORTSDIR}/${category}"
    PORTS=`echo *`

    for port in ${PORTS}; do
        if [ ! -d "${PORTSDIR}/${category}/${port}" ]; then continue; fi
        case "${port}" in
            CVS) continue ;;
            pkg) continue ;;
        esac

        $opt_verbose && echo "==> ${category}/${port}"

        cd "${PORTSDIR}/${category}/${port}"
        PKGORIGIN=`/usr/bin/make -VPKGORIGIN 2>/dev/null || true"`

        if [ "${PKGORIGIN}" != "${category}/${port}" ]; then
            echo "port \"${category}/${port}\" has the wrong PKGORIGIN \"${PKGORIGIN}\""
            rc=1
        fi
    done
done

return ${rc}
