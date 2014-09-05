# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	darkice
PORTVERSION=	1.2
PORTREVISION?=	1
CATEGORIES=	audio net
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IceCast, IceCast2, and ShoutCast live audio streamer

LICENSE=	GPLv3

OPTIONS_DEFINE=	JACK PULSEAUDIO
OPTIONS_MULTI=	CODEC
OPTIONS_MULTI_CODEC=	VORBIS OPUS LAME TWOLAME FAAC AACPLUS
OPTIONS_DEFAULT=	VORBIS

AACPLUS_DESC=	AAC HEv2 and libsamplerate support

USE_AUTOTOOLS=	aclocal automake autoconf
ACLOCAL_ARGS=	# none
AUTOMAKE_ARGS=	--add-missing --copy --foreign
CONFIGURE_ENV=	ac_cv_prog_acx_pthread_config=no
CONFIGURE_ARGS=	--without-alsa

SUB_FILES=	pkg-message
USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	libjack.so:${PORTSDIR}/audio/jack
CONFIGURE_ARGS+=	--with-jack-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-jack
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
LIB_DEPENDS+=	libpulse-simple.so:${PORTSDIR}/audio/pulseaudio
CONFIGURE_ARGS+=	--with-pulseaudio-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-pulseaudio
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libvorbis.so:${PORTSDIR}/audio/libvorbis
CONFIGURE_ARGS+=	--with-vorbis-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-vorbis
.endif

.if ${PORT_OPTIONS:MOPUS}
LIB_DEPENDS+=	libopus.so:${PORTSDIR}/audio/opus
CONFIGURE_ARGS+=	--with-opus-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-opus
.endif

.if ${PORT_OPTIONS:MLAME}
LIB_DEPENDS+=	libmp3lame.so:${PORTSDIR}/audio/lame
CONFIGURE_ARGS+=	--with-lame-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-lame
.endif

.if ${PORT_OPTIONS:MTWOLAME}
LIB_DEPENDS+=	libtwolame.so:${PORTSDIR}/audio/twolame
CONFIGURE_ARGS+=	--with-twolame-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-twolame
.endif

.if ${PORT_OPTIONS:MFAAC}
LIB_DEPENDS+=	libfaac.so:${PORTSDIR}/audio/faac
CONFIGURE_ARGS+=	--with-faac-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-faac
.endif

.if ${PORT_OPTIONS:MAACPLUS}
LIB_DEPENDS+=	libaacplus.so:${PORTSDIR}/audio/libaacplus \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate
CONFIGURE_ARGS+=	--with-aacplus-prefix=${LOCALBASE} \
			--with-samplerate-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-aacplus --without-samplerate
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 -pedantic||g' ${WRKSRC}/src/Makefile.am

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.cfg \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg.dist
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.cfg.5 ${STAGEDIR}${MAN5PREFIX}/man/man5

.include <bsd.port.mk>
