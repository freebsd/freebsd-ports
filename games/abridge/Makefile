# New ports collection makefile for:    abridge
# Date created:         19.05.2003
# Whom: Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$

PORTNAME=	abridge
PORTVERSION=	0.4.0
PORTREVISION=	1
PORTREVISON=	1
CATEGORIES=	games
MASTER_SITES=	http://www.abridgegame.org/src/

MAINTAINER=	Janos.Mohacsi@bsd.hu
COMMENT=	Bridge game

LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${X11BASE}/bin/wxgtk2-2.4-config

MAN1=		abridge.1
PLIST_FILES=	bin/abridge

.include <bsd.port.mk>
