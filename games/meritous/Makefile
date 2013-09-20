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
USE_GMAKE=	yes
USE_SDL=	sdl mixer image
ALL_TARGET=	default
USE_DOS2UNIX=	dat/d/helpfile.txt src/*.c

PORTDOCS=	*
PORTDATA=	*

PLIST_FILES=	bin/${PORTNAME}

DESKTOP_ENTRIES="Meritous" \
		"Action-adventure dungeon crawl game" \
		"${DATADIR}/i/icon.png" \
		"meritous" \
		"Game;ActionGame;AdventureGame;" \
		false

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|dat/|${DATADIR}/|' ${WRKSRC}/src/*.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/meritous ${PREFIX}/bin
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/dat && ${COPYTREE_SHARE} \* ${DATADIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
