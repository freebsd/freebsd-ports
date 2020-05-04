# $FreeBSD$

PORTNAME=	sonarqube
DISTVERSION=	8.3.0.34182
PORTREVISION=	0
CATEGORIES=	devel security www java
MASTER_SITES=	https://binaries.sonarsource.com/Distribution/sonarqube/:m_core \
		https://binaries.sonarsource.com/Distribution/sonar-csharp-plugin/:m_csharp \
		https://binaries.sonarsource.com/Distribution/sonar-java-plugin/:m_java \
		https://binaries.sonarsource.com/Distribution/sonar-javascript-plugin/:m_javascript \
		https://binaries.sonarsource.com/Distribution/sonar-python-plugin/:m_python \
		https://binaries.sonarsource.com/Distribution/sonar-scm-git-plugin/:m_scmgit \
		https://binaries.sonarsource.com/Distribution/sonar-vbnet-plugin/:m_vbnet
PKGNAMESUFFIX=	-community
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:m_core \
		sonar-csharp-plugin-${SONARCSHARP_VER}.jar:m_csharp \
		sonar-java-plugin-${SONARJAVA_VER}.jar:m_java \
		sonar-javascript-plugin-${SONARJAVASCRIPT_VER}.jar:m_javascript \
		sonar-python-plugin-${SONARPYTHON_VER}.jar:m_python \
		sonar-scm-git-plugin-${SONARSCMGIT_VER}.jar:m_scmgit \
		sonar-vbnet-plugin-${SONARVBNET_VER}.jar:m_vbnet
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	netchild@FreeBSD.org
COMMENT=	Web-based continuous code inspection tool

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix zip
CPE_VENDOR=	sonarsource
USE_JAVA=	yes

SHEBANG_FILES=	elasticsearch/bin/elasticsearch \
		elasticsearch/bin/elasticsearch-env

NO_ARCH=	yes
NO_BUILD=	yes
JAVA_VERSION=	11+
JAVA_VENDOR=	openjdk
USE_RC_SUBR=	${PORTNAME}

APP_NAME=	${PORTNAME}
APP_DIR=	libexec/${PORTNAME}
LOG_DIR=	/var/log/${PORTNAME}
PID_DIR=	/var/run/${PORTNAME}
JAR_VERSION=	${DISTVERSION}
DBBASE_DIR=	/var/db/${PORTNAME}
DATA_DIR=	${DBBASE_DIR}/data
TEMP_DIR=	${DBBASE_DIR}/temp

SONARCSHARP_VER=	8.6.1.17183
SONARJAVA_VER=		6.3.0.21585
SONARJAVASCRIPT_VER=	6.2.1.12157
SONARPYTHON_VER=	2.8.0.6204
SONARSCMGIT_VER=	1.11.1.2008
SONARVBNET_VER=		8.6.1.17183

USERS=		sonarqube
GROUPS=		sonarqube

SUB_LIST=	\
		APP_NAME=${APP_NAME} \
		APP_DIR=${APP_DIR} \
		JAVA_HOME=${JAVA_HOME} \
		JAVA=${JAVA} \
		LOG_DIR=${LOG_DIR} \
		PID_DIR=${PID_DIR} \
		JAR_VERSION=${JAR_VERSION} \
		DATA_DIR=${DATA_DIR} \
		TEMP_DIR=${TEMP_DIR}

SUB_FILES=	\
		${APP_NAME} \
		pkg-message

PLIST_SUB=	APP_NAME=${APP_NAME} \
		APP_DIR=${APP_DIR} \
		LOG_DIR=${LOG_DIR} \
		PID_DIR=${PID_DIR} \
		JAR_VERSION=${JAR_VERSION} \
		DBBASE_DIR=${DBBASE_DIR} \
		DATA_DIR=${DATA_DIR} \
		TEMP_DIR=${TEMP_DIR} \
		SONARCSHARP_VER=${SONARCSHARP_VER} \
		SONARJAVA_VER=${SONARJAVA_VER} \
		SONARJAVASCRIPT_VER=${SONARJAVASCRIPT_VER} \
		SONARPYTHON_VER=${SONARPYTHON_VER} \
		SONARSCMGIT_VER=${SONARSCMGIT_VER} \
		SONARVBNET_VER=${SONARVBNET_VER}

post-extract:
	${RM} -r ${WRKSRC}/bin ${WRKSRC}/lib/jsw ${WRKSRC}/conf/wrapper.conf
	${MV} ${WRKSRC}/conf/sonar.properties ${WRKSRC}/conf/sonar.properties.sample
.for plugin in sonar-csharp-plugin \
    sonar-java-plugin \
    sonar-javascript-plugin \
    sonar-python-plugin \
    sonar-scm-git-plugin \
    sonar-vbnet-plugin
	${RM} ${WRKSRC}/extensions/plugins/${plugin}-*.jar
.endfor
.for plugin in sonar-csharp-plugin-${SONARCSHARP_VER}.jar \
    sonar-java-plugin-${SONARJAVA_VER}.jar \
    sonar-javascript-plugin-${SONARJAVASCRIPT_VER}.jar \
    sonar-python-plugin-${SONARPYTHON_VER}.jar \
    sonar-scm-git-plugin-${SONARSCMGIT_VER}.jar \
    sonar-vbnet-plugin-${SONARVBNET_VER}.jar
	${CP} ${DISTDIR}/${plugin} ${WRKSRC}/extensions/plugins/
.endfor

post-patch:
	${REINPLACE_CMD} -e 's:%%LOG_DIR%%:${LOG_DIR}:g ; s:%%DATA_DIR%%:${DATA_DIR}:g ; s:%%TEMP_DIR%%:${TEMP_DIR}:g' ${WRKSRC}/conf/sonar.properties.sample

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${APP_DIR}/elasticsearch/plugins
	${MKDIR} ${STAGEDIR}${LOG_DIR} ${STAGEDIR}${PID_DIR} \
		${STAGEDIR}${DATA_DIR} ${STAGEDIR}${TEMP_DIR}
.for dir in conf elasticsearch extensions lib web
	cd ${WRKSRC}; ${COPYTREE_SHARE} ${dir} ${STAGEDIR}${PREFIX}/${APP_DIR} "! -name *\.orig"
.endfor

gen-plist:
	${ECHO} '@sample ${APP_DIR}/conf/sonar.properties.sample' >${PLIST}.new
	${ECHO} '@dir(sonarqube,sonarqube,755) %%DBBASE_DIR%%' >>${PLIST}.new
	${ECHO} '@dir(sonarqube,sonarqube,755) %%DATA_DIR%%' >>${PLIST}.new
	${ECHO} '@dir(sonarqube,sonarqube,755) %%TEMP_DIR%%' >>${PLIST}.new
	${ECHO} '@dir %%APP_DIR%%/elasticsearch/plugins' >>${PLIST}.new
#	${ECHO} '@dir(sonarqube,sonarqube,755) %%APP_DIR%%/extensions' >>${PLIST}.new
.for dir in conf elasticsearch lib web
	${FIND} ${STAGEDIR}${PREFIX}/${APP_DIR}/${dir} -type f |  \
	    ${SED} -e "s:${STAGEDIR}${PREFIX}/::g ; \
		s:${JAR_VERSION}:%%JAR_VERSION%%:g ; \
		s:\(.*elasticsearch/bin.*\):@(,,755) \1:g" | \
	    ${GREP} -v conf/sonar.properties.sample | ${SORT} >> ${PLIST}.new
.endfor
	${ECHO} '@owner sonarqube' >>${PLIST}.new
	${ECHO} '@group sonarqube' >>${PLIST}.new
.for dir in extensions
	${FIND} ${STAGEDIR}${PREFIX}/${APP_DIR}/${dir} -type d | \
	    ${SED} -e "s:${STAGEDIR}${PREFIX}/:@dir(sonarqube,sonarqube,755) :g" | \
	    ${SORT} >> ${PLIST}.new
	${FIND} ${STAGEDIR}${PREFIX}/${APP_DIR}/${dir} -type f | \
	    ${SED} -e "s:${STAGEDIR}${PREFIX}/::g ; \
		s:${JAR_VERSION}:%%JAR_VERSION%%:g ; \
		s:sonar-csharp-plugin-[0-9.]*.jar:sonar-csharp-plugin-%%SONARCSHARP_VER%%.jar:g ; \
		s:sonar-java-plugin-[0-9.]*.jar:sonar-java-plugin-%%SONARJAVA_VER%%.jar:g ; \
		s:sonar-javascript-plugin-[0-9.]*.jar:sonar-javascript-plugin-%%SONARJAVASCRIPT_VER%%.jar:g ; \
		s:sonar-python-plugin-[0-9.]*.jar:sonar-python-plugin-%%SONARPYTHON_VER%%.jar:g ; \
		s:sonar-scm-git-plugin-[0-9.]*.jar:sonar-scm-git-plugin-%%SONARSCMGIT_VER%%.jar:g ; \
		s:sonar-vbnet-plugin-[0-9.]*.jar:sonar-vbnet-plugin-%%SONARVBNET_VER%%.jar:g" | \
	    ${SORT} >> ${PLIST}.new
.endfor
	${ECHO} '@dir(sonarqube,sonarqube,755) %%LOG_DIR%%' >> ${PLIST}.new
	${ECHO} '@dir(sonarqube,sonarqube,755) %%PID_DIR%%' >> ${PLIST}.new

.include <bsd.port.mk>
