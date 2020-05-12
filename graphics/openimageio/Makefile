# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	openimageio
DISTVERSIONPREFIX=	Release-
DISTVERSION=	2.1.11.2
PORTREVISION=	5
CATEGORIES?=	graphics multimedia

MAINTAINER?=	FreeBSD@Shaneware.biz
COMMENT?=	OpenImageIO graphics library

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/tsl/robin_map.h:devel/robin-map
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libheif.so:graphics/libheif \
		libImath.so:graphics/ilmbase \
		libIlmImf.so:graphics/openexr \
		libpng.so:graphics/png \
		libsquish.so:graphics/squish \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp \
		libhdf5.so:science/hdf5

USES=		cmake jpeg compiler:c++11-lib iconv:wchar_t
USE_GITHUB=	yes
GH_ACCOUNT=	OpenImageIO
GH_PROJECT=	oiio

# fbm also installs bin/idiff
CONFLICTS=	fbm-[0-9]*

CMAKE_OFF=	BUILDSTATIC INSTALL_FONTS LINKSTATIC NOTHREADS \
		STOP_ON_WARNING USE_OPENSSL

OPTIONS_DEFINE=		DICOM DOCS FFMPEG FREETYPE GIF IMAGEVIEWER OCIO \
			OPENCV OPENJPEG RAW TBB TEST TOOLS VDB
OPTIONS_DEFAULT=	DICOM FREETYPE GIF OCIO OPENJPEG TOOLS
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
IMAGEVIEWER_USES=	gl qt:5
IMAGEVIEWER_IMPLIES=	TOOLS
IMAGEVIEWER_CMAKE_BOOL=	USE_QT USE_OPENGL
IMAGEVIEWER_USE=	GL=gl,glu,glew \
			QT=buildtools,core,gui,opengl,qmake_build,widgets

OCIO_DESC=		Color management support
OCIO_CMAKE_BOOL=	USE_OCIO
OCIO_LIB_DEPENDS=	libOpenColorIO.so:graphics/opencolorio

OPENCV_CMAKE_BOOL=	USE_OPENCV
OPENCV_LIB_DEPENDS=	libopencv_highgui.so:graphics/opencv \
			libopencv_core.so:graphics/opencv-core \
			libopenjpeg.so:graphics/openjpeg15

OPENJPEG_CMAKE_BOOL=	USE_OPENJPEG
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg

RAW_CMAKE_BOOL=		USE_LIBRAW
RAW_LIB_DEPENDS=	libraw_r.so:graphics/libraw

TBB_DESC=		Intel tbb support
TBB_CMAKE_BOOL=		USE_TBB
TBB_LIB_DEPENDS=	libtbb.so:devel/tbb

TEST_CMAKE_BOOL=	OIIO_BUILD_TESTS

TOOLS_DESC=		Build CLI tools
TOOLS_CMAKE_BOOL=	OIIO_BUILD_TOOLS

VDB_DESC=		OpenVDB support
VDB_CMAKE_BOOL=		USE_OPENVDB
VDB_LIB_DEPENDS=	libopenvdb.so:misc/openvdb

# DISTVERSION has an extra digit which isn't in the lib name
# for LIBVERS we want the first three digits
PLIST_SUB+=	LIBVERS=${DISTVERSION:C/([0-9]*)\.([0-9]*)\.([0-9]*)(.*)/\1.\2.\3/}

.include <bsd.port.options.mk>

.if ${SLAVE_PORT} == yes
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR}
LIB_DEPENDS+=	libOpenImageIO.so:graphics/openimageio
PLIST=		${PKGDIR}/pkg-plist-pybind
USES+=		python
USE_PYTHON=	flavors
CMAKE_ON+=	USE_PYTHON
CMAKE_ARGS+=	-DPYTHON_VERSION:STRING=${PYTHON_VER} \
		-DPYBIND11_INCLUDE_DIR:STRING="${PYTHONPREFIX_INCLUDEDIR}"

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib/python/site-packages/OpenImageIO.so ${STAGEDIR}${PYTHON_SITELIBDIR}
.else # SLAVE_PORT == no
USE_LDCONFIG=	yes
CMAKE_OFF+=	USE_PYTHON

post-install:
	${LN} -sf libOpenImageIO.so.2.1 \
		${STAGEDIR}${PREFIX}/lib/libOpenImageIO.so.2
	${LN} -sf libOpenImageIO_Util.so.2.1 \
		${STAGEDIR}${PREFIX}/lib/libOpenImageIO_Util.so.2

do-test-TEST-on:
	@cd ${BUILD_WRKSRC} && ${MAKE_CMD} ARGS=-V test
.endif

.include <bsd.port.mk>
