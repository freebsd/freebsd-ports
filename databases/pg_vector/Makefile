PORTNAME=	pg_vector
DISTVERSION=	v0.5.1
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	tz@FreeBSD.org
COMMENT=	PostgreSQL extension for vector similarity search

LICENSE=	BSD2CLAUSE

USES=		gmake pgsql:11+
WANT_PGSQL=	server

USE_GITHUB=	yes
GH_ACCOUNT=	pgvector
GH_PROJECT=	pgvector

MAKE_ENV=	USE_PGXS=1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/vector.so

.include <bsd.port.mk>
