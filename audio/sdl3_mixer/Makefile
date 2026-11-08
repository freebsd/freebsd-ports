PORTNAME=	sdl3_mixer
DISTVERSION=	3.2.4
CATEGORIES=	audio
MASTER_SITES=	https://github.com/libsdl-org/SDL_mixer/releases/download/release-${DISTVERSION}/
DISTNAME=	SDL3_mixer-${DISTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Library providing decoding of audio formats, mixing, various DSP processing effects and positional audio
WWW=		https://github.com/libsdl-org/SDL_mixer

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake pathfix pkgconfig sdl
USE_SDL=	sdl3
USE_LDCONFIG=	yes

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libfluidsynth.so:audio/fluidsynth \
		libgme.so:audio/libgme \
		libmpg123.so:audio/mpg123 \
		libopusfile.so:audio/opusfile \
		libwavpack.so:audio/wavpack \
		libvorbisfile.so:audio/libvorbis \
		libxmp.so:audio/libxmp

CMAKE_OFF=	SDLMIXER_DEPS_SHARED \
		SDLMIXER_EXAMPLES \
		SDLMIXER_FLAC_DRFLAC \
		SDLMIXER_INSTALL_CPACK \
		SDLMIXER_MIDI_TIMIDITY \
		SDLMIXER_MP3_DRMP3 \
		SDLMIXER_TESTS \
		SDLMIXER_VORBIS_STB

.include <bsd.port.mk>
