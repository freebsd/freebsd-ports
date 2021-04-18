# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	json
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	converters
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON parser/creator for Lua

RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}lpeg>=0.8.1:devel/lua-lpeg@${LUA_FLAVOR}

USES=		lua:run,module

MAKE_ARGS=	INSTALL_CMOD=${LUA_MODLIBDIR} INSTALL_LMOD=${LUA_MODSHAREDIR}
NO_ARCH=	yes

GH_ACCOUNT=	harningt
GH_PROJECT=	luajson
USE_GITHUB=	yes

.include <bsd.port.mk>
