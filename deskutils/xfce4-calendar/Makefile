# New ports collection makefile for:	xfce4-calendar
# Date created:		2003-01-14
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-calendar
PORTVERSION=	0.1.6
PORTREVISION=	2
CATEGORIES=	deskutils xfce
MASTER_SITES=	ftp://ftp.berlios.de/pub/xfce-goodies/4.0.4/ \
		http://www.xfce.org/archive/xfce-4.0.4/src/
DISTNAME=	xfcalendar-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	matt@rimasec.net
COMMENT=	A calendar application to manage your time with XFce 4

BUILD_DEPENDS=	xfce-mcs-manager:${PORTSDIR}/sysutils/xfce4-mcs-manager
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.1:${PORTSDIR}/x11-toolkits/libxfce4gui \
		dbh-1.0.1:${PORTSDIR}/databases/dbh

USE_GNOME=	gtk20 libxml2
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL_VER=	13
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
