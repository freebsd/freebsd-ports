# ports collection makefile for: jboss2
# Date created:                  16 April 2002
# Whom:                          Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	${APP_TITLE:L}
PORTVERSION=	2.4.11
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${APP_TITLE}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JBoss 2.x, an open-source J2EE application server

USE_JAVA=	yes
JAVA_VERSION=	1.2+

USE_ZIP=	YES
NO_BUILD=	YES

LATEST_LINK=	jboss2

WRKSRC=		${WRKDIR}/${DISTNAME}
APP_HOME?=	${PREFIX}/${PKGBASE}${PORTVERSION:R}
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
PW?=		/usr/sbin/pw
STDOUT_LOG=	${LOG_DIR}/stdout.log
STDERR_LOG=	${LOG_DIR}/stderr.log
AUTO_START?=	NO
STOP_TIMEOUT?=	5
PID_FILE=	/var/run/${APP_SHORTNAME}.pid
REPLACE_FILES=	${PORTSDIR}/www/jakarta-tomcat4/files/daemonctl.c \
		${PORTSDIR}/www/jakarta-tomcat4/files/daemonctl.1 \
		${PORTSDIR}/www/jakarta-tomcat4/files/startup.sh
JAR_FILE=	bin/run.jar

.include <bsd.port.pre.mk>

post-patch:
	@${ECHO_CMD} -n ">> Deleting the symbol CR (carriage return) in some files and removing unneeded files..."
	@${FIND} ${WRKSRC} -type f \
	-iname '*.mf' -or \
	-iname '*.css' -or \
	-iname '*.dtd' -or \
	-iname '*.txt' -or \
	-iname '*.xml' -or \
	-iname '*.conf' -or \
	-iname '*.java' -or \
	-iname '*.html' -or \
	-iname '*.policy' -or \
	-iname '*.properties' | \
	${XARGS} -n 10 -x ${SED} -i .orig -e "s|"`printf '\015'`"||g"
	@cd ${WRKSRC} && ${FIND} . -type f -name "*.orig" -or -iname "*.bat" -or -iname "*.exe" | ${XARGS} -n 10 -x ${RM} -f
	@${RM} -Rd ${WRKSRC}/tmp/deploy
	@${RM} -f ${WRKSRC}/db/hypersonic/default.*
	@${RM} -f ${WRKSRC}/db/jbossmq/*.dat0
	@${ECHO_CMD} " [ DONE ]"

.for f in ${REPLACE_FILES}
	@${ECHO_CMD} -n ">> Customizing `basename $f`..."
	@${SED} \
	-e "/%%APP_HOME%%/s//${APP_HOME:S/\//\\\//g}/g" \
	-e "/%%APP_SHORTNAME%%/s//${APP_SHORTNAME}/g" \
	-e "/%%APP_TITLE%%/s//${APP_TITLE}/g" \
	-e "/%%CONTROL_SCRIPT%%/s//${CONTROL_SCRIPT:S/\//\\\//g}/g" \
	-e "/%%CONTROL_SCRIPT_MANPAGE_TITLE%%/s//${CONTROL_SCRIPT_MANPAGE_TITLE}/g" \
	-e "/%%CONTROL_SCRIPT_NAME%%/s//${CONTROL_SCRIPT_NAME}/g" \
	-e "/%%GROUP%%/s//${GROUP}/g" \
	-e "/%%JAVA_CMD%%/s//bin\/java/g" \
	-e "/%%JAVA_HOME%%/s//${JAVA_HOME:S/\//\\\//g}/g" \
	-e "/%%JAR_FILE%%/s//${JAR_FILE:S/\//\\\//g}/g" \
	-e "/%%LOG_DIR%%/s//${LOG_DIR:S/\//\\\//g}/g" \
	-e "/%%PID_FILE%%/s//${PID_FILE:S/\//\\\//g}/g" \
	-e "/%%PORTNAME%%/s//${PORTNAME}/g" \
	-e "/%%PORTVERSION%%/s//${PORTVERSION}/g" \
	-e "/%%PREFIX%%/s//${PREFIX:S/\//\\\//g}/g" \
	-e "/%%STARTUP_SCRIPT_NAME%%/s//${STARTUP_SCRIPT_NAME}/g" \
	-e "/%%STDERR_LOG%%/s//${STDERR_LOG:S/\//\\\//g}/g" \
	-e "/%%STDOUT_LOG%%/s//${STDOUT_LOG:S/\//\\\//g}/g" \
	-e "/%%STOP_TIMEOUT%%/s//${STOP_TIMEOUT}/g" \
	-e "/%%USER%%/s//${USER}/g" \
	$f > ${WRKDIR}/`basename $f`
	@${ECHO_CMD} " [ DONE ]"
.endfor

pre-install:
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
	@PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} PRE-INSTALL

do-install:
	@${ECHO_CMD} -n ">> Creating destination directory..."
	@${MKDIR} ${APP_HOME}
	@${MKDIR} ${APP_HOME}/application-deployments
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Copying files to destination directory..."
	@${CP} -R ${WRKSRC}/* ${APP_HOME}
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Compiling and installing control program..."
	@${SED} \
	-e "/%%JAVA_ARGS%%/s///g" \
	-e "/%%JAR_ARGS%%/s///g" \
	${WRKDIR}/daemonctl.c > ${WRKDIR}/daemonctl_.c
	@cd ${WRKDIR} && ${CC} -ansi -o ${CONTROL_SCRIPT_NAME} daemonctl_.c
	@${CP} ${WRKDIR}/${CONTROL_SCRIPT_NAME} ${CONTROL_SCRIPT}
	@${CHOWN} ${USER}:${GROUP} ${CONTROL_SCRIPT}
	@${CHMOD} 6754 ${CONTROL_SCRIPT}
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Installing startup script..."
	@${CP} ${WRKDIR}/startup.sh ${STARTUP_SCRIPT}
	@${CHMOD} 0544 ${STARTUP_SCRIPT}
	@${ECHO_CMD} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing man pages..."
	@${INSTALL_MAN} ${WRKDIR}/daemonctl.1 ${MANPREFIX}/man/man1/${CONTROL_SCRIPT_NAME}.1
	@${ECHO_CMD} " [ DONE ]"
.endif

	@${ECHO_CMD} -n ">> Creating log files..."
	@${INSTALL} /dev/null ${STDOUT_LOG}
	@${INSTALL} /dev/null ${STDERR_LOG}
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Fixing ownership settings..."
	@${CHOWN} -R ${USER}:${GROUP} ${APP_HOME}
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Fixing permissions..."
	@${CHMOD} 755 `${FIND} ${APP_HOME} -type d`
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Creating PID file..."
	@${TOUCH} ${PID_FILE}
	@${CHOWN} ${USER}:${GROUP} ${PID_FILE}
	@${CHMOD} 0600 ${PID_FILE}
	@${ECHO_CMD} " [ DONE ]"

post-install:
	@${ECHO_CMD} "${APP_TITLE} ${PORTVERSION} has been installed in ${APP_HOME}."
	@${ECHO_CMD} "If a user should be able to use ${CONTROL_SCRIPT_NAME}, put it in the group ${GROUP}."
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} "Use 'man ${CONTROL_SCRIPT_NAME}' for information about starting and stopping ${APP_TITLE}."
.endif
.if ${AUTO_START} == "YES"
	@${CONTROL_SCRIPT} start || true
.endif

.include <bsd.port.post.mk>
