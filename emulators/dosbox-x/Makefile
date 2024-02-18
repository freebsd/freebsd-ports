PORTNAME=	dosbox-x
DISTVERSIONPREFIX=	${PORTNAME}-v
DISTVERSION=	2023.10.06
CATEGORIES=	emulators

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES+=	48c13acd1f3048891252cb92087cb6b20c29dc16.patch:-p1
# https://github.com/joncampbell123/dosbox-x/pull/4575
# dos_programs.cpp:5929:17: error: cannot initialize return object of type 'bool' with an rvalue of type 'std::nullptr_t'

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DOSBox fork
WWW=		https://dosbox-x.com/

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libslirp.so:net/libslirp
BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
BUILD_DEPENDS_i386=	nasm:devel/nasm

USES=		autoreconf gettext-runtime gl gnome iconv localbase pkgconfig sdl xorg
USE_GL=		gl
USE_GNOME=	glib20
USE_SDL=	net2 sdl2
USE_XORG=	x11 xkbfile xrandr
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--disable-emscripten --enable-hx-dos --enable-libslirp --enable-mt32 \
		--enable-opengl --enable-printer --disable-sdl --enable-sdl2 --enable-x11
INSTALL_TARGET=	install_strip

USE_GITHUB=	yes
GH_ACCOUNT=	joncampbell123

OPTIONS_DEFINE=		ALSA DOCS FFMPEG FLUIDSYNTH FREETYPE
OPTIONS_DEFAULT=	FFMPEG FLUIDSYNTH
OPTIONS_RADIO=		DEBUGGER
OPTIONS_RADIO_DEBUGGER=	DEBUGGER_ENABLE DEBUGGER_HEAVY

ALSA_DESC=		ALSA midi support
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa alsa-midi alsatest

DEBUGGER_ENABLE_DESC=	Enable internal debugger
DEBUGGER_HEAVY_DESC=	Enable internal debugger with extra features

DEBUGGER_ENABLE_CONFIGURE_ON=	--enable-debug=yes
DEBUGGER_HEAVY_CONFIGURE_ON=	--enable-debug=heavy

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ENABLE=	avcodec

FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CONFIGURE_ENABLE=	libfluidsynth

FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype

.include <bsd.port.mk>
