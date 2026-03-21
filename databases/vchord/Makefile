PORTNAME=	vchord
PORTVERSION=	1.1.0
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	arcade@b1t.name
COMMENT=	PostgreSQL extension designed for scalable, high-performance, and disk-efficient vector similarity search.
WWW=		https://github.com/tensorchord/VectorChord

LICENSE=	AGPLv3 EPL
LICENSE_COMB=	multi

USES=		cargo gmake pgsql
WANT_PGSQL=	server

USE_GITHUB=	yes
GH_ACCOUNT=	tensorchord
GH_PROJECT=	VectorChord

CARGO_FEATURES=	pg${PGSQL_VER}

MAKE_ARGS=	OPTFLAGS=""
MAKE_ENV=	USE_PGXS=1
PG_CONFIG=	${PREFIX}/bin/pg_config
PG_VERSION=	${PGSQL_VER}

.export PG_CONFIG

do-build:
	${GMAKE} -C ${WRKSRC} build

do-install:
	${GMAKE} DESTDIR=${STAGEDIR} -C ${WRKSRC} install

.include <bsd.port.mk>
