# $FreeBSD$

PORTNAME=	pgsql
PORTVERSION=	1.6.8
CATEGORIES=	databases
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	Lua binding for PostgreSQL

LICENSE=	BSD3CLAUSE

USES=		lua pgsql:9.5+
WANT_PGSQL=	client

USE_GITHUB=	yes
GH_ACCOUNT=	arcapos
GH_PROJECT=	luapgsql
GH_TAGNAME=	023992e

MAKE_ARGS=	LUA_VERSION=${LUA_VER}

PLIST_FILES=	${LUA_MODLIBDIR}/pgsql.so

do-install:
	${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}
	${INSTALL_LIB} ${WRKSRC}/libpgsql.so ${STAGEDIR}${LUA_MODLIBDIR}/pgsql.so

.include <bsd.port.mk>
