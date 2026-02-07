PORTNAME=	pglogical
DISTVERSIONPREFIX=	REL
DISTVERSION=	2_4_6
CATEGORIES=	databases

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Logical replication system as a PostgreSQL extension
WWW=		https://www.2ndquadrant.com/en/resources-old/pglogical/

LICENSE=	PostgreSQL

USES=		compiler:c11 cpe gettext-runtime gmake pgsql
CPE_VENDOR=	2ndquadrant

USE_GITHUB=	yes
GH_ACCOUNT=	2ndQuadrant
GH_PROJECT=	pglogical pglogical_dump:dump
GH_TAGNAME=	f66606d:dump
GH_SUBDIR=	pglogical_dump:dump

WANT_PGSQL=	client server
MAKE_ARGS=	USE_PGXS=1
LLD_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

DOCS_PORTDOCS=	*

.include <bsd.port.pre.mk>

# FFI
#TEST_DEPENDS=	pg_regress:databases/postgresql${PGSQL_VER_NODOT}-pg_regress
#TEST_TARGET=	do-test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pglogical_create_subscriber
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pglogical.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pglogical_output.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

#do-test:
#	${MAKE} ${MAKE_ARGS} check

.include <bsd.port.post.mk>
