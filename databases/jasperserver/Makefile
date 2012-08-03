# New ports collection makefile for:	jasperserver
# Date created:				27 August 2010
# Whom:					Jason Helfman
#
# $FreeBSD$
#

PORTNAME=	jasperserver
PORTVERSION=	4.5.0
CATEGORIES=	databases print java
MASTER_SITES=	SF/${PORTNAME}/JasperServer/JasperServer%20${PORTVERSION}/:source1
DISTFILES=	jasperreports-server-${PORTVERSION}-src.zip:source1 \
		jasperreports-server-cp-${PORTVERSION}-maven-repository.zip:source1
EXTRACT_ONLY=	jasperreports-server-${PORTVERSION}-src.zip

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Open Source Java Reporting Library

LICENSE=	GPLv2 MIT AL2
LICENSE_COMB=	multi

BUILD_DEPENDS=	mvn:${PORTSDIR}/devel/maven2

MANUAL_PACKAGE_BUILD=	distfile exceeds pointyhat filesize limit

SRCDIR=		${WRKDIR}/jasperreports-server-${PORTVERSION}-src
PATCH_WRKSRC=	${SRCDIR}
WRKSRC=		${SRCDIR}/${PORTNAME}/buildomatic
WRKDIR=		${WRKDIRPREFIX}${.CURDIR}/work
SQLSRC=		${WRKSRC}/install_resources/sql
JS=		${SRCDIR}/${PORTNAME}
JSREPO=		${JS}-repo
JSMAVENARCH=	jasperreports-server-cp-${PORTVERSION}-maven-repository.zip
JSUPDATE=	4.2.1-4.5.0

NO_WRKSUBDIR=	yes
USE_JAVA=	yes
JAVA_VENDOR?=	freebsd
JAVA_VERSION=	1.6
USE_ZIP=	yes

# use own DOS2UNIX in pre-patch, not the one from bsd.port.mk!
DOS2UNIX_REGEX=	.*(css|dtd|java|js|txt|wsdd|xml|xsl)$$

OPTIONS_DEFINE=	XLS
XLS_DESC=	Alternative Patches for XLS Spreadsheets
OPTIONS_SINGLE=	AS DB
OPTIONS_SINGLE_AS=	TOMCAT5 TOMCAT6 TOMCAT7
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
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
WANT_PGSQL_VER=	90
JDBC=	postgresql-9.0-802.jdbc4.jar
DISTFILES+=	postgresql-9.0-802.jdbc4.jar:source2
USE_PGSQL=	yes
DBUSER?=	pgsql
DBPASS?=	pgsql
DATABASE=	postgresql
PLIST_SUB+=	JDBC=${JDBC}
MASTER_SITES+=	http://jdbc.postgresql.org/download/:source2
.endif

.if ${PORT_OPTIONS:MTOMCAT5}
APPHOME?=	${LOCALBASE}/tomcat5.5
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
APPTYPE=	tomcat5
PLIST_SUB+=	APP_VERSION="tomcat5.5"
JDBCLOC=	common/lib
.endif

.if ${PORT_OPTIONS:MTOMCAT6}
APPHOME?=	${LOCALBASE}/apache-tomcat-6.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
APPTYPE=	tomcat6
PLIST_SUB+=	APP_VERSION="apache-tomcat-6.0"
JDBCLOC=	lib
.endif

.if ${PORT_OPTIONS:MTOMCAT7}
APPHOME?=	${LOCALBASE}/apache-tomcat-7.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat7
APPTYPE=	tomcat7
PLIST_SUB+=	APP_VERSION="apache-tomcat-7.0"
JDBCLOC=	lib
.endif

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

pre-extract:
	@if [ -e ~/.m2 -o -L ~/.m2 ]; then \
		${ECHO} A maven repository exists in your home directory. Please remove ~/.m2; \
		${FALSE} ; \
	fi

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
.if ${PORT_OPTIONS:MXLS}
	@${ECHO} "Applying alternative patches for Xls."
	@cd ${PATCH_WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/alt-patch-jasperserver__common__shared-config__applicationContext.xml
	@cd ${PATCH_WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/alt-patch-jasperserver__jasperserver-war__src__main__webappAdditions__WEB-INF__classes__jasperreports.properties
.endif

post-patch-script:
	@${ECHO_MSG} -n ">> Removing unneeded patched files..."
	@${FIND} ${WRKDIR} -type f \( -name '*.orig' \) -delete
	@${ECHO_MSG} " [ DONE ]"

post-extract-script:
	@${LN} -fs ${WRKDIR}/.m2 ~/.m2 && ${UNZIP_CMD} -qq ${DISTDIR}/${JSMAVENARCH} -d ${WRKDIR}/.m2

pre-build:
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
	@${ECHO} "repo-path = ${JSREPO}" >> ${APP_PROPERTIES}

.if ${PORT_OPTIONS:MMYSQL}
	${LN} -s ${JAVAJARDIR}/mysql-connector-java.jar ${SRCDIR}/${PORTNAME}/buildomatic/conf_source/db/mysql/jdbc/mysql-connector-java-5.1.17-bin.jar
.endif

do-build:
	@( cd ${WRKSRC} && ./js-ant clean-config )
	@( cd ${WRKSRC} && ./js-ant gen-config )
	@( cd ${WRKSRC} && ./js-ant add-jdbc-driver )
	@( ${CP} ${WRKDIR}/web.xml ${JS}/jasperserver-war/src/main/webappAdditions/WEB-INF/web.xml )
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

post-build:
	@if [ -L ~/.m2 ]; then ${RM} -f ~/.m2; fi

do-install:
	@( cd ${WRKSRC} && ./js-ant deploy-webapp-ce )
	@${INSTALL_DATA} ${FILESDIR}/jasperserverCreateDefaultSecurity-${DATABASE}.sql ${JSHOME}
	@( cd ${SQLSRC} && ${INSTALL_DATA} ${DATABASE}/js-create.ddl ${JSHOME} )
	@( cd ${SQLSRC} && ${INSTALL_DATA} ${DATABASE}/quartz.ddl ${JSHOME} )
	@( cd ${SQLSRC} && ${INSTALL_DATA} ${DATABASE}/upgrade-${DATABASE}-${JSUPDATE}-ce.sql ${JSHOME} )
	@${INSTALL} -m 440 ${QTZ_PROPERTIES} ${JSHOME}/WEB-INF/

#removed shipped driver from vendor
.if empty(PORT_OPTIONS:MMYSQL)
	${INSTALL_DATA} ${DISTDIR}/${JDBC} ${APPHOME}/${JDBCLOC}
	@${RM} ${APPHOME}/${JDBCLOC}/postgresql-9.0-801.jdbc3.jar
.else
	${LN} -s ${JAVAJARDIR}/mysql-connector-java.jar ${APPHOME}/${JDBCLOC}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
