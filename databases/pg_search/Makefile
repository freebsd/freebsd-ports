PORTNAME=	pg_search
PORTVERSION=	0.21.13
PORTREVISION=	0
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql${PGSQL_VER:S/.//}-
DISTFILES=	mecab-ipadic-2.7.0-20070801.tar.gz:lindera \
		mecab-ko-dic-2.1.1-20180720.tar.gz:lindera \
		unidic-mecab-2.1.2.tar.gz:lindera \
		mecab-ipadic-2.7.0-20250920.tar.gz:lindera \
		CC-CEDICT-MeCab-0.1.0-20200409.tar.gz:lindera
MASTER_SITES=	https://Lindera.dev/:lindera

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Simple, Elastic-Quality Search for Postgres
WWW=		https://www.paradedb.com/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cargo-pgrx>0:databases/cargo-pgrx

USES=		cargo gmake pgsql

USE_GITHUB=	yes
GH_ACCOUNT=	paradedb
GH_PROJECT=	paradedb
GH_TAGNAME=	v${PORTVERSION}

WANT_PGSQL=	server

LINDERA_VERSION=1.5.1
LINDERA_CACHE_PATH=${WRKDIR}/.lindera/
LINDERA_FILES:= ${DISTFILES:M*\:lindera}

MAKE_ARGS+=	PG_CONFIG=${LOCALBASE}/bin/pg_config
MAKE_ENV+=	MAKE=gmake \
		PATH=${PATH}:${WRKDIR}/.cargo/bin \
		PGRX_HOME=${WRKDIR}/.pgrx \
		LINDERA_CACHE=${LINDERA_CACHE_PATH}

.include "${.CURDIR}/Makefile.crates"

post-patch:
	${MKDIR} ${LINDERA_CACHE_PATH}/${LINDERA_VERSION}
.for file in ${LINDERA_FILES}
	${CP} ${DISTDIR}/${file:C/:lindera$//} ${LINDERA_CACHE_PATH}/${LINDERA_VERSION}/
.endfor

pre-build:
	${MKDIR} ${WRKDIR}/.pgrx
	${PRINTF} '[configs]\npg${PGSQL_VERSION}="${LOCALBASE}/bin/pg_config"\n' > ${WRKDIR}/.pgrx/config.toml

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} package

do-install:
	cd ${WRKSRC}/target/release/${PORTNAME}-pg${PGSQL_VER} && ${PAX} -rw . ${STAGEDIR}

.include <bsd.port.pre.mk>

.if ${PGSQL_VER} < 15
IGNORE=	Only supported on pgsql 15 and later
.endif

.include <bsd.port.post.mk>
