PORTNAME=	kimageformats
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	2
CATEGORIES=	graphics kde kde-frameworks

PATCH_SITES=	https://invent.kde.org/frameworks/${PORTNAME}/-/commit/
PATCHFILES+=	f475a4b24a16.patch:-p1 # chase https://github.com/AOMediaCodec/libavif/commit/b3d441ad6d3f
PATCHFILES+=	350ce1b990460cb2178f369f22fe80803f5645f3.diff:-p1 \
		1190e53e9b69da6f9663ceb75c4813c5708b7cbd.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library providing support for additional image formats

LIB_DEPENDS=	libImath.so:math/Imath

USES=		cmake compiler:c++11-lib kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	archive \
		ecm:build
USE_QT=		core gui printsupport widgets \
		buildtools:build qmake:build

CFLAGS+=	-I${LOCALBASE}/include/Imath

OPTIONS_DEFINE=	AVIF JXL HEIF OPENEXR
OPTIONS_DEFAULT=	AVIF JXL HEIF OPENEXR
OPTIONS_SUB=	yes

AVIF_LIB_DEPENDS=	libavif.so:graphics/libavif
AVIF_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_libavif

JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
JXL_CMAKE_BOOL=		KIMAGEFORMATS_JXL

HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
HEIF_CMAKE_BOOL=	KIMAGEFORMATS_HEIF

OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr
OPENEXR_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenEXR

post-patch:
		${REINPLACE_CMD} s,Imf::Int64,uint64_t, \
			${WRKSRC}/src/imageformats/exr.cpp

.include <bsd.port.mk>
