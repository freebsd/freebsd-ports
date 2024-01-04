PORTNAME=	wildfly
PORTVERSION=	17.0.1
CATEGORIES=	java www
MASTER_SITES=	https://download.jboss.org/wildfly/${WILDFLY_VERSION}/
DISTNAME=	wildfly-${WILDFLY_VERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Replacement for JBoss Application Server
WWW=		https://wildfly.org/

LICENSE=	GPLv2

USE_JAVA=	8+
USE_RC_SUBR=	wildfly

NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	APP_SHORTNAME=${PORTNAME} \
		LOG_DIR=${LOG_DIR} \
		USERS=${USERS} \
		GROUPS=${GROUPS} \
		PID_FILE=${PID_FILE} \
		APP_HOME=${PREFIX}/${PORTNAME}

USERS=		www
GROUPS=		www

PLIST_SUB=	APP_HOME=${PORTNAME}

VAR_DIR?=	/var
LOG_DIR?=	${VAR_DIR}/log/${PORTNAME}
PID_FILE=	${VAR_DIR}/run/${PORTNAME}.pid
WILDFLY_VERSION=${PORTVERSION}.Final

CONFIG_FILES=	appclient/configuration/appclient.xml \
		appclient/configuration/logging.properties \
		domain/configuration/application-roles.properties \
		domain/configuration/application-users.properties \
		domain/configuration/default-server-logging.properties \
		domain/configuration/domain.xml \
		domain/configuration/host-master.xml \
		domain/configuration/host-slave.xml \
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
	${RMDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/.installation
.for FILE in ${CONFIG_FILES}
	${MV} ${STAGEDIR}${PREFIX}/${PORTNAME}/${FILE} \
		${STAGEDIR}${PREFIX}/${PORTNAME}/${FILE}.sample
.endfor

.include <bsd.port.mk>
