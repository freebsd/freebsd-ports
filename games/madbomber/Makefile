# New ports collection makefile for:	madbomber
# Date created:				28 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	madbomber
PORTVERSION=	0.2.5
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/madbomber/src/ \
		ftp://ftp.billsgames.com/unix/x/madbomber/src/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	A clone of Activision's classic Atari 2600 console game "Kaboom!"

LICENSE=	GPLv2

USE_SDL=	mixer image sdl

CPPFLAGS+=	`${SDL_CONFIG} --cflags` -DDATA_PREFIX=\"${DATADIR}/\"
LDFLAGS+=	`${SDL_CONFIG} --libs`

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDATA=	*
PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt TODO.txt

.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o ${PORTNAME} \
		${PORTNAME}.c ${LDFLAGS} -lSDL_mixer -lSDL_image

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# Data
	${MKDIR} ${DATADIR}
.for d in images music sounds
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

# Pixmaps
	${INSTALL_DATA} ${WRKSRC}/data/images/icon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
