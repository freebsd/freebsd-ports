# $FreeBSD$

PORTNAME=	lgi
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	lua@FreeBSD.org
COMMENT=	Lua bindings to libraries using GObject-Introspection

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	pavouk
GH_COMMIT=	efa920a
GH_TAGNAME=	0.7.2

USES=		gmake lua pkgconfig
MAKE_ARGS+=	PREFIX=${PREFIX} LUA_LIBDIR=${LUA_MODLIBDIR} \
		LUA_INCDIR=${LUA_INCDIR} LUA_VERSION=${LUA_VER} \
		CORE=corelgilua${LUA_VER_STR}.so
MAKE_ENV+=	LUA_CFLAGS=-I${LUA_INCDIR}

post-patch:
	@${REINPLACE_CMD} -e 's/51/${LUA_VER_STR}/g' \
		${WRKSRC}/lgi/core.c \
		${WRKSRC}/lgi/core.lua

.include <bsd.port.mk>
