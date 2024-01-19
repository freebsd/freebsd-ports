PORTNAME=	aqualung
PORTVERSION=	1.0
PORTREVISION=	25
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Music player with rich features
WWW=		https://aqualung.jeremyevans.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on legacy libraries such as GTK2 and FFmpeg 4, consider using audio/strawberry instead
EXPIRATION_DATE=2024-02-29

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libmp3lame.so:audio/lame \
		libcddb.so:audio/libcddb \
		libmad.so:audio/libmad \
		libmodplug.so:audio/libmodplug \
		liboggz.so:audio/liboggz \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libvorbis.so:audio/libvorbis \
		libmac.so:audio/mac \
		libmpcdec.so:audio/musepack \
		libspeex.so:audio/speex \
		libwavpack.so:audio/wavpack \
		libavcodec.so.58:multimedia/ffmpeg4 \
		libcdio_paranoia.so:sysutils/libcdio-paranoia \
		liblrdf.so:textproc/liblrdf

USES=		compiler:c++11-lang cpe gettext gnome localbase lua:52 pkgconfig
USE_GNOME=	gtk20 libxml2 libxslt
GNU_CONFIGURE=	yes

LDFLAGS+=	-L${LOCALBASE}/ffmpeg4/lib
CONFIGURE_ENV+=	PKG_CONFIG_PATH="${LOCALBASE}/ffmpeg4/libdata/pkgconfig"
MAKE_ENV+=	PKG_CONFIG_PATH="${LOCALBASE}/ffmpeg4/libdata/pkgconfig"

CONFIGURE_ARGS=	--with-ifp=no

DESKTOP_ENTRIES="Aqualung" "" "${DATADIR}/general.png" "aqualung" \
		"Audio;AudioVideo;GTK;" ""

OPTIONS_DEFINE=		ALSA DOCS JACK PULSEAUDIO SNDIO

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ON=	--with-alsa=yes
ALSA_CONFIGURE_OFF=	--with-alsa=no
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ON=	--with-jack=yes
JACK_CONFIGURE_OFF=	--with-jack=no
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ON=	--with-pulse=yes
PULSEAUDIO_CONFIGURE_OFF=	--with-pulse=no
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_ON=	--with-sndio=yes
SNDIO_CONFIGURE_OFF=	--with-sndio=no

post-patch:
# Remove unused duplicate global symbols (-fno-common)
	@${REINPLACE_CMD} -E '/^g?char command/d' \
		${WRKSRC}/src/gui_main.c \
		${WRKSRC}/src/playlist.c

.include <bsd.port.mk>
