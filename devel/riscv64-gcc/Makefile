# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	6.1.0
CATEGORIES=	devel
PKGNAMEPREFIX=	riscv64-

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Cross GNU Compiler Collection for ${PKGNAMEPREFIX:C/-//g}

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PKGNAMEPREFIX}binutils>0:devel/${PKGNAMEPREFIX}binutils
RUN_DEPENDS=	${PKGNAMEPREFIX}binutils>0:devel/${PKGNAMEPREFIX}binutils
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd-riscv
GH_PROJECT=	riscv-gcc
GH_TAGNAME=	095b1d6

USES=	iconv gmake libtool makeinfo

GCC_TARGET=	${PKGNAMEPREFIX}unknown-${OPSYS:tl}${OSREL}

CONFIGURE_ENV=	LC_ALL=C
MAKE_ENV=	LC_ALL=C
GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_ARGS=	--target=${GCC_TARGET} \
		--with-sysroot=/ \
		--without-newlib \
		--without-headers \
		--with-pkgversion="FreeBSD Ports Collection for ${PKGNAMEPREFIX:C/-//g}" \
		--with-system-zlib \
		--with-as=${LOCALBASE}/bin/${PKGNAMEPREFIX}freebsd-as \
		--with-ld=${LOCALBASE}/bin/${PKGNAMEPREFIX}freebsd-ld \
		--disable-werror \
		--disable-shared \
		--enable-threads \
		--enable-tls \
		--enable-languages=c,c++ \
		--with-gmp=${LOCALBASE} \
		--with-mpfr=${LOCALBASE} \
		--with-mpc=${LOCALBASE} \
		--disable-libatomic \
		--disable-libmudflap \
		--disable-libssp \
		--disable-libquadmath \
		--disable-libgomp \
		--disable-nls \
		--disable-bootstrap \
		--disable-multilib

ALL_TARGET=	inhibit-libc=true all-gcc
INSTALL_TARGET=	inhibit-libc=true install-gcc

PLIST_SUB=	GCC_TARGET=${GCC_TARGET} \
		GCC_VERSION=${PORTVERSION}

post-install:
	@if [ -d ${STAGEDIR}${PREFIX}/${INFO_PATH} ] ; then ${RM} -r ${STAGEDIR}${PREFIX}/${INFO_PATH}; fi
	@${RM} ${STAGEDIR}${PREFIX}/man/man7/*

.include <bsd.port.mk>
