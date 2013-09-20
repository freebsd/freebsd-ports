# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	madbomber
PORTVERSION=	0.2.5
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/madbomber/src/ \
		ftp://ftp.billsgames.com/unix/x/madbomber/src/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Clone of Activision's classic Atari 2600 console game "Kaboom!"

LICENSE=	GPLv2

USE_SDL=	mixer image sdl

CPPFLAGS+=	`${SDL_CONFIG} --cflags` -DDATA_PREFIX=\"${DATADIR}/\"
LDFLAGS+=	`${SDL_CONFIG} --libs`

PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt TODO.txt

DESKTOP_ENTRIES="Mad Bomber" "${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" false

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o ${PORTNAME} \
		${PORTNAME}.c ${LDFLAGS} -lSDL_mixer -lSDL_image

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

	${MKDIR} ${DATADIR}
.for d in images music sounds
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} ${d} ${DATADIR})
.endfor

	${INSTALL_DATA} ${WRKSRC}/data/images/icon.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
