# Created by: Richard Kiss
# $FreeBSD$

PORTNAME=	lua
PORTVERSION=	5.1.5
PORTREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	http://www.lua.org/ftp/ \
		ftp://ftp.ntua.gr/pub/lang/lua/ \
		ftp://ftp.gwdg.de/pub/languages/lua/

MAINTAINER=	lua@FreeBSD.org
COMMENT=	Small, compilable scripting language providing easy access to C code

LICENSE=	MIT

PATCH_WRKSRC=	${WRKSRC}/src
USE_LUA=	5.1
LUA_COMPS=	# only define variables
ALL_TARGET=	freebsd
USE_PKGCONFIG=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes
MAKE_ENV=	LUA_SONAME="liblua-${LUA_VER}.so.${LUA_VER_SH}"
# Overriding __MAKE_CONF makes sure that we don't re-parse
# /etc/make.conf during do-build, which would jeopardize the build
# if, for instance, the user set CFLAGS=mumble
# NOTE: /etc/make.conf is read BEFORE Makefile, so we already
# have its settings when we get here.
# See http://wiki.freebsd.org/MatthiasAndree/LuaLessonsLearnt
MAKE_ARGS=	__MAKE_CONF=${NONEXISTENT}
# liblua.so requires libm, so make sure it has an explicit dependency
# so that applications need not second-guess lua's dependencies.
LDFLAGS+=	-lm

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

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "powerpc"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		'/^INSTALL_.*=/s/INSTALL_TOP/prefix/ ; \
		 s|^(CC\|AR\|RANLIB)=|\1?=| ; \
		 /^CFLAGS=/ { s/=/+=/; s/-O2//; } ; \
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
	@${REINPLACE_CMD} -e '/LUA_ROOT/s|/usr/local|${PREFIX}|' \
		${WRKSRC}/src/luaconf.h

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
.if ${PORT_OPTIONS:MDOCS}
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

.include <bsd.port.post.mk>
