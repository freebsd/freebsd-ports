# New ports collection makefile for:	gcolor
# Date created:		20 Feb 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gcolor
PORTVERSION=	0.4
CATEGORIES=	graphics gnome x11
MASTER_SITES=	http://download.sourceforge.net/gcolor/

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs

USE_X_PREFIX=	yes
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GTK_CONFIG="${GTK_CONFIG}"

.include <bsd.port.mk>
