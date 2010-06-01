# New ports collection makefile for: 	lua
# Date created:				27 June 1999
# Whom:					Richard Kiss
#
# $FreeBSD$
#

PORTNAME=	lua
PORTVERSION=	5.1.4
CATEGORIES=	lang
MASTER_SITES=	http://www.lua.org/ftp/ \
		ftp://ftp.tecgraf.puc-rio.br/pub/lua/ \
		ftp://csg.uwaterloo.ca/pub/lhf/lua/ \
		ftp://ftp.ntua.gr/pub/lang/lua/ \
		ftp://ftp.uni-trier.de/pub/languages/lua/ \
		ftp://ftp.gwdg.de/pub/languages/lua/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Small, compilable scripting language providing easy access to C code

USE_LUA=	5.1
LUA_COMPS=	# only define variables
ALL_TARGET=	freebsd
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
MAKE_ENV=	LUA_SONAME="liblua-${LUA_VER}.so.${LUA_VER_SH}"

MAN1=		lua-${LUA_VER}.1 luac-${LUA_VER}.1
DOCSDIR=	${PREFIX}/share/doc/${LUA_SUBDIR}
PORTDOCS=	*
LATEST_LINK=	${LUA_SUBDIR}

LUA_BIN=	lua luac
LUA_INC=	lua.h luaconf.h lualib.h lauxlib.h ../etc/lua.hpp
LUA_MAN=	${LUA_BIN:S/$/.1/}
LUA_ETC=	Makefile README all.c lua.ico luavs.bat min.c \
		noparser.c strict.lua
LUA_TEST=	README bisect.lua cf.lua echo.lua env.lua factorial.lua \
		fib.lua fibfor.lua globals.lua hello.lua life.lua luac.lua \
		printf.lua readonly.lua sieve.lua sort.lua table.lua \
		trace-calls.lua trace-globals.lua xd.lua

post-patch:
	@${REINPLACE_CMD} -Ee \
		'/^INSTALL_.*=/s/INSTALL_TOP/prefix/ ; \
		 s|^(CC=).*|\1 ${CC}| ; \
		 s|^(CFLAGS=)|\1 ${CFLAGS}| ; \
		 s|/usr/local|${PREFIX}|' \
		 ${WRKSRC}/Makefile ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -i '' -Ee \
		's|^(prefix=).*|\1 ${PREFIX}| ; \
		s|^(libdir=).*|\1 ${LUA_LIBDIR}| ; \
		s|^(includedir=).*|\1 ${LUA_INCDIR}| ; \
		s|^(INSTALL_BIN=).*|\1 ${LUA_BINDIR}| ; \
		s|^(INSTALL_INC=).*|\1 ${LUA_INCDIR}| ; \
		s|^(INSTALL_LIB=).*|\1 ${LUA_LIBDIR}| ; \
		s|^(INSTALL_CMOD=).*|\1 ${LUA_MODLIBDIR}| ; \
		s|^(INSTALL_LMOD=).*|\1 ${LUA_MODSHAREDIR}|' \
		${WRKSRC}/etc/lua.pc
	@${REINPLACE_CMD} -e 's,rand *(,random(,g' \
		${WRKSRC}/src/lmathlib.c

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
	${INSTALL_PROGRAM} ${WRKSRC}/src/liblua.so \
		${LUA_LIBDIR}/liblua-${LUA_VER}.so.${LUA_VER_SH}
	@${LN} -sf liblua-${LUA_VER}.so.${LUA_VER_SH} ${LUA_LIBDIR}/liblua.so
	@${LN} -sf ${LUA_SUBDIR}/liblua-${LUA_VER}.so.${LUA_VER_SH} \
		${PREFIX}/lib
	@${LN} -sf liblua-${LUA_VER}.so.${LUA_VER_SH} \
		${PREFIX}/lib/liblua-${LUA_VER}.so
# Manual pages.
.for f in ${LUA_MAN}
	${INSTALL_MAN} ${WRKSRC}/doc/${f} \
		${PREFIX}/man/man1/${f:C/.1$//}-${LUA_VER}.1
.endfor
# Documentation.
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR}/etc
	${MKDIR} ${DOCSDIR}/test
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.gif ${DOCSDIR}
.for f in ${LUA_ETC}
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${DOCSDIR}/etc
.endfor
.for f in ${LUA_TEST}
	${INSTALL_DATA} ${WRKSRC}/test/${f} ${DOCSDIR}/test
.endfor
.endif
# lua.pc
	${INSTALL_DATA} ${WRKSRC}/etc/lua.pc ${PREFIX}/libdata/pkgconfig/lua-${LUA_VER}.pc
# Module directories.
	${MKDIR} ${LUA_MODLIBDIR}
	${MKDIR} ${LUA_MODSHAREDIR}

.if ${MACHINE_ARCH:L} == "amd64" || ${MACHINE_ARCH:L} == "powerpc"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.mk>
