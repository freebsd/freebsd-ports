# New ports collection makefile for:	xfce4-windowlist-plugin
# Date created:		2003-04-26
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-windowlist-plugin
PORTVERSION=	0.1.0
PORTREVISION=	3
CATEGORIES=	deskutils xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/ \
		http://matt.nerim.net/xfce-goodies/ \
		http://xfce.org/~kelnos/mirrors/xfce-goodies/
DISTNAME=	xfce4-windowlist-plugin-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	matt@bsdfly.org
COMMENT=	A windowlist plugin for xfce4-panel

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

USE_GNOME=	gtk20 libxml2
USE_X_PREFIX=	yes
USE_INC_LIBTOOL_VER=13
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
