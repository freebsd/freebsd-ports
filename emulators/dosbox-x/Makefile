PORTNAME=	dosbox-x
DISTVERSIONPREFIX=	${PORTNAME}-v
DISTVERSION=	2025.12.01
CATEGORIES=	emulators

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	DOSBox fork
WWW=		https://dosbox-x.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
BUILD_DEPENDS_i386=	nasm:devel/nasm
LIB_DEPENDS=	libpng16.so:graphics/png \
		libslirp.so:net/libslirp

USES=		autoreconf gettext-runtime gl gnome iconv localbase pkgconfig sdl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	joncampbell123
USE_GL=		gl
USE_GNOME=	glib20
USE_SDL=	net2 sdl2
USE_XORG=	x11 xkbfile xrandr
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-emscripten --enable-hx-dos --enable-libslirp --enable-mt32 \
		--enable-opengl --enable-printer --disable-sdl --enable-sdl2 --enable-x11
INSTALL_TARGET=	install_strip

PORTDOCS=	NEWS README.*

OPTIONS_DEFINE=		ALSA DOCS FFMPEG FLUIDSYNTH FREETYPE
OPTIONS_DEFAULT=	FFMPEG FLUIDSYNTH
OPTIONS_RADIO=		DEBUGGER
OPTIONS_RADIO_DEBUGGER=	DEBUGGER_ENABLE DEBUGGER_HEAVY

ALSA_DESC=		ALSA midi support
DEBUGGER_ENABLE_DESC=	Enable internal debugger
DEBUGGER_HEAVY_DESC=	Enable internal debugger with extra features

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa alsa-midi alsatest

DEBUGGER_ENABLE_CONFIGURE_ON=	--enable-debug=yes
DEBUGGER_HEAVY_CONFIGURE_ON=	--enable-debug=heavy

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ENABLE=	avcodec

FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CONFIGURE_ENABLE=	libfluidsynth

FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
