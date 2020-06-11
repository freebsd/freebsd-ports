# Created by: Anton Tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	neovim
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.3
CATEGORIES=	editors

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Next-generation Vim

LICENSE=	APACHE20

BUILD_DEPENDS=	gperf:devel/gperf \
		${LUA_MODLIBDIR}/bit.so:devel/lua-bitop@${LUA_FLAVOR} \
		${LUA_MODLIBDIR}/lpeg.so:devel/lua-lpeg@${LUA_FLAVOR}
LIB_DEPENDS=	libluv.so:devel/luv \
		libmsgpackc.so:devel/msgpack \
		libtermkey.so:devel/libtermkey \
		libunibilium.so:devel/unibilium \
		libuv.so:devel/libuv \
		libvterm.so:devel/libvterm
TEST_DEPENDS=	autoconf>=0:devel/autoconf \
		aclocal:devel/automake \
		gmake:devel/gmake \
		libtool:devel/libtool

USES=		cmake iconv pathfix pkgconfig
USE_GITHUB=	yes
GH_TUPLE=	libmpack:libmpack:1.0.5:libmpack \
		libmpack:libmpack-lua:1.0.7:libmpack_lua
PORTSCOUT=	limit:^[0-9\.v]+$$

CMAKE_ARGS=	-DLUA_PRG:FILEPATH="${LUA_CMD}" \
		-DCMAKE_INSTALL_MANDIR:PATH="${MANPREFIX}/man" \
		-DDEPS_PREFIX:PATH="${LOCALBASE}"

OPTIONS_DEFINE=	LUAJIT NLS PYNVIM
OPTIONS_DEFAULT=LUAJIT
OPTIONS_EXCLUDE_aarch64=LUAJIT
OPTIONS_EXCLUDE_mips64=	LUAJIT
OPTIONS_EXCLUDE_powerpc=LUAJIT
OPTIONS_EXCLUDE_powerpc64=	LUAJIT
OPTIONS_EXCLUDE_riscv=	LUAJIT
OPTIONS_EXCLUDE_sparc64=LUAJIT
OPTIONS_SUB=	yes

LUAJIT_DESC=	Use LuaJIT for faster Lua code
PYNVIM_DESC=	Enable support for plugins written in python

LUAJIT_CMAKE_OFF=	-DPREFER_LUA:BOOL="ON"
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_USES=		lua:build
LUAJIT_USES_OFF=	lua:52
NLS_CMAKE_BOOL=	ENABLE_LIBINTL
NLS_USES=	gettext
PYNVIM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pynvim>=0.3.0:editors/py-pynvim@${PY_FLAVOR}
PYNVIM_USES=		python:run

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
USES+=		compiler:gcc-c++11-lib
.endif

post-patch:
	${REINPLACE_CMD} -e \
		's|lua_objlen|lua_rawlen| ; \
		 s|luaL_reg |luaL_Reg | ; \
		 s|luaL_register(L, NULL, \(.*\));|luaL_setfuncs(L, \1, 0);|' \
		${WRKSRC_libmpack_lua}/lmpack.c

post-patch-NLS-off:
	${REINPLACE_CMD} -e '/add_subdirectory(po)/d' ${WRKSRC}/src/nvim/CMakeLists.txt

pre-build:
	${LN} -s ${WRKSRC_libmpack} ${WRKSRC_libmpack_lua}/mpack-src
	${MKDIR} ${BUILD_WRKSRC}/src/nvim
	(cd ${WRKSRC_libmpack_lua} && ${CC} ${CFLAGS} -fPIC \
		-I${LUA_INCDIR} -shared lmpack.c -o \
		${BUILD_WRKSRC}/src/nvim/mpack.so \
		${LUA_LIBDIR}/liblua-${LUA_VER}.so)
	${LN} -s ${BUILD_WRKSRC}/src/nvim/mpack.so ${BUILD_WRKSRC}/runtime/mpack.so

.include <bsd.port.mk>
