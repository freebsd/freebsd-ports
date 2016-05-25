# $FreeBSD$

PORTNAME=	khangman
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	games kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Hangman game for KDE 4

USE_KDE4=	kdelibs libkdeedu automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	corelib declarative gui opengl script xml \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
