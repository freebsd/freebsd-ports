# New ports collection makefile for:   lua50-gettext
# Date created:        31 May 2006
# Whom:                Andrew Turner <andrew+ports@fubar.geek.nz>
#
# $FreeBSD$
#

PORTNAME=	gettext
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= philip
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTFILES=	lua_gettext.c?rev=${CVER} gettext.lua?rev=${LVER}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gettext binding for Lua 5

USE_LUA?=	5.1
USE_GETTEXT=	yes

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
	${INSTALL_DATA} ${WRKSRC}/gettext.lua ${LUA_MODSHAREDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/lgettext.so ${LUA_MODLIBDIR}

.include <bsd.port.mk>
