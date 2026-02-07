PORTNAME=	pgvector
PORTVERSION=	0.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	tz@FreeBSD.org
COMMENT=	PostgreSQL extension for vector similarity search

LICENSE=	PostgreSQL

NOT_FOR_ARCHS=		i386

USES=		gmake pgsql
WANT_PGSQL=	server

USE_GITHUB=	yes
GH_ACCOUNT=	pgvector
GH_PROJECT=	pgvector

MAKE_ARGS=	OPTFLAGS=""
MAKE_ENV=	USE_PGXS=1

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/vector.so

.include <bsd.port.mk>
