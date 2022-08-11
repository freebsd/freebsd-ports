PORTNAME=	vera-fpw
PORTVERSION=	${VERA_VER}.${VERAFPW_VER}
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/vera/
DISTNAME=	vera-${VERA_VER}-fpw${VERAFPW_VER}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual Entity of Relevant Aconyms (EPWING V1 format)

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/vera
EXTRACT_BEFORE_ARGS=	-qL
VERA_VER=	1.8
VERAFPW_VER=	1.0.3

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/vera-fpw/vera/data
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/vera-fpw/vera/gaiji
	${INSTALL_DATA} ${WRKSRC}/vera/data/honmon \
		${STAGEDIR}${PREFIX}/share/dict/vera-fpw/vera/data
	${INSTALL_DATA} ${WRKSRC}/vera/gaiji/gai16h \
		${STAGEDIR}${PREFIX}/share/dict/vera-fpw/vera/gaiji
	${INSTALL_DATA} ${WRKSRC}/catalogs \
		${STAGEDIR}${PREFIX}/share/dict/vera-fpw
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} readme.txt vera.tex \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
