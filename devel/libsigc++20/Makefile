# New ports collection makefile for:   libsigc++2
# Date created:        14 Feb 2004
# Whom:                Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libsigc++
PORTVERSION=	2.0.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/libsigc++/${PORTVERSION:R}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Callback Framework for C++

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_GCC=	3.4
USE_GMAKE=	yes
LATEST_LINK=	libsigc++20
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_LIBTOOL_VER=15

PLIST_SUB=	VERSION="2.0" API_VERSION="2.0"

.include <bsd.port.mk>
