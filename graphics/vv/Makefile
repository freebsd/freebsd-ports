# $FreeBSD$

PORTNAME=	vv
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0-271
DISTVERSIONSUFFIX=	-g24b75af3
PORTREVISION=	10
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and simple 4D image viewer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN=		wrong LIB_DEPENDS

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libgdcmCommon.so:devel/gdcm \
		libhdf5_cpp.so:science/hdf5 \
		libITKLabelMap-4.13.so:science/InsightToolkit \
		libpng.so:graphics/png \
		libsz.so:science/szip \
		libtiff.so:graphics/tiff \
		libvtkIOSQL-8.1.so:math/vtk8

USES=		cmake compiler:c++11-lang jpeg qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	open-vv
USE_QT=		core designer gui network sql widgets xml buildtools_build qmake_build
USE_XORG=	ice sm x11 xext xt
USE_CXXSTD=	c++11

PLIST_FILES=	bin/vv

post-configure: # need to investigate where these strings come from
	@${REINPLACE_CMD} 's| -lGTest::GTest -lGTest::Main | |' ${BUILD_WRKSRC}/build.ninja

.include <bsd.port.mk>
