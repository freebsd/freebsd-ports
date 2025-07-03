PORTNAME=	promscale
PORTVERSION=	0.8.0
PORTREVISION=	22
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Tables, types and functions supporting Promscale
WWW=		https://www.timescale.com/promscale

LICENSE=	PostgreSQL

ONLY_FOR_ARCHS=	aarch64 amd64

RUN_DEPENDS=	timescaledb>=2.9.1:databases/timescaledb
BUILD_DEPENDS=	bash>0:shells/bash

USES=		cargo gmake pgsql

USE_GITHUB=	yes
GH_ACCOUNT=	timescale
GH_PROJECT=	promscale_extension

WANT_PGSQL=	server

MAKE_ARGS+=	PG_CONFIG=${LOCALBASE}/bin/pg_config
MAKE_ENV+=	MAKE=gmake PATH=${PATH}:${WRKDIR}/.cargo/bin

.include "${.CURDIR}/crates.mk"

post-patch:
	${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/cargo-crates/pgx-pg-sys-*/build.rs

pre-build:
	${RLN} ${WRKSRC}/cargo-crates/cargo-pgx-0.6.1 ${WRKDIR}/pgx
	${SETENV} ${MAKE_ENV} cargo install --offline --path ${WRKDIR}/pgx cargo-pgx
	${MKDIR} ${WRKDIR}/.pgx
	${PRINTF} '[configs]\npg${PGSQL_VERSION}="${LOCALBASE}/bin/pg_config"\n' > ${WRKDIR}/.pgx/config.toml

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} package

do-install:
	cd ${WRKSRC}/target/release/promscale-pg${PGSQL_VER} && ${PAX} -rw . ${STAGEDIR}

.include <bsd.port.pre.mk>

.if ${PGSQL_VER} > 15
IGNORE=		Only supported up to pgsql 15
.endif

.include <bsd.port.post.mk>
