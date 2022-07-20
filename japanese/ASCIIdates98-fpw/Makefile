PORTNAME=	ASCIIdates98-fpw
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/ASCIIdates98/
DISTNAME=	${PORTNAME:S/-fpw//}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese dictionary for PC terms in '98 ASCII Dates Book (EPWING V1 format)

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ascdates
EXTRACT_BEFORE_ARGS=	-qL

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/ASCIIdates98-fpw/ascdates/data
	${INSTALL_DATA} ${WRKSRC}/ascdates/data/honmon \
		${STAGEDIR}${PREFIX}/share/dict/ASCIIdates98-fpw/ascdates/data
	${INSTALL_DATA} ${WRKSRC}/catalogs \
		${STAGEDIR}${PREFIX}/share/dict/ASCIIdates98-fpw
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
