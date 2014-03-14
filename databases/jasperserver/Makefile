# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jasperserver
PORTVERSION=	5.5.0
CATEGORIES=	databases print java
MASTER_SITES=	http://downloads.sourceforge.net/project/jasperserver/JasperServer/JasperReports%20Server%20Community%20Edition%205.5.0/:source1 \
		SF/bsdsrc/:source2 \
		http://dev.quadras.co.id/archiva/repository/internal/org/codehaus/mojo/cobertura-maven-plugin/2.5-Jaspersoft/:source3
DISTFILES=	jasperreports-server-cp-${PORTVERSION}-src.zip:source1 \
		FreeBSD-jasperreports-server-cp-${PORTVERSION}-maven-repository.zip:source2 \
		cobertura-maven-plugin-2.5-Jaspersoft.jar:source3 \
		cobertura-maven-plugin-2.5-Jaspersoft.pom:source3
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	jasperreports-server-cp-${PORTVERSION}-src.zip \
		FreeBSD-jasperreports-server-cp-${PORTVERSION}-maven-repository.zip

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Open Source Java Reporting Library

LICENSE=	GPLv3 MIT APACHE20
LICENSE_COMB=	multi

BUILD_DEPENDS=	mvn:${PORTSDIR}/devel/maven2

SRCDIR=		${WRKDIR}/jasperreports-server-cp-${PORTVERSION}-src
PATCH_WRKSRC=	${SRCDIR}
WRKSRC=		${SRCDIR}/${PORTNAME}/buildomatic
WRKDIR=		${WRKDIRPREFIX}${.CURDIR}/work
SQLSRC=		${WRKSRC}/install_resources/sql
JS=		${SRCDIR}/${PORTNAME}
JSREPO=		${JS}-repo
JSUPDATE=	5.2.0-${PORTVERSION}

NO_WRKSUBDIR=	yes
USES=		zip
USE_JAVA=	yes

# use own DOS2UNIX in pre-patch, not the one from bsd.port.mk!
DOS2UNIX_REGEX=	.*(css|dtd|java|js|txt|wsdd|xml|xsl)$$

OPTIONS_DEFINE=	HEADLESS
HEADLESS_DESC=	Optimize for Headless Systems
OPTIONS_SINGLE=	AS DB
OPTIONS_SINGLE_AS=	TOMCAT6 TOMCAT7
OPTIONS_SINGLE_DB=	MYSQL PGSQL
OPTIONS_DEFAULT=	TOMCAT6 PGSQL

REPLACE_FILES=	${JS}/jasperserver-war/src/main/webappAdditions/WEB-INF/web.xml
REPLACE_LIST_TEMP=	${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/}

SUB_FILES=	pkg-message

SUB_LIST=	DATABASE=${DATABASE} \
		JSDB=${JSDB} \
		JSHOME=${JSHOME} \
		JSTIMEOUT=${JSTIMEOUT} \
		JSUPDATE=${JSUPDATE} \
		PORTNAME=${PORTNAME} \
		PORTSDIR=${PORTSDIR} \
		PORTVERSION=${PORTVERSION} \
		SRCDIR=${SRCDIR}

PLIST_SUB=	DATABASE=${DATABASE} \
		JDBCLOC=${JDBCLOC} \
		JSUPDATE=${JSUPDATE} \
		PORTNAME=${PORTNAME}

PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MHEADLESS}
JAVA_VERSION=	1.7
.else
JAVA_VERSION=	1.6
.endif

.if ${PORT_OPTIONS:MMYSQL}
BROKEN=	org.springframework.jdbc.UncategorizedSQLException \
	http://community.jaspersoft.com//questions/823526/jasperserver-src-distribution-550
WANT_MYSQL_VER=	55
DBUSER?=	root
DBPASS?=
DATABASE=	mysql
RUN_DEPENDS+=	${JAVAJARDIR}/mysql-connector-java.jar:${PORTSDIR}/databases/mysql-connector-java
BUILD_DEPENDS+=	${JAVAJARDIR}/mysql-connector-java.jar:${PORTSDIR}/databases/mysql-connector-java
PLIST_SUB+=	JDBC="mysql-connector-java.jar"
.endif

#use version 90, application is certified w/ pg90
.if ${PORT_OPTIONS:MPGSQL}
WANT_PGSQL_VER=	90+
JDBC=	postgresql-9.2-1002.jdbc4.jar
USE_PGSQL=	yes
DBUSER?=	pgsql
DBPASS?=	pgsql
DATABASE=	postgresql
PLIST_SUB+=	JDBC=${JDBC}
.endif

.if ${PORT_OPTIONS:MTOMCAT6}
VER=	6
.else
VER=	7
.endif

APPHOME?=	${LOCALBASE}/apache-tomcat-${VER}.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat${VER}
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat${VER}
APPTYPE=	tomcat${VER}
PLIST_SUB+=	APP_VERSION="apache-tomcat-${VER}.0"
JDBCLOC=	lib

DBHOST?=	localhost

APP_PROPERTIES=	${SRCDIR}/${PORTNAME}/buildomatic/default_master.properties
QTZ_PROPERTIES=	${SRCDIR}/${PORTNAME}/${PORTNAME}-war/target/${PORTNAME}/WEB-INF/js.quartz.properties

JSDB?=	jasperserver
JSPORT?=	8080
JSEXTRA?=
JSHOME?=	${APPHOME}/webapps/${PORTNAME}
JSMAILHOST?=	localhost
JSMAILUSER?=	admin
JSMAILPASS?=	password
JSMAILFROM?=	"admin@localhost"
JSMAILPROTO?=	smtp
JSMAILPORT?=	25
JSTIMEOUT?=	20

pre-fetch:
# show the update warning before we fetch ~400MB sources
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

# We can not use the USE_DOS2UNIX routine, since WRKDIR is redefined
# and we have to convert files in a directory above WRKSRC!
pre-patch:
	@${ECHO_MSG} "===>   Converting DOS text files to UNIX text files"
	@${FIND} -E ${SRCDIR} -type f -iregex '${DOS2UNIX_REGEX}' -print0 | \
		${XARGS} -0 ${SED} -i '' -e 's/$$//'

post-patch:
.for file in ${REPLACE_FILES}
	@${ECHO_MSG} -n ">> Customizing `basename ${file}`..."
	@${SED} ${REPLACE_LIST_TEMP} ${file} > ${WRKDIR}/`basename ${file}`
	@${ECHO_MSG} " [ DONE ]"
.endfor
	@${REINPLACE_CMD} -e 's|--DROP|-- DROP|' ${SQLSRC}/mysql/quartz.ddl

post-patch-script:
	@${ECHO_MSG} -n ">> Removing unneeded patched files..."
	@${FIND} ${WRKDIR} -type f \( -name '*.orig' \) -delete
	@${ECHO_MSG} " [ DONE ]"

pre-build: extract patch
	@${MKDIR} ${JSREPO}/org/codehaus/mojo/cobertura-maven-plugin/2.5-Jaspersoft
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/cobertura-* ${JSREPO}/org/codehaus/mojo/cobertura-maven-plugin/2.5-Jaspersoft

	@${ECHO} "appServerType = ${APPTYPE}" > ${APP_PROPERTIES}
	@${ECHO} "appServerDir = ${APPHOME}" >> ${APP_PROPERTIES}
	@${ECHO} "dbType = ${DATABASE}" >> ${APP_PROPERTIES}
	@${ECHO} "dbUsername = ${DBUSER}" >> ${APP_PROPERTIES}
	@${ECHO} "dbPassword = ${DBPASS}" >> ${APP_PROPERTIES}
	@${ECHO} "dbHost = ${DBHOST}" >> ${APP_PROPERTIES}
	@${ECHO} "js.dbName = ${JSDB}" >> ${APP_PROPERTIES}

	@( if [ -f ${LOCALBASE}/bin/mvn ] ; then \
		${ECHO} "maven = ${JAVASHAREDIR}/maven2/bin/mvn" >> ${APP_PROPERTIES} ; \
		else ${FALSE}; \
	fi )
.if ${PORT_OPTIONS:MMYSQL}
	@${ECHO} "maven.jdbc.groupId = mysql" >> ${APP_PROPERTIES}
	@${ECHO} "maven.jdbc.version = 5.1.17-bin" >> ${APP_PROPERTIES}
	@${ECHO} "maven.jdbc.artifactId = mysql-connector-java" >> ${APP_PROPERTIES}
.endif
	@${ECHO} "js-path = ${JS}" >> ${APP_PROPERTIES}
	@${ECHO} "js-pro-path = ${JS}" >> ${APP_PROPERTIES}
	@${ECHO} "maven.build.type = repo" >> ${APP_PROPERTIES}
	@${ECHO} "repo-path = ${JSREPO}" >> ${APP_PROPERTIES}
	@${ECHO} "maven-localrepo-path = ${WRKDIR}/repository" >> ${APP_PROPERTIES}
	@${ECHO} "SKIP_TEST_ARG=skipTests" >> ${APP_PROPERTIES}

.if ${PORT_OPTIONS:MMYSQL}
	@( if [ -f ${JAVAJARDIR}/mysql-connector-java.jar ] ; then \
		${LN} -sf ${JAVAJARDIR}/mysql-connector-java.jar ${SRCDIR}/${PORTNAME}/buildomatic/conf_source/db/mysql/jdbc/mysql-connector-java-5.1.17-bin.jar; \
	fi )
.endif

do-build:
# although log will show Downloading, maven is in offline mode and can't download
	${CP} ${APP_PROPERTIES} ${SRCDIR}/${PORTNAME}/buildomatic/sample_conf
	@( cd ${WRKSRC} && ./js-ant clean-config )
	@( cd ${WRKSRC} && ./js-ant gen-config )
	@( ${CP} ${WRKDIR}/web.xml ${JS}/jasperserver-war/src/main/webappAdditions/WEB-INF/web.xml )
.if ${PORT_OPTIONS:MMYSQL}
	@( cd ${WRKSRC} && ./js-ant add-jdbc-driver )
.endif
	@( cd ${WRKSRC} && ./js-ant build-ce )

.if empty(PORT_OPTIONS:MPGSQL)
	@${ECHO} "quartz.delegateClass=org.quartz.impl.jdbcjobstore.StdJDBCDelegate" > ${QTZ_PROPERTIES}
.else
	@${ECHO} "quartz.delegateClass=org.quartz.impl.jdbcjobstore.PostgreSQLDelegate" > ${QTZ_PROPERTIES}
.endif

	@${ECHO} "quartz.tablePrefix=QRTZ_" >> ${QTZ_PROPERTIES}
	@${ECHO} "quartz.extraSettings=${JSEXTRA}" >> ${QTZ_PROPERTIES}
	@${ECHO} "report.scheduler.web.deployment.uri=http://${DBHOST}:${JSPORT}/${JSDB}" >> ${QTZ_PROPERTIES}
	@${ECHO} "report.scheduler.mail.sender.host=${JSMAILHOST}" >> ${QTZ_PROPERTIES}
	@${ECHO} "report.scheduler.mail.sender.username=${JSMAILUSER}" >> ${QTZ_PROPERTIES}
	@${ECHO} "report.scheduler.mail.sender.password=${JSMAILPASS}" >> ${QTZ_PROPERTIES}
	@${ECHO} "report.scheduler.mail.sender.from=${JSMAILFROM}" >> ${QTZ_PROPERTIES}
	@${ECHO} "report.scheduler.mail.sender.protocol=${JSMAILPROTO}" >> ${QTZ_PROPERTIES}
	@${ECHO} "report.scheduler.mail.sender.port=${JSMAILPORT}" >> ${QTZ_PROPERTIES}

do-install:
	@( cd ${WRKSRC} && ./js-ant deploy-webapp-ce )
	@${INSTALL_DATA} ${FILESDIR}/jasperserverCreateDefaultSecurity-${DATABASE}.sql ${JSHOME}
	@( cd ${SQLSRC} && ${INSTALL_DATA} ${DATABASE}/js-create.ddl ${JSHOME} )
	@( cd ${SQLSRC} && ${INSTALL_DATA} ${DATABASE}/quartz.ddl ${JSHOME} )
	@( cd ${SQLSRC} && ${INSTALL_DATA} ${DATABASE}/upgrade-${DATABASE}-5.1.0-5.2.0-ce.sql ${JSHOME} )
	@( cd ${SQLSRC} && ${INSTALL_DATA} ${DATABASE}/upgrade-${DATABASE}-${JSUPDATE}-ce.sql ${JSHOME} )
	@${INSTALL} -m 440 ${QTZ_PROPERTIES} ${JSHOME}/WEB-INF/

#removed shipped driver from vendor
.if ${PORT_OPTIONS:MMYSQL}
	@${RM} ${APPHOME}/${JDBCLOC}/mysql-connector-java-5.1.17-bin.jar
	${LN} -s ${JAVAJARDIR}/mysql-connector-java.jar ${APPHOME}/${JDBCLOC}
	@${RM} ${APPHOME}/${JDBCLOC}/postgresql-9.2-1002.jdbc4.jar
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${SRCDIR}/JasperReports-Server-CP-Source-Build-Guide.pdf ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
