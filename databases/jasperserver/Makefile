# New ports collection makefile for:	jasperserver
# Date created:				27 August 2010
# Whom:					Jason Helfman
#
# $FreeBSD$
#

PORTNAME=	jasperserver
PORTVERSION=	3.5.0
CATEGORIES=	databases print java
MASTER_SITES=	SF/${PORTNAME}/JasperServer/JasperServer%20${PORTVERSION}/:source1 \
		http://www.glenbarber.us/ports/databases/${PORTNAME}/:source2
DISTFILES=	${PORTNAME}-${PORTVERSION}-src.zip:source1 \
		${PORTNAME}-${PORTVERSION}-maven-repository.tar.gz:source2
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}-src.zip

MAINTAINER=	jhelfman@experts-exchange.com
COMMENT=	Open Source Java Reporting Library

BUILD_DEPENDS=	mvn:${PORTSDIR}/devel/maven2

LICENSE_COMB=	multi
LICENSE=	GPLv2 MIT ASL

SRCDIR=		${WRKDIR}/jasperserver-${PORTVERSION}-src
PATCH_WRKSRC=	${SRCDIR}
WRKSRC=		${WRKDIR}/jasperserver-${PORTVERSION}-src/${PORTNAME}/buildomatic
WRKDIR?=	${WRKDIRPREFIX}${.CURDIR}/work
SQLSRC=		${WRKDIR}/jasperserver-${PORTVERSION}-src/${PORTNAME}/scripts
JS=		${WRKDIR}/jasperserver-${PORTVERSION}-src/${PORTNAME}
JSREPO=		${JS}-repo
JSMAVENTAR=	${PORTNAME}-${PORTVERSION}-maven-repository.tar.gz

NO_WRKSUBDIR=	yes
USE_JAVA=	yes
JAVA_VENDOR?=	freebsd
JAVA_VERSION?=	1.6+
USE_ZIP=	yes
# use own DOS2UNIX in pre-patch, not the one from bsd.port.mk!
DOS2UNIX_REGEX=	.*(css|dtd|java|js|txt|wsdd|xml|xsl)$$

OPTIONS=	TOMCAT5 "Enable Tomcat 5.x support"	on \
		TOMCAT6 "Enable Tomcat 6.x support"	off

REPLACE_FILES=	${JS}/jasperserver-war/src/main/webappAdditions/WEB-INF/web.xml
REPLACE_LIST_TEMP=	${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/}

SUB_FILES=	pkg-message

SUB_LIST=	DATABASE=${DATABASE} \
		JSHOME=${JSHOME} \
		JSTIMEOUT=${JSTIMEOUT} \
		PORTNAME=${PORTNAME} \
		PORTSDIR=${PORTSDIR} \
		PORTVERSION=${PORTVERSION}

.include <bsd.port.options.mk>

# set a dummy user/passwd and the target database
# else the build will fail
# We need the native SQL client for several task after installation!
USE_MYSQL=	yes
MYNAME?=	root
MYPASS?=
DATABASE=	mysql
PLIST_SUB+=	JDBC="mysql-connector-java-5.1.5.jar" DATABASE=${DATABASE}

.if defined(WITH_TOMCAT5)
BUILD_DEPENDS+=	tomcat>=5.5.31:${PORTSDIR}/www/tomcat55
RUN_DEPENDS+=	tomcat>=5.5.31:${PORTSDIR}/www/tomcat55
APPHOME?=	${LOCALBASE}/tomcat5.5
JSHOME?=	${APPHOME}/webapps/${PORTNAME}
PLIST_SUB+=	APP_VERSION="tomcat5.5"
.endif

.if defined(WITH_TOMCAT6)
BUILD_DEPENDS+=	tomcat>=6.0.29:${PORTSDIR}/www/tomcat6
RUN_DEPENDS+=	tomcat>=6.0.29:${PORTSDIR}/www/tomcat6
APPHOME?=	${LOCALBASE}/apache-tomcat-6.0
JSHOME?=	${APPHOME}/webapps/${PORTNAME}
PLIST_SUB+=	APP_VERSION="apache-tomcat-6.0"
.endif

DBHOST?=	localhost

APP_PROPERTIES=	${SRCDIR}/${PORTNAME}/buildomatic/default_master.properties
JS_PROPERTIES=	${SRCDIR}/${PORTNAME}/buildomatic/js-build.properties
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
.endif

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
	@${LN} -fs ${WRKDIR}/.m2 ~/.m2 && ${TAR} -C ${WRKDIR} -xf ${DISTDIR}/${JSMAVENTAR};\

pre-build:
	@${ECHO} "appServerDir = ${APPHOME}" > ${APP_PROPERTIES}
	@${ECHO} "dbType = mysql" >> ${APP_PROPERTIES}
	@${ECHO} "dbUsername = ${MYNAME}" >> ${APP_PROPERTIES}
	@${ECHO} "dbPassword = ${MYPASS}" >> ${APP_PROPERTIES}
	@${ECHO} "dbHost = ${DBHOST}" >> ${APP_PROPERTIES}

	@( if [ -f ${LOCALBASE}/bin/mvn ] ; then \
		${ECHO} "maven = ${LOCALBASE}/bin/mvn" > ${JS_PROPERTIES} ; \
		else ${FALSE}; \
	fi )
	@${ECHO} "js-base-path = ${JS}" >> ${JS_PROPERTIES}
	@${ECHO} "repo-path = ${JSREPO}">> ${JS_PROPERTIES}
	@${CHMOD} 0755 ${SRCDIR}/${PORTNAME}/buildomatic/js-ant ${SRCDIR}/apache-ant/bin/ant

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
	@( cd ${SQLSRC} && ${INSTALL_DATA} ${DATABASE}/jasperserverCreate-${DATABASE}.ddl ${JSHOME} )
	@( cd ${SQLSRC} && ${INSTALL_DATA} ${DATABASE}/jasperserverCreateDefaultSecurity-${DATABASE}.sql ${JSHOME} )
	@${INSTALL} -m 640 ${MAIL_PROPERTIES} ${JSHOME}/WEB-INF/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
