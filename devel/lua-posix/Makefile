# Created by: Andrew Turner <andrew+ports@fubar.geek.nz>
# $FreeBSD$

PORTNAME=	posix
PORTVERSION=	31
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POSIX layer for Lua

LICENSE=	MIT

USES=		lua
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LUA_INCLUDE=-I${LUA_INCDIR} \
		LUA=${LOCALBASE}/bin/lua${LUA_VER_STR}

USE_GITHUB=	yes
GH_PROJECT=	luaposix
GH_ACCOUNT=	luaposix
GH_TAGNAME=	release-v31
GH_COMMIT=	30b4b1e

MAKE_ARGS=	POSIX_EXTRA_CFLAGS="" POSIX_EXTRA_LDFLAGS=""

PLIST_FILES=	%%LUA_MODSHAREDIR%%/curses.lua \
		%%LUA_MODLIBDIR%%/curses_c.so \
		%%LUA_MODSHAREDIR%%/posix.lua \
		%%LUA_MODLIBDIR%%/posix_c.so

PORTDOCS=	*

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/ext/posix/.libs/posix_c.so ${STAGEDIR}${LUA_MODLIBDIR}/
	${INSTALL_LIB} ${WRKSRC}/ext/curses/.libs/curses_c.so ${STAGEDIR}${LUA_MODLIBDIR}/
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/lib/curses.lua ${STAGEDIR}${LUA_MODSHAREDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/lib/posix.lua ${STAGEDIR}${LUA_MODSHAREDIR}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc ; ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
