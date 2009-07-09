# New ports collection makefile for:   lua50-filename
# Date created:        17 April 2006
# Whom:                Andrew Turner <andrew+ports@fubar.geek.nz>
#
# $FreeBSD$
#

PORTNAME=	filename
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= philip
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTFILES=	filename.lua?rev=${PORTVERSION}
EXTRACT_ONLY=	#

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Filename-manipulating functions for Lua 5

USE_LUA?=	5.1
LUA_COMPS=	lua posix
.if ${USE_LUA} == 5.0
LUA_COMPS+=	compat51
.endif
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%LUA_MODSHAREDIR%%/filename.lua

post-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}/filename.lua

do-install:
	${INSTALL_DATA} ${WRKDIR}/filename.lua \
		${LUA_MODSHAREDIR}/${DISTFILES:C/\?.*$//}

.include <bsd.port.mk>
