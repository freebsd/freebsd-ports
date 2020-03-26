# $FreeBSD$

PORTNAME=	sonar-scanner-cli
DISTVERSION=	4.3.0.2102
PORTREVISION=	0
CATEGORIES=	devel security www java
MASTER_SITES=	https://binaries.sonarsource.com/Distribution/${PORTNAME}/

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Scanner component of SonarQube

LICENSE=	LGPL3

# node -> JS analysis
RUN_DEPENDS=	node:www/node

USES=		cpe zip
CPE_VENDOR=	sonarsource
USE_JAVA=	yes

WRKSRC=		${WRKDIR}/sonar-scanner-${DISTVERSION}

NO_ARCH=	yes
NO_BUILD=	yes
JAVA_VERSION=	11+
JAVA_VENDOR=	openjdk

APP_NAME=	${PORTNAME}
APP_DIR=	libexec/${PORTNAME}
JAR_VERSION=	${DISTVERSION}

SUB_LIST=	\
		APP_DIR=${APP_DIR} \
		JAR_VERSION=${JAR_VERSION}

SUB_FILES=	\
		sonar-scanner \
		pkg-message

PLIST_SUB=	\
		APP_DIR=${APP_DIR} \
		JAR_VERSION=${JAR_VERSION}

post-extract:
	${MV} ${WRKSRC}/conf/sonar-scanner.properties ${WRKSRC}/conf/sonar-scanner.properties.sample
	${RM} ${WRKSRC}/bin/*.bat

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${APP_DIR}
	${INSTALL} ${WRKDIR}/sonar-scanner ${STAGEDIR}${PREFIX}/bin/
.for dir in bin conf lib
	cd ${WRKSRC}; ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${PREFIX}/${APP_DIR} "! -name *\.orig"
.endfor

gen-plist:
	${ECHO} '@sample ${APP_DIR}/conf/sonar-scanner.properties.sample' >${PLIST}.new
	${ECHO} 'bin/sonar-scanner' >>${PLIST}.new
.for dir in bin conf lib
	${FIND} ${STAGEDIR}${PREFIX}/${APP_DIR}/${dir} -type f |  \
	    ${SED} -e "s:${STAGEDIR}${PREFIX}/::g ; \
		s:${JAR_VERSION}:%%JAR_VERSION%%:g" | \
	    ${GREP} -v conf/sonar-scanner.properties | ${SORT} >> ${PLIST}.new
.endfor

.include <bsd.port.mk>
