# $FreeBSD$

PORTNAME=	argparse
PORTVERSION=	0.7.1
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Feature-rich command line parser for Lua

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	lua:module
NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	luarocks

PLIST_FILES=	${LUA_MODSHAREDIR}/argparse.lua

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/src/argparse.lua ${STAGEDIR}${LUA_MODSHAREDIR}

.include <bsd.port.mk>
