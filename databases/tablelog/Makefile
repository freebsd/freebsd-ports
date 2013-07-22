# Created by: Robert Gogolok <gogo@cs.uni-sb.de>
# $FreeBSD$

PORTNAME=	tablelog
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1387/

MAINTAINER=	gogo@cs.uni-sb.de
COMMENT=	Logs changes on a table in PostgreSQL

WRKSRC=		${WRKDIR}/table_log-${DISTVERSION}

USES=		gmake
USE_PGSQL=	yes
WANT_PGSQL_VER=	91-
MAKE_ARGS=	USE_PGXS=1

PORTDOCS=	README.table_log table_log.sql

do-install:
	@${MKDIR} ${PREFIX}/lib/postgresql/
	@${INSTALL_PROGRAM} ${WRKSRC}/table_log.so ${PREFIX}/lib/postgresql/
	@${MKDIR} ${PREFIX}/share/postgresql/contrib/
	@${INSTALL_DATA} ${WRKSRC}/table_log_init.sql \
		${PREFIX}/share/postgresql/contrib/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
