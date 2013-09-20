# Created by: Andrew Turner <andrew+ports@fubar.geek.nz>
# $FreeBSD$

PORTNAME=	posix
PORTVERSION=	5.0
CATEGORIES=	devel
MASTER_SITES=	http://www.tecgraf.puc-rio.br/~lhf/ftp/lua/5.0/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTFILES=	lposix.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A POSIX layer for Lua

USE_LUA?=	5.1
WRKSRC=		${WRKDIR}/posix

PLIST_FILES=	%%LUA_MODSHAREDIR%%/posix.lua \
		%%LUA_MODLIBDIR%%/lposix.so

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${USE_LUA} == 5.1
EXTRA_PATCHES=	${FILESDIR}/extrapatch-51-lposix.c \
		${FILESDIR}/extrapatch-51-posix.lua \
		${FILESDIR}/extrapatch-51-test.lua
.elif ${USE_LUA} == 5.0
EXTRA_PATCHES=	${FILESDIR}/extrapatch-50-Makefile
.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif
.endif

do-install:
	@${INSTALL_DATA} ${WRKSRC}/posix.lua ${LUA_MODSHAREDIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/lposix.so ${LUA_MODLIBDIR}

.include <bsd.port.post.mk>
