#_ Created by: Alex Trull <freebsd.alex@trull.org>

PORTNAME=	scummvm
PORTVERSION=	2.5.1
PORTREVISION=	1
CATEGORIES=	games emulators
MASTER_SITES=	https://downloads.scummvm.org/frs/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Interpreter for several adventure games

LICENSE=	GPLv2+
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

USES=		cpe gl gmake gnome iconv jpeg pkgconfig sdl tar:xz
USE_GL=		gl glew
HAS_CONFIGURE=	yes
USE_SDL=	sdl2

CONFIGURE_ARGS=	--disable-alsa \
		--disable-debug \
		--disable-fluidlite \
		--disable-gtk \
		--disable-nasm \
		--disable-tremor \
		--enable-verbose-build \
		--with-a52-prefix=${LOCALBASE} \
		--with-jpeg-prefix=${LOCALBASE} \
		--with-mad-prefix=${LOCALBASE} \
		--with-ogg-prefix=${LOCALBASE} \
		--with-png-prefix=${LOCALBASE} \
		--with-sdl-prefix=${LOCALBASE} \
		--with-vorbis-prefix=${LOCALBASE} \
		--with-zlib-prefix=/usr

LDFLAGS+=	-lpthread

OPTIONS_DEFINE=		CURL DOCS FLAC GIF FLUIDSYNTH MT32EMU SNDIO TTS XENGINES
OPTIONS_DEFAULT=	GIF MT32EMU
OPTIONS_SUB=		yes

CURL_DESC=	Enable ScummVM cloud storage backend
MT32EMU_DESC=	MT-32 emulator
TTS_DESC=	Text-to-Speech support
XENGINES_DESC=	Experimental/Unstable engine support

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ON=	--with-libcurl-prefix=${LOCALBASE}
CURL_CONFIGURE_OFF=	--disable-libcurl

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_ON=	--with-flac-prefix=${LOCALBASE}
FLAC_CONFIGURE_OFF=	--disable-flac

FLUIDSYNTH_LIB_DEPENDS=		libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CONFIGURE_ON=	--with-fluidsynth-prefix=${LOCALBASE}
FLUIDSYNTH_CONFIGURE_OFF=	--disable-fluidsynth

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CONFIGURE_ON=	--with-gif-prefix=${LOCALBASE}
GIF_CONFIGURE_OFF=	--disable-gif

MT32EMU_CONFIGURE_OFF=	--disable-mt32emu

SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_ON=	--with-sndio-prefix=${LOCALBASE}
SNDIO_CONFIGURE_OFF=	--disable-sndio

TTS_LIB_DEPENDS=	libspeechd.so:accessibility/speech-dispatcher
TTS_CONFIGURE_ON=	--enable-tts
TTS_CONFIGURE_OFF=	--disable-tts

XENGINES_CONFIGURE_ON=	--enable-all-engines
XENGINES_CONFIGURE_OFF=	--disable-all-unstable-engines

.include <bsd.port.pre.mk>

.if ${ARCH} == armv6 || ${ARCH} == armv7
CONFIGURE_ENV+=	ASFLAGS=-meabi=5
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/dists/${PORTNAME}.desktop \
		${STAGEDIR}${DESKTOPDIR}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.post.mk>
