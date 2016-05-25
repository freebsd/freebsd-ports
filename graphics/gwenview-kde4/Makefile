# $FreeBSD$

PORTNAME=	gwenview
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and browser for KDE 4

LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libpng.so:graphics/png

USE_KDE4=	kactivities kdelibs baloo kfilemetadata \
		libkdcraw libkipi libkonq automoc4 soprano
USES=		cmake:outsource jpeg pkgconfig tar:xz
USE_QT4=	corelib gui opengl qmake_build moc_build uic_build rcc_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
