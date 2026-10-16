PORTNAME=	pgdog
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.61
CATEGORIES=	databases

MAINTAINER=	mahlon@martini.nu
COMMENT=	PostgreSQL connection pooler, load balancer and database sharder
WWW=		https://pgdog.dev/ \
		https://github.com/pgdogdev/pgdog/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo gmake llvm:build ssl
USE_GITHUB=	yes
GH_ACCOUNT=	pgdogdev
GH_TUPLE=	pganalyze:libpg_query:aa71ad962b654c1d608c687232c047e48dba6452:libpg_query
USE_RC_SUBR=	pgdog

CARGO_INSTALL=	no

RUSTFLAGS+=	--cfg tokio_unstable

USERS=		pgdog
GROUPS=		pgdog

PLIST_FILES=	bin/pgdog \
		"@dir(pgdog,pgdog,0755) ${ETCDIR_REL}" \
		"@sample(pgdog,pgdog,0644) ${ETCDIR_REL}/pgdog.toml.sample" \
		"@sample(pgdog,pgdog,0600) ${ETCDIR_REL}/users.toml.sample"

PORTDOCS=	*.md
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

post-extract:
	${RMDIR} ${WRKSRC_crate_pg_raw_parse}/libpg_query
	${CP} -R ${WRKSRC_libpg_query} ${WRKSRC_crate_pg_raw_parse}/libpg_query

do-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/pgdog ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/example.pgdog.toml ${STAGEDIR}${ETCDIR}/pgdog.toml.sample
	${INSTALL_DATA} ${WRKSRC}/example.users.toml ${STAGEDIR}${ETCDIR}/users.toml.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.md ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
