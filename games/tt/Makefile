# New ports collection makefile for:	tt
# Date created:				11 Sent 2003
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	tt
PORTVERSION=	14.0
CATEGORIES=	games
MASTER_SITES=	http://www.miketaylor.org.uk/tech/tt/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Tetris for Terminals

ALL_TARGET=	tt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tt ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
