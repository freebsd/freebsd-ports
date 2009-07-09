# New ports collection makefile for:   lua50-dfui
# Date created:        18 April 2006
# Whom:                Andrew Turner <andrew+ports@fubar.geek.nz>
#
# $FreeBSD$
#

PORTNAME=	dfui
PORTVERSION=	0.1.20050901
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	philip
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTNAME=	lua-dfui-0.1.20050901

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	DFUI binding for Lua 5.0.x

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/lua50-compat51:extract
LIB_DEPENDS=	dfui4.4:${PORTSDIR}/devel/libdfui

USE_BZIP2=	yes
USE_LUA=	5.0
LUA_COMPS=	compat51 posix
WRKSRC=		${WRKDIR}/lua-dfui-${PORTVERSION}

COMPAT_SRC=	`(cd ${PORTSDIR}/devel/lua50-compat51 && ${MAKE} -V WRKSRC)`
MAKE_ENV=	COMPAT="${COMPAT_SRC}"

PLIST_FILES=	%%LUA_MODLIBDIR%%/ldfui.so \
		%%LUA_MODSHAREDIR%%/dfui.lua

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ldfui.so ${LUA_MODLIBDIR}
	${INSTALL_DATA} ${WRKSRC}/dfui.lua ${LUA_MODSHAREDIR}

.include <bsd.port.mk>
