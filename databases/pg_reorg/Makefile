# Created by: Alexander Pyhalov <alp@sfedu.ru>
# $FreeBSD$

PORTNAME=	pg_reorg
PORTVERSION=	1.1.8
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/3395/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PostgreSQL utility to reorganize tables

LICENSE=	BSD

MAKE_ENV=	USE_PGXS=0
USES=		gmake pgsql

PLIST_FILES=	bin/pg_reorg \
		lib/postgresql/pg_reorg.so \
		share/postgresql/contrib/pg_reorg--1.1.8.sql \
		share/postgresql/contrib/pg_reorg.sql \
		share/postgresql/contrib/uninstall_pg_reorg.sql
PLIST_DIRSTRY=	share/postgresql/contrib
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/)

.include <bsd.port.mk>
