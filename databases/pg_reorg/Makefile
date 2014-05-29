# Created by: Alexander Pyhalov <alp@sfedu.ru>
# $FreeBSD$

PORTNAME=	pg_reorg
PORTVERSION=	1.1.10
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/3644/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PostgreSQL utility to reorganize tables

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

MAKE_ENV=	USE_PGXS=0
USES=		gmake pgsql uidfix
WANT_PGSQL=server

PLIST_FILES=	bin/pg_reorg lib/postgresql/pg_reorg.so

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/)

.include <bsd.port.pre.mk>

.if ${PGSQL_VER} >= 9.1
PLIST_FILES+=	share/postgresql/extension/pg_reorg--1.1.10.sql \
		share/postgresql/extension/pg_reorg.control \
		share/postgresql/extension/pg_reorg.sql \
		share/postgresql/extension/uninstall_pg_reorg.sql
.else
PLIST_FILES+=	share/postgresql/contrib/pg_reorg--1.1.8.sql \
		share/postgresql/contrib/pg_reorg.sql \
		share/postgresql/contrib/uninstall_pg_reorg.sql
.endif

.include <bsd.port.post.mk>
