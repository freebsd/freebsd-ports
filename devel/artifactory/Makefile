# $FreeBSD$

PORTNAME=	artifactory
PORTVERSION=	4.7.1
CATEGORIES=	devel java
MASTER_SITES=	https://bintray.com/artifact/download/jfrog/artifactory/
DISTNAME=	jfrog-${PORTNAME}-oss-${PORTVERSION}

MAINTAINER=	dharrigan@gmail.com
COMMENT=	Universal Artifact Repository Manager

LICENSE=	GPLv3 LGPL3 APACHE20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LESSER
LICENSE_FILE_APACHE20=	${WRKSRC}/tomcat/LICENSE

RUN_DEPENDS=	bash:shells/bash

WRKSRC=		${WRKDIR}/${PORTNAME}-oss-${PORTVERSION}

NO_ARCH=	yes
USE_JAVA=	yes
USES=		shebangfix zip
SHEBANG_FILES=	bin/artifactory.sh
NO_BUILD=	yes
JAVA_VERSION=	1.8+
JAVA_VENDOR=	openjdk
USE_RC_SUBR=	${PORTNAME}

APP_NAME=	${PORTNAME}
APP_HOME?=	${PORTNAME}
PID_FILE?=	/var/run/${PORTNAME}.pid
VARDIR=		/var/${PORTNAME}

USERS=		artifactory
GROUPS=		artifactory

SUB_LIST=	APP_HOME=${PREFIX}/${APP_HOME} \
		APP_NAME=${APP_NAME} \
		PID_FILE=${PID_FILE} \
		VARDIR=${VARDIR}

SUB_FILES=	pkg-message \

PLIST_SUB=	APP_HOME=${APP_HOME} \
		VARDIR=${VARDIR}

do-install:
.for f in artifactory-service.exe artifactory.bat installService.bat \
	uninstallService.bat
	${RM} ${WRKSRC}/bin/${f}
.endfor
	${RM} ${WRKSRC}/tomcat/bin/*.bat

	${MKDIR} ${STAGEDIR}${PREFIX}/${APP_HOME}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${APP_HOME})

	${MKDIR} ${STAGEDIR}/${VARDIR}/tomcat/logs/catalina
	${LN} -sf ${VARDIR}/tomcat/logs/catalina ${STAGEDIR}${PREFIX}/${APP_HOME}/tomcat/logs

.for d in etc logs
	${MV} ${STAGEDIR}${PREFIX}/${APP_HOME}/${d} ${STAGEDIR}/${VARDIR}
	${LN} -sf ${VARDIR}/${d} ${STAGEDIR}${PREFIX}/${APP_HOME}/${d}
.endfor

.for d in temp webapps work
	${MV} ${STAGEDIR}${PREFIX}/${APP_HOME}/tomcat/${d} ${STAGEDIR}/${VARDIR}/tomcat
	${LN} -sf ${VARDIR}/tomcat/${d} ${STAGEDIR}${PREFIX}/${APP_HOME}/tomcat/${d}
.endfor

.for d in data backup support
	${MKDIR} ${STAGEDIR}/${VARDIR}/${d}
	${LN} -sf ${VARDIR}/${d} ${STAGEDIR}${PREFIX}/${APP_HOME}/${d}
.endfor

.include <bsd.port.mk>
