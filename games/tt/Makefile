# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	tt
PORTVERSION=	15.1
CATEGORIES=	games
MASTER_SITES=	http://www.miketaylor.org.uk/tech/tt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tetris for Terminals

ALL_TARGET=	tt

PORTDOCS=	*

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} -g games -m 2555 ${WRKSRC}/tt ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
