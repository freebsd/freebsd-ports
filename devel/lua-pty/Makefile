# New ports collection makefile for:   lua50-pty
# Date created:        17 April 2006
# Whom:                Andrew Turner <andrew+ports@fubar.geek.nz>
#
# $FreeBSD$
#

PORTNAME=	pty
PORTVERSION=	1.25
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= philip
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTFILES=	pty.lua?rev=1.2 pty.c?rev=1.25

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Pty (pseudo-terminal) bindings for Lua 5

USE_LUA?=	5.1

.if ${USE_LUA} == 5.0
LUA_COMPS=	compat51 lua
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/devel/lua50-compat51:extract
COMPAT_SRC=	`(cd ${PORTSDIR}/devel/lua50-compat51 && ${MAKE} -V WRKSRC)`
MAKE_ENV=	COMPATDIR="${COMPAT_SRC}"
.endif

PLIST_FILES=	%%LUA_MODSHAREDIR%%/pty.lua \
		%%LUA_MODLIBDIR%%/lpty.so

do-extract:
	@${MKDIR} ${WRKSRC}
.for file in ${DISTFILES}
	@${CP} ${DISTDIR}/${file} ${WRKSRC}/${file:C/\?.*$//}
.endfor
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lpty.so ${LUA_MODLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/pty.lua ${LUA_MODSHAREDIR}

.include <bsd.port.mk>
