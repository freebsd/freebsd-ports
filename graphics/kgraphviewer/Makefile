# New ports collection makefile for:	kgraphviewer
# Date created:		2008-09-01
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kgraphviewer
PORTVERSION=	${APP_VER}.${EXTRA_VER}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${EXTRA_VER}/src/extragear
DISTNAME=	${PORTNAME}-${APP_VER}-kde${EXTRA_VER}
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	GraphViz dot graph viewer for KDE

USE_BZIP2=	yes
USE_KDE4=	kdelibs pimlibs kdeprefix kdehier automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes

APP_VER=	2.0.2
EXTRA_VER=	4.2.3

.include <bsd.port.mk>
