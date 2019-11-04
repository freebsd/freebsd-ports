# Created by: rfarmer@predatorlabs.net
# $FreeBSD$

PORTNAME=	javahelp
PORTVERSION=	2.0.05.20170719
CATEGORIES=	java devel

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Online help support for Java applications

LICENSE=	CDDL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${TOMCAT_jsp}:${TOMCAT_PORT}

USE_GITHUB=	yes
GH_ACCOUNT=	javaee
GH_TAGNAME=	3ca862d
USE_JAVA=	yes
USE_ANT=	yes

JAVA_VER=	1.${JAVA_PORT_VERSION:C/^([0-9])\.([0-9])(.*)$/\1.\2/}
TOMCAT_VER?=	8.5
TOMCAT_PORT=	www/tomcat${TOMCAT_VER:S/.0//:S/.//}
TOMCAT_DIR=	${LOCALBASE}/apache-tomcat-${TOMCAT_VER}
TOMCAT_jsp=	${TOMCAT_DIR}/lib/jsp-api.jar
TOMCAT_servlet=	${TOMCAT_DIR}/lib/servlet-api.jar

MAKE_ARGS=	-Djsp-jar=${TOMCAT_jsp} \
		-Dfile.reference.jsp-api.jar=${TOMCAT_jsp} \
		-Dservlet-jar=${TOMCAT_servlet} \
		-Dfile.reference.servlet-api.jar=${TOMCAT_servlet} \
		-Djavac.target=${JAVA_VER} \
		-Ddefault.javac.target=${JAVA_VER} \
		-Dtomcat-zip-present=true

BUILD_WRKSRC=	${WRKSRC}/javahelp_nbproject
SUB_FILES=	jhindexer \
		jhsearch
SUB_LIST=	JAVA_VER=${JAVA_VER}+

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/jhindexer ${WRKDIR}/jhsearch ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${BUILD_WRKSRC}/dist/lib/*.jar ${STAGEDIR}${JAVAJARDIR}/
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}/dtd
	${INSTALL_DATA} ${WRKSRC}/jhMaster/JavaHelp/doc/public-spec/dtd/*_2_0.dtd ${STAGEDIR}${JAVAJARDIR}/dtd/

.include <bsd.port.mk>
