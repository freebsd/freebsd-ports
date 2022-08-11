PORTNAME=	flower-fpw
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/Flower/
DISTNAME=	Flower-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dictionary for flowers (EPWING V1 format)

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/flower
EXTRACT_BEFORE_ARGS=	-qL

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/flower-fpw/flower/data
	${INSTALL_DATA} ${WRKSRC}/flower/data/honmon \
		${STAGEDIR}${PREFIX}/share/dict/flower-fpw/flower/data
	${INSTALL_DATA} ${WRKSRC}/catalogs \
		${STAGEDIR}${PREFIX}/share/dict/flower-fpw
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
