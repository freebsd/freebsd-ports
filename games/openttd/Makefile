# New ports collection makefile for:	OpenTTD
# Date created:				16 Dec 2004
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openttd
PORTVERSION=	0.4.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An open source clone of Microprose Transport Tycoon Deluxe

DISTVERSIONSUFFIX=	-source

LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png

USE_GMAKE=	yes

pre-everything::
.if !defined(WITH_MIDI_PLAYER)
	@${ECHO_MSG} "Define WITH_MIDI_PLAYER=/path/to/player to build with external MIDI player"
.else
MAKE_ARGS+=	MIDI=${WITH_MIDI_PLAYER}
.endif
.if !defined(WITH_DEDICATED_SERVER_ONLY)
	@${ECHO_MSG} "Define WITH_DEDICATED_SERVER_ONLY to build CLI-based dedicated server"
USE_SDL=	sdl
.else
MAKE_ARGS+=	DEDICATED=1
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|-O2 $$(WARNING_DISPLAY)|${CFLAGS} $$(WARNING_DISPLAY)|' \
		${WRKSRC}/Makefile
.if defined(WITH_DEDICATED_SERVER_ONLY)
	@${REINPLACE_CMD} -e 's|^WITH_SDL|#WITH_SDL|' ${WRKSRC}/makefiledir/Makefile.libdetection
.endif

MAKE_ARGS+=	RELEASE=${PORTVERSION} DATA_DIR="share/openttd" \
		USE_HOMEDIR=1 PERSONAL_DIR=.openttd INSTALL=1 VERBOSE=1

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN6=		openttd.6

do-install:
	@${MKDIR} ${DATADIR}/data ${DATADIR}/lang
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/data/* ${DATADIR}/data
	${INSTALL_DATA} ${WRKSRC}/lang/*.lng ${DATADIR}/lang
	${INSTALL_MAN} ${WRKSRC}/docs/${MAN6} ${MANPREFIX}/man/man6
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in Howto_compile_lng_files_from_CLI.txt Manual.txt console.txt \
	landscape.html landscape_grid.html multiplayer.txt \
	ottd-colour-palette.gif ottd-colourtext-palette.png tileh.png
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
. endfor
.endif

post-install:
	@${SED} -e 's|$${DATADIR}|${DATADIR}|' ${.CURDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
