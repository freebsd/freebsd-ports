# Ports collection makefile for:   uqm
# Date created:                    14 September 2003
# Whom:                            benlutz@datacomm.ch
#
# $FreeBSD$
#
# Ur-Quan Masters offers add-on packages that enhance the game. These are
# optional. The following add-ons exist at the moment:
#
# Voice add-on (110 MB). Enable this with -DVOICEADDON
#
# 3DO Music add-on (18 MB). Enable this with -DMUSICADDON
#

PORTNAME=	uqm
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sc2
DISTFILES=	${PORTNAME}-${PORTVERSION}-source.tgz ${PORTNAME}-${PORTVERSION}-content.zip
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-source.tgz

MAINTAINER=	benlutz@datacomm.ch
COMMENT=	A port of the original Star Control 2 for 3DO consoles

ONLY_FOR_ARCHS=	i386

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis

USE_XLIB=	yes
USE_GMAKE=	yes
USE_SDL=	image sdl
USE_REINPLACE=	yes
NO_INSTALL_MANPAGES=	yes

.ifdef(VOICEADDON)
DISTFILES+=	${PORTNAME}-${PORTVERSION}-voice.zip
PLIST_SUB+=	VOICEADDON=""
.else
PLIST_SUB+=	VOICEADDON="@comment "
.endif

.ifdef(MUSICADDON)
DISTFILES+=	${PORTNAME}-${PORTVERSION}-3domusic.zip
PLIST_SUB+=	MUSICADDON=""
.else
PLIST_SUB+=	MUSICADDON="@comment "
.endif

pre-everything::
.ifdef(!VOICEADDON || !MUSICADDON)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may specify the following options:"
.endif
.ifdef(!VOICEADDON)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "-DVOICEADDON"
	@${ECHO_MSG} "  Installs the voice add-on (110MB)."
.endif
.ifdef(!MUSICADDON)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "-DMUSICADDON"
	@${ECHO_MSG} "  Installs the music add-on (18MB) containing the original"
	@${ECHO_MSG} "  3do music files. Note that there is music without this"
	@${ECHO_MSG} "  add-on, just not as much."
.endif

post-extract:
	${CP} ${DISTDIR}/${PORTNAME}-${PORTVERSION}-content.zip ${WRKSRC}/content/packages/

do-configure:
	cd ${WRKSRC} && ${SETENV} LOCALBASE=${LOCALBASE} PREFIX=${PREFIX} ./build.sh uqm config

do-build:
	cd ${WRKSRC} && ./build.sh uqm

do-install:
	cd ${WRKSRC} && ./build.sh uqm install
.ifdef(VOICEADDON)
	${MKDIR} ${PREFIX}/share/uqm/content/packages/addons/voice
	${CP} ${DISTDIR}/${PORTNAME}-${PORTVERSION}-voice.zip ${PREFIX}/share/uqm/content/packages/addons/voice
	${REINPLACE_CMD} -e "s/\"$$\@\"/--addon voice \"$$\@\"/" ${PREFIX}/bin/uqm
.endif
.ifdef(MUSICADDON)
	${MKDIR} ${PREFIX}/share/uqm/content/packages/addons/3domusic
	${CP} ${DISTDIR}/${PORTNAME}-${PORTVERSION}-3domusic.zip ${PREFIX}/share/uqm/content/packages/addons/3domusic
	${REINPLACE_CMD} -e "s/\"$$\@\"/--addon 3domusic \"$$\@\"/" ${PREFIX}/bin/uqm
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/lib/uqm/uqm
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/users/manual.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
