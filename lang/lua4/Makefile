# New ports collection makefile for: 	lua
# Date created:				27 June 1999
# Whom:					Richard Kiss <him@richardkiss.com>
#
# $FreeBSD$
#

PORTNAME=	lua
PORTVERSION=	4.0
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.tecgraf.puc-rio.br/pub/lua/ \
		ftp://csg.uwaterloo.ca/pub/lhf/lua/ \
		ftp://ftp.ntua.gr/pub/lang/lua/ \
		ftp://ftp.uni-trier.de/pub/languages/lua/ \
		ftp://ftp.gwdg.de/pub/languages/lua/

MAINTAINER=	him@richardkiss.com
COMMENT=	Small, compilable scripting language providing easy access to C code

LATEST_LINK=	lua4
MAN1=		luac.1
WRKSRC=		${WRKDIR}/lua
ALL_TARGET=	all so
INSTALLS_SHLIB=	YES

CONFLICTS=	lua-5*

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
	@ ${INSTALL_DATA} ${WRKSRC}/lib/liblua.so.4.0 ${PREFIX}/lib/liblua.so.4
	@ ${LN} -s ${PREFIX}/lib/liblua.so.4 ${PREFIX}/lib/liblua.so
	@ ${INSTALL_DATA} ${WRKSRC}/lib/liblualib.a ${PREFIX}/lib
	@ ${INSTALL_DATA} ${WRKSRC}/lib/liblualib.so.4.0 ${PREFIX}/lib/liblualib.so.4
	@ ${LN} -s ${PREFIX}/lib/liblualib.so.4 ${PREFIX}/lib/liblualib.so

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/lua
	@${STRIP_CMD} ${PREFIX}/bin/luac

.if ${MACHINE_ARCH:L} == "amd64"
CFLAGS+=    -fPIC
.endif

.include <bsd.port.mk>
