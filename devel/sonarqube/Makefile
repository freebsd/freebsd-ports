# Created by: Dusan Vejnovic <freebsd@dussan.org>
# $FreeBSD$

PORTNAME=	sonarqube
PORTVERSION=	6.2
CATEGORIES=	devel www java
MASTER_SITES=	http://sonarsource.bintray.com/Distribution/sonarqube/

MAINTAINER=	freebsd@dussan.org
COMMENT=	Platform for continuous inspection of code quality

BROKEN=		unfetchable

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbiconv.so:converters/iconv
RUN_DEPENDS=	javaservicewrapper:sysutils/javaservicewrapper

NO_ARCH=	yes
NO_BUILD=	yes

USE_RC_SUBR=	${PORTNAME}
USERS=		www
GROUPS=		www

USES=		cpe dos2unix zip
CPE_VENDOR=	sonarsource
DOS2UNIX_GLOB=	*.properties *.conf

USE_JAVA=	yes
JAVA_VERSION=	1.7+

SQ_FILE=	sonar.sh
SQ_HOME=	${PREFIX}/share/${PORTNAME}
SQ_DB_DIR=	/var/db/${PORTNAME}
SQ_LOG_DIR=	/var/log/${PORTNAME}
SQ_LOG_FILE=	${PORTNAME}.log
SQ_JSW=		${PREFIX}/lib/javaservicewrapper

SUB_LIST+=	SQ_DB_DIR=${SQ_DB_DIR} \
			SQ_GROUP=${GROUPS} \
			SQ_LOG_DIR=${SQ_LOG_DIR} \
			SQ_LOG_FILE=${SQ_LOG_FILE} \
			SQ_RC=${PORTNAME} \
			SQ_RUN=${SQ_HOME}/bin/freebsd/${SQ_FILE} \
			SQ_USER=${USERS}
PLIST_SUB+=	SQ_DB_DIR=${SQ_DB_DIR} \
			SQ_GROUP=${GROUPS} \
			SQ_HOME=${SQ_HOME} \
			SQ_LOG_DIR=${SQ_LOG_DIR} \
			SQ_USER=${USERS}

OPTIONS_RADIO=		SQL
OPTIONS_RADIO_SQL=	MYSQL PGSQL

MYSQL_USE=	mysql=yes
PGSQL_USES=	pgsql

post-patch:
	@${REINPLACE_CMD} -e 's|%%DIR%%|${SQ_HOME}|' \
		-e 's|%%LIB%%|${SQ_JSW}|' \
		-e 's|%%LOG%%|${SQ_LOG_DIR}/${SQ_LOG_FILE}|' \
		-e 's|%%LOGDIR%%|${SQ_LOG_DIR}|' \
		-e 's|%%DBDIR%%|${SQ_DB_DIR}|' \
		-e 's|%%WRAPPER_JAR%%|${SQ_JSW}/lib/wrapper.jar|' \
		${WRKSRC}/conf/wrapper.conf ${WRKSRC}/conf/sonar.properties

do-install:
	@${MKDIR} ${STAGEDIR}${SQ_HOME}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${SQ_HOME})
	@${MKDIR} ${STAGEDIR}${SQ_HOME}/bin/freebsd/lib
	@${CP} ${STAGEDIR}${SQ_HOME}/bin/linux-x86-64/${SQ_FILE} \
		${STAGEDIR}${SQ_HOME}/bin/freebsd
	@${REINPLACE_CMD} -e 's|#RUN_AS_USER=|RUN_AS_USER=${USERS}|' \
		-e 's|-p $$pid -o args|ww $$pid|' \
		-e 's|=\"./wrapper\"|=\"${SQ_JSW}/bin/wrapper\"|' \
		${STAGEDIR}${SQ_HOME}/bin/freebsd/${SQ_FILE}
	@${MV} -f ${STAGEDIR}${SQ_HOME}/bin/freebsd/${SQ_FILE} \
		${STAGEDIR}${SQ_HOME}/bin/freebsd/${SQ_FILE}.sample
	@${MV} -f ${STAGEDIR}${SQ_HOME}/conf/sonar.properties \
		${STAGEDIR}${SQ_HOME}/conf/sonar.properties.sample
	@${MV} -f ${STAGEDIR}${SQ_HOME}/conf/wrapper.conf \
	${STAGEDIR}${SQ_HOME}/conf/wrapper.conf.sample
	@${RM} -drf ${STAGEDIR}${SQ_HOME}/bin/linux-x86-32
	@${RM} -drf ${STAGEDIR}${SQ_HOME}/bin/linux-x86-64
	@${RM} -drf ${STAGEDIR}${SQ_HOME}/bin/macosx-universal-64
	@${RM} -drf ${STAGEDIR}${SQ_HOME}/bin/windows-x86-32
	@${RM} -drf ${STAGEDIR}${SQ_HOME}/bin/windows-x86-64

.include <bsd.port.mk>
