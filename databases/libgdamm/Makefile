# New ports collection makefile for:    libglademm
# Date created:         1 Oct 2003
# Whom:                 Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libgdamm
PORTVERSION=	1.3.0
PORTREVISION=	3
CATEGORIES=	databases gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.3
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libgda2 library

LIB_DEPENDS=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack libgda2
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static

.include <bsd.port.mk>
