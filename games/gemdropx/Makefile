# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	gemdropx
PORTVERSION=	0.9
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/gemdropx/src/ \
		ftp://ftp.billsgames.com/unix/x/gemdropx/src/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Interesting one-player puzzle game for X (SDL)

LICENSE=	GPLv2

ALL_TARGET=	${PORTNAME}
USE_SDL=	image mixer sdl

USE_GMAKE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.xmp

PORTDATA=	*
PORTDOCS=	AUTHORS.txt CHANGES.txt ICON.txt README.txt TODO.txt

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
# Fix SDL, CFLAGS
	@${REINPLACE_CMD} \
	-e 's|sdl-config|$(SDL_CONFIG)|' \
	-e 's|CC=gcc|CC?=g++|' \
	-e 's|CXX=gcc|CXX?=g++|' \
	-e 's|CFLAGS=-Wall $(SDL_CFLAGS)|CFLAGS+=$(SDL_CFLAGS)|' \
		${WRKSRC}/Makefile

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Data
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} "images sounds" ${DATADIR})

# Pixmaps
	${INSTALL_DATA} ${WRKSRC}/data/images/gemdropx-icon.xpm ${PREFIX}/share/pixmaps/${PORTNAME}.xmp

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
