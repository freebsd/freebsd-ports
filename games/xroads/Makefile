# New ports collection makefile for:	xroads
# Date created:				21 June 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xroads
PORTVERSION=	0.6
CATEGORIES=	games
MASTER_SITES=	http://www.autobahn.mb.ca/~foxtrot/ \
		http://supernova.dyn.ml.org/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	will@FreeBSD.org

USE_X_PREFIX=	yes
FETCH_BEFORE_ARGS=	-t -b

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xroads ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/games/xroads
.for file in 00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18
	${INSTALL_DATA} ${WRKSRC}/map${file}.xrm ${PREFIX}/share/games/xroads
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xroads
.for file in BUGS CHANGELOG README
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xroads
.endfor
.endif

.include <bsd.port.mk>
