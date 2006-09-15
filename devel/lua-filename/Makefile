# New ports collection makefile for:   lua50-filename
# Date created:        17 April 2006
# Whom:                Andrew Turner <andrew+ports@fubar.geek.nz>
#
# $FreeBSD$
#

PORTNAME=	filename
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	http://cvs.bsdinstaller.org/cgi-bin/cvsweb.cgi/installer/src/lib/lua/filename/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTFILES=	filename.lua?rev=${PORTVERSION}
EXTRACT_ONLY=	#

MAINTAINER=	andrew+ports@fubar.geek.nz
COMMENT=	Filename-manipulating functions for Lua 5.0.x

USE_LUA=	5.0
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%LUA_MODSHAREDIR%%/filename.lua

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} \
		${LUA_MODSHAREDIR}/${DISTFILES:C/\?.*$//}

.include <bsd.port.mk>
