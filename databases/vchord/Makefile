PORTNAME=	vchord
DISTVERSION=	1.1.1
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	arcade@b1t.name
COMMENT=	PostgreSQL extension for vector similarity search
WWW=		https://github.com/tensorchord/VectorChord

LICENSE=	AGPLv3 EPL
LICENSE_COMB=	multi

# https://github.com/supervc-stack/VectorChord/issues/440
NOT_FOR_ARCHS=	armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	requires 64 bit CPU

USES=		cargo gmake pgsql
WANT_PGSQL=	server

USE_GITHUB=	yes
GH_ACCOUNT=	tensorchord
GH_PROJECT=	VectorChord

CARGO_FEATURES=	pg${PGSQL_VER}
CARGO_BUILD=	no
CARGO_INSTALL=	no

MAKE_ARGS=	OPTFLAGS=""
MAKE_ENV=	USE_PGXS=1 PG_CONFIG=${PG_CONFIG}
PG_CONFIG=	${LOCALBASE}/bin/pg_config
PG_VERSION=	${PGSQL_VER}

.include <bsd.port.mk>
