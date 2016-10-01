# Created by: sunghyuk
# $FreeBSD$

PORTNAME=	pllua
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/3481/
PKGNAMEPREFIX=	postgresql-

MAINTAINER=	sunghyuk@gmail.com
COMMENT=	PL/Lua procedural language for PostgreSQL database

LICENSE=	MIT

DEPRECATED=	Depends on expired PostgreSQL 9.1
EXPIRATION_DATE=	2016-10-08

USES=		gmake lua pgsql:9.1-
INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKSRC}/pkg-message

MAKE_ARGS=	LUAINC=-I${LUA_INCDIR} \
		LUALIB="-L${LUA_LIBDIR} -llua-${LUA_VER}"

.include <bsd.port.mk>
