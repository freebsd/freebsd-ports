# New ports collection makefile for:	xfce4-xkb-plugin
# Date created:				2004-08-27
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	xfce4-xkb-plugin
PORTVERSION=	0.3.2
PORTREVISION=	4
CATEGORIES=	deskutils xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
DIST_SUBDIR=	xfce4

MAINTAINER=	des@FreeBSD.org
COMMENT=	Keyboard layout switching plugin for XFce4

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui
RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

USE_GNOME=	gtk20 libxml2
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_INC_LIBTOOL_VER=	13
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
