# $FreeBSD$

PORTNAME=	kanagram
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	games kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Letter order game for KDE 4

USE_KDE4=	kdelibs libkdeedu automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	xml corelib declarative gui opengl script xml \
		moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
