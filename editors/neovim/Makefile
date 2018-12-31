# Created by: Anton Tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	neovim
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2
CATEGORIES=	editors

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Next-generation Vim

LICENSE=	APACHE20

BUILD_DEPENDS=	gperf:devel/gperf \
		${LUA_MODLIBDIR}/bit.so:devel/lua-bitop \
		${LUA_MODLIBDIR}/lpeg.so:devel/lua-lpeg
LIB_DEPENDS=	libluajit-5.1.so:lang/luajit \
		libmsgpackc.so:devel/msgpack \
		libtermkey.so:devel/libtermkey \
		libunibilium.so:devel/unibilium \
		libuv.so:devel/libuv \
		libvterm.so:devel/libvterm

USES=		cmake iconv lua:build pathfix pkgconfig
USE_GITHUB=	yes
GH_TUPLE=	libmpack:libmpack:1.0.5:libmpack \
		libmpack:libmpack-lua:1.0.7:libmpack_lua

CMAKE_ARGS=	-DLUA_PRG:FILEPATH="${LUA_CMD}" \
		-DCMAKE_INSTALL_MANDIR:PATH="${MANPREFIX}/man" \
		-DDEPS_PREFIX:PATH="${LOCALBASE}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_CMAKE_BOOL=	ENABLE_LIBINTL
NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e \
		's|lua_objlen|lua_rawlen| ; \
		 s|luaL_reg |luaL_Reg | ; \
		 s|luaL_register(L, NULL, \(.*\));|luaL_setfuncs(L, \1, 0);|' \
		${WRKSRC_libmpack_lua}/lmpack.c

post-patch-NLS-off:
	@${REINPLACE_CMD} -e '/add_subdirectory(po)/d' ${WRKSRC}/src/nvim/CMakeLists.txt

pre-build:
	${LN} -s ${WRKSRC_libmpack} ${WRKSRC_libmpack_lua}/mpack-src
	@${MKDIR} ${BUILD_WRKSRC}/src/nvim
	(cd ${WRKSRC_libmpack_lua} && ${CC} ${CFLAGS} -fPIC \
		-I${LUA_INCDIR} -shared lmpack.c -o \
		${BUILD_WRKSRC}/src/nvim/mpack.so \
		${LUA_LIBDIR}/liblua-${LUA_VER}.so)
	${LN} -s ${BUILD_WRKSRC}/src/nvim/mpack.so ${BUILD_WRKSRC}/runtime/mpack.so

.include <bsd.port.mk>
