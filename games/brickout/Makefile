# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	brickout
PORTVERSION=	2002.06.09
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/agenda/brickout/src/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Ball-and-paddle game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		localbase
USE_SDL=	sdl mixer

PORTDOCS=	CHANGES.txt README.txt TODO.txt
PORTDATA=	*
PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

DESKTOP_ENTRIES="Brickout" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		""

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} \
		-DIMAGEDIR=\"${DATADIR}/images-sdl/\" \
	        -DSOUNDDIR=\"${DATADIR}/sounds/\" \
		-DMUSICDIR=\"${DATADIR}/music/\" \
		-DUSE_SDL \
		`sdl-config --cflags --libs` -lSDL_mixer \
		-o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} "images-sdl music sounds" ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
