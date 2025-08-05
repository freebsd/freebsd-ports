PORTNAME=	jenkins
PORTVERSION=	2.522
CATEGORIES=	devel java
MASTER_SITES=	https://get.jenkins.io/war/${PORTVERSION}/
DISTNAME=	jenkins
EXTRACT_SUFX=	.war
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}
EXTRACT_ONLY=

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Open-source continuous integration server
WWW=		https://jenkins.io/

LICENSE=	MIT

USES=		cpe java
JAVA_VERSION=	21+
USE_RC_SUBR=	jenkins

CONFLICTS=	jenkins-lts

NO_ARCH=	yes
NO_BUILD=	yes

JENKINS_HOME?=		${PREFIX}/jenkins
JENKINS_USER?=		jenkins
JENKINS_GROUP?=		jenkins
JENKINS_LOG_FILE?=	/var/log/jenkins.log

.if ${JENKINS_USER} == "jenkins"
USERS=	jenkins
.endif
.if ${JENKINS_GROUP} == "jenkins"
GROUPS=	jenkins
.endif

SUB_LIST+=	JAVA_HOME=${JAVA_HOME} \
		JENKINS_GROUP=${JENKINS_GROUP} \
		JENKINS_HOME=${JENKINS_HOME} \
		JENKINS_LOG_FILE=${JENKINS_LOG_FILE} \
		JENKINS_USER=${JENKINS_USER}
PLIST_SUB+=	JENKINS_GROUP=${JENKINS_GROUP} \
		JENKINS_USER=${JENKINS_USER}

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${JENKINS_HOME}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
