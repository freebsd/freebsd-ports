PORTNAME=	openimageio
DISTVERSIONPREFIX=	Release-
DISTVERSION=	2.2.19.0
CATEGORIES=	graphics multimedia
PKGNAMESUFFIX=	-ociov1
# special port to link oiio libs with ociov1
# specifically to build blender-lts28 while still officially supported

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	OpenImageIO graphics library linked to ocio v1

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/include/tsl/robin_map.h:devel/robin-map
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libfmt.so:devel/libfmt \
		libhdf5.so:science/hdf5 \
		libheif.so:graphics/libheif \
		libImath.so:math/Imath \
		libOpenColorIOv1.so:graphics/opencoloriov1 \
		libOpenEXR.so:graphics/openexr \
		libpng.so:graphics/png \
		libsquish.so:graphics/squish \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp

USES=		cmake jpeg compiler:c++14-lang iconv:wchar_t
USE_GITHUB=	yes
GH_ACCOUNT=	OpenImageIO
GH_PROJECT=	oiio

CMAKE_ON=	USE_OCIO
CMAKE_OFF=	BUILDSTATIC INSTALL_FONTS LINKSTATIC NOTHREADS \
		STOP_ON_WARNING USE_OPENSSL USE_QT USE_OPENGL \
		OIIO_BUILD_TESTS OIIO_BUILD_TOOLS USE_PYTHON
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DICOM DOCS FFMPEG FREETYPE GIF \
			OPENCV OPENJPEG PTEX RAW TBB VDB
OPTIONS_DEFAULT=	DICOM FREETYPE GIF OPENJPEG PTEX
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

OPENCV_CMAKE_BOOL=	USE_OPENCV
OPENCV_LIB_DEPENDS=	libopencv_core.so:graphics/opencv \
			libopenjpeg.so:graphics/openjpeg15

OPENJPEG_CMAKE_BOOL=	USE_OPENJPEG
OPENJPEG_LIB_DEPENDS=	libopenjp2.so:graphics/openjpeg

PTEX_DESC=		ptex support
PTEX_LIB_DEPENDS=	libPtex.so:graphics/ptex

RAW_CMAKE_BOOL=		USE_LIBRAW
RAW_LIB_DEPENDS=	libraw_r.so:graphics/libraw

TBB_DESC=		Intel tbb support
TBB_CMAKE_BOOL=		USE_TBB
TBB_LIB_DEPENDS=	libtbb.so:devel/onetbb

VDB_DESC=		OpenVDB support
VDB_CMAKE_ARGS=		-DCMAKE_CXX_STANDARD=14
VDB_CMAKE_BOOL=		USE_OPENVDB
VDB_LIB_DEPENDS=	libopenvdb.so:misc/openvdb

# DISTVERSION has an extra digit which isn't in the lib name
# for LIBVERS we want the first three digits
PLIST_SUB=	SHL3=${PORTVERSION:R} SHL2=${PORTVERSION:R:R}
DOCSDIR=	${PREFIX}/share/doc/openimageio-${PKGNAMESUFFIX}

post-patch:
	${REINPLACE_CMD} -e 's|<OpenColorIO/|<OpenColorIOv1/|g' \
		${WRKSRC}/src/libOpenImageIO/color_ocio.cpp

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/include/OpenImageIO${PKGNAMESUFFIX} \
		-name '*.h' -or -name '*.hpp' | \
		${XARGS} ${REINPLACE_CMD} -e 's|<OpenImageIO/|<OpenImageIO${PKGNAMESUFFIX}/|g'
	${FIND} ${STAGEDIR}${PREFIX}/include/OpenImageIO${PKGNAMESUFFIX} -name '*.bak' -delete
	@(cd ${STAGEDIR}${PREFIX}/lib/cmake  && ${MV} OpenImageIO OpenImageIO${PKGNAMESUFFIX})
	@(cd ${STAGEDIR}${PREFIX}/share/cmake/Modules && \
		${MV} FindOpenImageIO.cmake FindOpenImageIO${PKGNAMESUFFIX}.cmake)

.include <bsd.port.mk>
