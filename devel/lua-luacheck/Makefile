# $FreeBSD$

PORTNAME=	luacheck
PORTVERSION=	0.25.g20200825
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Linter and static analyzer for lua files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LUA_REFMODSHAREDIR}/argparse.lua:devel/lua-argparse@${LUA_FLAVOR} \
		${LUA_REFMODLIBDIR}/lfs.so:devel/luafilesystem@${LUA_FLAVOR}

USES=		lua
NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	luarocks
GH_TAGNAME=	4e5774169fa

INSTALL_DIR=	${LUA_MODSHAREDIR}/luacheck

do-install:
	${MKDIR} ${STAGEDIR}${INSTALL_DIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/luacheck.lua ${STAGEDIR}${INSTALL_DIR}/bin
	(cd ${WRKSRC} && \
	    ${COPYTREE_SHARE} src ${STAGEDIR}${INSTALL_DIR}/)
	${INSTALL_SCRIPT} ${FILESDIR}/luacheck.in \
	    ${STAGEDIR}${PREFIX}/bin/luacheck
	${REINPLACE_CMD} -e "s,%%LUA_CMD%%,${LUA_CMD},g" \
	    -e "s,%%INSTALL_DIR%%,${INSTALL_DIR},g" \
		${STAGEDIR}${PREFIX}/bin/luacheck

.include <bsd.port.mk>
