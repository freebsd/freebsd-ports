# Created by: Andrew Turner <andrew+ports@fubar.geek.nz>
# $FreeBSD$

PORTNAME=	app
PORTVERSION=	1.72
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= philip
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTFILES=	app.lua?rev=${PORTVERSION}
EXTRACT_ONLY=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	App framework for Lua 5.0.x

USE_LUA=	5.0
LUA_COMPS=	filename posix pty
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%LUA_MODSHAREDIR%%/app.lua

NO_STAGE=	yes
do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} \
		${LUA_MODSHAREDIR}/${DISTFILES:C/\?.*$//}

.include <bsd.port.mk>
