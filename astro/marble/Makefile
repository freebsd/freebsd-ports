# New ports collection makefile for:	marble
# Date created:		2010-05-30
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	marble
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	astro kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	kdeedu-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Virtual globe and world atlas for KDE

LIB_DEPENDS=	gps.20:${PORTSDIR}/astro/gpsd

CONFLICTS=	kdeedu-4.5.[0-5]

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
DISTINFO_FILE=	${PORTSDIR}/misc/kdeedu4/distinfo

WRKSRC=		${WRKDIR}/${DISTNAME}/marble
CMAKE_OUTSOURCE=	yes

.include <bsd.port.mk>
