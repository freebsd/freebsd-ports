# $FreeBSD$

PORTNAME=	wildmidi
PORTVERSION=	0.3.8
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	audio

MAINTAINER=	liangtai.s16@gmail.com
COMMENT=	Simple software midi player and core softsynth library

# player: GPLv3, library: LGPL3
LICENSE=	LGPL3

USE_GITHUB=	yes
GH_ACCOUNT=	Mindwerks
USES=		gmake cmake:outsource
USE_LDCONFIG=	yes

OPTIONS_SUB=	yes
OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	ALSA OSS OPENAL OPENALSOFT
OPTIONS_DEFINE=	PLAYER PLAYERSTATIC STATIC
OPTIONS_DEFAULT=	ALSA PLAYER

STATIC_CMAKE_ON=	-DWANT_STATIC:BOOL=ON
STATIC_CMAKE_OFF=	-DWANT_STATIC:BOOL=OFF

PLAYER_DESC=	Simple player
PLAYERSTATIC_DESC=	Simple player using STATIC libWildMidi
BACKEND_DESC=	Sound system PLAYER and PLAYERSTATIC uses
PLAYER_CMAKE_ON=	-DWANT_PLAYER:BOOL=ON
PLAYER_CMAKE_OFF=	-DWANT_PLAYER:BOOL=OFF
PLAYERSTATIC_CMAKE_ON=	-DWANT_PLAYERSTATIC:BOOL=ON
PLAYERSTATIC_CMAKE_OFF=	-DWANT_PLAYERSTATIC:BOOL=OFF
ALSA_CMAKE_ON=	-DWANT_ALSA:BOOL=ON
ALSA_CMAKE_OFF=	-DWANT_ALSA:BOOL=OFF
OSS_CMAKE_ON=	-DWANT_OSS:BOOL=ON
OSS_CMAKE_OFF=	-DWANT_OSS:BOOL=OFF
OPENALSOFT_DESC=	OpenAL support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPLAYER} || ${PORT_OPTIONS:MPLAYERSTATIC}
LICENSE+=	GPLv3
LICENSE_COMB=	multi
CMAKE_ARGS+=	-DWANT_OPENAL:BOOL=OFF
.  if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:audio/alsa-lib
.  elif ${PORT_OPTIONS:MOPENALSOFT}
LIB_DEPENDS+=	libopenal.so:audio/openal-soft
CMAKE_ARGS+=	-DWANT_OPENAL:BOOL=ON
.  elif ${PORT_OPTIONS:MOPENAL}
LIB_DEPENDS+=	libopenal.so:audio/openal
CMAKE_ARGS+=	-DWANT_OPENAL:BOOL=ON
.  endif
.endif

post-patch:
	@${GREP} -L ${LOCALBASE} ${WRKSRC}/cfg/wildmidi.cfg | ${XARGS} \
		${REINPLACE_CMD} -e "/^dir \/usr\/share\//{" \
		-e "s|/usr/share/midi/freepats|${LOCALBASE}/share/freepats|;" \
		-e "h; x; s|^|# |; s|freepats|guspat|; H; s|guspat|eawpats|; H;" \
		-e "s|eawpats|eawplus|; H; x;}"
	@${GREP} -L ${LOCALBASE} ${WRKSRC}/docs/man/man1/wildmidi.1 \
		${WRKSRC}/docs/man/man5/wildmidi.cfg.5 \
		${WRKSRC}/CMakeLists.txt | ${XARGS} \
		${REINPLACE_CMD} -e 's@/etc/wildmidi/@${DATADIR}/@' \
		-e 's@/etc/@${DATADIR}/@'
	@${GREP} -l share/man ${WRKSRC}/src/CMakeLists.txt | ${XARGS} \
		${REINPLACE_CMD} '/INSTALL/s@share/man@man@'

pre-install:
	@${RM} -f ${WRKSRC}/docs/man/man1/wildmidi.1${REINPLACE_ARGS:S/-i//} \
		${WRKSRC}/docs/man/man5/wildmidi.cfg.5${REINPLACE_ARGS:S/-i//}
	${MKDIR} ${STAGEDIR}${DATADIR} ; \
	${CP} ${WRKSRC}/cfg/wildmidi.cfg ${STAGEDIR}${DATADIR}/wildmidi.cfg.sample

.include <bsd.port.mk>
