# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	openvex
PORTVERSION=	0.5.2
CATEGORIES=	devel
MASTER_SITES=	http://acadix.biz/Ports/distfiles/ \
		http://personalpages.tds.net/~jwbacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Open source firmware for Vex robotics controllers

LICENSE=	GPLv3

BUILD_DEPENDS=	sdcc:${PORTSDIR}/lang/sdcc \
		gpasm:${PORTSDIR}/devel/gputils
RUN_DEPENDS=	vexctl:${PORTSDIR}/devel/roboctl \
		sdcc:${PORTSDIR}/lang/sdcc \
		gpasm:${PORTSDIR}/devel/gputils

REINPLACE_ARGS=	-i ""

MAN1=		openvex.1 openvex-new-project.1

ALL_TARGET=	all clean

post-patch:
# Use make's -C option to descent into directories and fix parallel builds
	@${REINPLACE_CMD} -e 's/^all:/& depend/ ; s/ make depend &&//' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E 's/cd (.+)(;| &&) make/$$(MAKE) -C \1/' \
		${WRKSRC}/Advanced/Makefile ${WRKSRC}/Beginner/Makefile \
		${WRKSRC}/HiBob/Makefile ${WRKSRC}/Makefile

.include <bsd.port.mk>
