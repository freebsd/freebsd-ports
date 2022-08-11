PORTNAME=	stdlib
PORTVERSION=	41.2.2
DISTVERSIONPREFIX=	release-v
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Standard Lua Libraries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LUA_PKGNAMEPREFIX}stdlib-debug>=0:devel/lua-stdlib-debug@${LUA_FLAVOR} \
		${LUA_PKGNAMEPREFIX}stdlib-normalize>=2.0:devel/lua-stdlib-normalize@${LUA_FLAVOR}

USES=		lua:module

CONFIGURE_ARGS=	--docdir=${DOCSDIR} LUA=${LUA_CMD}
GNU_CONFIGURE=	yes
NO_ARCH=	yes

GH_ACCOUNT=	lua-stdlib
GH_PROJECT=	lua-stdlib
USE_GITHUB=	yes

DOCSDIR=	${LUA_DOCSDIR}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
