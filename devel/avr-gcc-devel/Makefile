# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	4.10.0.s20140803
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GCC/snapshots/${DISTVERSION}
PKGNAMEPREFIX=	avr-
PKGNAMESUFFIX=	-devel
# DISTNAME=	gcc-${DISTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	FSF GCC 4.x for Atmel AVR 8-bit RISC cross-development

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BUILD_DEPENDS=	avr-as:devel/avr-binutils \
		avr-ld:devel/avr-binutils
LIB_DEPENDS=	libmpfr.so:math/mpfr \
		libgmp.so:math/gmp \
		libmpc.so:math/mpc
RUN_DEPENDS=	avr-as:devel/avr-binutils \
		avr-ld:devel/avr-binutils

# DISTVERSION relates to downloads, GCC_VERSION and SUFFIX to names
# of executables and directories once installed.  A PORTVERSION of
# 4.Y.2.s20130808 results in values of 4.Y-20130808, 4.Y.2, and 4Y
# for these three.
DISTVERSION=	${PORTVERSION:C/([0-9]+\.[0-9]+).*\.s([0-9]+)/\1-\2/}
GCC_VERSION=	${PORTVERSION:C/(.+)\.s[0-9]{8}/\1/}
SUFFIX=		${PORTVERSION:C/([0-9]+).([0-9]+).*/\1\2/}

USES=		bison gettext gmake perl5 tar:bzip2 libtool
USE_PERL5=	build
CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64")
ARCH=		x86_64
.endif

CONFLICTS=	avr-gcc-4*

CONFIGURE_ARGS=	--target=avr --disable-libssp --with-gmp=${LOCALBASE} --enable-languages="c c++"

WITHOUT_CPU_CFLAGS=This is a cross-compiler.

INFO=		cpp gcc gccint cppinternals gccinstall

post-configure:
	${MKDIR} ${WRKSRC}/gcc/include

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/gcc/avr/4.10.0/liblto_plugin.so.0

.include <bsd.port.post.mk>
