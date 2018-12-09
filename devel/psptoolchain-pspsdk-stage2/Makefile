# Created by: Tassilo Philipp <tphilipp@potion-studios.com>
# $FreeBSD$

PORTREVISION=		2

PKGNAMESUFFIX=		-stage2

MAINTAINER=		tphilipp@potion-studios.com
COMMENT=		PlayStation Portable development toolchain ${PORTNAME}

BUILD_DEPENDS=		psp-cpp:devel/psptoolchain-gcc-stage2 \
			psp-gcc:devel/psptoolchain-gcc-stage2 \
			psp-gcov:devel/psptoolchain-gcc-stage2 \
			psp-g++:devel/psptoolchain-gcc-stage2 \
			psp-ar:devel/psptoolchain-binutils \
			${LOCALBASE}/psp/lib/libc.a:devel/psptoolchain-newlib

# psp-gcc doesn't need -march=... in CFLAGS (e.g. set by CPUTYPE in make.conf)
CONFIGURE_ENV=		CFLAGS="${CFLAGS:C/(^|[[:space:]])-march=[^[:space:]]*//g}"
CONFIGURE_ARGS=		--prefix=${PREFIX} --with-pspdev="${LOCALBASE}"

PLIST=			${.CURDIR}/pkg-plist
MASTERDIR=		${.CURDIR}/../psptoolchain-pspsdk-stage1

.include "${MASTERDIR}/Makefile"
