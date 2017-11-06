# $FreeBSD$

PORTNAME=	libopencm3
PORTVERSION=	0.0.20170522
CATEGORIES=	devel

MAINTAINER=	lev@FreeBSD.org
COMMENT=	LGPLv3 Cortex-M0/M3/M4 runtime library

LICENSE=	LGPL3

BUILD_DEPENDS=	${LOCALBASE}/gcc-arm-embedded-${TOOLCHAIN_FULL_VERSION}/bin/arm-none-eabi-gcc:devel/gcc-arm-embedded

USE_GITHUB=	yes
GH_ACCOUNT=	libopencm3
GH_TAGNAME=	b76d853

USES=		gmake python:2,build shebangfix

SHEBANG_FILES=	scripts/irq2nvic_h \
		scripts/lpcvtcksum

TOOLCHAIN_FULL_VERSION?=6-2017-q2-update
TOOLCHAIN_PORT_VERSION?=6.3.20170628
TOOLCHAIN_TARGET?=arm-none-eabi

DESTDIRNAME=	STAGEDIR
MAKE_ENV=	PATH=${LOCALBASE}/gcc-arm-embedded-${TOOLCHAIN_FULL_VERSION}/bin:${PATH} \
		DESTDIR=${STAGEDIR}${PREFIX}/gcc-arm-embedded-${TOOLCHAIN_FULL_VERSION}

PLIST_SUB+=	TARGET=${TOOLCHAIN_TARGET} FULL_VERSION=${TOOLCHAIN_FULL_VERSION}

do-configure:
	${FIND} ${WRKSRC} -name Makefile -o -name \*.mk -type f | ${XARGS} ${REINPLACE_CMD} -e 's|PREFIX|TARGET|g'

.include <bsd.port.mk>
