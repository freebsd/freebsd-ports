# $FreeBSD$

PORTNAME=	luv
DISTVERSION=	1.30.1-1
CATEGORIES=	devel

MAINTAINER=	checo1705@secmail.pro
COMMENT=	libuv bindings for lua

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libuv.so:devel/libuv

USES=		cmake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	luvit keplerproject:compat
GH_PROJECT=	luv lua-compat-5.3:compat
GH_TAGNAME=	bc91f40:compat
GH_SUBDIR=	deps/lua-compat-5.3:compat

OPTIONS_DEFINE=		DOCS EXAMPLES LUAJIT
OPTIONS_DEFAULT_i386=	LUAJIT
OPTIONS_DEFAULT_amd64=	LUAJIT

LUAJIT_DESC=		Use LuaJIT (instead of just Lua)
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_CMAKE_ON=	-DWITH_LUA_ENGINE=LuaJIT
LUAJIT_USES_OFF=	lua
LUAJIT_CMAKE_OFF=	-DWITH_LUA_ENGINE=Lua

CMAKE_ON=	BUILD_SHARED_LIBS WITH_SHARED_LIBUV
CMAKE_OFF=	BUILD_MODULE
CMAKE_ARGS=	-DLUA_BUILD_TYPE=System \
		-DLUA_COMPAT53_DIR=deps/lua-compat-5.3

PLIST_FILES=	lib/libluv.so \
		lib/libluv.so.1 \
		lib/libluv.so.1.30.1 \
		libdata/pkgconfig/libluv.pc \
		include/luv/util.h \
		include/luv/luv.h \
		include/luv/lreq.h \
		include/luv/lhandle.h

PORTDOCS=	docs.md

PORTEXAMPLES=	*

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
