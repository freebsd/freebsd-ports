PORTNAME=	wordnet-fpw
PORTVERSION=	${WN_VER}.${WNFPW_VER}
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/wordnet/
DISTNAME=	wordnet-${WN_VER}-fpw${WNFPW_VER}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	English - English Dictionary (EPWING V1 format)

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/wordnet
EXTRACT_BEFORE_ARGS=	-qL
WNFPW_VER=	1.1.3
WN_VER=		1.6

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/wordnet-fpw/wordnet/data
	${INSTALL_DATA} ${WRKSRC}/wordnet/data/honmon \
		${STAGEDIR}${PREFIX}/share/dict/wordnet-fpw/wordnet/data
	${INSTALL_DATA} ${WRKSRC}/catalogs \
		${STAGEDIR}${PREFIX}/share/dict/wordnet-fpw
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
