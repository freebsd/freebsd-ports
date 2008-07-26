# New ports collection makefile for:	roboctl
# Date created:		2007-05-03
# Whom:			Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	roboctl
PORTVERSION=	0.3.1
CATEGORIES=	devel
MASTER_SITES=	http://personalpages.tds.net/~jwbacon/Ports/distfiles/ \
		http://jbacon.dyndns.org/~bacon/Ports/distfiles/

MAINTAINER=	jwbacon@tds.net
COMMENT=	API for communications with Lego and Vex robot controllers

LIB_DEPENDS=	usb-0.1.8:${PORTSDIR}/devel/libusb \
		gamepad.1:${PORTSDIR}/devel/libgamepad

OPTIONS=	CUTECOM "Install cutecom for Vex debugging" On

MAN1=		legoctl.1 vexctl.1 nxtremote.1
MAN3=		roboctl.3

.include <bsd.port.pre.mk>

.if defined(WITH_CUTECOM)
RUN_DEPENDS+=	cutecom:${PORTSDIR}/comms/cutecom
.endif

.include <bsd.port.post.mk>
