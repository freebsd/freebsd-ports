PORTNAME=	darkice
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	audio net
MASTER_SITES=	https://github.com/rafael2k/darkice/releases/download/v${PORTVERSION}/

MAINTAINER=	takefu@airport.fm
COMMENT=	IceCast, IceCast2, and ShoutCast live audio streamer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-alsa
CONFIGURE_ENV=	ac_cv_prog_acx_pthread_config=no
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		JACK PULSEAUDIO
OPTIONS_DEFAULT=	VORBIS
OPTIONS_MULTI=		CODEC
OPTIONS_MULTI_CODEC=	FAAC LAME OPUS TWOLAME VORBIS

FAAC_LIB_DEPENDS=	libfaac.so:audio/faac
FAAC_CONFIGURE_ON=	--with-faac-prefix=${LOCALBASE}
FAAC_CONFIGURE_OFF=	--without-faac
JACK_LIB_DEPENDS=	libjack.so:audio/jack\
			libsamplerate.so:audio/libsamplerate
JACK_CONFIGURE_WITH=	jack
LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
LAME_CONFIGURE_ON=	--with-lame-prefix=${LOCALBASE}
LAME_CONFIGURE_OFF=	--without-lame
OPUS_LIB_DEPENDS=	libopus.so:audio/opus\
			libogg.so:audio/libogg
OPUS_CONFIGURE_WITH=	opus
PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio\
			libsamplerate.so:audio/libsamplerate
PULSEAUDIO_CONFIGURE_WITH=	pulseaudio
TWOLAME_LIB_DEPENDS=	libtwolame.so:audio/twolame
TWOLAME_CONFIGURE_WITH=	twolame
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis\
			libogg.so:audio/libogg
VORBIS_CONFIGURE_WITH=	vorbis

SOURCE_URL=		man/darkice.1 man/darkice.cfg.5 src/IceCast2.cpp src/main.cpp

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 -pedantic||g' ${WRKSRC}/src/Makefile.in
.for i in ${SOURCE_URL}
	@${REINPLACE_CMD} -e 's|http://code.google.com/p/darkice/|http://darkice.org/|' ${WRKSRC}/${i}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.cfg \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.cfg.sample
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.cfg.5 ${STAGEDIR}${PREFIX}/share/man/man5

.include <bsd.port.mk>
