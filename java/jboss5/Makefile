# ports collection makefile for: jboss5
# Date created:                  7 May 2007
# Whom:                          nemoliu@FreeBSD.org <nemoliu@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	jboss
PORTVERSION=	5.1.0.GA
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/JBoss/JBoss-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	jonc@chen.org.nz
COMMENT=	Open-source J2EE application server (5.x family)

LATEST_LINK=	jboss5
USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native
ANT_HOME=	${WRKSRC}/tools
ANT=		${WRKSRC}/tools/bin/ant
DATADIR=	${PREFIX}/share/${UNIQUENAME}
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}

MANUAL_PACKAGE_BUILD=	fetches files in build phase

MAKE_ARGS=	-buildfile build/build.xml

USE_RC_SUBR=	jboss5
SUB_FILES=	pkg-install pkg-deinstall pkg-message

PORTDATA=	*
PORTDOCS=	*

VAR_DIR?=	/var
LOG_DIR?=	${VAR_DIR}/log/${UNIQUENAME}
DEPLOY_DIR?=	${VAR_DIR}/${UNIQUENAME}
USER=		www
GROUP=		www
STOP_TIMEOUT?=	30
PID_FILE=	/var/run/${UNIQUENAME}.pid

JBOSSOUTPUT=	${WRKSRC}/build/output/${PORTNAME}-${PORTVERSION}
APP_HOME_FILES=	bin/run.jar client lib common

PKGMESSAGE=	${WRKDIR}/pkg-message

SUB_LIST=	APP_HOME=${DATADIR} \
		APP_SHORTNAME=${UNIQUENAME} \
		GROUP=${GROUP} \
		LOG_DIR=${LOG_DIR} \
		DEPLOY_DIR=${DEPLOY_DIR} \
		PID_FILE=${PID_FILE} \
		PKGNAME=${PKGNAME} \
		PORTNAME=${PORTNAME} \
		PORTVERSION=${PORTVERSION} \
		PREFIX=${PREFIX} \
		STOP_TIMEOUT=${STOP_TIMEOUT} \
		USER=${USER}

.include <bsd.port.pre.mk>

do-build:
	@(cd ${BUILD_WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	${MKDIR} ${DATADIR}/bin && ${CHOWN} -R ${USER}:${GROUP} ${DATADIR}
	${MKDIR} ${DEPLOY_DIR} && ${CHOWN} ${USER}:${GROUP} ${DEPLOY_DIR}
	(cd ${JBOSSOUTPUT} && ${FIND} ${APP_HOME_FILES} |\
		${CPIO} -pdmu -R ${USER}:${GROUP} ${DATADIR})
	(cd ${JBOSSOUTPUT}/server && ${FIND} . |\
		${CPIO} -pdmu -R ${USER}:${GROUP} ${DEPLOY_DIR})
	(cd ${WRKSRC}/jbossas/remoting/output/lib && ${FIND} . |\
		${CPIO} -pdmu -R ${USER}:${GROUP} ${DATADIR}/common/lib)
	(cd ${JBOSSOUTPUT}/client && ${FIND} jboss-remoting.jar jboss-serialization.jar |\
		${CPIO} -pdmu -R ${USER}:${GROUP} ${DATADIR}/common/lib)
	${INSTALL} -o ${USER} -g ${GROUP} -m 0640 /dev/null ${PID_FILE}
.if !defined(NOPORTDOCS)
	cd ${JBOSSOUTPUT}/docs \
		&& ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
		&& ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

post-install:
	@${ECHO_CMD} "@cwd ${VAR_DIR}" >> ${TMPPLIST}
	@${FIND} -s ${JBOSSOUTPUT}/server -not -type d | \
		${SED} -ne 's,^${JBOSSOUTPUT}/server/,${DEPLOY_DIR:S,^${VAR_DIR}/,,}/,p' >> ${TMPPLIST}
	@${FIND} -s -d ${JBOSSOUTPUT}/server -type d | \
		${SED} -ne 's,^${JBOSSOUTPUT}/server/,@dirrm ${DEPLOY_DIR:S,^${VAR_DIR}/,,}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${DEPLOY_DIR:S,^${VAR_DIR}/,,}" >> ${TMPPLIST}
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
