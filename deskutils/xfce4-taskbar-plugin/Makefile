# New ports collection makefile for:	xfce4-taskbar-plugin
# Date created:		2003-04-26
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-taskbar-plugin
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	deskutils xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/ \
		http://matt.nerim.net/xfce-goodies/ \
		http://xfce.org/~kelnos/mirrors/xfce-goodies/
DISTNAME=	xfce4-taskbar-plugin-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	matt@bsdfly.org
COMMENT=	A taskbar plugin for xfce4-panel

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

USE_GNOME=	gtk20 libxml2
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
