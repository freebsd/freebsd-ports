# New ports collection makefile for:	OpenTTD
# Date created:				16 Dec 2004
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openttd
PORTVERSION=	0.3.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An open source clone of Microprose Transport Tycoon Deluxe

LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_SDL=	sdl

post-extract:
	@${REINPLACE_CMD} -e 's|-O2 $$(WARNING_DISPLAY)|${CFLAGS} $$(WARNING_DISPLAY)|' \
		-e 's|`$$(SDL-CONFIG) --cflags`|$$(shell $$(SDL-CONFIG) --cflags)|' \
		-e 's|`$$(SDL-CONFIG) --libs`|$$(shell $$(SDL-CONFIG) --libs)|' \
		-e 's|CC=|CC\?=|; s|CXX=|CXX\?=|; s|x86_64|amd64|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|' ${WRKSRC}/extmidi.c

MAKE_ARGS+=	RELEASE=${PORTVERSION} GAME_DATA_DIR=${DATADIR}/ \
		USE_HOMEDIR=1 PERSONAL_DIR=.openttd

PKGMESSAGE=	${WRKDIR}/pkg-message

pre-everything::
.if !defined(WITH_MIDI_PLAYER)
	@${ECHO_MSG} "Define WITH_MIDI_PLAYER=/path/to/player to build with external MIDI player"
.else
MAKE_ARGS+=	MIDI=${WITH_MIDI_PLAYER}
.endif
.if !defined(WITH_NETWORK)
	@${ECHO_MSG} "Define WITH_NETWORK to enable networking (EXPERIMENTAL!)"
.else
MAKE_ARGS+=	WITH_NETWORK=1
.endif

do-install:
	@${MKDIR} ${DATADIR}/data ${DATADIR}/lang
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/data/* ${DATADIR}/data
	${INSTALL_DATA} ${WRKSRC}/lang/*.lng ${DATADIR}/lang
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in Howto_compile_lng_files_from_CLI.txt Manual.txt console.txt landscape.html \
	multiplayer.txt ottd-colour-palette.gif textcolor.txt tileh.png
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
. endfor
.endif

post-install:
	@${SED} -e 's|$${DATADIR}|${DATADIR}|' ${.CURDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
