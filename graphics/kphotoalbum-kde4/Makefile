# New ports collection makefile for:	kimdaba
# Date created:			Sat Dec 13 16:09:29 CET 2003
# Whom:				Markus Brueffer <brueffer@phoenix-systems.de>
#
# $FreeBSD$

PORTNAME=	kphotoalbum
PORTVERSION=	${APP_VER}.${EXTRA_VER}
PORTREVISION=	4
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/extragear
DISTNAME=	${PORTNAME}-${APP_VER}-kde${EXTRA_VER}
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and organizer for KDE

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		exiv2.10:${PORTSDIR}/graphics/exiv2 \
		kipi.8:${PORTSDIR}/graphics/libkipi-kde4

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

LATEST_LINK=	${PORTNAME}-kde4

APP_VER=	4.1.1
EXTRA_VER=	4.4.0

OPTIONS=	MARBLE "Geolocation support (requires astro/marble)" off

.include <bsd.port.options.mk>

.if defined(WITH_MARBLE)
LIB_DEPENDS+=	marblewidget.11:${PORTSDIR}/astro/marble
.else
CMAKE_ARGS+=	-DWITH_Marble:BOOL=Off
.endif

.include <bsd.port.mk>
