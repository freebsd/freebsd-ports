PORTNAME=	jinput
DISTVERSION=	2.0.10
PORTEPOCH=	1
CATEGORIES=	games java

MAINTAINER=	voidanix@420blaze.it
COMMENT=	Java Game Controller API
WWW=		https://github.com/jinput/jinput

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${JAVAJARDIR}/jutils/jutils.jar:games/jutils \
		maven>0:devel/maven
RUN_DEPENDS=	${JAVAJARDIR}/jutils/jutils.jar:games/jutils

# Using a fork because of maven dependencies
USE_GITLAB=	yes
GL_ACCOUNT=	voidanix
GL_TAGNAME=	bf22dd975bbba31f01895332255b63df376894e6

USE_JAVA=	8+

PLIST_DIRS=	${JAVAJARDIR}/${PORTNAME}
PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}/${PORTNAME}.jar

MAVEN_ARGS=	-Dmaven.antrun.skip -Dmaven.javadoc.skip -Dmaven.source.skip -Dmaven.test.skip -DskipTests -DskipITs
MAVEN_REPO=	-Dmaven.repo.local=${WRKSRC}/repository

pre-build:
	${CP} ${JAVAJARDIR}/jutils/jutils.jar ${WRKSRC}/repository/net/java/jutils/jutils/1/jutils-1.jar
	${SED} -i -e '/example/d; s|<arg>-Werror</arg>||' ${WRKSRC}/pom.xml
	# 1) example/ReadAllEvents.java:[5,28] cannot find symbol ...
	# 2) [ERROR] warnings found and -Werror specified ...

do-build:
	cd ${WRKSRC}; \
		${SETENV} mvn -P windows,linux,osx,wintab ${MAVEN_REPO} ${MAVEN_ARGS} --offline package

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/uberjar/target/${PORTNAME}-${PORTVERSION}-SNAPSHOT.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}/${PORTNAME}.jar

.include <bsd.port.mk>
