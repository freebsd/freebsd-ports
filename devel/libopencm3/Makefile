PORTNAME=	libopencm3
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=v
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	lev@FreeBSD.org
COMMENT=	LGPLv3 Cortex-M0/M3/M4 runtime library
WWW=		https://github.com/libopencm3/libopencm3

LICENSE=	LGPL3

BUILD_DEPENDS=	${LOCALBASE}/gcc-arm-embedded-${TOOLCHAIN_FULL_VERSION}/bin/arm-none-eabi-gcc:devel/gcc-arm-embedded

USES=		gmake python:build shebangfix
USE_GITHUB=	yes
SHEBANG_FILES=	scripts/irq2nvic_h \
		scripts/lpcvtcksum

TOOLCHAIN_FULL_VERSION?=14.2.rel1
TOOLCHAIN_TARGET?=arm-none-eabi

DESTDIRNAME=	STAGEDIR
MAKE_ENV=	PATH=${LOCALBASE}/gcc-arm-embedded-${TOOLCHAIN_FULL_VERSION}/bin:${PATH} \
		DESTDIR=${STAGEDIR}${PREFIX}/gcc-arm-embedded-${TOOLCHAIN_FULL_VERSION}

PLIST_SUB+=	TARGET=${TOOLCHAIN_TARGET} FULL_VERSION=${TOOLCHAIN_FULL_VERSION}

do-configure:
	${FIND} ${WRKSRC} -name Makefile -o -name \*.mk -type f | ${XARGS} ${REINPLACE_CMD} -e 's|PREFIX|TARGET|g'

.include <bsd.port.mk>
