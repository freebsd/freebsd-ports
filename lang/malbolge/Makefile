# Created by: Dereckson <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	malbolge
PORTVERSION=	0.1.1
CATEGORIES=	lang
MASTER_SITES=	http://cdn.bitbucket.org/dereckson/${PORTNAME}/downloads/

MAINTAINER=	dereckson@gmail.com
COMMENT=	An esoteric language

PLIST_FILES=	bin/malbolge
OPTIONS_DEFINE=	DOCS
PORTDOCS=	*

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/malbolge ${STAGEDIR}${PREFIX}/bin

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/malbolge.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
