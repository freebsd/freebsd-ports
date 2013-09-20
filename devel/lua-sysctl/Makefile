# $FreeBSD$

PORTNAME=	lua-sysctl
PORTVERSION=	1.0
CATEGORIES=	devel

MAINTAINER=	lua@FreeBSD.org
COMMENT=	A small sysctl(3) interface for lua

USE_GITHUB=	yes
USES=		pkgconfig
USE_LUA=	yes
PLIST_FILES=	%%LUA_MODSHAREDIR%%/sysctl.lua \
		%%LUA_MODLIBDIR%%/sysctl/core.so
PLIST_DIRS=	%%LUA_MODLIBDIR%%/sysctl

GH_ACCOUNT=	kAworu
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	345dc69

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${LUA_MODLIBDIR}/sysctl
	${INSTALL_SCRIPT} ${WRKSRC}/sysctl.lua ${LUA_MODSHAREDIR}/sysctl.lua
	${INSTALL_SCRIPT} ${WRKSRC}/build/core.so ${LUA_MODLIBDIR}/sysctl/core.so

.include <bsd.port.post.mk>
