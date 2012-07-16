# New ports collection makefile for:	powerarchitect
# Date created:				05 Jun 2008
# Whom:					José García Juanino <jjuanino@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	powerarchitect
PORTVERSION=	1.0.6
CATEGORIES=	databases java
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	SQL-Power-Architect-generic-jdbc-${PORTVERSION}

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Data modeling and profiling tool

LICENSE=	GPLv3

OPTIONS_DEFINE=	ORACLE_JDBC MYSQL_JDBC PGSQL_JDBC

USE_JAVA=	yes

JAVA_VERSION=	1.5+

NO_BUILD=	yes

PROJECTHOST=	power-architect
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/architect-${PORTVERSION}
SUB_FILES=	${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MORACLE_JDBC}
RUN_DEPENDS+=	${JAVALIBDIR}/ojdbc-10.2.0.5.jar:${PORTSDIR}/databases/jdbc-oracle10g
.endif
.if ${PORT_OPTIONS:MMYSQL_JDBC}
RUN_DEPENDS+=	${JAVALIBDIR}/mysql-connector-java.jar:${PORTSDIR}/databases/mysql-connector-java
.endif
.if ${PORT_OPTIONS:MPGSQL_JDBC}
RUN_DEPENDS+=	${JAVALIBDIR}/postgresql.jar:${PORTSDIR}/databases/postgresql-jdbc
.endif

do-install:
	@${MKDIR} ${DATADIR}/jdbc
	@cd ${WRKSRC}/ && \
	    ${INSTALL_DATA} architect.jar ${DATADIR}/ && \
	    ${INSTALL_DATA} jdbc/sqlserver_2005.jar ${DATADIR}/jdbc/ && \
	    ${COPYTREE_SHARE} lib ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README.generic ${DOCSDIR}
.endif

.include <bsd.port.mk>
