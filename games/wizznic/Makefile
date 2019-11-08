# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wizznic
PORTVERSION=	0.9.9
DISTVERSIONSUFFIX=-src
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Source%20Releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of the arcade classic Puzznic

LICENSE=	GPLv3+

LIB_DEPENDS=	libpng.so:graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

USES=		gmake sdl tar:bzip2
USE_CSTD=	gnu89
USE_SDL=	image mixer sdl
MAKE_ENV=	DATADIR=${DATADIR}/ BINDIR=${PREFIX}/bin
ALL_TARGET=	sdl

PORTDOCS=	changelog.txt credits.txt music-score-credits.txt readme.txt

DESKTOP_ENTRIES="Wizznic!" "${COMMENT}" ${PORTNAME} \
		"${PORTNAME}" "Game;LogicGame;" false

OPTIONS_DEFINE=	DOCS

post-install:
	@${CHMOD} -R 755 ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}
	${LN} -sf ${DATADIR}/packs/001_wizznic/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
