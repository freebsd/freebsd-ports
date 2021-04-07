PORTNAME=	bumprace
PORTVERSION=	1.5.8
CATEGORIES=	games
MASTER_SITES=	https://bitbucket.org/karlb/bumprace/get/ \
		http://mirror.amdmi3.ru/distfiles/${DIST_SUBDIR}/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple arcade racing game

LICENSE=	GPLv2+ CC-BY-2.0 CC-BY-3.0
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/karlb-bumprace-e73baa9e7465

USES=		autoreconf gmake jpeg localbase sdl tar:bz2
GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer image

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png
PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="BumpRace" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		""

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/macosx/icon.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/FAQ ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
