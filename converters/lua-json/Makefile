# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	json
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	converters
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JSON parser/creator for Lua

RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}lpeg>=0.8.1:devel/lua-lpeg@${LUA_FLAVOR}

MAKE_ARGS=	INSTALL_CMOD=${LUA_MODLIBDIR} INSTALL_LMOD=${LUA_MODSHAREDIR}
NO_ARCH=	yes
USES=		lua:run,module

GH_ACCOUNT=	harningt
GH_PROJECT=	lua${PORTNAME}
USE_GITHUB=	yes

.include <bsd.port.mk>
