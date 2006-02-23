# New ports collection makefile for:	xfce4-windowlist-plugin
# Date created:		2003-04-26
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-windowlist-plugin
PORTVERSION=	0.1.0
PORTREVISION=	4
CATEGORIES=	deskutils xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
DISTNAME=	xfce4-windowlist-plugin-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A windowlist plugin for xfce4-panel

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

USE_GNOME=	gtk20 libxml2
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
