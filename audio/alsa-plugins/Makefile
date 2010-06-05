# New ports collection makefile for:   alsa-plugins
# Date created:                June 29, 2009
# Whom:                        Aragon Gouveia <aragon@phat.za.net>
#
# $FreeBSD$
#

PORTNAME=	alsa-plugins
PORTVERSION=	1.0.23
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.silug.org/pub/alsa/plugins/ \
		ftp://gd.tuwien.ac.at/opsys/linux/alsa/plugins/ \
		http://dl.ambiweb.de/mirrors/ftp.alsa-project.org/plugins/ \
		ftp://ftp.alsa-project.org/pub/plugins/
MAINTAINER=	aragon@phat.za.net
COMMENT=	ALSA compatibility library plugins

LIB_DEPENDS=	asound.2:${PORTSDIR}/audio/alsa-lib
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	JACK		"JACK audio support (requires SAMPLERATE)"	Off \
		LAVC		"libavcodec support"	Off \
		SAMPLERATE	"libsamplerate support"	Off \
		PULSE		"PulseAudio support"	Off \
		SPEEX		"Speex support"		Off

.include <bsd.port.options.mk>

.if defined(WITH_JACK)
.if defined(WITHOUT_SAMPLERATE)
IGNORE=			JACK audio support requires SAMPLERATE
.endif
LIB_DEPENDS+=		jack.0:${PORTSDIR}/audio/jack
PLIST_SUB+=		JACK=""
.else
PLIST_SUB+=		JACK="@comment "
CONFIGURE_ARGS+=	--disable-jack
.endif

.if defined(WITH_LAVC)
CONFIGURE_ARGS+=	--enable-avcodec
CONFIGURE_ENV+=		CFLAGS=-I${LOCALBASE}/include
LIB_DEPENDS+=		avcodec.1:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=		LAVC=""
.else
CONFIGURE_ARGS+=	--disable-avcodec
PLIST_SUB+=		LAVC="@comment "
.endif

.if defined(WITH_PULSE)
LIB_DEPENDS+=		pulse.0:${PORTSDIR}/audio/pulseaudio
PLIST_SUB+=		PULSE=""
.else
PLIST_SUB+=		PULSE="@comment "
CONFIGURE_ARGS+=	--disable-pulseaudio
.endif

.if defined(WITH_SAMPLERATE)
LIB_DEPENDS+=		samplerate.1:${PORTSDIR}/audio/libsamplerate
PLIST_SUB+=		SAMPLERATE=""
.else
PLIST_SUB+=		SAMPLERATE="@comment "
CONFIGURE_ARGS+=	--disable-samplerate
.endif

.if defined(WITH_SPEEX)
CONFIGURE_ARGS+=	--with-speex=lib
LIB_DEPENDS+=		speex.1:${PORTSDIR}/audio/speex
PLIST_SUB+=		SPEEX=""
.else
CONFIGURE_ARGS+=	--without-speex
PLIST_SUB+=		SPEEX="@comment "
.endif

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/LIBS/s/-ldl//g' \
		-e '/lt_cv_dlopen/s/-ldl//g' \
		-Ee '/ac_config_files/s:(usb_stream|arcam-av)/Makefile::g' \
		-e '/CONFIG_FILES/ { /usb_stream/d; /arcam-av/d; }' \
		${WRKSRC}/configure
	${REINPLACE_CMD} \
		'/SUBDIRS/ { s/usb_stream//g; s/arcam-av//g; }' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
