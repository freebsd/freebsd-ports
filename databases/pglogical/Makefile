# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	pglogical
DISTVERSIONPREFIX=	REL
DISTVERSION=	2_2_1
PORTREVISION=	2
CATEGORIES=	databases

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Logical replication system as a PostgreSQL extension

LICENSE=	PostgreSQL

USES=		gettext-runtime gmake pgsql:9.4+

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

.if ${PGSQL_VER:M9.4}
PLIST_SUB+=	PGSQL94=""
.else
PLIST_SUB+=	PGSQL94="@comment "
.endif

.if ${PGSQL_VER} >= 11
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-pglogical__apply__spi.c
.endif

# FFI
#TEST_DEPENDS=	pg_regress:databases/postgresql${PGSQL_VER_NODOT}-pg_regress
#TEST_TARGET=	do-test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pglogical_create_subscriber
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pglogical.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pglogical_output.so
.if ${PGSQL_VER:M9.4}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pglogical_dump
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

#do-test:
#	${MAKE} ${MAKE_ARGS} check

.include <bsd.port.post.mk>
