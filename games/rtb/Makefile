# New ports collection makefile for:	RealTimeBattle
# Date created:				30 June 2000
# Whom:				Dishanker Rajakulendren <draj@oceanfree.net>
#
# $FreeBSD$
#

PORTNAME=	RealTimeBattle
PORTVERSION=	1.0.4
CATEGORIES=	games
MASTER_SITES=	http://www.lysator.liu.se/realtimebattle/Download/

MAINTAINER=	draj@oceanfree.net

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--enable-debug
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
