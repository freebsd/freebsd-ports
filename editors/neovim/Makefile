# Created by: Anton Tornqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	neovim
PORTVERSION=	0.1.4
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Next generation Vim

LICENSE=	APACHE20

BUILD_DEPENDS=	${LUA_MODLIBDIR}/bit.so:devel/lua-bitop \
		${LUA_MODLIBDIR}/lpeg.so:devel/lua-lpeg
LIB_DEPENDS=	libunibilium.so:devel/unibilium \
		libvterm.so:devel/libvterm \
		libtermkey.so:devel/libtermkey \
		libluajit-5.1.so:lang/luajit \
		libuv.so:devel/libuv \
		libmsgpack.so:devel/msgpack

USES=		cmake:outsource gettext iconv ninja lua:build pathfix pkgconfig
USE_GITHUB=	yes
GH_TUPLE=	tarruda:libmpack:1.0.2:libmpack

CMAKE_ARGS=	-DLUA_PRG:FILEPATH="${LUA_CMD}" \
		-DCMAKE_INSTALL_MANDIR:PATH="${MANPREFIX}/man" \
		-DDEPS_PREFIX:PATH="${LOCALBASE}"

post-patch:
	@${REINPLACE_CMD} -e \
		's|lua_objlen|lua_rawlen| ; \
		 s|luaL_reg |luaL_Reg | ; \
		 s|luaL_register(L, NULL, \(.*\));|luaL_setfuncs(L, \1, 0);|' \
		${WRKSRC_libmpack}/binding/lua/lmpack.c

pre-build:
	@${MKDIR} ${BUILD_WRKSRC}/src/nvim
	@(cd ${WRKSRC_libmpack}/binding/lua && ${CC} ${CFLAGS} -fPIC \
		-I${LUA_INCDIR} -shared lmpack.c -o \
		${BUILD_WRKSRC}/src/nvim/mpack.so \
		${LUA_LIBDIR}/liblua-${LUA_VER}.so)

.include <bsd.port.mk>
