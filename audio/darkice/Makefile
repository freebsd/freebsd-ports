# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	darkice
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	audio net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IceCast, IceCast2, and ShoutCast live audio streamer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_acx_pthread_config=no
CONFIGURE_ARGS=	--without-alsa

SUB_FILES=	pkg-message
USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=		JACK PULSEAUDIO
OPTIONS_MULTI=		CODEC
OPTIONS_MULTI_CODEC=	AACPLUS FAAC LAME OPUS TWOLAME VORBIS
OPTIONS_DEFAULT=	VORBIS

AACPLUS_DESC=		AAC HEv2 and libsamplerate support
AACPLUS_LIB_DEPENDS=	libaacplus.so:audio/libaacplus \
			libsamplerate.so:audio/libsamplerate
AACPLUS_CONFIGURE_ON=	--with-aacplus --with-samplerate
AACPLUS_CONFIGURE_OFF=	--without-aacplus --without-samplerate
FAAC_LIB_DEPENDS=	libfaac.so:audio/faac
FAAC_CONFIGURE_ON=	--with-faac-prefix=${LOCALBASE}
FAAC_CONFIGURE_OFF=	--without-faac
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CONFIGURE_WITH=	jack
LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
LAME_CONFIGURE_ON=	--with-lame-prefix=${LOCALBASE}
LAME_CONFIGURE_OFF=	--without-lame
OPUS_LIB_DEPENDS=	libopus.so:audio/opus
OPUS_CONFIGURE_WITH=	opus
PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio
TWOLAME_LIB_DEPENDS=	libtwolame.so:audio/twolame
TWOLAME_CONFIGURE_WITH=	twolame
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_CONFIGURE_WITH=	vorbis

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 -pedantic||g' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.cfg \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg.sample
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.cfg.5 ${STAGEDIR}${MAN5PREFIX}/man/man5

.include <bsd.port.mk>
