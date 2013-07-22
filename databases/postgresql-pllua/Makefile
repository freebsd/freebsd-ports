# Created by: sunghyuk
# $FreeBSD$

PORTNAME=	pllua
PORTVERSION=	0.3.2
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/2401/
PKGNAMEPREFIX=	postgresql-

MAINTAINER=	sunghyuk@gmail.com
COMMENT=	PL/Lua procedural language for PostgreSQL database

USES=		gmake
USE_PGSQL=	yes
WANT_PGSQL_VER=	91-
USE_LUA=	5.1+

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKSRC}/pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|%LUA_INC%|${LUA_INCDIR}|g' \
			-e 's|%LUA_LIB%|${LUA_LIBDIR}|g' \
			${WRKSRC}/Makefile
post-install:
	@${ECHO_MSG} ''
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ''

.include <bsd.port.mk>
