# $FreeBSD$

PORTNAME=	luacheck
PORTVERSION=	0.21.2
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Linter and static analyzer for lua files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LUA_REFMODLIBDIR}/lfs.so:devel/luafilesystem@${LUA_FLAVOR}

USES=	lua
NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	mpeterv

INSTALL_DIR=	${LUA_MODSHAREDIR}/luacheck

do-install:
	(cd ${WRKSRC} && \
	    ${LUA_CMD} install.lua ${STAGEDIR}${INSTALL_DIR})
	@${RLN} ${STAGEDIR}${INSTALL_DIR}/bin/luacheck \
	    ${STAGEDIR}${PREFIX}/bin/luacheck
	@${RLN} ${STAGEDIR}${INSTALL_DIR}/bin/luacheck.lua \
	    ${STAGEDIR}${PREFIX}/bin/luacheck.lua

.include <bsd.port.mk>
