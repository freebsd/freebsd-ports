# Created by: Jose Garcia Juanino <jjuanino@gmail.com>
# $FreeBSD$

PORTNAME=	powerarchitect
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	databases java
MASTER_SITES=	http://download.sqlpower.ca/architect/1.0.8/community/
DISTNAME=	SQL-Power-Architect-generic-jdbc-${PORTVERSION}

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Data modeling and profiling tool

LICENSE=	GPLv3

USE_JAVA=	yes
NO_BUILD=	yes

PORTDOCS=	*
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/architect-${PORTVERSION}
SUB_FILES=	${PORTNAME}

OPTIONS_DEFINE=	DOCS MYSQL_JDBC PGSQL_JDBC

MYSQL_JDBC_RUN_DEPENDS=	${JAVALIBDIR}/mysql-connector-java.jar:databases/mysql-connector-java
PGSQL_JDBC_RUN_DEPENDS=	${JAVALIBDIR}/postgresql.jar:databases/postgresql-jdbc

do-install:
	@${MKDIR} ${STAGEDIR}/${DATADIR}/jdbc
	(cd ${WRKSRC}/ && \
	    ${INSTALL_DATA} architect.jar ${STAGEDIR}/${DATADIR}/ && \
	    ${INSTALL_DATA} jdbc/sqlserver_2005.jar ${STAGEDIR}/${DATADIR}/jdbc/ && \
	    ${COPYTREE_SHARE} lib ${STAGEDIR}/${DATADIR})
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.generic ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
