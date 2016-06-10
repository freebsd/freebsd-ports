# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	pglogical
PORTVERSION=	1.1.2
CATEGORIES=	databases
MASTER_SITES=	http://packages.2ndquadrant.com/pglogical/tarballs/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Logical replication system as a PostgreSQL extension

LICENSE=	PostgreSQL

BUILD_DEPENDS=	${LOCALBASE}/lib/postgresql/pglogical_output.so:databases/pglogical-output
RUN_DEPENDS=	${LOCALBASE}/lib/postgresql/pglogical_output.so:databases/pglogical-output

USES=		gmake pgsql:9.4+ tar:bzip2
WANT_PGSQL=	client server

MAKE_ARGS=	USE_PGXS=1

OPTIONS_DEFINE=	DOCS

DOCS_PORTDOCS=	*

# FFI
#TEST_DEPENDS=	pg_regress:databases/postgresql${PGSQL_VER_NODOT}-pg_regress
#TEST_TARGET=	do-test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pglogical_create_subscriber
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pglogical.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

#do-test:
#	${MAKE} ${MAKE_ARGS} check

.include <bsd.port.mk>
