# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	openvex
PORTVERSION=	0.5.1
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

MAN1=		openvex.1 openvex-new-project.1

ALL_TARGET=	all clean

.include <bsd.port.mk>
