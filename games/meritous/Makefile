# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	meritous
PORTVERSION=	1.2
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://www.asceai.net/files/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}_v${PORTVERSION:C/\.//}_src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Action-adventure dungeon crawl game

LICENSE=	GPLv3

USE_BZIP2=	yes
USES=		gmake
USE_SDL=	sdl mixer image
ALL_TARGET=	default
USE_DOS2UNIX=	dat/d/helpfile.txt src/*.c

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="Meritous" \
		"Action-adventure dungeon crawl game" \
		"${DATADIR}/i/icon.png" \
		"meritous" \
		"Game;ActionGame;AdventureGame;" \
		false

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|dat/|${DATADIR}/|' ${WRKSRC}/src/*.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/meritous ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/dat && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
