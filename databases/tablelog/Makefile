# Created by: Robert Gogolok <gogo@cs.uni-sb.de>
# $FreeBSD$

PORTNAME=	tablelog
PORTVERSION=	0.4.4
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1387/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Logs changes on a table in PostgreSQL

LICENSE=	PostgreSQL

WRKSRC=		${WRKDIR}/table_log-${DISTVERSION}

USES=		gmake pgsql
LLD_UNSAFE=	yes
MAKE_ARGS=	USE_PGXS=1

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/postgresql/
	${INSTALL_LIB} ${WRKSRC}/table_log.so \
		${STAGEDIR}${PREFIX}/lib/postgresql/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/postgresql/contrib/
	${INSTALL_DATA} ${WRKSRC}/table_log_init.sql \
		${STAGEDIR}${PREFIX}/share/postgresql/contrib/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC} && ${INSTALL_DATA} README.table_log table_log.sql \
		${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
