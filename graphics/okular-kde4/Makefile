# $FreeBSD$

PORTNAME=	okular
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	13
CATEGORIES=	graphics kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 universal document viewer

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre \
		libkscreen.so:graphics/libkscreen \
		libqca.so:devel/qca@qt4 \
		libtiff.so:graphics/tiff \
		libspectre.so:print/libspectre \
		libchm.so:misc/chmlib \
		libfreetype.so:print/freetype2 \
		libepub.so:textproc/ebook-tools \
		libqmobipocket.so:graphics/kdegraphics-mobipocket-kde4

USES=		cmake:outsource jpeg kde:4 pkgconfig qt:4 tar:xz
USE_KDE=	kdelibs automoc4 qimageblitz kactivities \
		libkexiv2
USE_QT=		corelib declarative gui opengl xml \
		qmake_build moc_build uic_build rcc_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DVI

DVI_DESC=	Device independent TeX files support (requires teTeX)
DVI_USE=	TEX=latex

.include <bsd.port.mk>
