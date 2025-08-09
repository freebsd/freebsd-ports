PORTNAME=	openimageio
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.13.1
# PORTREVISION must be set with ?= so as not to stomp over
# py-openimageio's PORTREVISION.
# Also, just to be on the safe side, when resetting,
# best keep PORTREVISION?=	0.
PORTREVISION?=	11
CATEGORIES?=	graphics multimedia

MAINTAINER?=	FreeBSD@Shaneware.biz
COMMENT?=	OpenImageIO graphics library
WWW=		https://www.openimageio.org/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/tsl/robin_map.h:devel/robin-map \
		libfmt>10.0.0:devel/libfmt \
		libjpeg-turbo>3.0.0:graphics/libjpeg-turbo
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libImath.so:math/Imath \
		libOpenColorIO.so:graphics/opencolorio \
		libOpenEXR.so:graphics/openexr \
		libheif.so:graphics/libheif \
		libpng.so:graphics/png \
		libpugixml.so:textproc/pugixml \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp
RUN_DEPENDS=	libfmt>10.0.0:devel/libfmt \
		libjpeg-turbo>3.0.0:graphics/libjpeg-turbo

USES=		cmake jpeg compiler:c++17-lang iconv:wchar_t

USE_GITHUB=	yes
GH_ACCOUNT=	AcademySoftwareFoundation
GH_PROJECT=	OpenImageIO

CMAKE_ARGS=	-DCMAKE_CXX_STANDARD:INTEGER=17 # OpenVDB uses the C++17 STL
# feature std::tuple_size_v; since the slave port py-openimageio excludes
# options - this is a global line here
CMAKE_ON=	BUILD_SHARED_LIBS USE_EXTERNAL_PUGIXML
CMAKE_OFF=	BUILD_FMT_FORCE BUILD_MISSING_FMT INSTALL_FONTS INTERNALIZE_FMT \
		LINKSTATIC OIIO_DOWNLOAD_MISSING_TESTDATA OIIO_USING_FMT_LOCAL \
		STOP_ON_WARNING

SHL1=		${PORTVERSION:R:R:R}
SHL2=		${PORTVERSION:R:R}
SHL3=		${PORTVERSION:R}
PLIST_SUB=	SHL1=${SHL1} SHL2=${SHL2} SHL3=${SHL3}

OPTIONS_DEFINE=		DICOM DOCS FFMPEG FREETYPE GIF IMAGEVIEWER \
			OPENCV OPENJPEG PTEX RAW TBB TEST TOOLS VDB
OPTIONS_DEFAULT=	DICOM FREETYPE GIF OPENJPEG PTEX TBB TOOLS VDB
OPTIONS_SUB=		yes

DICOM_DESC=		DICOM/MEDICOM support
FFMPEG_DESC=		Use FFmpeg to support extra file types
IMAGEVIEWER_DESC=	Build image viewer (requires Qt)
PTEX_DESC=		Per face texture library support
TBB_DESC=		Intel tbb support
TOOLS_DESC=		Build CLI tools
VDB_DESC=		OpenVDB support

DICOM_LIB_DEPENDS=	libdcmimage.so:graphics/dcmtk
DICOM_USES=		gnome ssl
DICOM_USE=		gnome=libxml2
DICOM_CMAKE_BOOL=	USE_DICOM

DOCS_CMAKE_BOOL=	INSTALL_DOCS
DOCS_CMAKE_ON=		-DCMAKE_INSTALL_DOCDIR:STRING=${DOCSDIR}

FFMPEG_LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg
FFMPEG_CMAKE_BOOL=	USE_FFMPEG

FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_RUN_DEPENDS=	${LOCALBASE}/share/fonts/Droid/DroidSans.ttf:x11-fonts/droid-fonts-ttf
FREETYPE_CMAKE_BOOL=	USE_FREETYPE

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CMAKE_BOOL=		USE_GIF

IMAGEVIEWER_IMPLIES=	TOOLS
IMAGEVIEWER_USES=	gl qt:6
IMAGEVIEWER_USE=	GL=gl,glu QT=base
IMAGEVIEWER_CMAKE_BOOL=	USE_QT

OPENCV_IMPLIES=		OPENJPEG
OPENCV_LIB_DEPENDS=	libopencv_core.so:graphics/opencv
OPENCV_CMAKE_BOOL=	USE_OPENCV

OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg
OPENJPEG_CMAKE_BOOL=	USE_OPENJPEG

PTEX_LIB_DEPENDS=	libPtex.so:graphics/ptex
PTEX_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Ptex

RAW_LIB_DEPENDS=	libraw_r.so:graphics/libraw
RAW_CMAKE_BOOL=		USE_LIBRAW

TBB_LIB_DEPENDS=	libtbb.so:devel/onetbb
TBB_CMAKE_BOOL=		USE_TBB

TEST_CMAKE_BOOL=	OIIO_BUILD_TESTS

TOOLS_CMAKE_BOOL=	OIIO_BUILD_TOOLS

VDB_IMPLIES=		TBB
VDB_LIB_DEPENDS=	libopenvdb.so:misc/openvdb
VDB_CMAKE_BOOL=		USE_OPENVDB

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE}," \
	${WRKSRC}/src/cmake/modules/FindPtex.cmake

.include <bsd.port.options.mk>

.if ${SLAVE_PORT} == yes
BUILD_DEPENDS+=	${PREFIX}/share/cmake/pybind11/pybind11Config.cmake:devel/pybind11
LIB_DEPENDS+=	libOpenImageIO.so:graphics/openimageio
USES+=		python
USE_PYTHON=	flavors
CMAKE_ARGS+=	-DPYTHON_VERSION:STRING=${PYTHON_VER}
CMAKE_ON+=	USE_PYTHON
# we don't need the apps built - only libs.
CMAKE_OFF+=	EMBED_PLUGINS OIIO_BUILD_TESTS OIIO_BUILD_TOOLS USE_DICOM USE_FFMPEG USE_FREETYPE USE_GIF USE_LIBRAW USE_OPENCV USE_OPENJPEG USE_OPENVDB USE_QT USE_TBB
PLIST=		${PKGDIR}/pkg-plist-pybind

do-install:
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib/python/site-packages/OpenImageIO*.so ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
.else # SLAVE_PORT != yes
USE_LDCONFIG=	yes
CMAKE_OFF+=	USE_PYTHON

post-install:
	${LN} -sf libOpenImageIO.so.${SHL3} \
		${STAGEDIR}${PREFIX}/lib/libOpenImageIO.so.${SHL2}
	${LN} -sf libOpenImageIO.so.${SHL3} \
		${STAGEDIR}${PREFIX}/lib/libOpenImageIO.so.${SHL1}
	${LN} -sf libOpenImageIO_Util.so.${SHL3} \
		${STAGEDIR}${PREFIX}/lib/libOpenImageIO_Util.so.${SHL2}
	${LN} -sf libOpenImageIO_Util.so.${SHL3} \
		${STAGEDIR}${PREFIX}/lib/libOpenImageIO_Util.so.${SHL1}

do-test-TEST-on:
	@cd ${BUILD_WRKSRC} && ${SETENV} ARGS=-V ${MAKE_CMD} test
.endif # SLAVE_PORT

.include <bsd.port.mk>
