PORTNAME=	roget-fpw
PORTVERSION=	1.0.2
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/roget/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Roget's Thesaurus (EPWING V1 format)

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/roget
EXTRACT_BEFORE_ARGS=	-qL

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/roget-fpw/roget/data
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/roget-fpw/roget/gaiji
	${INSTALL_DATA} ${WRKSRC}/roget/data/honmon \
		${STAGEDIR}${PREFIX}/share/dict/roget-fpw/roget/data
	${INSTALL_DATA} ${WRKSRC}/roget/gaiji/gai16h \
		${STAGEDIR}${PREFIX}/share/dict/roget-fpw/roget/gaiji
	${INSTALL_DATA} ${WRKSRC}/catalogs \
		${STAGEDIR}${PREFIX}/share/dict/roget-fpw
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} readme.pkg readme.txt \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
