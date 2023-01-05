PORTNAME=	promscale
PORTVERSION=	0.7.0
PORTREVISION=	3
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Tables, types and functions supporting Promscale
WWW=		https://www.timescale.com/promscale

LICENSE=	PostgreSQL

ONLY_FOR_ARCHS=	aarch64 amd64
BROKEN=		fails to build using Rust 1.65.0 or newer, PR 267851

RUN_DEPENDS=	timescaledb>0:databases/timescaledb
BUILD_DEPENDS=	bash>0:shells/bash

USES=		cargo gmake pgsql:12+

# Depends on an unpublished crate. Can't use cargo.mk to fetch it.
PGX_REV=	96ece243
DISTFILES+=	pgx-${PGX_REV}.tar.gz
SITES.pgx-${PGX_REV}.tar.gz+=	${MASTER_SITE_GITHUB:=timescale/}pgx/archive/${PGX_REV}.tar.gz

USE_GITHUB=	yes
GH_ACCOUNT=	timescale timescale:pgx
GH_PROJECT=	promscale_extension pgx:pgx
GH_TAGNAME=	${PORTVERSION} 96ece243:pgx

WANT_PGSQL=	server

MAKE_ARGS+=	PG_CONFIG=${LOCALBASE}/bin/pg_config
MAKE_ENV+=	MAKE=gmake PATH=${PATH}:${WRKDIR}/.cargo/bin

.include "${.CURDIR}/crates.mk"

post-extract:
	${MV} ${WRKDIR}/pgx-* ${WRKDIR}/pgx

pre-configure:
	@${PATCH} -d ${WRKDIR} ${PATCH_ARGS} < ${PATCHDIR}/pgx-include-patch
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKDIR}/pgx/pgx-pg-sys/build.rs

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} cargo install --offline --path ../pgx/cargo-pgx cargo-pgx
	${MKDIR} ${WRKDIR}/.pgx
	${PRINTF} '[configs]\npg${PGSQL_VERSION}="${LOCALBASE}/bin/pg_config"\n' > ${WRKDIR}/.pgx/config.toml

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} package

do-install:
	cd ${WRKSRC}/target/release/promscale-pg${PGSQL_VER} && ${PAX} -rw . ${STAGEDIR}

.include <bsd.port.mk>
