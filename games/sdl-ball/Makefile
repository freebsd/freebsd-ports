PORTNAME=	sdl-ball
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	SDL-Ball_${PORTVERSION}_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arkanoid/Breakout clone with pretty graphics

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gl gmake sdl tar:xz
USE_SDL=	sdl mixer image ttf
USE_GL=		gl glu
MAKE_ENV=	DATADIR=${DATADIR}/

WRKSRC=		${WRKDIR}/SDL-Ball_src

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/themes && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/themes/default/icon32.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_DATA} ${WRKSRC}/sdl-ball.desktop ${STAGEDIR}${PREFIX}/share/applications/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
