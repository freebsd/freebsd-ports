# New ports collection makefile for:	seabattle
# Date created:				6 June 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	seabattle
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.deater.net/weave/vmwprod/
MASTER_SITE_SUBDIR=	games/strategy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A curses based battleship type game

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/seabattle ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/seabattle
	${INSTALL_DATA} ${WRKSRC}/*.au ${PREFIX}/share/seabattle
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/seabattle
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/doc/seabattle
.endif

.include <bsd.port.mk>
