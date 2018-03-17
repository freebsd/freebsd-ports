# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stdlib
PORTVERSION=	41.2.1
DISTVERSIONPREFIX=	release-v
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Standard Lua Libraries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}stdlib-debug>=0:devel/lua-stdlib-debug \
		${LUA_PKGNAMEPREFIX}stdlib-normalize>=2.0:devel/lua-stdlib-normalize

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	LUA=${LUA_CMD}
GNU_CONFIGURE=	yes
NO_ARCH=	yes
USES=		lua

GH_ACCOUNT=	lua-stdlib
GH_PROJECT=	lua-stdlib
USE_GITHUB=	yes

.include <bsd.port.mk>
