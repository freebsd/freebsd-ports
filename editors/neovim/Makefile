PORTNAME=	neovim
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	editors

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Next-generation Vim
WWW=		https://neovim.io/

LICENSE=	APACHE20

BUILD_DEPENDS=	gperf:devel/gperf \
		${LUA_REFMODLIBDIR}/bit.so:devel/lua-bitop@${LUA_FLAVOR} \
		${LUA_REFMODLIBDIR}/lpeg.so:devel/lua-lpeg@${LUA_FLAVOR}
LIB_DEPENDS=	libluv.so:devel/luv \
		libmsgpack-c.so:devel/msgpack-c \
		libtermkey.so:devel/libtermkey \
		libtree-sitter.so:devel/tree-sitter \
		libunibilium.so:devel/unibilium \
		libuv.so:devel/libuv \
		libvterm.so:devel/libvterm
RUN_DEPENDS=	${LUA_REFMODLIBDIR}/bit.so:devel/lua-bitop@${LUA_FLAVOR} \
		${LUA_REFMODLIBDIR}/lpeg.so:devel/lua-lpeg@${LUA_FLAVOR}

USES=		cmake cpe gettext iconv lua:51,build luajit \
		pathfix pkgconfig
USE_GITHUB=	yes
GH_TUPLE=	libmpack:libmpack:1.0.5:libmpack \
		libmpack:libmpack-lua:1.0.12:libmpack_lua

CMAKE_ARGS=	-DLUA_PRG:FILEPATH="${LUA_CMD}" \
		-DCMAKE_INSTALL_MANDIR:PATH="${PREFIX}/share/man" \
		-DDEPS_PREFIX:PATH="${LOCALBASE}" \
		-DCMAKE_LIBRARY_PATH:PATH="${LOCALBASE}/lib/lua/${LUA_VER}"
CFLAGS+=	-I${LOCALBASE}/include

DATADIR=	${PREFIX}/share/nvim
PORTSCOUT=	limit:^[0-9\.v]+$$
PORTDATA=	runtime

OPTIONS_DEFINE=	NLS PYNVIM
OPTIONS_SUB=	yes

PYNVIM_DESC=	Enable support for plugins written in python

NLS_CMAKE_BOOL=		ENABLE_LIBINTL

PYNVIM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pynvim>=0.3.0:editors/py-pynvim@${PY_FLAVOR}
PYNVIM_USES=		python:run

.include <bsd.port.mk>
