PORTNAME=	festival-freebsoft-utils
PORTVERSION=	0.10
PORTREVISION=	4
CATEGORIES=	audio accessibility
MASTER_SITES=	http://www.freebsoft.org/pub/projects/${PORTNAME}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Festival utilities focused on interaction with Speech Dispatcher

RUN_DEPENDS=	festival:audio/festival \
		sox:audio/sox

NO_BUILD=	yes
USES=		iconv

INFO=		${PORTNAME}
PORTDOCS=	ANNOUNCE NEWS README

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/festival/lib
	${INSTALL_DATA} ${WRKSRC}/*.scm ${STAGEDIR}${PREFIX}/share/festival/lib
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
