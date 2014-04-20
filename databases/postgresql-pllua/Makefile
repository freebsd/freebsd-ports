# Created by: sunghyuk
# $FreeBSD$

PORTNAME=	pllua
PORTVERSION=	1.0
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/3481/
PKGNAMEPREFIX=	postgresql-

MAINTAINER=	sunghyuk@gmail.com
COMMENT=	PL/Lua procedural language for PostgreSQL database

USES=		gmake lua
USE_PGSQL=	yes
WANT_PGSQL_VER=	91-
INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKSRC}/pkg-message

MAKE_ARGS=	LUAINC=-I${LUA_INCDIR} \
		LUALIB="-L${LUA_LIBDIR} -llua-${LUA_VER}"

.include <bsd.port.mk>
