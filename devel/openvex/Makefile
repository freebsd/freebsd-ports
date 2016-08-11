# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	openvex
PORTVERSION=	0.5.3
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Open source firmware for Vex robotics controllers

LICENSE=	GPLv3

BROKEN=		does not build (crt0iz.c:31: error 226: no type specifier for 'stack')
BROKEN_powerpc64=	does not build

BUILD_DEPENDS=	sdcc:lang/sdcc \
		gpasm:devel/gputils
RUN_DEPENDS=	vexctl:devel/roboctl \
		sdcc:lang/sdcc \
		gpasm:devel/gputils

USES+=		tar:xz

MAKE_FLAGS+=	PREFIX=${STAGEDIR}${PREFIX} \
		MANPREFIX=${STAGEDIR}${PREFIX}

post-patch:
	@${REINPLACE_CMD} \
		-e 's|--denable-peeps|--denable-peeps --use-non-free|g' \
		${WRKSRC}/Include/Makefile.sdcc_defs

.include <bsd.port.mk>
