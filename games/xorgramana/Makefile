PORTNAME=	xorgramana
PORTVERSION=	0.0.8
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	http://www.jwm-art.net/XorGramana/ \
		https://mirror.amdmi3.ru/distfiles/
DISTNAME=	XorGramana-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Logic word puzzle game set inside a series of mazes
WWW=		https://www.jwm-art.net/XorGramana/

USES=		gl gmake sdl tar:bzip2
USE_SDL=	sdl image
USE_GL=		glu

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

DESKTOP_ENTRIES="XorGramana" \
		"Logic word puzzle game set inside a series of mazes" \
		"${DATADIR}/GFX/x.png" \
		"xorgramana" \
		"Game;LogicGame;" \
		false

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|GFX/|${DATADIR}/&|' ${WRKSRC}/icons.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "data GFX" ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
