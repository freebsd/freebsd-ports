# New ports collection makefile for:   alsa-plugins
# Date created:                June 29, 2009
# Whom:                        Aragon Gouveia <aragon@phat.za.net>
#
# $FreeBSD$
#

PORTNAME=	alsa-plugins
PORTVERSION=	1.0.25
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.silug.org/pub/alsa/plugins/ \
		ftp://gd.tuwien.ac.at/opsys/linux/alsa/plugins/ \
		http://dl.ambiweb.de/mirrors/ftp.alsa-project.org/plugins/ \
		ftp://ftp.alsa-project.org/pub/plugins/

MAINTAINER=	aragon@phat.za.net
COMMENT=	ALSA compatibility library plugins

LIB_DEPENDS=	asound:${PORTSDIR}/audio/alsa-lib

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	${PREFIX}/lib/alsa-lib

OPTIONS_DEFINE=	ARIFF_OSS JACK FFMPEG PULSEAUDIO SAMPLERATE SPEEX
OPTIONS_DEFAULT=ARIFF_OSS
ARIFF_OSS_DESC=	FreeBSD-specific OSS plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MARIFF_OSS}
EXTRA_PATCHES+=	${FILESDIR}/alsa-plugins.patch
.endif

.if ${PORT_OPTIONS:MJACK}
.if empty(PORT_OPTIONS:MSAMPLERATE)
IGNORE=			JACK audio support requires SAMPLERATE
.endif
LIB_DEPENDS+=		jack:${PORTSDIR}/audio/jack
PLIST_SUB+=		JACK=""
.else
PLIST_SUB+=		JACK="@comment "
CONFIGURE_ARGS+=	--disable-jack
.endif

.if ${PORT_OPTIONS:MFFMPEG}
CONFIGURE_ARGS+=	--enable-avcodec
CFLAGS+=		-I${LOCALBASE}/include
LIB_DEPENDS+=		avcodec:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=		LAVC=""
.else
CONFIGURE_ARGS+=	--disable-avcodec
PLIST_SUB+=		LAVC="@comment "
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=		pulse:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=		PULSE=""
.else
PLIST_SUB+=		PULSE="@comment "
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif

.if ${PORT_OPTIONS:MSAMPLERATE}
LIB_DEPENDS+=		samplerate:${PORTSDIR}/audio/libsamplerate
PLIST_SUB+=		SAMPLERATE=""
.else
PLIST_SUB+=		SAMPLERATE="@comment "
CONFIGURE_ARGS+=	--disable-samplerate
.endif

.if ${PORT_OPTIONS:MSPEEX}
CONFIGURE_ARGS+=	--with-speex=lib
LIB_DEPENDS+=		speex:${PORTSDIR}/audio/speex
PLIST_SUB+=		SPEEX=""
.else
CONFIGURE_ARGS+=	--without-speex
PLIST_SUB+=		SPEEX="@comment "
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/LIBS/s/-ldl//g' \
		-e '/lt_cv_dlopen/s/-ldl//g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
