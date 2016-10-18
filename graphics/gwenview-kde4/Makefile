# $FreeBSD$

PORTNAME=	gwenview
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and browser for KDE 4

LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libpng.so:graphics/png

USES=		cmake:outsource jpeg kde:4 pkgconfig tar:xz
USE_KDE=	kactivities kdelibs baloo kfilemetadata \
		libkdcraw libkipi libkonq automoc4 soprano
USE_QT4=	corelib gui opengl qmake_build moc_build uic_build rcc_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
