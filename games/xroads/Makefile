# New ports collection makefile for:	xroads
# Version required:			0.3
# Date created:				21 June 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.3 1998/08/05 09:31:02 asami Exp $
#

DISTNAME=	xroads-v0.3
PKGNAME=	xroads-0.3
CATEGORIES=	games
MASTER_SITES=	http://www.geocities.com/SiliconValley/Way/1795/ \
		http://www.autobahn.mb.ca/~foxtrot/ \
		http://supernova.dyn.ml.org/

MAINTAINER=	andy@icc.surw.chel.su

USE_X_PREFIX=	yes
FETCH_BEFORE_ARGS=	-t

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xroads ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/xroads
.for file in map0 map1 map2 map3 map4 map5 map6 map7 map8
	@ ${INSTALL_DATA} ${WRKSRC}/${file}.xrm ${PREFIX}/share/xroads
.endfor
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/xroads
.for file in BUGS CHANGELOG README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xroads
.endfor
.endif

.include <bsd.port.mk>
