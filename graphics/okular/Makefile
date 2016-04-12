# $FreeBSD$

PORTNAME=	okular
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	4
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

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

USE_KDE4=	kdelibs kdeprefix automoc4 qimageblitz kactivities \
		libkexiv2
USE_QT4=	corelib declarative gui opengl xml \
		qmake_build moc_build uic_build rcc_build
USES=		cmake:outsource jpeg pkgconfig tar:xz
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DVI

DVI_DESC=	Device independent TeX files support (requires teTeX)
DVI_USE=	TEX=latex

.include <bsd.port.mk>
