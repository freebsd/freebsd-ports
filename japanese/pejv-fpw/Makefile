PORTNAME=	pejv-fpw
PORTVERSION=	1.0.4
PORTREVISION=	0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/pejv/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Esperanto-Japanese dictionary (EPWING V1 format)

USES=		zip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/pejv
EXTRACT_BEFORE_ARGS=	-qL

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dict/pejv-fpw/pejv/data
	${INSTALL_DATA} ${WRKSRC}/pejv/data/honmon \
		${STAGEDIR}${PREFIX}/share/dict/pejv-fpw/pejv/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${STAGEDIR}${PREFIX}/share/dict/pejv-fpw
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} readme legumin.doc pejvo.doc \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
