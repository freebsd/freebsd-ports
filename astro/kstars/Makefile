# New ports collection makefile for:	kstars
# Date created:				6 September 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kstars
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	astro kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 desktop planetarium

LIB_DEPENDS=	cfitsio.0:${PORTSDIR}/astro/cfitsio

BUILD_DEPENDS=	eigen>=2.0.b3:${PORTSDIR}/math/eigen2 \
		xplanet:${PORTSDIR}/astro/xplanet

RUN_DEPENDS=	xplanet:${PORTSDIR}/astro/xplanet

CONFLICTS=	kdeedu-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	opengl qmake_build moc_build rcc_build uic_build
USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
