PORTNAME=	krank
PORTVERSION=	07
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Little casual game
WWW=		https://krank.sourceforge.net/

RUN_DEPENDS=	${PYGAME} \
		${PYNUMPY}

USES=		python:run tar:bzip2
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	CHANGELOG.txt README

DESKTOP_ENTRIES="Krank" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

OPTIONS_DEFINE=	DOCS

post-extract:
	@${FIND} ${WRKSRC} -name .cvsignore -delete -or -name .DS_Store -delete

post-patch:
	@${REINPLACE_CMD} -e 's|`dirname.*|${DATADIR}|' ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.for d in art fonts html levels sounds src
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.iss ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/logo.xcf ${STAGEDIR}${DATADIR}
	${LN} -sf ${DATADIR}/html/gfx/logo.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
