# Ports collection Makefile for:        bulb
# Date created:                         03/09/2000
# Whom:                                 smoberly@xavier.dyndns.org
#
# $FreeBSD$
#

PORTNAME=	bulb
PORTVERSION=	1.0.6
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.idiap.ch/~gobry/bulb/

MAINTAINER=	smoberly@xavier.dyndns.org

LIB_DEPENDS=	panel_applet.4:${PORTSDIR}/x11/gnomecore

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" LDFLAGS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/gnome

.include <bsd.port.mk>
