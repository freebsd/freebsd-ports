# New ports collection makefile for: psptoolchain-gcc-stage2
# Date created:        15 February 2009
# Whom:                Tassilo Philipp <tphilipp@potion-studios.com>
#
# $FreeBSD$
#

PKGNAMESUFFIX=		-stage2

MAINTAINER=		tphilipp@potion-studios.com

BUILD_DEPENDS=		${LOCALBASE}/psp/lib/libc.a:${PORTSDIR}/devel/psptoolchain-newlib

MAKE_ENV=		CFLAGS_FOR_TARGET="-G0"
CONFIGURE_ARGS=		--prefix=${PREFIX} --target="psp" --enable-languages="c,c++" --with-newlib --enable-cxx-flags="-G0" --disable-nls

MAN1=			psp-g++.1

PLIST=			${.CURDIR}/pkg-plist
MASTERDIR=		${.CURDIR}/../psptoolchain-gcc-stage1

.include "${MASTERDIR}/Makefile"
