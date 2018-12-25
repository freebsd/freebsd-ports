# $FreeBSD$

PORTNAME=	gwenview
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	4
CATEGORIES=	graphics kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and browser for KDE 4

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libpng.so:graphics/png

USES=		cmake jpeg kde:4 pkgconfig qt:4 tar:xz
USE_KDE=	kactivities kdelibs baloo kfilemetadata \
		libkdcraw libkipi libkonq automoc4 soprano
USE_QT=		corelib gui opengl qmake_build moc_build uic_build rcc_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
