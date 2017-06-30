# $FreeBSD$

PORTNAME=	pg_rman
PORTVERSION=	1.3.3
CATEGORIES=	databases

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Online backup and restore tool for PostgreSQL

LICENSE=	BSD3CLAUSE

BROKEN=		checksum and size mismatch

USES=		gettext-runtime gmake pgsql
USE_GITHUB=	yes
PG_TAG_VERSION=	${PGSQL_DEFAULT:S/./_/}
GH_TUPLE=	ossc-db:pg_rman:REL${PG_TAG_VERSION}_STABLE
WANT_PGSQL=	client server
WANT_PGSQL_VER=	91+
MAKE_ARGS=	USE_PGXS=1
PLIST_FILES=	bin/pg_rman

.include <bsd.port.mk>
