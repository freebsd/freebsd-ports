# New ports collection makefile for:	jenkins
# Date created:		2011-03-03
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jenkins
PORTVERSION=	1.476
CATEGORIES=	devel java
MASTER_SITES=	http://mirrors.jenkins-ci.org/war/${PORTVERSION}/
DISTNAME=	jenkins
EXTRACT_SUFX=	.war
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Open-source continuous integration server

USE_JAVA=	yes
JAVA_VERSION=	1.5+

FETCH_ARGS=	-Fpr
NO_BUILD=	yes

USE_RC_SUBR=	jenkins

JENKINS_HOME?=	${PREFIX}/jenkins
JENKINS_USER?=	jenkins
JENKINS_GROUP?=	jenkins
JENKINS_LOG_FILE?=	/var/log/jenkins.log

.if ${JENKINS_USER} == "jenkins"
USERS=	jenkins
.endif
.if ${JENKINS_GROUP} == "jenkins"
GROUPS=	jenkins
.endif

PLIST_FILES=	%%DATADIR%%/${DISTNAME}${EXTRACT_SUFX}
PLIST_DIRS=	%%DATADIR%%
PLIST_DIRSTRY=	jenkins
SUB_LIST+=	JENKINS_HOME=${JENKINS_HOME} JENKINS_USER=${JENKINS_USER} JENKINS_GROUP=${JENKINS_GROUP} JAVA_HOME=${JAVA_HOME} JENKINS_LOG_FILE=${JENKINS_LOG_FILE}

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} "${DATADIR}"
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} ${DATADIR}/

.include <bsd.port.post.mk>
