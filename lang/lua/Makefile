# New ports collection makefile for: 	lua
# Date created:				27 June 1999
# Whom:					Richard Kiss <richard@homemail.com>
#
# $FreeBSD$
#

PORTNAME=	lua
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.tecgraf.puc-rio.br/pub/lua/ \
		ftp://csg.uwaterloo.ca/pub/lhf/lua/ \
		ftp://ftp.ntua.gr/pub/lang/lua/ \
		ftp://ftp.uni-trier.de/pub/languages/lua/ \
		ftp://ftp.gwdg.de/pub/languages/lua/

MAINTAINER=	richard@homemail.com

MAN1=		luac.1
WRKSRC=		${WRKDIR}/lua

do-install:
	@ ${MKDIR} ${PREFIX}/share/doc/lua
	@ ${INSTALL_PROGRAM} ${WRKSRC}/bin/lua ${PREFIX}/bin
	@ ${INSTALL_PROGRAM} ${WRKSRC}/bin/luac ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/doc/luac.1 ${PREFIX}/man/man1/luac.1
	@ ${INSTALL_DATA} ${WRKSRC}/doc/idx.html ${PREFIX}/share/doc/lua
	@ ${INSTALL_DATA} ${WRKSRC}/doc/index.html ${PREFIX}/share/doc/lua
	@ ${INSTALL_DATA} ${WRKSRC}/doc/luac.html ${PREFIX}/share/doc/lua
	@ ${INSTALL_DATA} ${WRKSRC}/doc/manual.html ${PREFIX}/share/doc/lua
	@ ${INSTALL_DATA} ${WRKSRC}/include/lua.h ${PREFIX}/include
	@ ${INSTALL_DATA} ${WRKSRC}/include/luadebug.h ${PREFIX}/include
	@ ${INSTALL_DATA} ${WRKSRC}/include/lualib.h ${PREFIX}/include
	@ ${INSTALL_DATA} ${WRKSRC}/include/lauxlib.h ${PREFIX}/include
	@ ${INSTALL_DATA} ${WRKSRC}/lib/liblua.a ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/lib/liblualib.a ${PREFIX}/lib

post-install:
	@strip ${PREFIX}/bin/lua
	@strip ${PREFIX}/bin/luac

.include <bsd.port.mk>
