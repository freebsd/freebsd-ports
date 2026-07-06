PORTNAME=	json
PORTVERSION=	1.3.5
CATEGORIES=	converters
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON parser/creator for Lua
WWW=		https://github.com/harningt/luajson

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}lpeg>=0.8.1:devel/lua-lpeg@${LUA_FLAVOR}

USES=		lua:run,module

MAKE_ARGS=	INSTALL_CMOD=${LUA_MODLIBDIR} INSTALL_LMOD=${LUA_MODSHAREDIR}
NO_ARCH=	yes

GH_ACCOUNT=	harningt
GH_PROJECT=	luajson
USE_GITHUB=	yes

.include <bsd.port.mk>
