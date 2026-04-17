PORTNAME=	suika3
DISTVERSION=	26.04.9
CATEGORIES=	games

MAINTAINER=	awe@noctvm.io
COMMENT=	2D game engine with DSL for visual novels
WWW=		https://suika3.vn \
		https://github.com/awemorris/suika3

LICENSE=	ZLIB

LIB_DEPENDS=	libbrotlicommon.so:archivers/brotli \
		libbrotlidec.so:archivers/brotli \
		libfreetype.so:print/freetype2 \
		libjpeg.so:graphics/jpeg-turbo \
		libogg.so:audio/libogg \
		libpng16.so:graphics/png \
		libvorbis.so:audio/libvorbis \
		libwebp.so:graphics/webp
RUN_DEPENDS=	${LOCALBASE}/share/fonts/noto/NotoSans-Regular.ttf:x11-fonts/noto-sans

USES=		cmake gl pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	awemorris
USE_GL=		gl
USE_XORG=	x11 xext xpm

CMAKE_ON=	SUIKA_ENABLE_DIST \
		SUIKA_ENABLE_INSTALL \
		SUIKA_ENABLE_JIT \
		SUIKA_ENABLE_
CMAKE_ARGS=	-DSUIKA_DIR_DOCS="share/doc/suika3" \
		-DSUIKA_DIR_GAME="share/examples/suika3"

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES GST JIT NLS TOOLS
OPTIONS_DEFAULT=	DOCS EXAMPLES GST JIT NLS TOOLS

TOOLS_DESC=	Install tools
GST_DESC=	Enable Gstreamer support
JIT_DESC=	Enable Just-in-Time compiler
NLS_DESC=	Enable language support

TOOLS_CMAKE_BOOL=	SUIKA_ENABLE_AOTCOMP SUIKA_ENABLE_BYTECOMP SUIKA_ENABLE_PACK
GST_LIB_DEPENDS=	libgstvideo-1.0.so:multimedia/gstreamer1-plugins
GST_USES=		gnome gstreamer
GST_USE=		GNOME=glib20 \
			GSTREAMER=core,faad,x264
GST_CMAKE_BOOL=		SUIKA_ENABLE_GST
JIT_CMAKE_BOOL=	SUIKA_ENABLE_JIT
NLS_CMAKE_BOOL=	SUIKA_ENABLE_I18N

# Remove the bundled font and use a packaged system font instead.
# The bundled font has a separate license (not ZLIB), and FreeBSD Ports
# should not install bundled fonts when system-packaged ones are available.
# Create a symlink to NotoSans to satisfy the engine's expected file name
# without modifying upstream sample data.
post-build:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/suika3/game/system/font
	${LN} -s ${LOCALBASE}/share/fonts/noto/NotoSans-Regular.ttf \
		${STAGEDIR}${PREFIX}/share/examples/suika3/game/system/font/rounded-l-mplus-1c-bold.ttf

.include <bsd.port.mk>
