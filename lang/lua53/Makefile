# Created by: GreenDog <fiziologus@gmail.com>
# $FreeBSD$

PORTNAME=	lua
PORTVERSION=	5.3.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.lua.org/ftp/
PKGNAMESUFFIX=	53

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, compilable scripting language providing easy access to C code

LICENSE=	MIT

USES=		libedit
LUA_VER=	5.3
USE_LDCONFIG=	yes

# Overriding __MAKE_CONF makes sure that we don't re-parse
# /etc/make.conf during do-build, which would jeopardize the build
# if, for instance, the user set CFLAGS=mumble
# NOTE: /etc/make.conf is read BEFORE Makefile, so we already
# have its settings when we get here.
# See http://wiki.freebsd.org/MatthiasAndree/LuaLessonsLearnt
MAKE_ARGS=	__MAKE_CONF=${NONEXISTENT}
# liblua.so requires libm, so make sure it has an explicit dependency
# so that applications need not second-guess lua's dependencies.
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lm -pthread
BUILD_WRKSRC=	${WRKSRC}/src
MAKE_ARGS+=	MYCFLAGS="${CFLAGS} ${CPPFLAGS} -DLUA_USE_LINUX" \
		MYLDFLAGS="${LDFLAGS}" \
		MYLIBS="-Wl,-E -L${LOCALBASE}/lib -ledit" \
		CC="${CC}" \
		LUA_T=lua53 \
		LUAC_T=luac53 \
		LUA_A=liblua-${LUA_VER}.a \
		LUA_SO=liblua-${LUA_VER}.so \
		LUA_SONAME=liblua-${LUA_VER}.so \
		TO_BIN="lua53 luac53" \
		TO_LIB="liblua-${LUA_VER}.a liblua-${LUA_VER}.so" \
		INSTALL_TOP=${STAGEDIR}${PREFIX} \
		INSTALL_INC=${STAGEDIR}${PREFIX}/include/lua53 \
		INSTALL_EXEC="${INSTALL_PROGRAM}"

# Cope with the lack of support for Lua 5.2 in bsd.lua.mk.  These
# overrides, which are required below, should be removed once bsd.lua.mk
# understands this lua version.
LUA_PREFIX?=	${PREFIX}
LUA_SUBDIR?=	lua${PKGNAMESUFFIX}
LUA_INCDIR?=	${LUA_PREFIX}/include/${LUA_SUBDIR}
LUA_LIBDIR?=	${LUA_PREFIX}/lib

SUB_FILES=	lua-${LUA_VER}.pc
SUB_LIST=	version=${PORTVERSION} \
		includedir=${LUA_INCDIR} \
		libdir=${LUA_LIBDIR} \
		soname=lua-${LUA_VER}

CFLAGS+=	-fPIC

post-patch:
	@${REINPLACE_CMD} -e 's,rand *(,random(,g' \
		${WRKSRC}/src/lmathlib.c
	@${REINPLACE_CMD} -e "/LUA_ROOT/s|/usr/local|${LUA_PREFIX}| ; \
		s,readline/,editline/,g ; \
		/history\.h/d" \
		${WRKSRC}/src/luaconf.h ${WRKSRC}/src/lua.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblua-${LUA_VER}.so
	@${MV} ${STAGEDIR}${PREFIX}/man/man1/lua.1 \
		${STAGEDIR}${PREFIX}/man/man1/lua53.1
	@${MV} ${STAGEDIR}${PREFIX}/man/man1/luac.1 \
		${STAGEDIR}${PREFIX}/man/man1/luac53.1
	${INSTALL_DATA} ${WRKDIR}/lua-${LUA_VER}.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
