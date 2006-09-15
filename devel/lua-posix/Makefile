# New ports collection makefile for:   lua50-posix
# Date created:        27 March 2006
# Whom:                Andrew Turner <andrew+ports@fubar.geek.nz>
#
# $FreeBSD$
#

PORTNAME=	posix
PORTVERSION=	5.0
CATEGORIES=	devel
MASTER_SITES=	http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/5.0/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTFILES=	lposix.tar.gz

MAINTAINER=	andrew+ports@fubar.geek.nz
COMMENT=	A POSIX layer for Lua

USE_LUA=	5.0
WRKSRC=		${WRKDIR}/posix

PLIST_FILES=	%%LUA_MODSHAREDIR%%/posix.lua \
		%%LUA_MODLIBDIR%%/lposix.so

do-install:
	@${INSTALL_DATA} ${WRKSRC}/posix.lua ${LUA_MODSHAREDIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/lposix.so ${LUA_MODLIBDIR}

.include <bsd.port.mk>
