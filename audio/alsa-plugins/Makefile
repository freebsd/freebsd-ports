# Created by: Aragon Gouveia <aragon@phat.za.net>
# $FreeBSD$

PORTNAME=	alsa-plugins
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.alsa-project.org/pub/plugins/ \
		GENTOO

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	ALSA compatibility library plugins

LICENSE=	LGPL21+

LIB_DEPENDS=	libasound.so:audio/alsa-lib

GNU_CONFIGURE=	yes
USES=		alias libtool:keepla localbase pkgconfig tar:bzip2
EXTRA_PATCHES+=	${FILESDIR}/alsa-plugins.patch
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${.CURDIR}/../alsa-lib/files

OPTIONS_DEFAULT=BUFSZ_P2 IO_PTR
OPTIONS_DEFINE=	JACK FFMPEG PULSEAUDIO SAMPLERATE SPEEX
OPTIONS_SUB=	yes

OPTIONS_GROUP=	OSS
OPTIONS_GROUP_OSS=IO_PTR BLKCNT_P2 BUFSZ_P2 VERBOSE

IO_PTR_DESC=	Precise playback/recording pointer
BLKCNT_P2_DESC=	Restrict number of fragments to ^2 aligned
BUFSZ_P2_DESC=	Restrict buffer size to ^2 aligned
VERBOSE_DESC=	Print debugging messages

IO_PTR_CFLAGS=	-DFREEBSD_OSS_USE_IO_PTR
BLKCNT_P2_CFLAGS=-DFREEBSD_OSS_BLKCNT_P2
BUFSZ_P2_CFLAGS=-DFREEBSD_OSS_BUFSZ_P2
VERBOSE_CFLAGS=	-DFREEBSD_OSS_DEBUG_VERBOSE

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_ENABLE=	jack
JACK_IMPLIES=		SAMPLERATE

FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_ENABLE=avcodec

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=pulseaudio

SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SAMPLERATE_CONFIGURE_ENABLE=samplerate

SPEEX_LIB_DEPENDS=	libspeex.so:audio/speex
SPEEX_CONFIGURE_ON=	--with-speex=lib
SPEEX_CONFIGURE_OFF=	--without-speex

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/LIBS/s/-ldl//g' \
		-e '/lt_cv_dlopen/s/-ldl//g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
