# $FreeBSD$

PORTNAME=	okular
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	5
CATEGORIES=	graphics kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 universal document viewer

LIB_DEPENDS=	libdjvulibre.so:graphics/djvulibre \
		libkscreen.so:graphics/libkscreen \
		libqca.so:devel/qca \
		libtiff.so:graphics/tiff \
		libpoppler-qt4.so:graphics/poppler-qt4 \
		libspectre.so:print/libspectre \
		libchm.so:misc/chmlib \
		libfreetype.so:print/freetype2 \
		libepub.so:textproc/ebook-tools \
		libqmobipocket.so:graphics/kdegraphics4-mobipocket

USES=		cmake:outsource jpeg kde:4 pkgconfig tar:xz
USE_KDE=	kdelibs automoc4 qimageblitz kactivities \
		libkexiv2
USE_QT4=	corelib declarative gui opengl xml \
		qmake_build moc_build uic_build rcc_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DVI

DVI_DESC=	Device independent TeX files support (requires teTeX)
DVI_USE=	TEX=latex

.include <bsd.port.mk>
