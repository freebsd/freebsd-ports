# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	pg_dirtyread
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read dead but unvacuumed tuples from a PostgreSQL relation

LICENSE=	BSD3CLAUSE

USES=		gmake pgsql:9.2+
LLD_UNSAFE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	ChristophBerg

WANT_PGSQL=	server

PLIST_FILES=	lib/postgresql/pg_dirtyread.so \
		share/postgresql/extension/pg_dirtyread--1.0.sql \
		share/postgresql/extension/pg_dirtyread--1.0--2.sql \
		share/postgresql/extension/pg_dirtyread--2.sql \
		share/postgresql/extension/pg_dirtyread.control

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pg_dirtyread.so

.include <bsd.port.mk>
