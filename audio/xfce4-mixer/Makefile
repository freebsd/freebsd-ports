# New ports collection makefile for:	xfce4-mixer
# Date created:		3 July 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-mixer
PORTVERSION=	4.0.5
PORTREVISION=	0
CATEGORIES=	audio xfce
MASTER_SITES=	ftp://ftp.berlios.de/pub/xfce-goodies/${PORTVERSION}/ \
		http://hannelore.f1.fhtw-berlin.de/mirrors/xfce4/xfce-${PORTVERSION}/src/
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	XFce 4 volume mixer module for xfce4-panel

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.1:${PORTSDIR}/x11-toolkits/libxfce4gui \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

USE_GETTEXT=	yes
USE_GNOME=	gtk20
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS=-I${LOCALBASE}/include \
		CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib

.include <bsd.port.mk>
