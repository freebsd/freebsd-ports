# $FreeBSD$

PORTNAME=	kturtle
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	lang kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Educational programming environment for KDE 4

USE_KDE4=	kdelibs automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	corelib gui xml moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
