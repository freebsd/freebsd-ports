PORTNAME=	web1913-fpw
PORTVERSION=	${WEBFPW_VER}
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/web1913/
DISTNAME=	${PORTNAME}${WEBFPW_VER}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Webster's Revised Unabridged Dictionary (1913) (EPWING V1 format)

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/web
EXTRACT_BEFORE_ARGS=	-qL
WEBFPW_VER=	1.1.2

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/web-fpw/web/data
	${INSTALL_DATA} ${WRKSRC}/web/data/honmon \
		${STAGEDIR}${PREFIX}/share/dict/web-fpw/web/data
	${INSTALL_DATA} ${WRKSRC}/catalogs \
		${STAGEDIR}${PREFIX}/share/dict/web-fpw
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
