# Created by: Aragon Gouveia <aragon@phat.za.net>
# $FreeBSD$

PORTNAME=	alsa-plugins
PORTVERSION=	1.0.27
PORTREVISION=	1
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

OPTIONS_DEFINE=	ARIFF_OSS JACK FFMPEG PULSEAUDIO SAMPLERATE SPEEX
OPTIONS_SUB=	${OPTIONS_DEFINE}
ARIFF_OSS_DESC=	FreeBSD-specific OSS plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MARIFF_OSS}
EXTRA_PATCHES+=	${FILESDIR}/alsa-plugins.patch
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
