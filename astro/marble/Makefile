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

LIB_DEPENDS=	gps.19:${PORTSDIR}/astro/gpsd

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
MD5_FILE=	${PORTSDIR}/misc/kdeedu4/distinfo
MAKE_JOBS_SAFE=	yes

CMAKE_SOURCE_PATH=	${WRKSRC}/marble
CMAKE_OUTSOURCE=	yes

pre-configure:
	${LN} -s ${WRKSRC}/doc/marble ${WRKSRC}/marble/marble

.include <bsd.port.mk>
