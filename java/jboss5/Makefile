# ports collection makefile for: jboss2
# Date created:                  16 April 2002
# Whom:                          Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${APP_TITLE:L}
PORTVERSION=	3.2.3
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	jonc@chen.org.nz
COMMENT=	JBoss 3, an open-source J2EE application server

USE_JAVA=	1.3+

USE_REINPLACE=	YES
USE_BZIP2=	YES

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

APP_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION:R}
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}${PORTVERSION:R}
LOG_DIR=	${APP_HOME}/log
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}
APP_TITLE=	JBoss
APP_SHORTNAME=	${PORTNAME}${PORTVERSION:R:R}
CONTROL_SCRIPT_NAME=	${APP_SHORTNAME}ctl
CONTROL_SCRIPT=	${PREFIX}/bin/${CONTROL_SCRIPT_NAME}
CONTROL_SCRIPT_MANPAGE_TITLE=	${CONTROL_SCRIPT_NAME:U}
STARTUP_ORDER=	020
STARTUP_SCRIPT_NAME=	${APP_SHORTNAME}.sh
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/${STARTUP_ORDER}.${STARTUP_SCRIPT_NAME}
USER=		www
GROUP=		www
STDOUT_LOG=	${LOG_DIR}/stdout.log
STDERR_LOG=	${LOG_DIR}/stderr.log
AUTO_START?=	NO
STOP_TIMEOUT?=	5
PID_FILE=	/var/run/${APP_SHORTNAME}.pid
JAR_FILE=	bin/run.jar
DAEMONCTL_DIR=	${PORTSDIR}/www/jakarta-tomcat4/files
DAEMONCTL_FILES=daemonctl.c daemonctl.1 startup.sh
MAN1=		${CONTROL_SCRIPT_NAME}.1

JBOSSOUTPUT=	${WRKSRC}/build/output/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

do-configure:
	@(cd ${DAEMONCTL_DIR} && ${CP} ${DAEMONCTL_FILES} ${WRKDIR})
	@(cd ${WRKDIR} && ${REINPLACE_CMD} \
		-e "s|%%APP_HOME%%|${APP_HOME}|g;" \
		-e "s|%%APP_SHORTNAME%%|${APP_SHORTNAME}|g;" \
		-e "s|%%APP_TITLE%%|${APP_TITLE}|g;" \
		-e "s|%%CONTROL_SCRIPT%%|${CONTROL_SCRIPT}|g;" \
		-e "s|%%CONTROL_SCRIPT_MANPAGE_TITLE%%|${CONTROL_SCRIPT_MANPAGE_TITLE}|g;" \
		-e "s|%%CONTROL_SCRIPT_NAME%%|${CONTROL_SCRIPT_NAME}|g;" \
		-e "s|%%GROUP%%|${GROUP}|g;" \
		-e "s|%%JAR_ARGS%%||g;" \
		-e "s|%%JAVA_ARGS%%||g;" \
		-e "s|%%JAVA_CMD%%|bin/java|g;" \
		-e "s|%%JAVA_HOME%%|${JAVA_HOME}|g;" \
		-e "s|%%JAR_FILE%%|${JAR_FILE}|g;" \
		-e "s|%%LOG_DIR%%|${LOG_DIR}|g;" \
		-e "s|%%PID_FILE%%|${PID_FILE}|g;" \
		-e "s|%%PORTNAME%%|${PORTNAME}|g;" \
		-e "s|%%PORTVERSION%%|${PORTVERSION}|g;" \
		-e "s|%%PREFIX%%|${PREFIX}|g;" \
		-e "s|%%STARTUP_SCRIPT_NAME%%|${STARTUP_SCRIPT_NAME}|g;" \
		-e "s|%%STDERR_LOG%%|${STDERR_LOG}|g;" \
		-e "s|%%STDOUT_LOG%%|${STDOUT_LOG}|g;" \
		-e "s|%%STOP_TIMEOUT%%|${STOP_TIMEOUT}|g;" \
		-e "s|%%USER%%|${USER}|g;" ${DAEMONCTL_FILES})

post-configure:
	@${ECHO_CMD} "Installation settings:"
	@${ECHO_CMD} "   Destination directory:    ${APP_HOME}"
	@${ECHO_CMD} "   Control program location: ${CONTROL_SCRIPT}"
	@${ECHO_CMD} "   Startup script location:  ${STARTUP_SCRIPT}"
	@${ECHO_CMD} "   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_CMD} "   Location of Java port:    ${JAVA_PORT}"
	@${ECHO_CMD} "   Using Jikes:              ${WITH_JIKES}"
	@${ECHO_CMD} "   Running as (user/group):  ${USER}/${GROUP}"
	@${ECHO_CMD} "   HTTP port:                ${HTTP_PORT}"
	@${ECHO_CMD} "   RMI port:                 ${RMI_PORT}"
	@${ECHO_CMD} "   Logfile stdout:           ${STDOUT_LOG}"
	@${ECHO_CMD} "   Logfile stderr:           ${STDERR_LOG}"
	@${ECHO_CMD} "   Starting after install:   ${AUTO_START}"
	@${ECHO_CMD} "   Stop time-out:            ${STOP_TIMEOUT} sec."

do-build:
	(cd ${WRKDIR} && ${CC} ${CFLAGS} -o ${CONTROL_SCRIPT_NAME} daemonctl.c)
	(cd ${WRKSRC}/build && ${SETENV} JAVA_HOME=${JAVA_HOME} PATH=${PATH}:${JAVA_HOME}/bin ${SH} build.sh)

pre-install:
	@PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

do-install:
	${MKDIR} ${APP_HOME} && ${CHOWN} ${USER}:${GROUP} ${APP_HOME}
	${MKDIR} ${LOG_DIR} && ${CHOWN} ${USER}:${GROUP} ${LOG_DIR}
	(cd ${JBOSSOUTPUT} && ${FIND} bin client lib server |\
		${CPIO} -pdmu -R ${USER}:${GROUP} ${APP_HOME})
	${INSTALL} -o ${USER} -g ${GROUP} -m 06754\
		${WRKDIR}/${CONTROL_SCRIPT_NAME} ${CONTROL_SCRIPT}
	${INSTALL_SCRIPT} ${WRKDIR}/startup.sh ${STARTUP_SCRIPT}
	${INSTALL} -o ${USER} -g ${GROUP} -m 0640 /dev/null ${STDOUT_LOG}
	${INSTALL} -o ${USER} -g ${GROUP} -m 0640 /dev/null ${STDERR_LOG}
	${INSTALL} -o ${USER} -g ${GROUP} -m 0640 /dev/null ${PID_FILE}
	${INSTALL_MAN} ${WRKDIR}/daemonctl.1 ${MANPREFIX}/man/man1/${CONTROL_SCRIPT_NAME}.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -r ${JBOSSOUTPUT}/docs/* ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD} "${PKGNAME} has been installed in ${APP_HOME}."
	@${ECHO_CMD} "If a user should be able to use ${CONTROL_SCRIPT_NAME}, put it in the group ${GROUP}."
	@${ECHO_CMD} "Use 'man ${CONTROL_SCRIPT_NAME}' for information about starting and stopping ${PORTNAME}."
.if ${AUTO_START} == "YES"
	@${CONTROL_SCRIPT} start || true
.endif

.include <bsd.port.post.mk>
