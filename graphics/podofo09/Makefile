PORTNAME=	podofo
PORTVERSION=	0.9.8
PORTREVISION=	1
CATEGORIES=	graphics print
MASTER_SITES=	SF
PKGNAMESUFFIX=	09

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PDF manipulation library and tools
WWW=		https://podofo.sourceforge.net/ \
		https://github.com/podofo/podofo

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libidn.so:dns/libidn

USES=		cmake compiler:c++11-lang cpe dos2unix pkgconfig ssl

CMAKE_ARGS=	-DFONTCONFIG_LIBRARIES=${LOCALBASE}/lib/libfontconfig.so \
		-DOPENSSL_INCLUDE_DIR=${OPENSSLINC} \
		-DOPENSSL_LIBRARIES=${OPENSSLDIR}
CMAKE_ON=	PODOFO_BUILD_SHARED PODOFO_BUILD_STATIC
USE_LDCONFIG=	yes

CPE_VENDOR=	podofo_project

DOS2UNIX_FILES=	cmake/modules/FindFREETYPE.cmake

OPTIONS_DEFINE=	IMPOSE JPEG PNG TIFF UNISTRING
OPTIONS_DEFAULT=JPEG PNG TIFF UNISTRING
IMPOSE_DESC=	Build impose tool (Lua required)
UNISTRING_DESC=	Use libunistring for conversion

IMPOSE_CMAKE_BOOL=	WANT_LUA
IMPOSE_CXXFLAGS=	-I${LUA_INCDIR}
IMPOSE_LDFLAGS=		-L${LUA_LIBDIR}
IMPOSE_USES=		lua
JPEG_CMAKE_BOOL=	WANT_LIBJPEG
JPEG_USES=		jpeg
PNG_CMAKE_BOOL=		WANT_PNG
PNG_LIB_DEPENDS=	libpng.so:graphics/png
TIFF_CMAKE_BOOL=	WANT_TIFF
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
UNISTRING_CMAKE_BOOL=	WANT_UNISTRING
UNISTRING_LIB_DEPENDS=	libunistring.so:devel/libunistring

post-patch:
	@${REINPLACE_CMD} -e '/^#include/s|podofo/podofo.h|podofo09/podofo.h|' \
		${WRKSRC}/examples/pdfcontentsgraph/PdfContentsGraph.h
	@${REINPLACE_CMD} -e '/^#include/s|podofo/base|podofo09/base|' \
		${WRKSRC}/src/podofo/doc/* \
		${WRKSRC}/src/podofo/base/PdfExtension.h
	@${RLN} ${WRKSRC}/src/podofo ${WRKSRC}/src/podofo09

.include <bsd.port.mk>
