# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aqualung
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Music player with rich features

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

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

USES=		gettext lua pkgconfig
USE_GNOME=	gtk20 libxml2 libxslt
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ifp=no

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DESKTOP_ENTRIES="Aqualung" "" "${DATADIR}/general.png" "aqualung" \
		"Audio;AudioVideo;GTK;" ""

OPTIONS_DEFINE=		ALSA DOCS JACK PULSEAUDIO

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_ON=	--with-alsa=yes
ALSA_CONFIGURE_OFF=	--with-alsa=no
JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_ON=	--with-jack=yes
JACK_CONFIGURE_OFF=	--with-jack=no
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ON=	--with-pulse=yes
PULSEAUDIO_CONFIGURE_OFF=	--with-pulse=no

.include <bsd.port.mk>
