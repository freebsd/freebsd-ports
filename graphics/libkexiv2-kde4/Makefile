# $FreeBSD$

PORTNAME=	libkexiv2
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	6
CATEGORIES=	graphics kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Exiv2 library interface for KDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libexiv2.so:graphics/exiv2

USES=		cmake kde:4 qt:4 tar:xz
USE_KDE=	automoc4 kdelibs
USE_QT=		corelib gui xml \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

pre-configure:
	${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_INSTALL_DIR}/libdata/' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
