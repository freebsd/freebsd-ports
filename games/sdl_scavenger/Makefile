# New Ports collection makefile for:	SDLScavenger
# Date created:		2012-04-21
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	sdl_scavenger
PORTVERSION=	145.1.2010.11.5
CATEGORIES=	games
MASTER_SITES=	SF/sdlscavenger/
DISTNAME=	sdlscav-145.1_2010_11_5

MAINTAINER=	nemysis@gmx.ch
COMMENT=	A Lode Runner like game

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/sdlscav-145

USE_ZIP=	yes
USE_SDL=	sdl image mixer
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/sdlscavenger \
		share/pixmaps/${PORTNAME}.png

PORTDATA=	*
PORTDOCS=	CREDITS DOC NEW_FEATURES README STRATEGY

ALL_TARGET=

.include <bsd.port.options.mk>

post-patch:
		@${REINPLACE_CMD} -e 's|data:/usr/local/games/scavenger|data:${DATADIR}/data|' \
			${WRKSRC}/names.h

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/sdlscav ${PREFIX}/bin/sdlscavenger

# Data
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} data ${DATADIR})

# Pixmaps
	${INSTALL_DATA} ${WRKSRC}/data/scav.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
