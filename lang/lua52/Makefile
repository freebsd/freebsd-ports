# Created by: GreenDog <fiziologus@gmail.com>
# $FreeBSD$

PORTNAME=	lua
PORTVERSION=	5.2.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.lua.org/ftp/
PKGNAMESUFFIX=	${LUA_VER_STR}

MAINTAINER=	fiziologus@gmail.com
COMMENT=	Small, compilable scripting language providing easy access to C code

LICENSE=	MIT

#USE_LUA=	5.2
LUA_VER=	5.2
LUA_VER_SH=	1
LUA_VER_STR=	52
LUA_SUBDIR=	lua${LUA_VER_STR}
LUA_PREFIX=	${PREFIX}
LUA_BINDIR=	${LUA_PREFIX}/bin/${LUA_SUBDIR}
LUA_INCDIR=	${LUA_PREFIX}/include/${LUA_SUBDIR}
LUA_LIBDIR=	${LUA_PREFIX}/lib/${LUA_SUBDIR}
LUA_MODLIBDIR=	${LUA_PREFIX}/lib/lua/${LUA_VER}
LUA_MODSHAREDIR=	${LUA_PREFIX}/share/lua/${LUA_VER}

ALL_TARGET=	freebsd
USE_LDCONFIG=	yes
MAKE_ENV=	LUA_SONAME="liblua-${LUA_VER}.so.${LUA_VER_SH}" \
		MYCFLAGS="${CFLAGS}" MYLDFLAGS="${LDFLAGS}"
# liblua.so requires libm, so make sure it has an explicit dependency
# so that applications need not second-guess lua's dependencies.
LDFLAGS+=	-lm -pthread

MAN1=		lua-${LUA_VER}.1 luac-${LUA_VER}.1
DOCSDIR=	${PREFIX}/share/doc/${LUA_SUBDIR}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "powerpc"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		"s|%%LUA_PREFIX%%|${LUA_PREFIX}| ; \
		s|%%LUA_BINDIR%%|${LUA_BINDIR}| ; \
		s|%%LUA_INCDIR%%|${LUA_INCDIR}| ; \
		s|%%LUA_LIBDIR%%|${LUA_LIBDIR}| ; \
		s|%%LUA_MODSHAREDIR%%|${LUA_MODSHAREDIR}| ; \
		s|%%LUA_MODLIBDIR%%|${LUA_MODLIBDIR}| ; \
		s|%%LUA_VER_SH%%|${LUA_VER_SH}|" \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,rand *(,random(,g' \
		${WRKSRC}/src/lmathlib.c
	@${REINPLACE_CMD} -e "/LUA_ROOT/s|/usr/local|${LUA_PREFIX}|" \
		${WRKSRC}/src/luaconf.h

post-install:
.for f in lua luac
	${LN} -sf ${LUA_BINDIR}/${f} ${PREFIX}/bin/${f}-${LUA_VER}
.endfor
	${LN} -sf ${LUA_LIBDIR}/liblua-${LUA_VER}.so.${LUA_VER_SH} ${LUA_LIBDIR}/liblua.so
	${LN} -sf ${LUA_SUBDIR}/liblua-${LUA_VER}.so.${LUA_VER_SH} ${PREFIX}/lib
	${LN} -sf liblua-${LUA_VER}.so.${LUA_VER_SH} ${PREFIX}/lib/liblua-${LUA_VER}.so

# Documentation.
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.html *.gif *.css *.png ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
