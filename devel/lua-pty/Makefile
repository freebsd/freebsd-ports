# Created by: Andrew Turner <andrew+ports@fubar.geek.nz>
# $FreeBSD$

PORTNAME=	pty
PORTVERSION=	1.25
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://files.luaforge.net/releases/compat/Compat-5.1/Compat-5.1release5/:compat
MASTER_SITE_SUBDIR= philip
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTFILES=	pty.lua?rev=1.2 pty.c?rev=1.25

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pty (pseudo-terminal) bindings for Lua 5

USE_LUA=	5.1

PLIST_FILES=	%%LUA_MODSHAREDIR%%/pty.lua \
		%%LUA_MODLIBDIR%%/lpty.so

do-extract:
	@${MKDIR} ${WRKSRC}
.for file in ${DISTFILES:C,:.*,,}
	@${CP} ${DISTDIR}/${file} ${WRKSRC}/${file:C/\?.*$//}
.endfor
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lpty.so ${STAGEDIR}${LUA_MODLIBDIR}
	@${MKDIR} ${STAGEDIR}${LUA_MODSHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/pty.lua ${STAGEDIR}${LUA_MODSHAREDIR}

.include <bsd.port.mk>
