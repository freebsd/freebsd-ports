PORTNAME=	neovim
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.5
CATEGORIES=	editors

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Next-generation Vim
WWW=		https://neovim.io/

LICENSE=	APACHE20

BUILD_DEPENDS=	gperf:devel/gperf \
		${LUA_MODLIBDIR}/bit.so:devel/lua-bitop@${LUA_FLAVOR} \
		${LUA_MODLIBDIR}/lpeg.so:devel/lua-lpeg@${LUA_FLAVOR}
LIB_DEPENDS=	libluv.so:devel/luv \
		libmsgpack-c.so:devel/msgpack-c \
		libtermkey.so:devel/libtermkey \
		libtree-sitter.so:devel/tree-sitter \
		libunibilium.so:devel/unibilium \
		libuv.so:devel/libuv \
		libvterm.so:devel/libvterm

USES=		cmake cpe gettext iconv lua:52,build luajit pathfix pkgconfig
USE_GITHUB=	yes
GH_TUPLE=	libmpack:libmpack:1.0.5:libmpack \
		libmpack:libmpack-lua:1.0.9:libmpack_lua
PORTSCOUT=	limit:^[0-9\.v]+$$

CMAKE_ARGS=	-DLUA_PRG:FILEPATH="${LUA_CMD}" \
		-DCMAKE_INSTALL_MANDIR:PATH="${MANPREFIX}/man" \
		-DDEPS_PREFIX:PATH="${LOCALBASE}"
CFLAGS+=	-I${LOCALBASE}/include

DATADIR=	${PREFIX}/share/nvim
PORTDATA=	runtime

OPTIONS_DEFINE=	NLS PYNVIM
OPTIONS_SUB=	yes

PYNVIM_DESC=	Enable support for plugins written in python

NLS_CMAKE_BOOL=		ENABLE_LIBINTL
PYNVIM_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pynvim>=0.3.0:editors/py-pynvim@${PY_FLAVOR}
PYNVIM_USES=		python:run

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
