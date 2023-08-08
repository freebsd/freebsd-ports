PORTNAME=	lgi
PORTVERSION=	0.9.2
PORTREVISION=	3
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/lgi-devs/lgi/commit/
PATCHFILES=	5cfd42c386d3adae6d211fbb4011179c3c141b04.diff:-p1

MAINTAINER=	andrew@tao11.riddles.org.uk
COMMENT=	Lua bindings to libraries using GObject-Introspection
WWW=		https://github.com/pavouk/lgi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libffi.so:devel/libffi

USES=		gmake gnome lua:-54,module pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	pavouk

USE_GNOME=	introspection:build,run

MAKE_ARGS=	PREFIX="${PREFIX}" LUA_LIBDIR="${LUA_MODLIBDIR}" \
		LUA_INCDIR="${LUA_INCDIR}" LUA_VERSION="${LUA_VER}" \
		CORE="corelgilua${LUA_VER_STR}.so" LUA="${LUA_CMD}"
MAKE_ENV=	LUA_CFLAGS="-I${LUA_INCDIR}"
TEST_TARGET=	check

post-patch:
	@${REINPLACE_CMD} -e 's/51/${LUA_VER_STR}/g' \
		${WRKSRC}/lgi/core.c \
		${WRKSRC}/lgi/core.lua

post-install:
	@${STRIP_CMD} ${STAGEDIR}${LUA_MODLIBDIR}/lgi/*.so

.include <bsd.port.mk>
