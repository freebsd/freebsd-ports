PORTNAME=	wildmidi
DISTVERSION=	0.4.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/Mindwerks/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple software midi player and core softsynth library
WWW=		https://www.mindwerks.net/projects/wildmidi/

# player: GPLv3, library: LGPL3
LICENSE=	LGPL3

USES=		cmake cpe
CPE_VENDOR=	mindwerks
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		PLAYER PLAYERSTATIC STATIC
OPTIONS_DEFAULT=	OSS PLAYER
OPTIONS_RADIO=		BACKEND
OPTIONS_RADIO_BACKEND=	ALSA OPENAL OSS
OPTIONS_SUB=		yes

BACKEND_DESC=		Sound system PLAYER and PLAYERSTATIC use
PLAYERSTATIC_DESC=	Simple player using STATIC libWildMidi
PLAYER_DESC=		Simple player

ALSA_CMAKE_BOOL=		WANT_ALSA
OPENAL_CMAKE_BOOL=		WANT_OPENAL
OSS_CMAKE_BOOL=			WANT_OSS
PLAYERSTATIC_IMPLIES=		STATIC
PLAYERSTATIC_CMAKE_BOOL=	WANT_PLAYERSTATIC
PLAYER_CMAKE_BOOL=		WANT_PLAYER
STATIC_CMAKE_BOOL=		WANT_STATIC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPLAYER} || ${PORT_OPTIONS:MPLAYERSTATIC}
LICENSE+=	GPLv3
LICENSE_COMB=	multi
.  if ${PORT_OPTIONS:MOPENAL}
USES+=	openal:al
.  elif ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:audio/alsa-lib
.  endif
.endif

post-patch:
	${REINPLACE_CMD} -e "/^dir \/usr\/share\//{" \
		-e "s|/usr/share/midi/freepats|${LOCALBASE}/share/freepats|;" \
		-e "h; x; s|^|# |; s|freepats|guspat|; H; s|guspat|eawpats|; H;" \
		-e "s|eawpats|eawplus|; H; x;}" ${WRKSRC}/cfg/wildmidi.cfg
	${REINPLACE_CMD} -e 's@/etc/wildmidi/@${DATADIR}/@' \
		-e 's@/etc/@${DATADIR}/@' ${WRKSRC}/docs/man/man1/wildmidi.1 \
		${WRKSRC}/docs/man/man5/wildmidi.cfg.5 \
		${WRKSRC}/CMakeLists.txt

pre-install:
	@${RM} ${WRKSRC}/docs/man/man1/wildmidi.1${REINPLACE_ARGS:S/-i//} \
		${WRKSRC}/docs/man/man5/wildmidi.cfg.5${REINPLACE_ARGS:S/-i//}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/cfg/wildmidi.cfg ${STAGEDIR}${DATADIR}/wildmidi.cfg.sample

.include <bsd.port.mk>
