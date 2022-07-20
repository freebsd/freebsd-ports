PORTNAME=	CGdic-fpw
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/CGdic1.5h/
DISTNAME=	CGdic1.5h-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese dictionary for CG (EPWING V1 format)

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/cg
EXTRACT_BEFORE_ARGS=	-qL

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/CGdic-fpw/cg/data
	${INSTALL_DATA} ${WRKSRC}/cg/data/honmon \
		${STAGEDIR}${PREFIX}/share/dict/CGdic-fpw/cg/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${STAGEDIR}${PREFIX}/share/dict/CGdic-fpw
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
