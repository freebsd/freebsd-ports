# $FreeBSD$

PORTNAME=	vv
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0-383
DISTVERSIONSUFFIX=	-g7a783a8b
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and simple 4D image viewer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	googletest>0:devel/googletest # error: unable to find library -lGTest::GTest, see https://github.com/open-vv/vv/issues/74
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libgdcmCommon.so:devel/gdcm \
		libhdf5_cpp.so:science/hdf5 \
		libITKLabelMap-5.0.so:science/InsightToolkit \
		libpng.so:graphics/png \
		libsz.so:science/szip \
		libtiff.so:graphics/tiff \
		libvtkIOSQL-8.2.so:math/vtk8

USES=		cmake compiler:c++11-lang eigen:3 jpeg qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	open-vv
USE_QT=		core designer gui network sql widgets xml buildtools_build qmake_build
USE_XORG=	ice sm x11 xext xt
USE_CXXSTD=	c++11

CMAKE_ARGS=	-DVTK_DIR:PATH=${LOCALBASE}/lib/vtk-8.2/cmake/vtk-8.2

PLIST_FILES=	bin/vv

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
CXXFLAGS+=	-msse2 # workaround for ITK failing to add -msse2 on i386: https://github.com/open-vv/vv/issues/83 & https://github.com/InsightSoftwareConsortium/ITK/issues/2011
.endif

post-configure: # workaround for "error: unable to find library -lGTest::GTest", see https://github.com/open-vv/vv/issues/74
	@${REINPLACE_CMD} -E 's/ -lGTest::(GTest|Main) / /g' ${BUILD_WRKSRC}/build.ninja

.include <bsd.port.post.mk>
