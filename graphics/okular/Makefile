# $FreeBSD$

PORTNAME=	okular
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE 4 universal document viewer

LIB_DEPENDS=	libdjvulibre.so:${PORTSDIR}/graphics/djvulibre \
		libkscreen.so:${PORTSDIR}/graphics/libkscreen \
		libqca.so:${PORTSDIR}/devel/qca \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libpoppler-qt4.so:${PORTSDIR}/graphics/poppler-qt4 \
		libspectre.so:${PORTSDIR}/print/libspectre \
		libchm.so:${PORTSDIR}/misc/chmlib \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libepub.so:${PORTSDIR}/textproc/ebook-tools \
		libqmobipocket.so:${PORTSDIR}/graphics/kdegraphics4-mobipocket

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
