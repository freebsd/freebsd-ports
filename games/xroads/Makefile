# New ports collection makefile for:	xroads
# Version required:			0.1.5
# Date created:				21 June 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/07/05 11:40:46 asami Exp $
#

DISTNAME=	xroads-v0.1.5
PKGNAME=	xroads-0.1.5
CATEGORIES=	games
MASTER_SITES=	http://www.geocities.com/SiliconValley/Way/1795/ \
		http://www.autobahn.mb.ca/~foxtrot/ \
		http://supernova.dyn.ml.org/

MAINTAINER=	andy@icc.surw.chel.su

USE_X_PREFIX=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xroads ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/xroads
.for file in map0 map1 map2 map3
	@ ${INSTALL_DATA} ${WRKSRC}/${file}.xrm ${PREFIX}/share/xroads
.endfor
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/xroads
.for file in BUGS CHANGELOG README
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xroads
.endfor
.endif

.include <bsd.port.mk>
