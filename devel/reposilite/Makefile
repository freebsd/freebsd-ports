PORTNAME=				reposilite
DISTVERSION=				3.5.25
DISTVERSIONSUFFIX=			-all
CATEGORIES=				devel www java
MASTER_SITES=				https://maven.reposilite.com/releases/com/reposilite/reposilite/${DISTVERSION}/
EXTRACT_SUFX=				.jar
EXTRACT_ONLY=

MAINTAINER=				thorsteinn@isnic.is
COMMENT=				Lightweight repository manager for Maven based artifacts
WWW=					https://reposilite.com

LICENSE=				APACHE20

USES=					java
JAVA_VERSION=				11+

NO_BUILD=				yes
NO_ARCH=				yes
NO_TEST=				yes
USE_RC_SUBR=				${PORTNAME}

REPOSILITE_WORKDIR=			/var/${PORTNAME}
REPOSILITE_LOGDIR=			/var/log/${PORTNAME}
REPOSILITE_RUNDIR=			/var/run/${PORTNAME}

REPOSILITE_USER=			${PORTNAME}
REPOSILITE_GROUP=			${REPOSILITE_USER}

USERS=					${REPOSILITE_USER}
GROUPS=					${REPOSILITE_GROUP}

SUB_LIST=				JARFILE=${JAVAJARDIR}/${DISTNAME}.jar \
						JAVA_HOME=${JAVA_HOME} \
						USER=${REPOSILITE_USER} \
						GROUP=${REPOSILITE_GROUP} \
						RUNDIR=${REPOSILITE_RUNDIR} \
						LOGDIR=${REPOSILITE_LOGDIR} \
						WORKDIR=${REPOSILITE_WORKDIR}

PLIST_SUB=				JARFILE=${JAVAJARDIR}/${DISTNAME}.jar \
						USER=${REPOSILITE_USER} \
						GROUP=${REPOSILITE_GROUP} \
						RUNDIR=${REPOSILITE_RUNDIR} \
						LOGDIR=${REPOSILITE_LOGDIR} \
						WORKDIR=${REPOSILITE_WORKDIR}

post-extract:
	@${TAR} -C ${WRKDIR} -xzf ${DISTDIR}/${DISTNAME}.jar tinylog.properties

post-patch:
	@${REINPLACE_CMD} -E \
		-e '27s#= .+$$#= ${REPOSILITE_LOGDIR}/${PORTNAME}.{date:yyyy-MM-dd}.log#' \
		-e '28s#= .+$$#= ${REPOSILITE_LOGDIR}/${PORTNAME}-latest.log#' \
		-e '30s#monthly: 03:00$$#daily: 00:00#' \
		${WRKDIR}/tinylog.properties

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${REPOSILITE_WORKDIR}
	${MKDIR} ${STAGEDIR}${REPOSILITE_LOGDIR}
	${MKDIR} ${STAGEDIR}${REPOSILITE_RUNDIR}
	${INSTALL_DATA} ${FILESDIR}/configuration.cdn.sample ${STAGEDIR}${ETCDIR}/
	${INSTALL_DATA} ${WRKDIR}/tinylog.properties ${STAGEDIR}${ETCDIR}/tinylog.properties.sample
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/

.include <bsd.port.mk>
