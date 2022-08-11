PORTNAME=	openjpeg
PORTVERSION=	2.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open-source JPEG 2000 codec

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake>=3:devel/cmake
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake cpe localbase:ldflags jpeg pkgconfig

CMAKE_OFF=	BUILD_DOC BUILD_JAVA BUILD_JPIP BUILD_JPIP_SERVER BUILD_LUTS_GENERATOR BUILD_TESTING BUILD_THIRDPARTY BUILD_UNIT_TESTS BUILD_VIEWER WITH_ASTYLE
CMAKE_ON=	BUILD_CODEC BUILD_PKGCONFIG_FILES BUILD_SHARED_LIBS BUILD_STATIC_LIBS
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION} VER=${PORTVERSION:R}

GH_ACCOUNT=	uclouvain
USE_GITHUB=	yes

CPE_VENDOR=	uclouvain

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/thirdparty/astyle/
	@${RM} -r ${WRKSRC}/thirdparty/include/
	@${RM} -r ${WRKSRC}/thirdparty/liblcms2/
	@${RM} -r ${WRKSRC}/thirdparty/libpng/
	@${RM} -r ${WRKSRC}/thirdparty/libtiff/
	@${RM} -r ${WRKSRC}/thirdparty/libz/

.include <bsd.port.mk>
