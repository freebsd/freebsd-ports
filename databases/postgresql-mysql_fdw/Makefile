# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	mysql_fdw
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PostgreSQL foreign data wrapper for MySQL

LICENSE=	PostgreSQL

USES=		gmake pgsql:9.3+ mysql
LLD_UNSAFE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	EnterpriseDB
GH_TAGNAME=	c14ee1d

MAKE_ENV=	USE_PGXS=1

WANT_PGSQL=	server

PLIST_FILES=	lib/postgresql/mysql_fdw.so \
		share/postgresql/extension/mysql_fdw--1.0.sql \
		share/postgresql/extension/mysql_fdw.control

do-patch:
	${SED} -i '.orig' 's/#if defined(__APPLE__)/& || defined(__FreeBSD__)/' ${WRKSRC}/mysql_fdw.c

.include <bsd.port.mk>
