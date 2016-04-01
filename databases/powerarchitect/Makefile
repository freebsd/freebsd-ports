# Created by: José García Juanino <jjuanino@gmail.com>
# $FreeBSD$

PORTNAME=	powerarchitect
PORTVERSION=	1.0.7
CATEGORIES=	databases java
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	SQL-Power-Architect-generic-jdbc-${PORTVERSION}

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Data modeling and profiling tool

LICENSE=	GPLv3

OPTIONS_DEFINE=	ORACLE_JDBC MYSQL_JDBC PGSQL_JDBC

ORACLE_JDBC_RUN_DEPENDS=	${JAVALIBDIR}/ojdbc-10.2.0.5.jar:databases/jdbc-oracle10g
MYSQL_JDBC_RUN_DEPENDS=	${JAVALIBDIR}/mysql-connector-java.jar:databases/mysql-connector-java
PGSQL_JDBC_RUN_DEPENDS=	${JAVALIBDIR}/postgresql.jar:databases/postgresql-jdbc

USE_JAVA=	yes

JAVA_VERSION=	1.6+

NO_BUILD=	yes

PORTDOCS=	*
PROJECTHOST=	power-architect
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/architect-${PORTVERSION}
SUB_FILES=	${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}/${DATADIR}/jdbc
	(cd ${WRKSRC}/ && \
	    ${INSTALL_DATA} architect.jar ${STAGEDIR}/${DATADIR}/ && \
	    ${INSTALL_DATA} jdbc/sqlserver_2005.jar ${STAGEDIR}/${DATADIR}/jdbc/ && \
	    ${COPYTREE_SHARE} lib ${STAGEDIR}/${DATADIR})
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.generic ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
