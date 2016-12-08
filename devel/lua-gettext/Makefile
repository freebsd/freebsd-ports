# Created by: Andrew Turner <andrew+ports@fubar.geek.nz>
# $FreeBSD$

PORTNAME=	gettext
PORTVERSION=	1.5
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://raw.githubusercontent.com/nuclewall/bsdinstaller/${COMMIT}/src/lib/lua/gettext/ \
		http://BSDforge.com/projects/source/devel/lua-gettext/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTFILES=	lua_gettext.c gettext.lua
DIST_SUBDIR=	lua-${PORTNAME}-${COMMIT}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Gettext binding for Lua 5

USES=		gettext lua:51

CVER=		1.15
LVER=		${PORTVERSION}
COMMIT=		8323bb9

PLIST_FILES=	%%LUA_MODSHAREDIR%%/gettext.lua \
		%%LUA_MODLIBDIR%%/lgettext.so
MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV+=	VPATH=${_DISTDIR}
NO_WRKSUBDIR=	yes

do-extract:
	# Bulding straight from ${_DISTDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	${INSTALL_DATA} ${_DISTDIR}/gettext.lua ${STAGEDIR}${LUA_MODSHAREDIR}
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lgettext.so ${STAGEDIR}${LUA_MODLIBDIR}

.include <bsd.port.mk>
