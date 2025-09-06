PORTNAME=	crengine-ng
DISTVERSION=	0.9.12
CATEGORIES=	deskutils

MAINTAINER=	kenrap@kennethraplee.com
COMMENT=	cross-platform library for text viewers and e-book readers
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

USES=		cmake:noninja pkgconfig desktop-file-utils jpeg

USE_GITLAB=	yes
GL_ACCOUNT=	coolreader-ng

CMAKE_ARGS=	-D CRE_BUILD_STATIC=OFF \
		-D DOC_BUFFER_SIZE=0x1400000 \
		-D DOC_DATA_COMPRESSION_LEVEL=3 \
		-D ENABLE_LTO=ON \
		-D MAX_IMAGE_SCALE_MUL=2

.include <bsd.port.mk>
