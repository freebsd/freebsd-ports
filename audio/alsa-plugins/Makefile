# Created by: Aragon Gouveia <aragon@phat.za.net>
# $FreeBSD$

PORTNAME=	alsa-plugins
PORTVERSION=	1.0.27
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ALSA/plugins \
		GENTOO/distfiles

MAINTAINER=	aragon@phat.za.net
COMMENT=	ALSA compatibility library plugins

LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pkgconfig
LDFLAGS+=	-L${LOCALBASE}/lib
EXTRA_PATCHES+=	${FILESDIR}/alsa-plugins.patch

OPTIONS_DEFAULT=BUFSZ_P2 IO_PTR
OPTIONS_DEFINE=	JACK FFMPEG PULSEAUDIO SAMPLERATE SPEEX
OPTIONS_SUB=	${OPTIONS_DEFINE}

OPTIONS_GROUP=	OSS
OPTIONS_GROUP_OSS=IO_PTR BLKCNT_P2 BUFSZ_P2 VERBOSE

IO_PTR_DESC=	Precise playback/recording pointer
BLKCNT_P2_DESC=	Restrict number of fragments to ^2 aligned
BUFSZ_P2_DESC=	Restrict buffer size to ^2 aligned (breaks aplay)
VERBOSE_DESC=	Print debugging messages

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIO_PTR}
CFLAGS+=	-DFREEBSD_OSS_USE_IO_PTR
.endif

.if ${PORT_OPTIONS:MBLKCNT_P2}
CFLAGS+=	-DFREEBSD_OSS_BLKCNT_P2
.endif

.if ${PORT_OPTIONS:MBUFSZ_P2}
CFLAGS+=	-DFREEBSD_OSS_BUFSZ_P2
.endif

.if ${PORT_OPTIONS:MVERBOSE}
CFLAGS+=	-DFREEBSD_OSS_DEBUG_VERBOSE
.endif

.if ${PORT_OPTIONS:MJACK}
.if empty(PORT_OPTIONS:MSAMPLERATE)
IGNORE=			JACK audio support requires SAMPLERATE
.endif
LIB_DEPENDS+=		libjack.so:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--disable-jack
.endif

.if ${PORT_OPTIONS:MFFMPEG}
CONFIGURE_ARGS+=	--enable-avcodec
CFLAGS+=		-I${LOCALBASE}/include
LIB_DEPENDS+=		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
.else
CONFIGURE_ARGS+=	--disable-avcodec
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=		libpulse.so:${PORTSDIR}/audio/pulseaudio
.else
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif

.if ${PORT_OPTIONS:MSAMPLERATE}
LIB_DEPENDS+=		libsamplerate.so:${PORTSDIR}/audio/libsamplerate
.else
CONFIGURE_ARGS+=	--disable-samplerate
.endif

.if ${PORT_OPTIONS:MSPEEX}
CONFIGURE_ARGS+=	--with-speex=lib
LIB_DEPENDS+=		libspeex.so:${PORTSDIR}/audio/speex
.else
CONFIGURE_ARGS+=	--without-speex
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/LIBS/s/-ldl//g' \
		-e '/lt_cv_dlopen/s/-ldl//g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
