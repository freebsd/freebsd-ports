# $FreeBSD$

PORTNAME=	kdegraphics-thumbnailers
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	graphics kde kde-kde4
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Thumbnailers for various graphics file formats

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

USES=		cmake kde:4 pkgconfig qt:4 tar:xz
USE_KDE=	kdelibs libkdcraw libkexiv2 automoc4
USE_QT=		gui qmake_build moc_build uic_build rcc_build

.include <bsd.port.mk>
