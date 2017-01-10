# Created by: Alexander Yerenkow <yerenkow@gmail.com>
# $FreeBSD$

PORTNAME=	wildfly10
PORTVERSION=	10.0.0
PORTREVISION=   3
CATEGORIES=	java www
MASTER_SITES=	http://download.jboss.org/wildfly/${WILDFLY_VERSION}/
DISTNAME=	wildfly-${WILDFLY_VERSION}

MAINTAINER=	yerenkow@gmail.com
COMMENT=	Replacement for JBoss Application Server

LICENSE=	GPLv2

USE_RC_SUBR=	wildfly10
USE_JAVA=	yes
JAVA_VERSION=	1.7+
USER=		www
GROUP=		www
VAR_DIR?=	/var
LOG_DIR?=	${VAR_DIR}/log/${PORTNAME}
PID_FILE=	${VAR_DIR}/run/${PORTNAME}.pid
WILDFLY_VERSION=${PORTVERSION}.Final
SUB_FILES=	pkg-message

SUB_LIST=	APP_SHORTNAME=${PORTNAME} \
		LOG_DIR=${LOG_DIR} \
		USER=${USER} \
		GROUP=${GROUP} \
		PID_FILE=${PID_FILE} \
		APP_HOME=${PREFIX}/wildfly-${PORTVERSION}
PLIST_SUB=	APP_HOME=wildfly-${PORTVERSION}

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

post-patch:
	${RM} ${WRKSRC}/bin/add-user.sh.orig

do-build:
	${RM} ${WRKSRC}/bin/*.bat
	${RM} ${WRKSRC}/bin/*.ps1
	${RM} -r ${WRKSRC}/bin/service
	${RM} -r ${WRKSRC}/bin/init.d

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/wildfly-${PORTVERSION}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/wildfly-${PORTVERSION})
	${RMDIR} ${STAGEDIR}${PREFIX}/wildfly-${PORTVERSION}/.installation
.for FILE in ${CONFIG_FILES}
	${MV} ${STAGEDIR}${PREFIX}/wildfly-${PORTVERSION}/${FILE} \
		${STAGEDIR}${PREFIX}/wildfly-${PORTVERSION}/${FILE}.sample
.endfor

.include <bsd.port.mk>
