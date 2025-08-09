PORTNAME=	podofo
PORTVERSION=	0.10.4
PORTREVISION=	2
CATEGORIES=	graphics print

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PDF manipulation library and tools
WWW=		https://podofo.sourceforge.net/ \
		https://github.com/podofo/podofo

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	fast_float>=0:math/fast_float \
		date>=0:devel/date \
		libfmt>=0:devel/libfmt \
		utf8cpp>=4.0.3:devel/utf8cpp
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libidn.so:dns/libidn

USES=		cmake compiler:c++17-lang cpe gnome localbase:ldflags pkgconfig ssl
USE_GNOME=	libxml2

CFLAGS+=	-I${LOCALBASE}/include/fast_float
CMAKE_ARGS=	-DFONTCONFIG_LIBRARIES=${LOCALBASE}/lib/libfontconfig.so \
		-DOPENSSL_INCLUDE_DIR=${OPENSSLINC} \
		-DOPENSSL_LIBRARIES=${OPENSSLLIB}
CMAKE_OFF=	PODOFO_BUILD_EXAMPLES \
		PODOFO_BUILD_LIB_ONLY \
		PODOFO_BUILD_STATIC \
		PODOFO_BUILD_TEST \
		PODOFO_BUILD_TOOLS
CMAKE_TESTING_ON=	PODOFO_BUILD_TEST
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes

CPE_VENDOR=	podofo_project

OPTIONS_DEFINE=	JPEG PNG TIFF
OPTIONS_DEFAULT=JPEG PNG TIFF

JPEG_CMAKE_BOOL=	WANT_LIBJPEG
JPEG_USES=		jpeg
PNG_CMAKE_BOOL=		WANT_PNG
PNG_LIB_DEPENDS=	libpng.so:graphics/png
TIFF_CMAKE_BOOL=	WANT_TIFF
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff

# Clean up bundled libraries
.if !defined(MAINTAINER_MODE)
EXTRACT_AFTER_ARGS=	--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/3rdparty/fast_float.h \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/3rdparty/date \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/3rdparty/fmt \
			--exclude ${GH_PROJECT_DEFAULT}-${GH_TAGNAME_EXTRACT}/3rdparty/utf8cpp \
			--no-same-owner --no-same-permissions
.else
post-patch:
	@${RM} ${WRKSRC}/3rdparty/fast_float.h
	@${RM} -r ${WRKSRC}/3rdparty/date/
	@${RM} -r ${WRKSRC}/3rdparty/fmt/
	@${RM} -r ${WRKSRC}/3rdparty/utf8cpp/
.endif

.include <bsd.port.mk>
