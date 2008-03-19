# New ports collection makefile for: 	lua
# Date created:				27 June 1999
# Whom:					Richard Kiss
#
# $FreeBSD$
#

PORTNAME=	lua
PORTVERSION=	5.1.3
CATEGORIES=	lang
MASTER_SITES=	http://www.lua.org/ftp/ \
		ftp://ftp.tecgraf.puc-rio.br/pub/lua/ \
		ftp://csg.uwaterloo.ca/pub/lhf/lua/ \
		ftp://ftp.ntua.gr/pub/lang/lua/ \
		ftp://ftp.uni-trier.de/pub/languages/lua/ \
		ftp://ftp.gwdg.de/pub/languages/lua/

MAINTAINER=	andrew+ports@fubar.geek.nz
COMMENT=	Small, compilable scripting language providing easy access to C code

USE_LUA=	5.1
LUA_COMPS=	# only define variables
ALL_TARGET=	freebsd
USE_GNOME=	pkgconfig

MAN1=		lua-${LUA_VER}.1 luac-${LUA_VER}.1
DOCSDIR=	${PREFIX}/share/doc/${LUA_SUBDIR}
LATEST_LINK=	${LUA_SUBDIR}

LUA_BIN=	lua luac
LUA_INC=	lua.h luaconf.h lualib.h lauxlib.h ../etc/lua.hpp
LUA_MAN=	${LUA_BIN:S/$/.1/}

post-patch:
	@${REINPLACE_CMD} -Ee \
		'/^INSTALL_.*=/s/INSTALL_TOP/prefix/ ; \
		 s|^(CC=).*|\1 ${CC}| ; \
		 s|^(CFLAGS=)|\1 ${CFLAGS}| ; \
		 s|/usr/local|${PREFIX}|' \
		 ${WRKSRC}/Makefile ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -Ee \
		's|^(prefix=).*|\1 ${PREFIX}| ; \
		s|^(libdir=).*|\1 ${LUA_LIBDIR}| ; \
		s|^(includedir=).*|\1 ${LUA_INCDIR}| ; \
		s|^(INSTALL_BIN=).*|\1 ${LUA_BINDIR}| ; \
		s|^(INSTALL_INC=).*|\1 ${LUA_INCDIR}| ; \
		s|^(INSTALL_LIB=).*|\1 ${LUA_LIBDIR}| ; \
		s|^(INSTALL_CMOD=).*|\1 ${LUA_MODLIBDIR}| ; \
		s|^(INSTALL_LMOD=).*|\1 ${LUA_MODSHAREDIR}|' \
		${WRKSRC}/etc/lua.pc && ${RM} ${WRKSRC}/etc/lua.pc.bak

post-build:
	@${RM} -f ${WRKSRC}/test/lua ${WRKSRC}/test/luac

do-install:
# Programs.
	${MKDIR} ${LUA_BINDIR}
.for f in ${LUA_BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${f} ${LUA_BINDIR}
	${LN} -sf ${LUA_SUBDIR}/${f} ${PREFIX}/bin/${f}-${LUA_VER}
.endfor
# Include files.
	${MKDIR} ${LUA_INCDIR}
.for f in ${LUA_INC}
	${INSTALL_DATA} ${WRKSRC}/src/${f} ${LUA_INCDIR}
.endfor
# Libraries.
	${MKDIR} ${LUA_LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/src/liblua.a ${LUA_LIBDIR}
# Manual pages.
.for f in ${LUA_MAN}
	${INSTALL_MAN} ${WRKSRC}/doc/${f} \
		${PREFIX}/man/man1/${f:C/.1$//}-${LUA_VER}.1
.endfor
# Documentation.
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.gif ${DOCSDIR}
	${CP} -r ${WRKSRC}/etc ${WRKSRC}/test ${DOCSDIR}
.endif
# Module directories.
	${MKDIR} ${LUA_MODLIBDIR}
	${MKDIR} ${LUA_MODSHAREDIR}
# pkg-config file.
	${INSTALL_DATA} ${WRKSRC}/etc/lua.pc ${PREFIX}/libdata/pkgconfig

.if ${MACHINE_ARCH:L} == "amd64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.mk>
