# Created by: Aragon Gouveia <aragon@phat.za.net>

PORTNAME=	alsa-plugins
PORTVERSION=	1.2.2
PORTREVISION=	5
DISTVERSIONPREFIX=	v
CATEGORIES=	audio
MASTER_SITES=	GH

USE_GITHUB=	yes
GH_ACCOUNT=	alsa-project
GH_PROJECT=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ALSA compatibility library plugins

LICENSE=	LGPL21+

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		alias autoreconf libtool:keepla localbase pkgconfig tar:bzip2
USE_LDCONFIG=	${PREFIX}/lib/alsa-lib
GNU_CONFIGURE=	yes
MAKE_ARGS+=	RM="${RM}"
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${.CURDIR}/../alsa-lib/files

OPTIONS_DEFAULT=	PULSEAUDIO
OPTIONS_DEFINE=		BUFSZ_P2 FFMPEG JACK PULSEAUDIO SAMPLERATE SPEEX
OPTIONS_SUB=		yes

OPTIONS_GROUP=		OSS
OPTIONS_GROUP_OSS=	BLKCNT_P2 BUFSZ_P2 VERBOSE

BLKCNT_P2_DESC=	Restrict number of fragments to ^2 aligned
BUFSZ_P2_DESC=	Restrict buffer size to ^2 aligned
VERBOSE_DESC=	Print debugging messages

BLKCNT_P2_CFLAGS=	-DFREEBSD_OSS_BLKCNT_P2
BUFSZ_P2_CFLAGS=	-DFREEBSD_OSS_BUFSZ_P2
VERBOSE_CFLAGS=		-DALSA_OSS_DEBUG_VERBOSE

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ENABLE=	libav

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=	jack
JACK_IMPLIES=		SAMPLERATE

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulseaudio

SAMPLERATE_LIB_DEPENDS=		libsamplerate.so:audio/libsamplerate
SAMPLERATE_CONFIGURE_ENABLE=	samplerate

SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex
SPEEX_CONFIGURE_ON=	--with-speex=lib
SPEEX_CONFIGURE_OFF=	--without-speex

.include <bsd.port.mk>
