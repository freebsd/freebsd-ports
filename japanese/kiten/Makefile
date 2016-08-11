# $FreeBSD$

PORTNAME=	kiten
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	japanese kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Japanese reference/study tool for KDE 4

USE_KDE4=	kdelibs automoc4
USES=		cmake:outsource tar:xz
USE_QT4=	corelib moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
