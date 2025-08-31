PORTNAME=	vectoroids
DISTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://tuxpaint.org/ftp/unix/x/${PORTNAME}/src/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Vector-based rock-shooting game similar to Asteroids
WWW=		http://www.newbreedsoftware.com/vectoroids/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake sdl
USE_SDL=	image2 mixer2 sdl2

PORTDOCS=	CHANGES.txt README.txt
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="Vectoroids" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

post-patch:
	@${FIND} ${WRKDIR} -name .xvpics | ${XARGS} ${RM} -r

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
.for d in images music sounds
	@(cd ${WRKSRC}/data && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${LN} -s ../${PORTNAME}/images/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${STAGEDIR}${PREFIX}/share/man/man6/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
