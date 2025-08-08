PORTNAME=	wildfly
DISTVERSION=	37.0.0
CATEGORIES=	java www
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${WILDFLY_VERSION}/
DISTNAME=	wildfly-${WILDFLY_VERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Replacement for JBoss Application Server
WWW=		https://wildfly.org/

LICENSE=	GPLv2

USES=		java
JAVA_VERSION=	17+
USE_RC_SUBR=	wildfly

NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	APP_SHORTNAME=${PORTNAME} \
		LOG_DIR=${LOG_DIR} \
		USER=${USERS} \
		GROUP=${GROUPS} \
		PID_FILE=${PID_FILE} \
		APP_HOME=${PREFIX}/${PORTNAME}

USERS=		www
GROUPS=		www

PLIST_SUB=	APP_HOME=${PORTNAME}

VAR_DIR?=	/var
LOG_DIR?=	${VAR_DIR}/log/${PORTNAME}
PID_FILE=	${VAR_DIR}/run/${PORTNAME}.pid
WILDFLY_VERSION=${DISTVERSION}.Final

CONFIG_FILES=	appclient/configuration/appclient.xml \
		appclient/configuration/logging.properties \
		domain/configuration/application-roles.properties \
		domain/configuration/application-users.properties \
		domain/configuration/default-server-logging.properties \
		domain/configuration/domain.xml \
		domain/configuration/host-primary.xml \
		domain/configuration/host-secondary.xml \
		domain/configuration/host.xml \
		domain/configuration/logging.properties \
		domain/configuration/mgmt-groups.properties \
		domain/configuration/mgmt-users.properties \
		standalone/configuration/application-roles.properties \
		standalone/configuration/application-users.properties \
		standalone/configuration/logging.properties \
		standalone/configuration/mgmt-groups.properties \
		standalone/configuration/mgmt-users.properties \
		standalone/configuration/standalone-full-ha.xml \
		standalone/configuration/standalone-full.xml \
		standalone/configuration/standalone-ha.xml \
		standalone/configuration/standalone.xml

post-extract:
	${RM} ${WRKSRC}/bin/add-user.sh.orig
	${RM} ${WRKSRC}/bin/*.bat
	${RM} ${WRKSRC}/bin/*.ps1
	${RM} -r ${WRKSRC}/bin/service
	${RM} -r ${WRKSRC}/bin/init.d

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${PORTNAME})
	${RM} -rf ${STAGEDIR}${PREFIX}/${PORTNAME}/.installation
.for FILE in ${CONFIG_FILES}
	${MV} ${STAGEDIR}${PREFIX}/${PORTNAME}/${FILE} \
		${STAGEDIR}${PREFIX}/${PORTNAME}/${FILE}.sample
.endfor
	${FIND} -s ${STAGEDIR}${PREFIX}/${PORTNAME} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' | \
		${SED} -E -e '/sample$$/ s#^#@sample #' | \
		${SED} -E -e '/bin\/.*sh$$/ s#^#@(,,755) #'>> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PORTNAME} -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}
	${ECHO_CMD} "@dir wildfly/.galleon/hashes/.installation" >> ${TMPPLIST}
	${ECHO_CMD} "@dir wildfly/.galleon/hashes/.well-known/acme-challenge" >> ${TMPPLIST}
	${ECHO_CMD} "@dir wildfly/.galleon/hashes/domain/tmp/auth" >> ${TMPPLIST}
	${ECHO_CMD} "@dir wildfly/.galleon/hashes/standalone/lib/ext" >> ${TMPPLIST}
	${ECHO_CMD} "@dir wildfly/.galleon/hashes/standalone/tmp/auth" >> ${TMPPLIST}
	${ECHO_CMD} "@dir wildfly/.galleon/hashes/standalone/tmp/embedded-server/auth" >> ${TMPPLIST}
	${ECHO_CMD} "@dir wildfly/.galleon/hashes/standalone/tmp/embedded-server/vfs/temp" >> ${TMPPLIST}
	${ECHO_CMD} "@dir wildfly/.well-known/acme-challenge" >> ${TMPPLIST}
	${ECHO_CMD} "@dir wildfly/domain/tmp/auth" >> ${TMPPLIST}
	${ECHO_CMD} "@dir wildfly/standalone/lib/ext" >> ${TMPPLIST}
	${ECHO_CMD} "@dir wildfly/standalone/tmp/auth" >> ${TMPPLIST}
	${ECHO_CMD} "@dir wildfly/standalone/tmp/embedded-server/auth" >> ${TMPPLIST}
	${ECHO_CMD} "@dir wildfly/standalone/tmp/embedded-server/vfs/temp" >> ${TMPPLIST}

.include <bsd.port.mk>
