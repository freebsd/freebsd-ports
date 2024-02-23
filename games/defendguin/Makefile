PORTNAME=	defendguin
DISTVERSION=	0.0.13
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://tuxpaint.org/ftp/unix/x/defendguin/src/ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Your mission is to defend little penguinoids
WWW=		http://www.newbreedsoftware.com/defendguin/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING.txt

USES=		gmake sdl shebangfix
USE_SDL=	mixer sdl

SHEBANG_FILES=	data/images/boss/ppm2bmp.sh data/images/ufo/ppm2bmp.sh
bash_CMD=	${SH}

DESKTOP_ENTRIES=	"Defendguin" \
			"" \
			"${PORTNAME}" \
			"${PORTNAME}" \
			"Game;ArcadeGame;" \
			""

PLIST_FILES=	bin/defendguin \
		share/man/man6/defendguin.6.gz \
		share/pixmaps/defendguin.png
PORTDATA=	images music sounds
PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt
OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
