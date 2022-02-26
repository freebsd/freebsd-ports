PORTNAME=	openimageio
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.12.0
# PORTREVISION must be set with ?= so as not to stomp over
# py-openimageio's PORTREVISION.
# Also, just to be on the safe side, when resetting,
# best keep PORTREVISION?=	0.
PORTREVISION?=	1
CATEGORIES?=	graphics multimedia

MAINTAINER?=	FreeBSD@Shaneware.biz
COMMENT?=	OpenImageIO graphics library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/tsl/robin_map.h:devel/robin-map
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libhdf5.so:science/hdf5 \
		libheif.so:graphics/libheif \
		libImath.so:math/Imath \
		libOpenColorIO.so:graphics/opencolorio \
		libOpenEXR.so:graphics/openexr \
		libpng.so:graphics/png \
		libsquish.so:graphics/squish \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp

USES=		cmake jpeg compiler:c++14-lang iconv:wchar_t qt:5

USE_QT+=	buildtools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	OpenImageIO
GH_PROJECT=	oiio

CMAKE_OFF=	BUILDSTATIC INSTALL_FONTS LINKSTATIC NOTHREADS \
		STOP_ON_WARNING USE_OPENSSL OIIO_DOWNLOAD_MISSING_TESTDATA

OPTIONS_DEFINE=		DICOM DOCS FFMPEG FREETYPE GIF IMAGEVIEWER \
			OPENCV OPENJPEG PTEX RAW TBB TEST TOOLS VDB
OPTIONS_DEFAULT=	DICOM FREETYPE GIF OPENJPEG PTEX TOOLS VDB
OPTIONS_SUB=		yes

DOCS_CMAKE_BOOL=	INSTALL_DOCS
DOCS_CMAKE_ON=		-DCMAKE_INSTALL_DOCDIR:STRING=${DOCSDIR}

DICOM_DESC=		DICOM/MEDICOM support
DICOM_CMAKE_BOOL=	USE_DICOM
DICOM_LIB_DEPENDS=	libdcmimage.so:graphics/dcmtk

FFMPEG_DESC=		Use FFmpeg to support extra file types
FFMPEG_CMAKE_BOOL=	USE_FFMPEG
FFMPEG_LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg

FREETYPE_CMAKE_BOOL=	USE_FREETYPE
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_RUN_DEPENDS=	${LOCALBASE}/share/fonts/Droid/DroidSans.ttf:x11-fonts/droid-fonts-ttf

GIF_CMAKE_BOOL=		USE_GIF
GIF_LIB_DEPENDS=	libgif.so:graphics/giflib

IMAGEVIEWER_DESC=	Build image viewer (requires Qt)
IMAGEVIEWER_USES=	gl
IMAGEVIEWER_IMPLIES=	TOOLS
IMAGEVIEWER_CMAKE_BOOL=	USE_QT USE_OPENGL
IMAGEVIEWER_USE=	GL=gl,glu,glew \
			QT=buildtools,core,gui,opengl,qmake_build,widgets

OPENCV_CMAKE_BOOL=	USE_OPENCV
OPENCV_IMPLIES=		OPENJPEG
OPENCV_LIB_DEPENDS=	libopencv_highgui.so:graphics/opencv \
			libopencv_core.so:graphics/opencv

OPENJPEG_CMAKE_BOOL=	USE_OPENJPEG
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg

PTEX_DESC=		ptex support
PTEX_LIB_DEPENDS=	libPtex.so:graphics/ptex

RAW_CMAKE_BOOL=		USE_LIBRAW
RAW_LIB_DEPENDS=	libraw_r.so:graphics/libraw

TBB_DESC=		Intel tbb support
TBB_CMAKE_BOOL=		USE_TBB
TBB_LIB_DEPENDS=	libtbb.so:devel/onetbb

TEST_CMAKE_BOOL=	OIIO_BUILD_TESTS

TOOLS_DESC=		Build CLI tools
TOOLS_CMAKE_BOOL=	OIIO_BUILD_TOOLS

VDB_DESC=		OpenVDB support
VDB_CMAKE_BOOL=		USE_OPENVDB
VDB_LIB_DEPENDS=	libopenvdb.so:misc/openvdb

PLIST_SUB=	SHL3=${PORTVERSION:R} SHL2=${PORTVERSION:R:R} SHL1=${PORTVERSION:R:R:R}
SHL2=		${PORTVERSION:R:R}
SHL1=		${PORTVERSION:R:R:R}

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE}," ${WRKSRC}/src/cmake/modules/FindPtex.cmake

.include <bsd.port.options.mk>

.if ${SLAVE_PORT} == yes
BUILD_DEPENDS+=	${PREFIX}/share/cmake/pybind11/pybind11Config.cmake:devel/pybind11
LIB_DEPENDS+=	libOpenImageIO.so:graphics/openimageio
PLIST=		${PKGDIR}/pkg-plist-pybind
USES+=		python
USE_PYTHON=	flavors
CMAKE_ON+=	USE_PYTHON
# we don't need the apps built - only libs.
CMAKE_OFF+=	USE_QT USE_OPENGL OIIO_BUILD_TOOLS OIIO_BUILD_TESTS \
		EMBED_PLUGINS
CMAKE_ARGS+=	-DPYTHON_VERSION:STRING=${PYTHON_VER}

do-install:
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib/python/site-packages/OpenImageIO*.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
.else # SLAVE_PORT != yes
USE_LDCONFIG=	yes
CMAKE_OFF+=	USE_PYTHON

post-install:
	${LN} -sf libOpenImageIO.so.${SHL2} \
		${STAGEDIR}${PREFIX}/lib/libOpenImageIO.so.${SHL1}
	${LN} -sf libOpenImageIO_Util.so.${SHL2} \
		${STAGEDIR}${PREFIX}/lib/libOpenImageIO_Util.so.${SHL1}

do-test-TEST-on:
	@cd ${BUILD_WRKSRC} && ${SETENV} ARGS=-V ${MAKE_CMD} test
.endif # SLAVE_PORT

.include <bsd.port.mk>
