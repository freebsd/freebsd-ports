# New ports collection makefile for:	jasperserver
# Date created:				27 August 2010
# Whom:					Jason Helfman
#
# $FreeBSD$
#

PORTNAME=	jasperserver
PORTVERSION=	4.0.0
CATEGORIES=	databases print java
MASTER_SITES=	SF/${PORTNAME}/JasperServer/JasperServer%20${PORTVERSION}/:source1
DISTFILES=	jasperreports-server-cp-${PORTVERSION}-src.zip:source1 \
		jasperreports-server-cp-${PORTVERSION}-maven-repository.zip:source1
EXTRACT_ONLY=	jasperreports-server-cp-${PORTVERSION}-src.zip

MAINTAINER=	jhelfman@experts-exchange.com
COMMENT=	Open Source Java Reporting Library

BUILD_DEPENDS=	mvn:${PORTSDIR}/devel/maven2

MANUAL_PACKAGE_BUILDING=	Requires ~360MB sources to download

LICENSE_COMB=	multi
LICENSE=	GPLv2 MIT ASL

SRCDIR=		${WRKDIR}/jasperreports-server-cp-${PORTVERSION}-src
PATCH_WRKSRC=	${SRCDIR}
WRKSRC=		${SRCDIR}/${PORTNAME}/buildomatic
WRKDIR=		${WRKDIRPREFIX}${.CURDIR}/work
SQLSRC=		${WRKSRC}/install_resources/sql
JS=		${SRCDIR}/${PORTNAME}
JSREPO=		${JS}-repo
JSMAVENARCH=	jasperreports-server-cp-${PORTVERSION}-maven-repository.zip

NO_WRKSUBDIR=	yes
USE_JAVA=	yes
JAVA_VENDOR?=	freebsd
JAVA_VERSION?=	1.6
USE_ZIP=	yes

# use own DOS2UNIX in pre-patch, not the one from bsd.port.mk!
DOS2UNIX_REGEX=	.*(css|dtd|java|js|txt|wsdd|xml|xsl)$$

OPTIONS=	TOMCAT5 "Enable Tomcat 5.x support"	on \
		TOMCAT6 "Enable Tomcat 6.x support"	off \
		MYSQL   "Enable Mysql 5.x support"	on \
		POSTGRESQL "Enable PostgreSQL 8.x support" off

REPLACE_FILES=	${JS}/jasperserver-war/src/main/webappAdditions/WEB-INF/web.xml
REPLACE_LIST_TEMP=	${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/}

SUB_FILES=	pkg-message

SUB_LIST=	DATABASE=${DATABASE} \
		JSHOME=${JSHOME} \
		JSTIMEOUT=${JSTIMEOUT} \
		PORTNAME=${PORTNAME} \
		PORTSDIR=${PORTSDIR} \
		PORTVERSION=${PORTVERSION} \
		SRCDIR=${SRCDIR}

PLIST_SUB=	DATABASE=${DATABASE} \
		JDBCLOC=${JDBCLOC} \
		PORTNAME=${PORTNAME}

.include <bsd.port.options.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
MYNAME?=	root
MYPASS?=
DATABASE=	mysql
PLIST_SUB+=	JDBC="mysql-connector-java-5.1.10.jar"
.endif

#use version 84, application is certified against this version
.if defined(WITH_POSTGRESQL)
USE_PGSQL=	yes
WANT_PGSQL_VER= 84
MYNAME?=	pgsql
MYPASS?=	pgsql
DATABASE=	postgresql
JDBC=		postgresql-8.4-702.jdbc4.jar
PLIST_SUB+=	JDBC=${JDBC}
MASTER_SITES+=	http://jdbc.postgresql.org/download/:source2
DISTFILES+=	postgresql-8.4-702.jdbc4.jar:source2
.endif

.if defined(WITH_TOMCAT5)
APPHOME?=	${LOCALBASE}/tomcat5.5
BUILD_DEPENDS+= ${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
RUN_DEPENDS+=   ${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat55
APPTYPE=	tomcat5
JSHOME?=	${APPHOME}/webapps/${PORTNAME}
PLIST_SUB+=	APP_VERSION="tomcat5.5"
JDBCLOC=	common/lib
.endif

.if defined(WITH_TOMCAT6)
APPHOME?=	${LOCALBASE}/apache-tomcat-6.0
BUILD_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	${APPHOME}/bin/bootstrap.jar:${PORTSDIR}/www/tomcat6
APPTYPE=	tomcat6
JSHOME?=	${APPHOME}/webapps/${PORTNAME}
PLIST_SUB+=	APP_VERSION="apache-tomcat-6.0"
JDBCLOC=	lib
.endif

DBHOST?=	localhost

APP_PROPERTIES=	${SRCDIR}/${PORTNAME}/buildomatic/default_master.properties
MAIL_PROPERTIES=${SRCDIR}/${PORTNAME}/buildomatic/build_conf/default/webapp/WEB-INF/js.quartz.properties

JSPORT?=	8080
JSEXTRA?=
JSMAILHOST?=	localhost
JSMAILUSER?=	admin
JSMAILPASS?=	password
JSMAILFROM?=	"admin@localhost"
JSMAILPROTO?=	smtp
JSMAILPORT?=	25
JSTIMEOUT?=	20

check-sanity:
.if ( defined(WITH_TOMCAT5) && defined(WITH_TOMCAT6) )
IGNORE=	you can only define one application server
.elif ( !defined(WITH_TOMCAT5) && !defined(WITH_TOMCAT6) )
IGNORE=	choose at least one application server
.elif ( defined(WITH_MYSQL) && defined(WITH_POSTGRESQL) )
IGNORE=	you can only define one database
.elif ( !defined(WITH_MYSQL) && !defined(WITH_POSTGRESQL) )
IGNORE=	choose at least one database
.endif

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
	@( if [ -f ${JS}/jasperserver-war/src/main/webappAdditions/WEB-INF/web.xml.orig ] ; then \
		${RM} ${JS}/jasperserver-war/src/main/webappAdditions/WEB-INF/web.xml.orig ; \
	else ${FALSE}; \
	fi )
.endfor

post-extract-script:
	@${LN} -fs ${WRKDIR}/.m2 ~/.m2 && ${UNZIP_CMD} -qq ${DISTDIR}/${JSMAVENARCH} -d ${WRKDIR}/.m2

pre-build:
	@${ECHO} "appServerType = ${APPTYPE}" > ${APP_PROPERTIES}
	@${ECHO} "appServerDir = ${APPHOME}" >> ${APP_PROPERTIES}
	@${ECHO} "dbType = ${DATABASE}" >> ${APP_PROPERTIES}
	@${ECHO} "dbUsername = ${MYNAME}" >> ${APP_PROPERTIES}
	@${ECHO} "dbPassword = ${MYPASS}" >> ${APP_PROPERTIES}
	@${ECHO} "dbHost = ${DBHOST}" >> ${APP_PROPERTIES}

	@( if [ -f ${LOCALBASE}/bin/mvn ] ; then \
		${ECHO} "maven = ${JAVASHAREDIR}/maven2/bin/mvn" >> ${APP_PROPERTIES} ; \
		else ${FALSE}; \
	fi )
	@${ECHO} "js-path = ${JS}" >> ${APP_PROPERTIES}
	@${ECHO} "js-pro-path = ${JS}" >> ${APP_PROPERTIES}
	@${ECHO} "js-repo-path = ${JSREPO}">> ${APP_PROPERTIES}

do-build:
	@( cd ${WRKSRC} && ./js-ant clean-config )
	@( cd ${WRKSRC} && ./js-ant gen-config )
	@( cd ${WRKSRC} && ./js-ant add-jdbc-driver )
	@( ${CP} ${WRKDIR}/web.xml ${JS}/jasperserver-war/src/main/webappAdditions/WEB-INF/web.xml )
	@( cd ${WRKSRC} && ./js-ant build-ce )

	@${ECHO} "quartz.delegateClass=org.quartz.impl.jdbcjobstore.StdJDBCDelegate" > ${MAIL_PROPERTIES}
	@${ECHO} "quartz.tablePrefix=QRTZ_" >> ${MAIL_PROPERTIES}
	@${ECHO} "quartz.extraSettings=${JSEXTRA}" >> ${MAIL_PROPERTIES}
	@${ECHO} "report.scheduler.web.deployment.uri=http://localhost:${JSPORT}/${PORTNAME}" >> ${MAIL_PROPERTIES}
	@${ECHO} "report.scheduler.mail.sender.host=${JSMAILHOST}" >> ${MAIL_PROPERTIES}
	@${ECHO} "report.scheduler.mail.sender.username=${JSMAILUSER}" >> ${MAIL_PROPERTIES}
	@${ECHO} "report.scheduler.mail.sender.password=${JSMAILPASS}" >> ${MAIL_PROPERTIES}
	@${ECHO} "report.scheduler.mail.sender.from=${JSMAILFROM}" >> ${MAIL_PROPERTIES}
	@${ECHO} "report.scheduler.mail.sender.protocol=${JSMAILPROTO}" >> ${MAIL_PROPERTIES}
	@${ECHO} "report.scheduler.mail.sender.port=${JSMAILPORT}" >> ${MAIL_PROPERTIES}

post-build:
	@if [ -L ~/.m2 ]; then ${RM} -f ~/.m2; fi

do-install:
	@( cd ${WRKSRC} && ./js-ant deploy-webapp-ce )
	@${INSTALL_DATA} ${FILESDIR}/jasperserverCreateDefaultSecurity-${DATABASE}.sql ${JSHOME}
	@( cd ${SQLSRC} && ${INSTALL_DATA} ${DATABASE}/js-create.ddl ${JSHOME} )
	@( cd ${SQLSRC} && ${INSTALL_DATA} ${DATABASE}/quartz.ddl ${JSHOME} )
	@${INSTALL} -m 440 ${MAIL_PROPERTIES} ${JSHOME}/WEB-INF/

.if ( defined(WITH_TOMCAT6) || defined(WITH_TOMCAT5) && !defined(WITH_MYSQL) )
	${INSTALL_DATA} ${DISTDIR}/${JDBC} ${APPHOME}/${JDBCLOC}
	@${RM} ${APPHOME}/${JDBCLOC}/postgresql-8.1-407.jdbc3.jar
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
