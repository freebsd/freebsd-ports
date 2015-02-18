# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aqualung
DISTVERSION=	1.0-rc1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Music player with rich features

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
		libmp3lame.so:${PORTSDIR}/audio/lame \
		libcddb.so:${PORTSDIR}/audio/libcddb \
		libmad.so:${PORTSDIR}/audio/libmad \
		libmodplug.so:${PORTSDIR}/audio/libmodplug \
		liboggz.so:${PORTSDIR}/audio/liboggz \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libmac.so:${PORTSDIR}/audio/mac \
		libmpcdec.so:${PORTSDIR}/audio/musepack \
		libspeex.so:${PORTSDIR}/audio/speex \
		libwavpack.so:${PORTSDIR}/audio/wavpack \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libcdio_paranoia.so:${PORTSDIR}/sysutils/libcdio-paranoia \
		liblrdf.so:${PORTSDIR}/textproc/liblrdf

USES=		gettext lua:51 pkgconfig
USE_GNOME=	gtk20 libxml2 libxslt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-alsa=no --with-ifp=no

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DESKTOP_ENTRIES="Aqualung" "" "${DATADIR}/general.png" "aqualung" \
		"Audio;AudioVideo;GTK;" ""

OPTIONS_DEFINE=		DOCS JACK PULSEAUDIO

JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_ON=	--with-jack=yes
JACK_CONFIGURE_OFF=	--with-jack=no
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ON=	--with-pulse=yes
PULSEAUDIO_CONFIGURE_OFF=	--with-pulse=no

.include <bsd.port.mk>
