# $FreeBSD$

PORTNAME=	kdegraphics-mobipocket
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mobipocket plugins for Strigi indexing and thumbnails

USES=		cmake:outsource tar:xz
USE_KDE4=	kdelibs automoc4 strigi
USE_QT4=	corelib gui qmake_build moc_build uic_build rcc_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
