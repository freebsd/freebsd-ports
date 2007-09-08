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
# The purpose of this script is to find the installed port which contains
# the specified libraries.
#

print_usage() {
	echo "Usage: $0 [-b base ...] lib_name ..."
	echo "Example: $0 -b /usr/local -b /space/porttest libX11.so"
}

which pkg_which >/dev/null 2>&1
if [ $? -ne 0 ]; then
	echo "pkg_which not found in path (${PATH}), aborting" | fmt
	exit 1
fi

args=$(getopt b:h $@)
if [ $? -ne 0 ]; then
	print_usage
	exit 2
fi

set -- ${args}
for arg; do
	case "${arg}" in
	-b)
		bases="${bases} $2"
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

if [ -z "${bases}" ]; then
	bases=/usr/local
fi

if [ -z "${PORTSDIR}" ]; then
	PORTSDIR=$(make -f /etc/make.conf -V PORTSDIR)
fi

if [ -z "${PORTSDIR}" ]; then
	PORTSDIR=/usr/ports
fi
if [ ! -d "${PORTSDIR}" ]; then
	echo "PORTSDIR = ${PORTSDIR} is not a directory."
	exit 1
fi

if [ -z "${PKG_DBDIR}" ]; then
	PKG_DBDIR=/var/db/pkg
fi
if [ ! -d "${PKG_DBDIR}" ]; then
	echo "PKG_DBDIR = ${PKG_DBDIR} is not a directory."
	exit 1
fi

for i in $@; do
	result=""

	case $i in
	libcrypto.so|libssl.so)
		echo "USE_OPENSSL=	yes"
		continue
		;;
	esac

	if [ -e /lib/$i -o -e /usr/lib/$i ]; then
		# base system lib, skipping
		shift
		continue
	fi


	lib=${i##*/}
	lib="$(echo ${lib} | sed -e 's:^lib:: ; s:\.so.*::')"
	# I didn't managed to make awk accept a pattern with a '/' inside,
	# so don't complain about using grep+awk instead of awk only.
	lib_pathname=$(ldconfig -r | grep $i | awk '{print $3}')

	origin=unknown
	for base in ${bases}; do
		port=$(pkg_which "${base}/lib/$i")

		if [ -f $PKG_DBDIR/$port/+CONTENTS ]; then
			origin=$(grep "@comment ORIGIN:" \
				$PKG_DBDIR/$port/+CONTENTS \
				| sed -e 's/@comment ORIGIN://')
			break
		else
			continue
		fi
	done

	if [ ${origin} = unknown ]; then
		if [ -f ${lib_pathname} ]; then
			port=$(pkg_which "${lib_pathname}")
			if [ -f /var/db/pkg/$port/+CONTENTS ]; then
				origin=$(grep "@comment ORIGIN:" \
					/var/db/pkg/$port/+CONTENTS \
					| sed -e 's/@comment ORIGIN://')
			else
				result="${lib} ($i) not found, unknown origin"
			fi
		fi
	fi

	if [ ${origin} != unknown ]; then
		category=${origin%/*}
		portname=${origin##*/}

		XORG="$(egrep ${origin}\$ ${PORTSDIR}/Mk/bsd.xorg.mk \
			2>/dev/null | grep _LIB | sed -e 's:_LIB.*::')"

		GNOME="$(egrep ${origin}\$ ${PORTSDIR}/Mk/bsd.gnome.mk \
			2>/dev/null | grep _LIB | sed -e 's:_LIB.*::')"

		EFL="$([ "X$(make ${PORTSDIR}/Mk/bsd.efl.mk -V \
			_${portname}_CATEGORY )" = "X${category}" ] && \
			echo ${portname})"

		GL="$(egrep  ${origin}\$ ${PORTSDIR}/Mk/bsd.port.mk \
			2>/dev/null | grep _LIB_DEPENDS \
			| sed -e 's:_GL_:: ; s:_LIB_DEPENDS.*::')"

	fi

	if [ -n "${XORG}" ]; then
		result="USE_XORG+=	${XORG}		(${origin})"
		if [ $(echo ${XORG} | wc -w) -ne 1 ]; then
			result="${result}        # result ambiguous, check yourself: ${lib}"
		fi
	fi

	if [ -n "${GNOME}" ]; then
		result="USE_GNOME+=	${GNOME}		(${origin})"
		if [ $(echo ${GNOME} | wc -w) -ne 1 ]; then
			result="${result}        # result ambiguous, check yourself: ${lib}"
		fi
	fi

	if [ -n "${EFL}" ]; then
		result="USE_EFL+=	${EFL}		(${origin})"
	fi

	if [ -n "${GL}" ]; then
		result="USE_GL+=       ${GL}		(${origin})"
	fi

	# USE_xxx exceptions, sorting key is the USE_xxx name
	# START and STOP are needed for a perfect match
	case "START${origin}STOP" in
	STARTdevel/famSTOP|STARTdevel/gaminSTOP)
		result="USE_FAM=	yes		(${origin})"
		;;
	STARTprint/freetypeSTOP)
		result="USE_FREETYPE=	yes		(${origin})"
		;;
	STARTdevel/gettextSTOP)
		result="USE_GETTEXT=	yes		(${origin})"
		;;
	STARTconverters/libiconvSTOP)
		result="USE_ICONV=	yes		(${origin})"
		;;
	STARTnet/openldap*sasl*clientSTOP)
		result="USE_OPENLDAP=	yes	WANT_OPENLDAP_SASL=	yes"
		;;
	STARTnet/openldap*clientSTOP)
		result="USE_OPENLDAP=	yes		(${origin})"
		;;
	STARTdevel/sdl12STOP)
		result="USE_SDL=	sdl		(${origin})"
		;;
	/sdl_)
		result="USE_SDL=	$(echo $origin | sed -e 's:.*/sdl_::g')		(${origin})"
		;;
	esac

	if [ -z "${result}" ]; then
		result="${lib}:\${PORTSDIR}/${origin}"
	fi

	echo "${result}"
	shift
done | sort -u
