# $FreeBSD$

PORTNAME=	sysctl
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	lua@FreeBSD.org
COMMENT=	Small sysctl(3) interface for lua

USE_GITHUB=	yes
USES=		pkgconfig lua
PLIST_FILES=	%%LUA_MODSHAREDIR%%/sysctl.lua \
		%%LUA_MODLIBDIR%%/sysctl/core.so
PLIST_DIRS=	%%LUA_MODLIBDIR%%/sysctl

GH_ACCOUNT=	kAworu
GH_PROJECT=	lua-${PORTNAME}
GH_COMMIT=	345dc69

post-patch:
	@${REINPLACE_CMD} -e "s/5.1/${LUA_VER}/g" ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}/sysctl \
		${STAGEDIR}${LUA_MODSHAREDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sysctl.lua ${STAGEDIR}${LUA_MODSHAREDIR}/sysctl.lua
	${INSTALL_SCRIPT} ${WRKSRC}/build/core.so ${STAGEDIR}${LUA_MODLIBDIR}/sysctl/core.so

.include <bsd.port.mk>
