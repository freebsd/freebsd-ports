# Created by: benlutz@datacomm.ch
# $FreeBSD$

PORTNAME=	uqm
PORTVERSION=	0.7.0
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/sc2/UQM/${PORTVERSION:R}
DISTFILES=	${DISTNAME}-source.tgz ${PORTNAME}-${DATAVERSION}-content.uqm
EXTRACT_ONLY=	${DISTNAME}-source.tgz

MAINTAINER=	mail@maxlor.com
COMMENT=	Port of the original Star Control 2 for 3DO consoles

LICENSE=	GPLv2

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libmikmod.so:audio/libmikmod \
		libpth.so:devel/pth

USES=		gmake pkgconfig
USE_SDL=	image sdl
DATAVERSION=	0.7.0

OPTIONS_DEFINE=	VOICE MUSIC OPENAL DOCS
MUSIC_DESC=	3DO music add-on (18 MiB)
VOICE_DESC=	Speech add-on (109 MiB)
OPTIONS_GROUP=	SOUNDTRACK_REMIXES
REMIX_PACKS=	1 2 3 4
OPTIONS_GROUP_SOUNDTRACK_REMIXES=	REMIX1 REMIX2 REMIX3 REMIX4
REMIX1_DESC=	"Super Meelee!"                  (47 MiB)
REMIX2_DESC=	"Neutral Aliens, Don't Shoot!"   (57 MiB)
REMIX3_DESC=	"Ur-Quan Hierarchy"              (38 MiB)
REMIX4_DESC=	"The New Alliance of Free Stars" (82 MiB)

OPTIONS_SUB=	yes

VOICE_DISTFILES=	${PORTNAME}-${DATAVERSION}-voice.uqm
MUSIC_DISTFILES=	${PORTNAME}-${DATAVERSION}-3domusic.uqm
OPENAL_USES=	openal:al

.include <bsd.port.options.mk>

.for i in ${REMIX_PACKS}
.	if ${PORT_OPTIONS:MREMIX${i}}
MASTER_SITES+=	SF/sc2/UQM%20Remix%20Packs/UQM%20Remix%20Pack%20${i}:remixpack${i}
DISTFILES+=	${PORTNAME}-remix-disc${i}.uqm:remixpack${i}
.	endif
.endfor

post-extract:
	@${MKDIR} ${WRKSRC}/content/addons ${WRKSRC}/content/packages
	@${CP} ${DISTDIR}/${PORTNAME}-${DATAVERSION}-content.uqm ${WRKSRC}/content/packages/
.if ${PORT_OPTIONS:MVOICE}
	@${CP} ${DISTDIR}/${PORTNAME}-${DATAVERSION}-voice.uqm ${WRKSRC}/content/addons/
.endif
.if	${PORT_OPTIONS:MMUSIC}
	@${CP} ${DISTDIR}/${PORTNAME}-${DATAVERSION}-3domusic.uqm ${WRKSRC}/content/addons/
.endif
.for i in ${REMIX_PACKS}
.	if ${PORT_OPTIONS:MREMIX${i}}
	@${CP} ${DISTDIR}/${PORTNAME}-remix-disc${i}.uqm ${WRKSRC}/content/addons/
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
.if	${PORT_OPTIONS:MINET6}
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
	@(cd ${WRKSRC} && ${SETENV} LOCALBASE=${LOCALBASE} PREFIX=${PREFIX} ./build.sh uqm config)

do-build:
	@(cd ${WRKSRC} && ./build.sh uqm)

do-install:
	@(cd ${WRKSRC} && ${SETENV} STAGEDIR="${STAGEDIR}" ./build.sh uqm install)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/uqm/uqm
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/users/manual.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
