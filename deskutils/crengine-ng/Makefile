PORTNAME=	crengine-ng
DISTVERSION=	0.9.12
CATEGORIES=	deskutils

MAINTAINER=	kenrap@kennethraplee.com
COMMENT=	Cross-platform library for text viewers and e-book readers
WWW=		https://gitlab.com/coolreader-ng/crengine-ng

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libgif.so:graphics/giflib \
		libharfbuzz.so:print/harfbuzz \
		libpng.so:graphics/png \
		libunibreak.so:textproc/libunibreak \
		libutf8proc.so:textproc/utf8proc \
		libzstd.so:archivers/zstd

USES=		cmake pkgconfig desktop-file-utils jpeg

USE_GITLAB=	yes
GL_ACCOUNT=	coolreader-ng

CMAKE_ARGS=	-D CRE_BUILD_STATIC=OFF \
		-D DOC_DATA_COMPRESSION_LEVEL=3

.if defined(WITH_LTO)
CMAKE_ARGS+= -D ENABLE_LTO=ON
.endif

.include <bsd.port.mk>
