# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	patapizza-tetris
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	https://github.com/patapizza/tetris/downloads/
DISTNAME=	${PORTNAME:S/patapizza-//}-${DISTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Unofficial clone of the original Tetris game

LICENSE=	GPLv3

OPTIONS_DEFINE=	DATA
OPTIONS_DEFAULT=DATA

FETCH_ARGS?=	-Fpr
USE_GMAKE=	yes
USE_SDL=	sdl image gfx ttf

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDATA=	*
PORTDOCS=	README.md

SUB_FILES=	${PORTNAME}.sh

post-patch:
	${REINPLACE_CMD} -e 's:%%PREFIX%%:${PREFIX}:g' ${WRKSRC}/Makefile

.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && ${CC} -o ${PORTNAME} ${CFLAGS} \
		-DDATA_PREFIX=\"${DATADIR}/\" \
		-lm `${SDL_CONFIG} --cflags --libs` -lSDL -lSDL_image -lSDL_gfx -lSDL_ttf -lm tetris.c

do-install:
# Scripts
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

# Executable
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${DATADIR}

# Data
.if ${PORT_OPTIONS:MDATA}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} images ${DATADIR})
.endif

# Pixmaps
	${INSTALL_DATA} ${WRKSRC}/images/logo.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
