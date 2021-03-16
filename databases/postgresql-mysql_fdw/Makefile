# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	mysql_fdw
DISTVERSIONPREFIX=	REL-
DISTVERSION=	2_5_5
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	tz@FreeBSD.org
COMMENT=	PostgreSQL foreign data wrapper for MySQL

LICENSE=	PostgreSQL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake pgsql:9.6-13 mysql
WANT_PGSQL=	server
USE_GITHUB=	yes
GH_ACCOUNT=	EnterpriseDB

MAKE_ENV=	USE_PGXS=1

PLIST_FILES=	lib/postgresql/mysql_fdw.so \
		share/postgresql/extension/mysql_fdw--1.0--1.1.sql \
		share/postgresql/extension/mysql_fdw--1.0.sql \
		share/postgresql/extension/mysql_fdw--1.1.sql \
		share/postgresql/extension/mysql_fdw.control

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/mysql_fdw.so

.include <bsd.port.mk>
