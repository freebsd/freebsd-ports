# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	2.29
PORTREVISION=	20180105
PORTEPOCH=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	riscv64-

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	GNU binutils for RISC-V cross-development

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc

USES=	bison gmake libtool makeinfo

USE_GITHUB=	yes
GH_ACCOUNT=	freebsd-riscv
GH_PROJECT=	riscv-binutils-gdb
GH_TAGNAME=	dc03ed3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX}${OPSYS:tl} \
		--with-sysroot=/ \
		--disable-gdb \
		--disable-sim \
		--enable-tls \
		--disable-werror \
		--disable-nls \
		--disable-intl \
		--disable-shared \
		--with-system-zlib \
		--with-gmp=${LOCALBASE} \
		--with-mpfr=${LOCALBASE}

.include <bsd.port.pre.mk>

post-install:
	@if [ -d ${STAGEDIR}${PREFIX}/${INFO_PATH} ] ; then ${RM} -r ${STAGEDIR}${PREFIX}/${INFO_PATH}; fi

.include <bsd.port.post.mk>
