# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	jasperreports
PORTVERSION=	5.5.2
PORTREVISION=	1
CATEGORIES=	databases print java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/JasperReports%20${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}.jar ${PORTNAME}-applet-${PORTVERSION}.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JasperReports is a powerful open source Java reporting tool

RUN_DEPENDS=	${JAVALIBDIR}/itext.jar:devel/itext			\
		${JAVALIBDIR}/xalan.jar:textproc/xalan-j		\
		${JAVALIBDIR}/crimson.jar:textproc/crimson		\
		${JAVALIBDIR}/poi.jar:textproc/apache-poi		\
		${JAVALIBDIR}/jfreechart.jar:java/jfreechart	\
		${LOCALBASE}/share/java/batik/lib/batik-all.jar:graphics/batik	\
		${JAVALIBDIR}/commons-beanutils.jar:java/jakarta-commons-beanutils\
		${JAVALIBDIR}/commons-digester.jar:textproc/apache-commons-digester

OPTIONS_DEFINE=	MYSQL PGSQL HSQLDB
OPTIONS_DEFAULT=MYSQL PGSQL

HSQLDB_DESC=	Install libraries required for HSQLDB

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.

LICENSE=	LGPL3

PLIST_FILES=	${DISTFILES:S|^|%%JAVAJARDIR%%/|:S|-${PORTVERSION}||}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${JAVALIBDIR}/mysql-connector-java.jar:databases/mysql-connector-java
.else
RUN_DEPENDS+=	${JAVALIBDIR}/log4j.jar:devel/log4j
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${JAVALIBDIR}/postgresql.jar:databases/postgresql-jdbc
.endif

.if ${PORT_OPTIONS:MHSQLDB}
RUN_DEPENDS+=	${JAVALIBDIR}/hsqldb.jar:databases/hsqldb
.endif

post-extract:
.for jf in ${DISTFILES}
	${MV} ${WRKDIR}/${jf} ${WRKDIR}/${jf:S|-${PORTVERSION}||}
.endfor

do-install:
	${INSTALL_DATA} ${DISTFILES:S|^|${WRKDIR}/|:S|-${PORTVERSION}||}	\
		${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
