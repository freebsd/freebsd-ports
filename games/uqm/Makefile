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
PORTVERSION=	0.5.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sc2
DISTFILES=	${PORTNAME}-${PORTVERSION}-source.tar.gz ${PORTNAME}-${PORTVERSION}-content.uqm
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-source.tar.gz

MAINTAINER=	benlutz@datacomm.ch
COMMENT=	A port of the original Star Control 2 for 3DO consoles

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis

USE_XLIB=	yes
USE_GMAKE=	yes
USE_SDL=	image sdl
NO_INSTALL_MANPAGES=	yes

ONLY_FOR_ARCHS=	i386

OPTIONS=	VOICE "Voice add-on (110MB)" Off \
		MUSIC "Music add-on (18MB)" Off \
		OPENAL "OpenAL support (experimental)" Off

.include <bsd.port.pre.mk>

.ifdef(WITH_VOICE)
DISTFILES+=	${PORTNAME}-${PORTVERSION}-voice.uqm
PLIST_SUB+=	VOICEADDON=""
.else
PLIST_SUB+=	VOICEADDON="@comment "
.endif

.ifdef(WITH_MUSIC)
DISTFILES+=	${PORTNAME}-${PORTVERSION}-3domusic.uqm
PLIST_SUB+=	MUSICADDON=""
.else
PLIST_SUB+=	MUSICADDON="@comment "
.endif

.ifdef(WITH_OPENAL)
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
.endif

.if ${OSVERSION} < 500000
BROKEN=		does not compile
.endif

post-extract:
	${MKDIR} ${WRKSRC}/content/packages
	${RM} -rf ${WRKSRC}/content/CVS # seems to have erroneously slipped into release tarball
	${CP} ${DISTDIR}/${PORTNAME}-${PORTVERSION}-content.uqm ${WRKSRC}/content/packages/
.ifdef(WITH_VOICE)
	${CP} ${DISTDIR}/${PORTNAME}-${PORTVERSION}-voice.uqm ${WRKSRC}/content/packages/
.endif
.ifdef(WITH_MUSIC)
	${CP} ${DISTDIR}/${PORTNAME}-${PORTVERSION}-3domusic.uqm ${WRKSRC}/content/packages/
.endif

do-configure:
	@${ECHO_MSG} CHOICE_debug_VALUE=\'nodebug\' >  ${WRKSRC}/config.state
	@${ECHO_MSG} CHOICE_graphics_VALUE=\'opengl\' >> ${WRKSRC}/config.state
.ifdef(WITH_OPENAL)
	@${ECHO_MSG} CHOICE_sound_VALUE=\'openal\' >> ${WRKSRC}/config.state
.else
	@${ECHO_MSG} CHOICE_sound_VALUE=\'mixsdl\' >> ${WRKSRC}/config.state
.endif
	@${ECHO_MSG} CHOICE_ovcodec_VALUE=\'standard\' >> ${WRKSRC}/config.state
	@${ECHO_MSG} CHOICE_ioformat_VALUE=\'stdio_zip\' >> ${WRKSRC}/config.state
	@${ECHO_MSG} CHOICE_accel_VALUE=\'asm\' >> ${WRKSRC}/config.state
	@${ECHO_MSG} INPUT_install_prefix_VALUE=\'${PREFIX}\' >> ${WRKSRC}/config.state
	@${ECHO_MSG} INPUT_install_bindir_VALUE=\''$$prefix/bin'\' >> ${WRKSRC}/config.state
	@${ECHO_MSG} INPUT_install_libdir_VALUE=\''$$prefix/lib'\' >> ${WRKSRC}/config.state
	@${ECHO_MSG} INPUT_install_sharedir_VALUE=\''$$prefix/share'\' >> ${WRKSRC}/config.state
	cd ${WRKSRC} && ${SETENV} LOCALBASE=${LOCALBASE} X11BASE=${X11BASE} PREFIX=${PREFIX} ./build.sh uqm config

do-build:
	cd ${WRKSRC} && ./build.sh uqm

do-install:
	cd ${WRKSRC} && ./build.sh uqm install

post-install:
	${STRIP_CMD} ${PREFIX}/lib/uqm/uqm
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/users/manual.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
