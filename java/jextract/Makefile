PORTNAME=	jextract
DISTVERSION=	g20260826
CATEGORIES=	java devel

MAINTAINER=	igor@kolesnik.es
COMMENT=	Generate Java bindings from native library headers
WWW=		https://openjdk.org/projects/code-tools/

LICENSE=	GPLv2

BUILD_DEPENDS=	gradle:devel/gradle

USES=		java llvm:build,run

USE_GITHUB=	yes
GH_ACCOUNT=	openjdk
GH_TAGNAME=	2aaa694aa6d241f4704f5ac69c1f8d898e7cfcc8
JAVA_VERSION=	25+

NO_ARCH=	yes
SUB_FILES=	jextract
SUB_LIST=	JAVA=${JAVA} LLVM_PREFIX=${LLVM_PREFIX} JAVAJARDIR=${JAVAJARDIR}

_GRADLE_ENV=	GRADLE_USER_HOME=${WRKDIR}/gradle-home \
		JAVA_VERSION=${JAVA_VERSION}
# JPMS module versions must start with a digit; strip the leading "g".
MODULE_VERSION=	${DISTVERSION:C/^g//}

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${_GRADLE_ENV} gradle --no-daemon \
		-Pjdk_home=${JAVA_HOME} \
		-Pllvm_home=${LLVM_PREFIX} \
		-Pversion=${MODULE_VERSION} \
		clean jar

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/jextract ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/build/libs/org.openjdk.jextract-${MODULE_VERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/org.openjdk.jextract.jar

.include <bsd.port.mk>
