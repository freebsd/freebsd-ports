PORTNAME=	kimageformats
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	2
CATEGORIES=	graphics kde kde-frameworks

COMMENT=	Plugins to allow QImage to support extra file formats
MAINTAINER=	kde@FreeBSD.org

USES=		cmake gl kde:6 pkgconfig qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	archive ecm:build
USE_QT=		base

OPTIONS_DEFINE=	AVIF JXL HEIF OPENEXR RAW
OPTIONS_DEFAULT=	AVIF JXL HEIF OPENEXR RAW
OPTIONS_SUB=	yes

AVIF_LIB_DEPENDS=	libavif.so:graphics/libavif
AVIF_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_libavif

JXL_LIB_DEPENDS=	libjxl.so:graphics/libjxl
JXL_CMAKE_BOOL=		KIMAGEFORMATS_JXL

HEIF_LIB_DEPENDS=	libheif.so:graphics/libheif
HEIF_CMAKE_BOOL=	KIMAGEFORMATS_HEIF

OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr \
			libImath.so:math/Imath
OPENEXR_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenEXR

RAW_LIB_DEPENDS=	libraw.so:graphics/libraw
RAW_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_libraw

.include <bsd.port.mk>
