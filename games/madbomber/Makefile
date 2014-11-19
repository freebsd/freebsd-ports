# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	madbomber
PORTVERSION=	0.2.5
PORTREVISION=	14
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/madbomber/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Clone of Activision's classic Atari 2600 console game "Kaboom!"

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USE_SDL=	mixer image sdl

CPPFLAGS+=	`${SDL_CONFIG} --cflags` -DDATA_PREFIX=\"${DATADIR}/\"
LDFLAGS+=	`${SDL_CONFIG} --libs`

PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Mad Bomber" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o ${PORTNAME} \
		${PORTNAME}.c ${LDFLAGS} -lSDL_mixer -lSDL_image

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for d in images music sounds
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor

	${LN} -sf ${DATADIR}/images/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
