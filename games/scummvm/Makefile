PORTNAME=	scummvm
PORTVERSION=	2.8.0
CATEGORIES=	games emulators
MASTER_SITES=	https://downloads.scummvm.org/frs/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Interpreter for several adventure games
WWW=		https://www.scummvm.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liba52.so:audio/liba52 \
		libfaad.so:audio/faad \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libmad.so:audio/libmad \
		libmpeg2.so:multimedia/libmpeg2 \
		libogg.so:audio/libogg \
		libpng.so:graphics/png \
		libtheoradec.so:multimedia/libtheora \
		libvorbis.so:audio/libvorbis

USES=		compiler:c++11-lang cpe gl gmake gnome iconv jpeg \
		localbase:ldflags pkgconfig sdl tar:xz
USE_GL=		gl glew
USE_SDL=	sdl2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-alsa \
		--disable-debug \
		--disable-fluidlite \
		--disable-gtk \
		--disable-nasm \
		--disable-tremor \
		--enable-verbose-build \
		--with-zlib-prefix=/usr

LDFLAGS+=	-lpthread

OPTIONS_DEFINE=		CURL DOCS FLAC GIF FLUIDSYNTH MIKMOD MT32EMU SNDIO SONIVOX TTS VPX XENGINES
OPTIONS_DEFAULT=	GIF MIKMOD MT32EMU
OPTIONS_SUB=		yes

CURL_DESC=	Enable ScummVM cloud storage backend
MT32EMU_DESC=	MT-32 emulator
SONIVOX_DESC=	Sonivox EAS (Embedded Audio Synthesis) sound driver
TTS_DESC=	Text-to-Speech support
XENGINES_DESC=	Experimental/Unstable engine support

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_OFF=	--disable-libcurl

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_OFF=	--disable-flac

FLUIDSYNTH_LIB_DEPENDS=		libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CONFIGURE_OFF=	--disable-fluidsynth

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CONFIGURE_OFF=	--disable-gif

MIKMOD_LIB_DEPENDS=	libmikmod.so:audio/libmikmod
MIKMOD_CONFIGURE_ON=	--enable-mikmod
MIKMOD_CONFIGURE_OFF=	--disable-mikmod

MT32EMU_CONFIGURE_OFF=	--disable-mt32emu

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_OFF=	--disable-sndio

SONIVOX_LIB_DEPENDS=	libsonivox.so:audio/sonivox
SONIVOX_CONFIGURE_ON=	--enable-sonivox
SONIVOX_CONFIGURE_OFF=	--disable-sonivox

TTS_LIB_DEPENDS=	libspeechd.so:accessibility/speech-dispatcher
TTS_CONFIGURE_ON=	--enable-tts
TTS_CONFIGURE_OFF=	--disable-tts

VPX_LIB_DEPENDS=	libvpx.so:multimedia/libvpx
VPX_CONFIGURE_ON=	--enable-vpx
VPX_CONFIGURE_OFF=	--disable-vpx

XENGINES_CONFIGURE_ON=	--enable-all-engines
XENGINES_CONFIGURE_OFF=	--disable-all-unstable-engines

.include <bsd.port.pre.mk>

.if ${ARCH} == armv6 || ${ARCH} == armv7
CONFIGURE_ENV+=	ASFLAGS=-meabi=5
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
