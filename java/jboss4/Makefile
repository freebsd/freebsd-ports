# ports collection makefile for: jboss2
# Date created:                  16 April 2002
# Whom:                          Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${APP_TITLE:L}
PORTVERSION=	4.0.2
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	jonc@chen.org.nz
COMMENT=	Open-source J2EE application server (4.x family)

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant

LATEST_LINK=	jboss4
USE_JAVA=	yes
JAVA_VERSION=	1.4+

USE_REINPLACE=	YES
USE_RC_SUBR=	YES
USE_BZIP2=	YES

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

APP_HOME?=	${PREFIX}/${APP_SHORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}${PORTVERSION:R}
LOG_DIR=	${APP_HOME}/log
APP_TITLE=	JBoss
APP_SHORTNAME=	${UNIQUENAME}
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
JAVA_OPTS=
JAVA_CP=	bin/run.jar:${JAVA_HOME}/lib/tools.jar
JAVA_MAIN=	org.jboss.Main
DAEMONCTL_DIR=	${FILESDIR}
DAEMONCTL_FILES=daemonctl.c daemonctl.1 startup.sh pkg-message
MAN1=		${CONTROL_SCRIPT_NAME}.1

JBOSSOUTPUT=	${WRKSRC}/build/output/${PORTNAME}-${PORTVERSION}
APP_HOME_FILES=	bin client lib server

PLIST_FILES=	${CONTROL_SCRIPT:S,^${PREFIX}/,,} \
		${STARTUP_SCRIPT:S,^${PREFIX}/,,} \
		${STDOUT_LOG:S,^${PREFIX}/,,} \
		${STDERR_LOG:S,^${PREFIX}/,,}

PKGMESSAGE=	${WRKDIR}/pkg-message.fmt

.include <bsd.port.pre.mk>

do-configure:
	@(cd ${DAEMONCTL_DIR} && ${CP} ${DAEMONCTL_FILES} ${WRKDIR})
	@(cd ${WRKDIR} && ${REINPLACE_CMD} \
		-e "s|%%RC_SUBR%%|${RC_SUBR}|g;" \
		-e "s|%%APP_HOME%%|${APP_HOME}|g;" \
		-e "s|%%APP_SHORTNAME%%|${APP_SHORTNAME}|g;" \
		-e "s|%%APP_TITLE%%|${APP_TITLE}|g;" \
		-e "s|%%CONTROL_SCRIPT%%|${CONTROL_SCRIPT}|g;" \
		-e "s|%%CONTROL_SCRIPT_MANPAGE_TITLE%%|${CONTROL_SCRIPT_MANPAGE_TITLE}|g;" \
		-e "s|%%CONTROL_SCRIPT_NAME%%|${CONTROL_SCRIPT_NAME}|g;" \
		-e "s|%%GROUP%%|${GROUP}|g;" \
		-e "s|%%JAVA%%|${JAVA}|g;" \
		-e "s|%%JAVA_CP%%|${JAVA_CP}|g;" \
		-e "s|%%JAVA_HOME%%|${JAVA_HOME}|g;" \
		-e "s|%%JAVA_MAIN%%|${JAVA_MAIN}|g;" \
		-e "s|%%JAVA_OPTS%%|${JAVA_OPTS}|g;" \
		-e "s|%%JAVA_PORT_VERSION%%|${JAVA_PORT_VERSION}|g;" \
		-e "s|%%JAVA_PORT_OS_DESCRIPTION%%|${JAVA_PORT_OS_DESCRIPTION}|g;" \
		-e "s|%%JAR_FILE%%|${JAR_FILE}|g;" \
		-e "s|%%LOG_DIR%%|${LOG_DIR}|g;" \
		-e "s|%%PID_FILE%%|${PID_FILE}|g;" \
		-e "s|%%PKGNAME%%|${PKGNAME}|g;" \
		-e "s|%%PORTNAME%%|${PORTNAME}|g;" \
		-e "s|%%PORTVERSION%%|${PORTVERSION}|g;" \
		-e "s|%%PREFIX%%|${PREFIX}|g;" \
		-e "s|%%STARTUP_SCRIPT%%|${STARTUP_SCRIPT}|g;" \
		-e "s|%%STDERR_LOG%%|${STDERR_LOG}|g;" \
		-e "s|%%STDOUT_LOG%%|${STDOUT_LOG}|g;" \
		-e "s|%%STOP_TIMEOUT%%|${STOP_TIMEOUT}|g;" \
		-e "s|%%USER%%|${USER}|g;" ${DAEMONCTL_FILES})
	@${FMT} -s 80 ${WRKDIR}/pkg-message >${PKGMESSAGE}

post-configure:
	@${ECHO_MSG} "Installation settings:"
	@${ECHO_MSG} "   Destination directory:    ${APP_HOME}"
	@${ECHO_MSG} "   Control program location: ${CONTROL_SCRIPT}"
	@${ECHO_MSG} "   Startup script location:  ${STARTUP_SCRIPT}"
	@${ECHO_MSG} "   Location of JDK:          ${JAVA_HOME}"
	@${ECHO_MSG} "   Location of Java port:    ${JAVA_PORT}"
	@${ECHO_MSG} "   Startup Java Options:     ${JAVA_OPTS}"
	@${ECHO_MSG} "   Running as (user/group):  ${USER}/${GROUP}"
	@${ECHO_MSG} "   Logfile stdout:           ${STDOUT_LOG}"
	@${ECHO_MSG} "   Logfile stderr:           ${STDERR_LOG}"
	@${ECHO_MSG} "   Starting after install:   ${AUTO_START}"
	@${ECHO_MSG} "   Stop time-out:            ${STOP_TIMEOUT} sec."

do-build:
	(cd ${WRKDIR} && ${CC} ${CFLAGS} -o ${CONTROL_SCRIPT_NAME} daemonctl.c)
	(cd ${WRKSRC}/build && ${SETENV} JAVA_HOME="${JAVA_HOME}" PATH="${JAVA_HOME}/bin:${PATH}" ${SH} build.sh)

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${MKDIR} ${APP_HOME} && ${CHOWN} ${USER}:${GROUP} ${APP_HOME}
	${MKDIR} ${LOG_DIR} && ${CHOWN} ${USER}:${GROUP} ${LOG_DIR}
	(cd ${JBOSSOUTPUT} && ${FIND} ${APP_HOME_FILES} |\
		${CPIO} -pdmu -R ${USER}:${GROUP} ${APP_HOME})
	${INSTALL} -o ${USER} -g ${GROUP} -m 06754\
		${WRKDIR}/${CONTROL_SCRIPT_NAME} ${CONTROL_SCRIPT}
	${INSTALL_SCRIPT} ${WRKDIR}/startup.sh ${STARTUP_SCRIPT}
	${INSTALL} -o ${USER} -g ${GROUP} -m 0640 /dev/null ${STDOUT_LOG}
	${INSTALL} -o ${USER} -g ${GROUP} -m 0640 /dev/null ${STDERR_LOG}
	${INSTALL} -o ${USER} -g ${GROUP} -m 0640 /dev/null ${PID_FILE}
	${INSTALL_MAN} ${WRKDIR}/daemonctl.1 ${MANPREFIX}/man/man1/${CONTROL_SCRIPT_NAME}.1
.if !defined(NOPORTDOCS)
	cd ${JBOSSOUTPUT}/docs \
		&& ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

post-install:
	@${FIND} -s ${APP_HOME_FILES:S,^,${JBOSSOUTPUT}/,} -not -type d | \
		${SED} -ne 's,^${JBOSSOUTPUT},${APP_HOME:S,${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${APP_HOME_FILES:S,^,${JBOSSOUTPUT}/,} -type d | \
		${SED} -ne 's,^${JBOSSOUTPUT},@dirrm ${APP_HOME:S,${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${APP_HOME:S,^${PREFIX}/,,}/log" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${APP_HOME:S,^${PREFIX}/,,}" >> ${TMPPLIST}
.if ${AUTO_START} == "YES"
	@${CONTROL_SCRIPT} start || true
.endif
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
