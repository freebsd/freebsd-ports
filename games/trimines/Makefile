# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	trimines
PORTVERSION=	1.3.0
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.freewebs.com/trimines/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Mine sweeper game that uses triangles instead of squares

USES=		sdl
USE_SDL=	sdl

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*
PORTDOCS=	*

DESKTOP_ENTRIES="Trimines" \
		"Trimines" \
		"" \
		"trimines" \
		"Game;LogicGame;" \
		""

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/src/gfx.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} src/main.c -o ./${PORTNAME} \
		`${SDL_CONFIG} --cflags --libs`

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
