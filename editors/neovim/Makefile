PORTNAME=	neovim
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.2
PORTREVISION=	1
CATEGORIES=	editors

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Next-generation Vim
WWW=		https://neovim.io/

LICENSE=	APACHE20

BUILD_DEPENDS=	${LUA_REFMODLIBDIR}/bit.so:devel/lua-bitop@${LUA_FLAVOR} \
		${LUA_REFMODLIBDIR}/lpeg.so:devel/lua-lpeg@${LUA_FLAVOR}
LIB_DEPENDS=	libluv.so:devel/luv \
		libmsgpack-c.so:devel/msgpack-c \
		libtree-sitter.so:devel/tree-sitter \
		libunibilium.so:devel/unibilium \
		libutf8proc.so:textproc/utf8proc \
		libuv.so:devel/libuv \
		libvterm.so:devel/libvterm
RUN_DEPENDS=	${LUA_REFMODLIBDIR}/bit.so:devel/lua-bitop@${LUA_FLAVOR} \
		${LUA_REFMODLIBDIR}/lpeg.so:devel/lua-lpeg@${LUA_FLAVOR}
TEST_DEPENDS=	gmake:devel/gmake

USES=		cmake cpe gettext iconv lua:51,build luajit \
		pathfix pkgconfig

USE_GITHUB=	yes
GH_TUPLE=	tree-sitter:tree-sitter-c:v0.24.1:treesitter_c \
		tree-sitter-grammars:tree-sitter-lua:v0.4.0:treesitter_lua \
		tree-sitter-grammars:tree-sitter-markdown:v0.5.0:treesitter_markdown \
		tree-sitter-grammars:tree-sitter-query:v0.6.1:treesitter_query \
		tree-sitter-grammars:tree-sitter-vim:v0.6.0:treesitter_vim \
		neovim:tree-sitter-vimdoc:v4.0.0:treesitter_vimdoc

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

NLS_CMAKE_BOOL=		ENABLE_LIBINTL ENABLE_TRANSLATIONS

PYNVIM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pynvim>=0.3.0:editors/py-pynvim@${PY_FLAVOR}
PYNVIM_USES=		python:run

post-configure:
	${MKDIR} ${BUILD_WRKSRC}/.deps/build/src
	${MV} ${WRKSRC_treesitter_c} ${BUILD_WRKSRC}/.deps/build/src/treesitter_c
	${MV} ${WRKSRC_treesitter_lua} ${BUILD_WRKSRC}/.deps/build/src/treesitter_lua
	${MV} ${WRKSRC_treesitter_markdown} ${BUILD_WRKSRC}/.deps/build/src/treesitter_markdown
	${MV} ${WRKSRC_treesitter_query} ${BUILD_WRKSRC}/.deps/build/src/treesitter_query
	${MV} ${WRKSRC_treesitter_vim} ${BUILD_WRKSRC}/.deps/build/src/treesitter_vim
	${MV} ${WRKSRC_treesitter_vimdoc} ${BUILD_WRKSRC}/.deps/build/src/treesitter_vimdoc
	${MAKE_ENV} ${CMAKE_BIN} -S ${WRKSRC}/cmake.deps -B ${BUILD_WRKSRC}/.deps ${CMAKE_ARGS} \
		-DUSE_BUNDLED:BOOL=OFF -DUSE_BUNDLED_TS_PARSERS:BOOL=ON \
		-DUSE_EXISTING_SRC_DIR:BOOL=ON

post-build:
	${CMAKE_BIN} --build ${BUILD_WRKSRC}/.deps

post-stage:
	cd ${BUILD_WRKSRC}/.deps/usr/lib/nvim && ${COPYTREE_SHARE} parser ${STAGEDIR}${PREFIX}/lib/nvim
	${FIND} ${STAGEDIR}${PREFIX}/lib/nvim -name "*.so" -exec ${STRIP_CMD} {} +

do-test:
	${GMAKE} -C ${WRKSRC} test

.include <bsd.port.mk>
