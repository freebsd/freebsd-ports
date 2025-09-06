PORTNAME=	devil
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.0
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Cross-platform image library
WWW=		https://openil.sourceforge.net/ \
		https://github.com/DentonW/DevIL

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake pkgconfig
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	DentonW
GH_PROJECT=	DevIL
USE_LDCONFIG=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

CMAKE_SOURCE_PATH=	${WRKSRC}/DevIL

OPTIONS_DEFINE=	JPEG JASPER LCMS2 LIBMNG PNG TIFF SQUISH DOCS EXAMPLES
OPTIONS_DEFAULT=JPEG JASPER LCMS2 LIBMNG PNG TIFF SQUISH

JPEG_USES=		jpeg
JPEG_CMAKE_OFF=		-DIL_NO_JPG=1

JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
JASPER_CMAKE_OFF=	-DIL_NO_JP2=1

LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS2_CMAKE_OFF=	-DIL_NO_LCMS=1

LIBMNG_LIB_DEPENDS=	libmng.so:graphics/libmng
LIBMNG_CMAKE_OFF=	-DIL_NO_MNG=1

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CMAKE_OFF=		-DIL_NO_PNG=1

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CMAKE_OFF=		-DIL_NO_TIF=1

# With OPENEXR the library is not usable from plain C (instant segfault)
# (but need to recheck with 1.8.0), also the detection is broken
#OPENEXR_LIB_DEPENDS=	libOpenEXR.so:graphics/openexr
#OPENEXR_CMAKE_OFF=	-DIL_NO_EXR=1
CMAKE_ARGS+=		-DIL_NO_EXR=1

SQUISH_DESC=		Enable DXT compression via libsquish
SQUISH_LIB_DEPENDS=	libsquish.so:graphics/squish
SQUISH_CMAKE_BOOL=	IL_USE_DXTC_SQUISH

# Fails to build with NVTT, uses not installed header
# (and NVTT is deprecated anyway)
#NVTT_DESC=		Enable NVidia texture tools support
#NVTT_BROKEN=		does not build
#NVTT_LIB_DEPENDS=	libnvtt.so:graphics/nvidia-texture-tools
#NVTT_CMAKE_BOOL=	IL_USE_DXTC_NVIDIA
CMAKE_ARGS+=		-DIL_USE_DXTC_NVIDIA=0

post-install-DOCS-on:
	cd ${WRKSRC}/DevIL-docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/DevIL && ${INSTALL_DATA} CREDITS NEWS README.md TODO ${STAGEDIR}${DOCSDIR}/

post-install-EXAMPLES-on:
	cd ${WRKSRC}/DevIL/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
