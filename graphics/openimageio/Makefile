# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	openimageio
PORTVERSION=	1.8.17
DISTVERSIONPREFIX=	Release-
PORTREVISION=	2
CATEGORIES?=	graphics multimedia

MAINTAINER?=	FreeBSD@Shaneware.biz
COMMENT?=	OpenImageIO graphics library

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libImath.so:graphics/ilmbase \
		libIlmImf.so:graphics/openexr \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp \
		libhdf5.so:science/hdf5

USES=		cmake jpeg compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	OpenImageIO
GH_PROJECT=	oiio

# fbm also installs bin/idiff
CONFLICTS=	fbm-[0-9]*

CMAKE_ARGS=	USE_CPP:STRING=11
CMAKE_OFF=	BUILDSTATIC LINKSTATIC NOTHREADS STOP_ON_WARNING USE_OPENSSL

OPTIONS_DEFINE=		DOCS FFMPEG FREETYPE GIF IMAGEVIEWER OCIO OPENCV \
			OPENJPEG RAW TEST
OPTIONS_DEFAULT=	FREETYPE GIF OCIO OPENJPEG
OPTIONS_SUB=		yes

DOCS_CMAKE_BOOL=	INSTALL_DOCS
DOCS_CMAKE_ON=		-DCMAKE_INSTALL_DOCDIR:STRING=${DOCSDIR}

FFMPEG_DESC=		Use FFmpeg to support extra file types
FFMPEG_CMAKE_BOOL=	USE_FFMPEG
FFMPEG_LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg

FREETYPE_CMAKE_BOOL=	USE_FREETYPE
FREETYPE_CMAKE_ON=	-DFONTS_INSTALL_DIR:STRING=share/fonts/oiio_dev
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2

GIF_CMAKE_BOOL=		USE_GIF
GIF_LIB_DEPENDS=	libgif.so:graphics/giflib

IMAGEVIEWER_DESC=	Build image viewer (requires Qt)
IMAGEVIEWER_USES=	qt:5
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

TEST_CMAKE_BOOL=	OIIO_BUILD_TESTS

PLIST_SUB+=		LIBVERS=${PORTVERSION}

.include <bsd.port.options.mk>

.if ${SLAVE_PORT} == yes
LIB_DEPENDS+=	libOpenImageIO.so:graphics/openimageio \
		${PY_BOOST}
PLIST=		${PKGDIR}/pkg-plist-pybind
USES+=		python
USE_PYTHON=	flavors
CMAKE_ON+=	USE_PYTHON
CMAKE_OFF+=	OIIO_BUILD_TOOLS USE_FFMPEG
CMAKE_ARGS+=	-DPYTHON_VERSION:STRING=${PYTHON_VER}

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_LIB} ${BUILD_WRKSRC}/src/python/OpenImageIO.so ${STAGEDIR}${PYTHON_SITELIBDIR}
.else # SLAVE_PORT == no
USE_LDCONFIG=	yes
CMAKE_ON+=	DOIIO_BUILD_TOOLS
CMAKE_OFF+=	USE_PYTHON

post-install:
	${LN} -sf libOpenImageIO.so.1.8 \
		${STAGEDIR}${PREFIX}/lib/libOpenImageIO.so.1
	${LN} -sf libOpenImageIO_Util.so.1.8 \
		${STAGEDIR}${PREFIX}/lib/libOpenImageIO_Util.so.1

do-test-TEST-on:
	@cd ${BUILD_WRKSRC} && ${MAKE_CMD} ARGS=-V test
.endif

.include <bsd.port.mk>
