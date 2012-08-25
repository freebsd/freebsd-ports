# New Ports collection makefile for:	twind
# Date created:		2012-04-11
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	twind
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Match and remove all of the blocks before time runs out

LICENSE=	GPLv2

USE_SDL=	sdl image mixer
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDATA=	*
PORTDOCS=	AUTHORS CREDITS ChangeLog NEWS README TODO

.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && ${CC} -o ${PORTNAME} ${CFLAGS} \
		-DDATA_PREFIX=\"${DATADIR}/\" -DAUDIO -DLINUX \
		-lm `${SDL_CONFIG} --cflags --libs` -lSDL_mixer -lSDL_image twind.c
do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Data
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "graphics music sound" ${DATADIR})

# Pixmaps
	${INSTALL_DATA} ${WRKSRC}/graphics/${PORTNAME}.png ${PREFIX}/share/pixmaps/

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
