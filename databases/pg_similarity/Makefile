# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	pg_similarity
PORTVERSION=	20160917
PORTREVISION=	1
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	amutu@amutu.com
COMMENT=	Set of functions and operators for executing similarity queries

LICENSE=	BSD3CLAUSE

USES=		gmake pgsql:9.1+
USE_GITHUB=	yes
GH_ACCOUNT=	eulerto
GH_TAGNAME=	be1a8b0

MAKE_ENV=	USE_PGXS=1

WANT_PGSQL=	server

PLIST_FILES=	lib/postgresql/pg_similarity.so \
		share/postgresql/extension/pg_similarity--1.0.sql \
		share/postgresql/extension/pg_similarity--unpackaged--1.0.sql \
		share/postgresql/extension/pg_similarity.control \
		share/postgresql/extension/pg_similarity.sql

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pg_similarity.so

.include <bsd.port.mk>
