# New ports collection makefile for:	xfce4-notes-plugin
# Date created:		06 October 2003
# Whom:			Thorsten Greiner <thorsten.greiner@web.de>
#
# $FreeBSD$
#

PORTNAME=	xfce4-notes-plugin
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	deskutils xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
DIST_SUBDIR=	xfce4

MAINTAINER=	thorsten.greiner@web.de
COMMENT=	Sticky notes panel plugin for XFce4

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.1:${PORTSDIR}/x11-toolkits/libxfce4gui
RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

USE_GNOME=	gtk20 libxml2
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
