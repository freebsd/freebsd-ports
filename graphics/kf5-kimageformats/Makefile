PORTNAME=	kimageformats
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	2
CATEGORIES=	graphics kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library providing support for additional image formats

LIB_DEPENDS=	libImath.so:math/Imath

USES=		cmake compiler:c++11-lib kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	archive ecm
USE_QT=		core gui printsupport widgets \
		buildtools_build qmake_build

CFLAGS+=	-I${LOCALBASE}/include/Imath

OPTIONS_DEFINE=	AVIF OPENEXR
OPTIONS_DEFAULT=	AVIF OPENEXR
OPTIONS_SUB=	yes

AVIF_DESC=		AV1 Image File Format via libavif
AVIF_LIB_DEPENDS=	libavif.so:graphics/libavif
AVIF_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_libavif

OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr
OPENEXR_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenEXR

post-patch:
		${REINPLACE_CMD} s,Imf::Int64,uint64_t, \
			${WRKSRC}/src/imageformats/exr.cpp

.include <bsd.port.mk>
