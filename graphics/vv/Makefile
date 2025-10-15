PORTNAME=	vv
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0-406
DISTVERSIONSUFFIX=	-gd33ac3e8
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and simple 4D image viewer
WWW=		https://github.com/open-vv/vv

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	googletest>0:devel/googletest # error: unable to find library -lGTest::GTest, see https://github.com/open-vv/vv/issues/74
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libfreetype.so:print/freetype2 \
		libgdcmCommon.so:devel/gdcm \
		libhdf5_cpp.so:science/hdf5 \
		libITKLabelMap-5.0.so:science/InsightToolkit501 \
		libmpi.so:net/mpich \
		libnetcdf.so:science/netcdf \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff \
		libvtkIOSQL-${VTK_VER}.so:math/vtk9

USES=		cmake compiler:c++11-lang eigen:3 jpeg python:build,run qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	open-vv
USE_QT=		core designer gui network opengl declarative sql widgets xml buildtools:build qmake:build
USE_XORG=	ice sm x11 xext xt
USE_CXXSTD=	c++11

CMAKE_ARGS=	-DVTK_DIR:PATH=${LOCALBASE}/lib/vtk-8.2/cmake/vtk-8.2

PLIST_FILES=	bin/vv

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
CXXFLAGS+=	-msse2 # workaround for ITK failing to add -msse2 on i386: https://github.com/open-vv/vv/issues/83 & https://github.com/InsightSoftwareConsortium/ITK/issues/2011
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/VTK_OVERRIDE/override/g' \
		${WRKSRC}/vv/vtkVOXImageWriter.h \
		${WRKSRC}/vv/vvAnimatedGIFWriter.h \
		${WRKSRC}/vv/vvBlendImageActor.h \
		${WRKSRC}/vv/vvClipPolyData.h \
		${WRKSRC}/vv/vvGlyph2D.h \
		${WRKSRC}/vv/vvGlyphSource.h \
		${WRKSRC}/vv/vvInteractorStyleNavigator.h \
		${WRKSRC}/vv/vvLandmarksGlyph.h \
		${WRKSRC}/vv/vvSlicer.h
	@${REINPLACE_CMD} -e 's/Widget()->GetRenderWindow()/Widget()->renderWindow()/g' \
		${WRKSRC}/vv/vvToolHistogramCommand.cxx
	@${REINPLACE_CMD} -e 's/Widget->GetRenderWindow()/Widget->renderWindow()/g' \
		${WRKSRC}/vv/vvMainWindow.cxx \
		${WRKSRC}/vv/vvSegmentationDialog.cxx \
		${WRKSRC}/vv/vvSurfaceViewerDialog.cxx \
		${WRKSRC}/vv/vvToolHistogram.cxx \
		${WRKSRC}/vv/vvToolProfile.cxx
	@${REINPLACE_CMD} -e 's/widget->GetRenderWindow()/widget->renderWindow()/g' \
		${WRKSRC}/vv/vvMainWindow.cxx

post-configure: # workaround for "error: unable to find library -lGTest::GTest", see https://github.com/open-vv/vv/issues/74
	@${REINPLACE_CMD} -E 's/ -lGTest::(GTest|Main) / /g' ${BUILD_WRKSRC}/build.ninja
	@${REINPLACE_CMD} -E 's|/usr/local/lib/libtiff\.so\.[0-9]+\.[0-9]+\.[0-9]+|/usr/local/lib/libtiff.so|g' ${BUILD_WRKSRC}/build.ninja

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.post.mk>
