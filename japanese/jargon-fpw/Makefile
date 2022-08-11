PORTNAME=	jargon-fpw
PORTVERSION=	2.0
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/jargon/
DISTNAME=	jargon-fpw${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The famous jargon file (EPWING V1 format)

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/jargon
EXTRACT_BEFORE_ARGS=	-qL

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/jargon-fpw/jargon/data
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/jargon-fpw/jargon/gaiji
	${INSTALL_DATA} ${WRKSRC}/jargon/data/honmon \
		${STAGEDIR}${PREFIX}/share/dict/jargon-fpw/jargon/data
	${INSTALL_DATA} ${WRKSRC}/jargon/gaiji/gai16f \
		${STAGEDIR}${PREFIX}/share/dict/jargon-fpw/jargon/gaiji
	${INSTALL_DATA} ${WRKSRC}/jargon/gaiji/gai16h \
		${STAGEDIR}${PREFIX}/share/dict/jargon-fpw/jargon/gaiji
	${INSTALL_DATA} ${WRKSRC}/catalogs \
		${STAGEDIR}${PREFIX}/share/dict/jargon-fpw
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} readme.1st readme.txt \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
