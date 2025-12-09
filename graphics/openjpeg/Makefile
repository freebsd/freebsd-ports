PORTNAME=	openjpeg
PORTVERSION=	2.5.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	graphics

PATCH_SITES=	https://github.com/uclouvain/openjpeg/commit/
PATCHFILES=	5e258319332800f7a9937dc0b8b16b19a07dea8f.patch:-p1 \
		7b508bb00f7fc5e7b61a6035fc4e2622d4ddff0d.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open-source JPEG 2000 codec
WWW=		https://www.openjpeg.org/ \
		https://github.com/uclouvain/openjpeg

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		cmake cpe localbase:ldflags jpeg pathfix pkgconfig

CMAKE_OFF=	BUILD_DOC \
		BUILD_JAVA \
		BUILD_JPIP \
		BUILD_JPIP_SERVER \
		BUILD_LUTS_GENERATOR \
		BUILD_TESTING \
		BUILD_THIRDPARTY \
		BUILD_UNIT_TESTS \
		BUILD_VIEWER \
		WITH_ASTYLE
CMAKE_ON=	BUILD_CODEC \
		BUILD_SHARED_LIBS \
		BUILD_STATIC_LIBS
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION} VER=${PORTVERSION:R}

GH_ACCOUNT=	uclouvain
USE_GITHUB=	yes

CPE_VENDOR=	uclouvain

# Clean up bundled libraries
.if !defined(MAINTAINER_MODE)
EXTRACT_AFTER_ARGS=	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/thirdparty/astyle \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/thirdparty/include \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/thirdparty/liblcms2 \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/thirdparty/libpng \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/thirdparty/libtiff \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/thirdparty/libz \
			--no-same-owner --no-same-permissions
.else
post-patch:
	@${RM} -r ${WRKSRC}/thirdparty/astyle/
	@${RM} -r ${WRKSRC}/thirdparty/include/
	@${RM} -r ${WRKSRC}/thirdparty/liblcms2/
	@${RM} -r ${WRKSRC}/thirdparty/libpng/
	@${RM} -r ${WRKSRC}/thirdparty/libtiff/
	@${RM} -r ${WRKSRC}/thirdparty/libz/
.endif

.include <bsd.port.mk>
