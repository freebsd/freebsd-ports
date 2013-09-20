# Created by: osa
# $FreeBSD$

PORTNAME=	cjson
PORTVERSION=	2.1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.kyne.com.au/~mark/software/download/
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}
DISTNAME=	lua-cjson-${PORTVERSION}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Fast JSON parsing and encoding support for Lua

USE_LUA?=	5.1

PLIST_FILES=	%%LUA_MODLIBDIR%%/cjson.so

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} '16,18d; \
		21s|^\(LUA_INCLUDE.*\)\(PREFIX\)\(.*\)|\1LOCALBASE\3/lua51|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cjson.so ${LUA_MODLIBDIR}

.include <bsd.port.mk>
