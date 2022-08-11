PORTNAME=	foldoc-fpw
PORTVERSION=	1.0.2
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/foldoc/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free On-line Dictionary of Computing (EPWING V1 format)

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/foldoc
EXTRACT_BEFORE_ARGS=	-qL

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/foldoc-fpw/foldoc/data
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/foldoc-fpw/foldoc/gaiji
	${INSTALL_DATA} ${WRKSRC}/foldoc/data/honmon \
		${STAGEDIR}${PREFIX}/share/dict/foldoc-fpw/foldoc/data
	${INSTALL_DATA} ${WRKSRC}/foldoc/gaiji/gai16h \
		${STAGEDIR}${PREFIX}/share/dict/foldoc-fpw/foldoc/gaiji
	${INSTALL_DATA} ${WRKSRC}/catalogs \
		${STAGEDIR}${PREFIX}/share/dict/foldoc-fpw
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
