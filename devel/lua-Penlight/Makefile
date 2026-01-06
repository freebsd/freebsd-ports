PORTNAME=	Penlight
DISTVERSION=	1.15.0
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	markj@FreeBSD.org
COMMENT=	Comprehensive set of libraries for Lua
WWW=		https://github.com/lunarmodules/Penlight

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}luafilesystem>=0:devel/luafilesystem@${LUA_FLAVOR}

USES=		lua:54,module

USE_GITHUB=	yes
GH_ACCOUNT=	lunarmodules

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}/pl
	${INSTALL_DATA} ${WRKSRC}/lua/pl/*.lua ${STAGEDIR}${LUA_MODSHAREDIR}/pl

.include <bsd.port.mk>
