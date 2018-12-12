# Created by: Jov amutu@amutu.com
# $FreeBSD$

PORTNAME=	tds_fdw
PORTVERSION=	1.0.8
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PostgreSQL foreign data wrapper to connect to TDS databases

LICENSE=	PostgreSQL

LIB_DEPENDS=	libsybdb.so:databases/freetds

USES=		gmake pgsql:9.2+
LLD_UNSAFE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	tds-fdw

PLIST_FILES=	lib/postgresql/tds_fdw.so \
		share/doc/postgresql/extension/README.tds_fdw.md \
		share/postgresql/extension/tds_fdw--1.0.8.sql \
		share/postgresql/extension/tds_fdw.control

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/tds_fdw.so

.include <bsd.port.mk>
