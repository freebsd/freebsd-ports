# New ports collection makefile for:    gconfmm
# Date created:         22 May 2003
# Whom:                 Alexander Nedotsukov <bland@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	gconfmm
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkmm
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for gconf2 API library

LIB_DEPENDS=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gconf2
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static

.include <bsd.port.mk>
