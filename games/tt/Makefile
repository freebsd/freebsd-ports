# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	tt
PORTVERSION=	15.1
CATEGORIES=	games
MASTER_SITES=	http://www.miketaylor.org.uk/tech/tt/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tetris for Terminals

USES=		ncurses

ALL_TARGET=	tt

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tt ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
