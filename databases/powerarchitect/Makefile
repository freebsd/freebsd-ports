# New ports collection makefile for:	powerarchitect
# Date created:				05 Jun 2008
# Whom:					José García Juanino <jjuanino@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	powerarchitect
PORTVERSION=	0.9.11
CATEGORIES=	databases java
MASTER_SITES=	http://power-architect.googlecode.com/files/ \
    		http://freshmeat.net/redir/powerarchitect/67980/url_tgz/
DISTNAME=	Architect-generic-jdbc-${PORTVERSION}

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Data modeling and profiling tool

OPTIONS=	ORACLE_JDBC "Enable JDBC connection to Oracle databases" off \
		MYSQL_JDBC "Enable JDBC connection to MySQL databases" off \
		PGSQL_JDBC "Enable JDBC connection to PostgreSQL databases" off

USE_JAVA=	yes

JAVA_VERSION=	1.5+

NO_BUILD=	yes

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKSRC=		${WRKDIR}/architect-${PORTVERSION}
SUB_FILES=	${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_ORACLE_JDBC)
RUN_DEPENDS+=	${JAVALIBDIR}/ojdbc14.jar:${PORTSDIR}/databases/jdbc-oracle9i
.endif
.if defined(WITH_MYSQL_JDBC)
RUN_DEPENDS+=	${JAVALIBDIR}/mysql-connector-java.jar:${PORTSDIR}/databases/mysql-connector-java
.endif
.if defined(WITH_PGSQL_JDBC)
RUN_DEPENDS+=	${JAVALIBDIR}/postgresql.jar:${PORTSDIR}/databases/postgresql-jdbc
.endif

do-install:
	@${MKDIR} ${DATADIR}/jdbc
	@cd ${WRKSRC}/ && \
	    ${INSTALL_DATA} architect.jar ${DATADIR}/ && \
	    ${INSTALL_DATA} jdbc/sqlserver_2005.jar ${DATADIR}/jdbc/ && \
	    ${COPYTREE_SHARE} lib ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README.generic ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
