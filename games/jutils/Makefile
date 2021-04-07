PORTNAME=	jutils
PORTVERSION=	1.0.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games java

MAINTAINER=	voidanix@420blaze.it
COMMENT=	Common utilities for Java Game Technology Group projects

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	mvn:devel/maven

# Using a fork because of maven dependencies
USE_GITLAB=	yes
GL_ACCOUNT=	voidanix
GL_COMMIT=	f950e23e42081308b4be3b0fc4b57d4dbab70dac

USE_JAVA=	8+

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}/${PORTNAME}.jar
PLIST_DIRS=	${JAVAJARDIR}/${PORTNAME}

MAVEN_ARGS=	-Dmaven.antrun.skip -Dmaven.javadoc.skip -Dmaven.source.skip -Dmaven.test.skip -DskipTests -DskipITs
MAVEN_REPO=	-Dmaven.repo.local=${WRKSRC}/repository

do-build:
	cd ${WRKSRC}; \
		${SETENV} mvn ${MAVEN_REPO} ${MAVEN_ARGS} --offline package

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/target/${PORTNAME}-${PORTVERSION}-SNAPSHOT.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}/${PORTNAME}.jar

.include <bsd.port.mk>
