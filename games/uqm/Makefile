# Ports collection makefile for:   uqm
# Date created:                    14 September 2003
# Whom:                            benlutz@datacomm.ch
#
# $FreeBSD$
#
# Ur-Quan Masters offers add-on packages that enhance the game. These are
# optional. The following add-ons exist at the moment:
#
# Voice add-on (110 MB). Enable this with -DWITH_VOICE
#
# 3DO Music add-on (18 MB). Enable this with -DWITH_MUSIC
#

PORTNAME=	uqm
PORTVERSION=	0.6.2
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/sc2/UQM/${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}-source.tgz ${PORTNAME}-${DATAVERSION}-content.uqm
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-source.tgz

MAINTAINER=	benlutz@datacomm.ch
COMMENT=	A port of the original Star Control 2 for 3DO consoles

LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		mikmod.2:${PORTSDIR}/audio/libmikmod

USE_GMAKE=	yes
USE_SDL=	image sdl
NO_INSTALL_MANPAGES=	yes
DATAVERSION=	0.6.0

OPTIONS=	VOICE "Voice add-on (110MB)" Off \
		MUSIC "Music add-on (18MB)" Off \
		OPENAL "OpenAL support (experimental)" Off

.include <bsd.port.pre.mk>

.ifdef(WITH_VOICE)
DISTFILES+=	${PORTNAME}-${DATAVERSION}-voice.uqm
PLIST_SUB+=	VOICEADDON=""
.else
PLIST_SUB+=	VOICEADDON="@comment "
.endif

.ifdef(WITH_MUSIC)
DISTFILES+=	${PORTNAME}-${DATAVERSION}-3domusic.uqm
PLIST_SUB+=	MUSICADDON=""
.else
PLIST_SUB+=	MUSICADDON="@comment "
.endif

.ifdef(WITH_OPENAL)
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
.endif

post-extract:
	${MKDIR} ${WRKSRC}/sc2/content/packages
	${CP} ${DISTDIR}/${PORTNAME}-${DATAVERSION}-content.uqm ${WRKSRC}/sc2/content/packages/
.ifdef(WITH_VOICE)
	${CP} ${DISTDIR}/${PORTNAME}-${DATAVERSION}-voice.uqm ${WRKSRC}/sc2/content/packages/
.endif
.ifdef(WITH_MUSIC)
	${CP} ${DISTDIR}/${PORTNAME}-${DATAVERSION}-3domusic.uqm ${WRKSRC}/sc2/content/packages/
.endif

do-configure:
	@${ECHO_MSG} CHOICE_debug_VALUE=\'nodebug\' >  ${WRKSRC}/sc2/config.state
	@${ECHO_MSG} CHOICE_graphics_VALUE=\'opengl\' >> ${WRKSRC}/sc2/config.state
.ifdef(WITH_OPENAL)
	@${ECHO_MSG} CHOICE_sound_VALUE=\'openal\' >> ${WRKSRC}/sc2/config.state
.else
	@${ECHO_MSG} CHOICE_sound_VALUE=\'mixsdl\' >> ${WRKSRC}/sc2/config.state
.endif
	@${ECHO_MSG} CHOICE_mikmod_VALUE=\'external\' >> ${WRKSRC}/sc2/config.state
	@${ECHO_MSG} CHOICE_ovcodec_VALUE=\'standard\' >> ${WRKSRC}/sc2/config.state
.ifdef(NO_INET6)
	@${ECHO_MSG} CHOICE_netplay_VALUE=\'full\' >> ${WRKSRC}/sc2/config.state
.else
	@${ECHO_MSG} CHOICE_netplay_VALUE=\'ipv4\' >> ${WRKSRC}/sc2/config.state
.endif
	@${ECHO_MSG} CHOICE_joystick_VALUE=\'enabled\' >> ${WRKSRC}/sc2/config.state
	@${ECHO_MSG} CHOICE_ioformat_VALUE=\'stdio_zip\' >> ${WRKSRC}/sc2/config.state
.if ${ARCH} == "i386"
	@${ECHO_MSG} CHOICE_accel_VALUE=\'asm\' >> ${WRKSRC}/sc2/config.state
.else
	@${ECHO_MSG} CHOICE_accel_VALUE=\'plainc\' >> ${WRKSRC}/sc2/config.state
.endif
	@${ECHO_MSG} INPUT_install_prefix_VALUE=\'${PREFIX}\' >> ${WRKSRC}/sc2/config.state
	@${ECHO_MSG} INPUT_install_bindir_VALUE=\''$$prefix/bin'\' >> ${WRKSRC}/sc2/config.state
	@${ECHO_MSG} INPUT_install_libdir_VALUE=\''$$prefix/lib'\' >> ${WRKSRC}/sc2/config.state
	@${ECHO_MSG} INPUT_install_sharedir_VALUE=\''$$prefix/share'\' >> ${WRKSRC}/sc2/config.state
	cd ${WRKSRC}/sc2 && ${SETENV} LOCALBASE=${LOCALBASE} PREFIX=${PREFIX} ./build.sh uqm config

do-build:
	cd ${WRKSRC}/sc2 && ./build.sh uqm

do-install:
	cd ${WRKSRC}/sc2 && ./build.sh uqm install

post-install:
	${STRIP_CMD} ${PREFIX}/lib/uqm/uqm
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/sc2/doc/users/manual.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
