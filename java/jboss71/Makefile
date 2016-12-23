# Created by: Alexander Yerenkow <yerenkow@gmail.com>
# $FreeBSD$

PORTNAME=	jboss71
PORTVERSION=	7.1.3
#PORTREVISION=	0
#PORTEPOCH=	0
CATEGORIES=	java www
MASTER_SITES=	https://javaz.org/distfiles/
DISTNAME2=	${GH_PROJECT}-${GH_TAGNAME}
DISTFILES=	m2-${DISTNAME2}.tar.xz ${DISTNAME}.tar.gz

MAINTAINER=	yerenkow@gmail.com
COMMENT=	JBoss 7.1.3.Final

DEPRECATED=     Unsupported, replaced by wildfly
EXPIRATION_DATE=2017-02-07

BROKEN_FreeBSD_9_i386=	does not build on FreeBSD 9.x i386

USE_GITHUB=	YES
GH_ACCOUNT=	jbossas
GH_PROJECT=	jboss-as
GH_TAGNAME=	7.1.3.Final

USE_RC_SUBR=	jboss71
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USER=		www
GROUP=		www
VAR_DIR?=	/var
LOG_DIR?=	${VAR_DIR}/log/${PORTNAME}
DEPLOY_DIR?=	${VAR_DIR}/${PORTNAME}
PID_FILE=	/var/run/${PORTNAME}.pid
JBOSSOUTPUT=	${WRKSRC}/build/target/${DISTNAME2}

SUB_LIST=	APP_SHORTNAME=${PORTNAME} \
		LOG_DIR=${LOG_DIR} \
		USER=${USER}\
		PID_FILE=${PID_FILE} \
		APP_HOME=${PREFIX}/${DISTNAME2}

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
	${MKDIR} ${STAGEDIR}${PREFIX}/${DISTNAME2} && cd ${JBOSSOUTPUT} && ${FIND} . | ${CPIO} -pdmu -R ${USER}:${GROUP} ${STAGEDIR}${PREFIX}/${DISTNAME2}

.include <bsd.port.mk>
