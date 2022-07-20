PORTNAME=	ryaku-fpw
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/Ryaku/
DISTNAME=	Ryaku-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Abbreviation (alphabet-->Japanese) dictionary (EPWING V1 format)

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ryaku
EXTRACT_BEFORE_ARGS=	-qL

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/ryaku-fpw/ryaku/data
	${INSTALL_DATA} ${WRKSRC}/ryaku/data/honmon \
		${STAGEDIR}${PREFIX}/share/dict/ryaku-fpw/ryaku/data
	${INSTALL_DATA} ${WRKSRC}/catalogs \
		${STAGEDIR}${PREFIX}/share/dict/ryaku-fpw
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
