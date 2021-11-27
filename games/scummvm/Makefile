#_ Created by: Alex Trull <freebsd.alex@trull.org>

PORTNAME=	scummvm
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	games emulators
MASTER_SITES=	https://downloads.scummvm.org/frs/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Interpreter for several adventure games

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfaad.so:audio/faad \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libmpeg2.so:multimedia/libmpeg2 \
		libtheoradec.so:multimedia/libtheora

USES=		cpe gmake gnome iconv jpeg pkgconfig sdl tar:xz
HAS_CONFIGURE=	yes
USE_SDL=	sdl2
INSTALLS_ICONS=	yes

CONFIGURE_ARGS=	--disable-alsa \
		--disable-debug \
		--disable-gtk \
		--disable-nasm \
		--disable-tremor \
		--enable-verbose-build \
		--with-jpeg-prefix=${LOCALBASE} \
		--with-sdl-prefix=${LOCALBASE} \
		--with-zlib-prefix=/usr

LDFLAGS+=	-lpthread

OPTIONS_DEFINE=		A52 CURL DOCS FLAC FLUIDSYNTH MP3 MT32EMU PNG SNDIO TTS VORBIS XENGINES
OPTIONS_DEFAULT=	A52 MP3 MT32EMU PNG VORBIS
OPTIONS_SUB=		yes

CURL_DESC=	Enable ScummVM cloud storage backend
MT32EMU_DESC=	MT-32 emulator
TTS_DESC=	Text-to-Speech support
XENGINES_DESC=	Experimental/Unstable engine support

A52_LIB_DEPENDS=	liba52.so:audio/liba52
A52_CONFIGURE_ON=	--with-a52-prefix=${LOCALBASE}
A52_CONFIGURE_OFF=	--disable-a52

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ON=	--with-libcurl-prefix=${LOCALBASE}
CURL_CONFIGURE_OFF=	--disable-libcurl

VORBIS_LIB_DEPENDS=	libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis
VORBIS_CONFIGURE_ON=	--with-ogg-prefix=${LOCALBASE} \
			--with-vorbis-prefix=${LOCALBASE}
VORBIS_CONFIGURE_OFF=	--disable-vorbis \
			--disable-ogg

MP3_LIB_DEPENDS=	libmad.so:audio/libmad
MP3_CONFIGURE_ON=	--with-mad-prefix=${LOCALBASE}
MP3_CONFIGURE_OFF=	--disable-mad

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_ON=	--with-png-prefix=${LOCALBASE}
PNG_CONFIGURE_OFF=	--disable-png

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_ON=	--with-flac-prefix=${LOCALBASE}
FLAC_CONFIGURE_OFF=	--disable-flac

FLUIDSYNTH_LIB_DEPENDS=		libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CONFIGURE_ON=	--with-fluidsynth-prefix=${LOCALBASE}
FLUIDSYNTH_CONFIGURE_OFF=	--disable-fluidsynth

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
