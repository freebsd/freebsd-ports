PORTNAME=	malbolge
PORTVERSION=	0.1.1
CATEGORIES=	lang
MASTER_SITES=	http://cdn.bitbucket.org/dereckson/${PORTNAME}/downloads/

MAINTAINER=	dereckson@gmail.com
COMMENT=	Esoteric language

PLIST_FILES=	bin/malbolge
OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/malbolge ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/malbolge.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
