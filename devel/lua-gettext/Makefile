# Created by: Andrew Turner <andrew+ports@fubar.geek.nz>
# $FreeBSD$

PORTNAME=	gettext
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://raw.githubusercontent.com/nuclewall/bsdinstaller/master/src/lib/lua/gettext/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTFILES=	lua_gettext.c?rev=${CVER} gettext.lua?rev=${LVER}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gettext binding for Lua 5

USES=		gettext lua:51

CVER=		1.15
LVER=		${PORTVERSION}

PLIST_FILES=	%%LUA_MODSHAREDIR%%/gettext.lua \
		%%LUA_MODLIBDIR%%/lgettext.so

do-extract:
	${MKDIR} ${WRKSRC}
.for file in ${DISTFILES}
	${CP} ${DISTDIR}/${file} ${WRKSRC}/${file:C/\?.*$//}
.endfor
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/gettext.lua ${STAGEDIR}${LUA_MODSHAREDIR}
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lgettext.so ${STAGEDIR}${LUA_MODLIBDIR}

.include <bsd.port.mk>
