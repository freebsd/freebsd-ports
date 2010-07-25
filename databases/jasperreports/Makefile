# New ports collection makefile for:	jasperreports
# Date created:		20 May 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	jasperreports
PORTVERSION=	3.7.4
CATEGORIES=	databases print java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/JasperReports%20${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}.jar ${PORTNAME}-applet-${PORTVERSION}.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JasperReports is a powerful open source Java reporting tool

RUN_DEPENDS=	${JAVALIBDIR}/itext.jar:${PORTSDIR}/devel/itext			\
		${JAVALIBDIR}/xalan.jar:${PORTSDIR}/textproc/xalan-j		\
		${JAVALIBDIR}/crimson.jar:${PORTSDIR}/textproc/crimson		\
		${JAVALIBDIR}/poi.jar:${PORTSDIR}/textproc/jakarta-poi		\
		${JAVALIBDIR}/jfreechart.jar:${PORTSDIR}/java/jfreechart	\
		${JAVASHAREDIR}/batik/batik.jar:${PORTSDIR}/graphics/batik	\
		${JAVALIBDIR}/commons-beanutils.jar:${PORTSDIR}/java/jakarta-commons-beanutils\
		${JAVALIBDIR}/commons-digester.jar:${PORTSDIR}/textproc/jakarta-commons-digester

.if !defined(WITHOUT_MYSQL)
RUN_DEPENDS+=	${JAVALIBDIR}/mysql-connector-java.jar:${PORTSDIR}/databases/mysql-connector-java
.else
RUN_DEPENDS+=	${JAVALIBDIR}/log4j.jar:${PORTSDIR}/devel/log4j
.endif

.if !defined(WITHOUT_PGSQL)
RUN_DEPENDS+=	${JAVALIBDIR}/postgresql.jar:${PORTSDIR}/databases/postgresql-jdbc
.endif

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.

PLIST_FILES=	${DISTFILES:S|^|%%JAVAJARDIR%%/|:S|-${PORTVERSION}||}

.include <bsd.port.pre.mk>

.if exists(${JAVALIBDIR}/classes12.zip)
WITH_ORACLE8=	yes
.endif
.if defined(WITH_ORACLE8)
RUN_DEPENDS+=	${JAVALIBDIR}/classes12.zip:${PORTSDIR}/databases/jdbc-oracle8i
.endif

.if exists(${JAVALIBDIR}/ojdbc14.jar)
WITH_ORACLE9=	yes
.endif
.if defined(WITH_ORACLE9)
RUN_DEPENDS+=	${JAVALIBDIR}/ojdbc14.jar:${PORTSDIR}/databases/jdbc-oracle9i
.endif

.if exists(${JAVALIBDIR}/hsqldb.jar)
WITH_HSQLDB=	yes
.endif
.if defined(WITH_HSQLDB)
RUN_DEPENDS+=	${JAVALIBDIR}/hsqldb.jar:${PORTSDIR}/databases/hsqldb
.endif

pre-everything::
	@${ECHO_MSG} '*********************************************************'
	@${ECHO_MSG} '* You need at least one JDBC driver.                    *'
.if !defined(WITHOUT_MYSQL)
	@${ECHO_MSG} '* Define WITHOUT_MYSQL to remove MySQL support.         *'
.endif
.if !defined(WITHOUT_PGSQL)
	@${ECHO_MSG} '* Define WITHOUT_PGSQL to remove PostgreSQL support.    *'
.endif
.if !defined(WITH_ORACLE8)
	@${ECHO_MSG} '* Define WITH_ORACLE8 to add Oracle 8i support.         *'
.endif
.if !defined(WITH_ORACLE9)
	@${ECHO_MSG} '* Define WITH_ORACLE9 to add Oracle 9i support.         *'
.endif
.if !defined(WITH_HSQLDB)
	@${ECHO_MSG} '* Define WITH_HSQLDB to add HSQLDB support.            *'
.endif
	@${ECHO_MSG} '*********************************************************'

post-extract:
.for jf in ${DISTFILES}
	${MV} ${WRKDIR}/${jf} ${WRKDIR}/${jf:S|-${PORTVERSION}||}
.endfor

do-install:
	${INSTALL_DATA} ${DISTFILES:S|^|${WRKDIR}/|:S|-${PORTVERSION}||}	\
		${JAVAJARDIR}

.include <bsd.port.post.mk>
