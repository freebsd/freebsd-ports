# Created by: Alexander Yerenkow <yerenkow@gmail.com>
# $FreeBSD$

PORTNAME=	jboss72
PORTVERSION=	7.2.0
PORTREVISION=	1
#PORTEPOCH=	0
CATEGORIES=	java www
MASTER_SITES=	https://javaz.org/distfiles/
DISTNAME=	${GH_PROJECT}-${GH_TAGNAME}
DISTFILES=	m2-${DISTNAME}.tar.xz ${DISTNAME}.tar.gz

MAINTAINER=	yerenkow@gmail.com
COMMENT=	JBoss 7.2.0.Final

LICENSE=	GPLv2

USE_GITHUB=	YES
GH_ACCOUNT=	jbossas
GH_PROJECT=	jboss-as
GH_TAGNAME=	7.2.0.Final
GH_COMMIT=	4ed76ce

USE_RC_SUBR=    jboss72
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USER=		www
GROUP=		www
VAR_DIR?=       /var
LOG_DIR?=       ${VAR_DIR}/log/${PORTNAME}
DEPLOY_DIR?=    ${VAR_DIR}/${PORTNAME}
PID_FILE=       /var/run/${PORTNAME}.pid
JBOSSOUTPUT=    ${WRKSRC}/build/target/${DISTNAME}

SUB_LIST=	APP_SHORTNAME=${PORTNAME} \
		LOG_DIR=${LOG_DIR} \
		USER=${USER}\
		PID_FILE=${PID_FILE} \
		APP_HOME=${PREFIX}/${DISTNAME}
PLIST_SUB=	APP_HOME=${DISTNAME}

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "To build you should have at least 2Gb of Ram (Or build will fail with java OOM Exception)"
	@${ECHO_MSG} "There's no dependensy on maven3, since JBoss can handle itself."

post-patch:
	${MV} ${WRKSRC}/tools/maven/conf/settings.xml ${WRKSRC}/tools/maven/conf/settings.xml.orig
	@${SED} -e 's,<!-- localRepository,<localRepository>${WRKDIR}/.m2/repository</localRepository><!-- localRepository,g' \
		 ${WRKSRC}/tools/maven/conf/settings.xml.orig > ${WRKSRC}/tools/maven/conf/settings.xml

do-build:
	cd ${WRKSRC} && ./build.sh -Dmaven.test.skip=true -DskipTests

do-install:
	${MKDIR} ${PREFIX}/${DISTNAME} && cd ${JBOSSOUTPUT} && ${FIND} . | ${CPIO} -pdmu -R ${USER}:${GROUP} ${PREFIX}/${DISTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=	does not work without base xz
.endif

.include <bsd.port.post.mk>
