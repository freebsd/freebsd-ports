PORTNAME=	aqualung
DISTVERSION=	1.2
PORTREVISION=	9
CATEGORIES=	audio

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Music player with rich features
WWW=		https://aqualung.jeremyevans.net/

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	a991c13d0df734a5d0fea7db6b181176858f3e58.patch:-p1 # Support newer audio/mac
PATCHFILES+=	d2c88317b6042a05c236faf3c09f600337c6379e.patch:-p1 # Support newer audio/mac
PATCHFILES+=	1c2a295a72e1e3abc6df40714d9753e311541550.patch:-p1 # Support newer audio/mac

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libmp3lame.so:audio/lame \
		libmad.so:audio/libmad \
		libmodplug.so:audio/libmodplug \
		libogg.so:audio/libogg \
		liboggz.so:audio/liboggz \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libvorbis.so:audio/libvorbis \
		libMAC.so:audio/mac \
		libspeex.so:audio/speex \
		libwavpack.so:audio/wavpack \
		libavcodec.so:multimedia/ffmpeg \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libcdio.so:sysutils/libcdio \
		libcdio_paranoia.so:sysutils/libcdio-paranoia \
		liblrdf.so:textproc/liblrdf \
		libfontconfig.so:x11-fonts/fontconfig

USES=		autoreconf compiler:c++11-lang cpe gettext gnome localbase lua:52 pkgconfig
USE_GNOME=	cairo gdkpixbuf gtk20 libxml2 libxslt

USE_GITHUB=	yes
GH_ACCOUNT=	jeremyevans

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-cddb=no \
		--with-ifp=no \
		--with-mpc=no

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
		${WRKSRC}/src/gui_main.c

.include <bsd.port.mk>
