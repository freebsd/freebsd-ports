# Created by: osa
# $FreeBSD$

PORTNAME=	redis-parser
DISTVERSION=	0.09rc7
CATEGORIES=	devel
MASTER_SITES=	https://github.com/agentzh/lua-redis-parser/tarball/master/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTNAME=	lua-${PORTNAME}-${DISTVERSION}-${GITVERSION}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Redis reply parser and request constructor library for Lua

BROKEN=		fails checksum because uses moving master branch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2014-04-18

USE_LUA?=	5.1
GITVERSION=	0-g32cee57
WRKSRC=		${WRKDIR}/agentzh-lua-redis-parser-${GITVERSION:S/^0-g//}

PLIST_FILES=	%%LUA_MODLIBDIR%%/redis/parser.so
PLIST_DIRS=	%%LUA_MODLIBDIR%%/redis

NO_STAGE=	yes
do-install:
	${MKDIR} ${LUA_MODLIBDIR}/redis
	${INSTALL_PROGRAM} ${WRKSRC}/parser.so ${LUA_MODLIBDIR}/redis

.include <bsd.port.mk>
