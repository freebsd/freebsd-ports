# Created by: Tassilo Philipp <tphilipp@potion-studios.com>

PORTREVISION=		0

PKGNAMESUFFIX=		-stage2

MAINTAINER=		ports@FreeBSD.org

BUILD_DEPENDS=		${LOCALBASE}/psp/lib/libc.a:devel/psptoolchain-newlib

USES=			iconv

MAKE_ENV=		CFLAGS_FOR_TARGET="-G0" PATH=${PREFIX}/bin:${PATH}
CONFIGURE_ARGS=		--prefix=${PREFIX} \
			--target="psp" \
			--enable-languages="c,c++" \
			--enable-lto \
			--with-newlib \
			--with-gmp=${LOCALBASE} \
			--with-mpfr \
			--disable-libssp \
			--disable-nls \
			--enable-cxx-flags="-G0" \
			--with-ld=${LOCALBASE}/bin/psp-ld \
			--with-as=${LOCALBASE}/bin/psp-as \
			--mandir=${PREFIX}/man

PLIST=			${.CURDIR}/pkg-plist
MASTERDIR=		${.CURDIR}/../psptoolchain-gcc-stage1

.include "${MASTERDIR}/Makefile"
