PORTNAME=	luv
#DISTVERSIONPREFIX=	v
DISTVERSION=	1.51.0-1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/luvit/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	libuv bindings for lua
WWW=		https://github.com/luvit/luv

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libuv.so:devel/libuv

USES=		cmake localbase luajit
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

CMAKE_ON=	BUILD_SHARED_LIBS WITH_SHARED_LIBUV
CMAKE_OFF=	BUILD_MODULE
CMAKE_ARGS=	-DLUA_BUILD_TYPE=System \
		-DLUA_COMPAT53_DIR=deps/lua-compat-5.3 \
		-DWITH_LUA_ENGINE=LuaJIT

PLIST_FILES=	lib/libluv.so \
		lib/libluv.so.1 \
		lib/libluv.so.1.51.0 \
		libdata/pkgconfig/libluv.pc \
		include/luv/util.h \
		include/luv/luv.h \
		include/luv/lreq.h \
		include/luv/lhandle.h

PORTDOCS=	docs.md

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
