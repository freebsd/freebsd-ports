# Created by: MAtthew Seaman
# $FreeBSD$

PORTNAME=	pglogical-output
PORTVERSION=	1.1.0
CATEGORIES=	databases
MASTER_SITES=	http://packages.2ndquadrant.com/pglogical/tarballs/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Logical replication system as a PostgreSQL extension

LICENSE=	PostgreSQL

USES=		gmake pgsql:9.4+ tar:bzip2
WANT_PGSQL=	server

MAKE_ARGS=	USE_PGXS=1

OPTIONS_DEFINE=	DOCS

DOCS_PORTDOCS=	*

# FFI
#TEST_DEPENDS=	pg_regress:databases/postgresql${PGSQL_VER_NODOT}-pg_regress
#TEST_TARGET=	do-test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pglogical_output.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/protocol.txt	${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/DESIGN.md		${STAGEDIR}${DOCSDIR}

#do-test:
#	${MAKE} ${MAKE_ARGS} installcheck

.include <bsd.port.mk>
