# Created by: Aragon Gouveia <aragon@phat.za.net>
# $FreeBSD$

PORTNAME=	alsa-plugins
PORTVERSION=	1.0.29
CATEGORIES=	audio
MASTER_SITES=	ALSA/plugins \
		GENTOO

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	ALSA compatibility library plugins

LICENSE=	LGPL21 # or any later version

LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib

GNU_CONFIGURE=	yes
USES=		alias libtool:keepla pkgconfig tar:bzip2
EXTRA_PATCHES+=	${FILESDIR}/alsa-plugins.patch
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${.CURDIR}/../alsa-lib/files
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFAULT=IO_PTR
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

JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack
JACK_CONFIGURE_ENABLE=	jack

FFMPEG_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
FFMPEG_CONFIGURE_ENABLE=avcodec
FFMPEG_CPPFLAGS=	-I${LOCALBASE}/include

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=pulseaudio

SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:${PORTSDIR}/audio/libsamplerate
SAMPLERATE_CONFIGURE_ENABLE=samplerate

SPEEX_LIB_DEPENDS=	libspeex.so:${PORTSDIR}/audio/speex
SPEEX_CONFIGURE_ON=	--with-speex=lib
SPEEX_CONFIGURE_OFF=	--without-speex

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJACK} && empty(PORT_OPTIONS:MSAMPLERATE)
IGNORE=			JACK audio support requires SAMPLERATE
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/LIBS/s/-ldl//g' \
		-e '/lt_cv_dlopen/s/-ldl//g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
