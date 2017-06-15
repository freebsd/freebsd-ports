# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	bumprace
PORTVERSION=	1.5.6
CATEGORIES=	games
MASTER_SITES=	https://bitbucket.org/karlb/bumprace/get/ \
		http://mirror.amdmi3.ru/distfiles/${DIST_SUBDIR}/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple arcade racing game

WRKSRC=		${WRKDIR}/karlb-bumprace-047c7a593bcc

USES=		gmake jpeg localbase tar:bz2
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
	${INSTALL_DATA} ${WRKSRC}/FAQ ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
