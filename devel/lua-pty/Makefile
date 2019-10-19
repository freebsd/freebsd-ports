# Created by: Andrew Turner <andrew+ports@fubar.geek.nz>
# $FreeBSD$

PORTNAME=	pty
PORTVERSION=	1.25
CATEGORIES=	devel
MASTER_SITES=	https://raw.githubusercontent.com/nuclewall/bsdinstaller/${COMMIT}/src/lib/lua/pty/ \
		https://BSDforge.com/projects/source/devel/lua-pty/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTFILES=	pty.lua pty.c
DIST_SUBDIR=	lua-${PORTNAME}-${COMMIT}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Pty (pseudo-terminal) bindings for Lua 5

USES=		lua:51

COMMIT=		8323bb9
MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV=	VPATH=${_DISTDIR}
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%LUA_MODSHAREDIR%%/pty.lua \
		%%LUA_MODLIBDIR%%/lpty.so

do-extract:
	${CP} -p ${_DISTFILES:S|^|${_DISTDIR}/|} ${WRKSRC}/

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lpty.so ${STAGEDIR}${LUA_MODLIBDIR}
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/pty.lua ${STAGEDIR}${LUA_MODSHAREDIR}

.include <bsd.port.mk>
