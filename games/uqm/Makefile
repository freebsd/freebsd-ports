# Created by: benlutz@datacomm.ch
# $FreeBSD$

PORTNAME=	uqm
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/sc2/UQM/${PORTVERSION:R}
DISTFILES=	${PORTNAME}-${PORTVERSION}-source.tgz ${PORTNAME}-${DATAVERSION}-content.uqm
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-source.tgz

MAINTAINER=	benlutz@datacomm.ch
COMMENT=	Port of the original Star Control 2 for 3DO consoles

LICENSE=	GPLv2

LIB_DEPENDS=	vorbis:${PORTSDIR}/audio/libvorbis \
		mikmod:${PORTSDIR}/audio/libmikmod

USES=		gmake pkgconfig
USE_SDL=	image sdl
NO_INSTALL_MANPAGES=	yes
DATAVERSION=	0.7.0

OPTIONS_DEFINE=	VOICE MUSIC OPENAL DOCS
MUSIC_DESC=	Music add-on
VOICE_DESC=	Voice add-on
OPTIONS_GROUP=	REMIXES
REMIX_PACKS=	1 2 3 4
.for i in ${REMIX_PACKS}
OPTIONS_GROUP_REMIXES+=REMIXPACK${i}
REMIXPACK${i}_DESC=	UQM Remix Pack ${i} add-on
.endfor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVOICE}
DISTFILES+=	${PORTNAME}-${DATAVERSION}-voice.uqm
PLIST_SUB+=	VOICEADDON=""
.else
PLIST_SUB+=	VOICEADDON="@comment "
.endif

.if ${PORT_OPTIONS:MMUSIC}
DISTFILES+=	${PORTNAME}-${DATAVERSION}-3domusic.uqm
PLIST_SUB+=	MUSICADDON=""
.else
PLIST_SUB+=	MUSICADDON="@comment "
.endif

.if ${PORT_OPTIONS:MOPENAL}
USE_OPENAL=	al
.endif

.for i in ${REMIX_PACKS}
.	if ${PORT_OPTIONS:MREMIXPACK${i}}
MASTER_SITES+=	SF/sc2/UQM%20Remix%20Packs/UQM%20Remix%20Pack%20${i}:remixpack${i}
DISTFILES+=	${PORTNAME}-remix-disc${i}.uqm:remixpack${i}
PLIST_SUB+=	REMIXPACK${i}ADDON=""
.	else
PLIST_SUB+=	REMIXPACK${i}ADDON="@comment "
.	endif
.endfor

post-extract:
	${MKDIR} ${WRKSRC}/content/addons ${WRKSRC}/content/packages
	${CP} ${DISTDIR}/${PORTNAME}-${DATAVERSION}-content.uqm ${WRKSRC}/content/packages/
.ifdef(WITH_VOICE)
	${CP} ${DISTDIR}/${PORTNAME}-${DATAVERSION}-voice.uqm ${WRKSRC}/content/addons/
.endif
.ifdef(WITH_MUSIC)
	${CP} ${DISTDIR}/${PORTNAME}-${DATAVERSION}-3domusic.uqm ${WRKSRC}/content/addons/
.endif
.for i in ${REMIX_PACKS}
.	if ${PORT_OPTIONS:MREMIXPACK${i}}
	${CP} ${DISTDIR}/${PORTNAME}-remix-disc${i}.uqm ${WRKSRC}/content/addons/
.	endif
.endfor

do-configure:
	@${ECHO_CMD} CHOICE_debug_VALUE=\'nodebug\' >  ${WRKSRC}/config.state
	@${ECHO_CMD} CHOICE_graphics_VALUE=\'opengl\' >> ${WRKSRC}/config.state
.if ${PORT_OPTIONS:MOPENAL}
	@${ECHO_CMD} CHOICE_sound_VALUE=\'openal\' >> ${WRKSRC}/config.state
.else
	@${ECHO_CMD} CHOICE_sound_VALUE=\'mixsdl\' >> ${WRKSRC}/config.state
.endif
	@${ECHO_CMD} CHOICE_mikmod_VALUE=\'external\' >> ${WRKSRC}/config.state
	@${ECHO_CMD} CHOICE_ovcodec_VALUE=\'standard\' >> ${WRKSRC}/config.state
.ifdef(NO_INET6)
	@${ECHO_CMD} CHOICE_netplay_VALUE=\'full\' >> ${WRKSRC}/config.state
.else
	@${ECHO_CMD} CHOICE_netplay_VALUE=\'ipv4\' >> ${WRKSRC}/config.state
.endif
	@${ECHO_CMD} CHOICE_joystick_VALUE=\'enabled\' >> ${WRKSRC}/config.state
	@${ECHO_CMD} CHOICE_ioformat_VALUE=\'stdio_zip\' >> ${WRKSRC}/config.state
.if ${ARCH} == "i386"
	@${ECHO_CMD} CHOICE_accel_VALUE=\'asm\' >> ${WRKSRC}/config.state
.else
	@${ECHO_CMD} CHOICE_accel_VALUE=\'plainc\' >> ${WRKSRC}/config.state
.endif
	@${ECHO_CMD} CHOICE_threadlib_VALUE=\'sdl\' >> ${WRKSRC}/config.state
	@${ECHO_CMD} INPUT_install_prefix_VALUE=\'${PREFIX}\' >> ${WRKSRC}/config.state
	@${ECHO_CMD} INPUT_install_bindir_VALUE=\''$$prefix/bin'\' >> ${WRKSRC}/config.state
	@${ECHO_CMD} INPUT_install_libdir_VALUE=\''$$prefix/lib'\' >> ${WRKSRC}/config.state
	@${ECHO_CMD} INPUT_install_sharedir_VALUE=\''$$prefix/share'\' >> ${WRKSRC}/config.state
	cd ${WRKSRC} && ${SETENV} LOCALBASE=${LOCALBASE} PREFIX=${PREFIX} ./build.sh uqm config

do-build:
	cd ${WRKSRC} && ./build.sh uqm

do-install:
	cd ${WRKSRC} && ./build.sh uqm install

post-install:
	${STRIP_CMD} ${PREFIX}/lib/uqm/uqm
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/users/manual.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
