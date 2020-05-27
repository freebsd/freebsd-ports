# $FreeBSD$

PORTNAME=	zanata-platform
PORTVERSION=	4.6.2
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/zanata/zanata-platform/releases/download/platform-${PORTVERSION}/ \
		https://repo1.maven.org/maven2/mysql/mysql-connector-java/${MYSQL_CONNECTOR_JAVA_VERSION}/:database
DISTFILES=	zanata-war-${PORTVERSION}.war \
		mysql-connector-java-${MYSQL_CONNECTOR_JAVA_VERSION}.jar:database
EXTRACT_ONLY=

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Web-based translation platform

LICENSE=	GPLv2 LGPL21+
LICENSE_COMB=	multi

NO_ARCH=	yes
NO_BUILD=	yes

# It's needed this specific version, databases/mysql-connector-java51 is
# currently with 5.1.47 version.
MYSQL_CONNECTOR_JAVA_VERSION=	5.1.26

PLIST_SUB=	APP_HOME=${APP_HOME}

OPTIONS_DEFINE=		CLAMAV

OPTIONS_SINGLE=		WF
OPTIONS_SINGLE_WF=	WILDFLY10 WILDFLY11 WILDFLY12 WILDFLY13 WILDFLY14 \
		WILDFLY15 WILDFLY16 WILDFLY90
OPTIONS_DEFAULT=	WILDFLY10

CLAMAV_DESC=		Clam AntiVirus
CLAMAV_RUN_DEPENDS=	clamav>=0:security/clamav

WILDFLY10_DESC=		WildFly version 10.0
WILDFLY10_VARS=		APP_HOME=${PREFIX}/wildfly10
WILDFLY10_RUN_DEPENDS=	${APP_HOME}/bin/standalone.sh:java/wildfly10

WILDFLY11_DESC=		WildFly version 11.0
WILDFLY11_VARS=		APP_HOME=${PREFIX}/wildfly11
WILDFLY11_RUN_DEPENDS=	${APP_HOME}/bin/standalone.sh:java/wildfly11

WILDFLY12_DESC=		WildFly version 12.0
WILDFLY12_VARS=		APP_HOME=${PREFIX}/wildfly12
WILDFLY12_RUN_DEPENDS=	${APP_HOME}/bin/standalone.sh:java/wildfly12

WILDFLY13_DESC=		WildFly version 13.0
WILDFLY13_VARS=		APP_HOME=${PREFIX}/wildfly13
WILDFLY13_RUN_DEPENDS=	${APP_HOME}/bin/standalone.sh:java/wildfly13

WILDFLY14_DESC=		WildFly version 14.0
WILDFLY14_VARS=		APP_HOME=${PREFIX}/wildfly14
WILDFLY14_RUN_DEPENDS=	${APP_HOME}/bin/standalone.sh:java/wildfly14

WILDFLY15_DESC=		WildFly version 15.0
WILDFLY15_VARS=		APP_HOME=${PREFIX}/wildfly15
WILDFLY15_RUN_DEPENDS=	${APP_HOME}/bin/standalone.sh:java/wildfly15

WILDFLY16_DESC=		WildFly version 16.0
WILDFLY16_VARS=		APP_HOME=${PREFIX}/wildfly16
WILDFLY16_RUN_DEPENDS=	${APP_HOME}/bin/standalone.sh:java/wildfly16

WILDFLY90_DESC=		WildFly version 9.0
WILDFLY90_VARS=		APP_HOME=${PREFIX}/wildfly90
WILDFLY90_RUN_DEPENDS=	${APP_HOME}/bin/standalone.sh:java/wildfly90

do-install:
	@${MKDIR} ${STAGEDIR}/var/lib/zanata
	@${MKDIR} ${STAGEDIR}${APP_HOME}/standalone/deployments \
		${STAGEDIR}${APP_HOME}/standalone/configuration
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/zanata-war-${PORTVERSION}.war \
		${STAGEDIR}/${APP_HOME}/standalone/deployments/ROOT.war
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/mysql-connector-java-${MYSQL_CONNECTOR_JAVA_VERSION}.jar \
		${STAGEDIR}/${APP_HOME}/standalone/deployments/mysql-connector-java.jar
	${INSTALL_DATA} ${FILESDIR}/standalone-zanata.xml.sample \
		${STAGEDIR}/${APP_HOME}/standalone/configuration

.include <bsd.port.mk>
