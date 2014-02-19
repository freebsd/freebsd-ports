# Created by: Dereckson <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	malbolge
PORTVERSION=	0.1.1
CATEGORIES=	lang
MASTER_SITES=	http://cdn.bitbucket.org/dereckson/${PORTNAME}/downloads/

MAINTAINER=	dereckson@gmail.com
COMMENT=	An esoteric language

PLIST_FILES=	bin/malbolge

PORTDOCS=	*

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/malbolge ${PREFIX}/bin

OPTIONS_DEFINE=	DOCS 

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/malbolge.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
