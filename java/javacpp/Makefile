PORTNAME=	javacpp
DISTVERSION=	1.5.13
CATEGORIES=	java devel
MASTER_SITES=	https://repo1.maven.org/maven2/org/bytedeco/${PORTNAME}/${DISTVERSION}/ \
		https://codeload.github.com/bytedeco/${PORTNAME}/tar.gz/${DISTVERSION}?dummy=/:test
DISTFILES=	${DISTNAME}.jar \
		${GH_ACCOUNT}-${DISTNAME}_GH0.tar.gz:test # USE_GITHUB changes DISTVERSION etc.
EXTRACT_ONLY=

MAINTAINER=	markus.graf@markusgraf.net
COMMENT=	Java-C++ bridge generator
WWW=		https://github.com/bytedeco/javacpp

LICENSE=	APACHE20

USES=		java

TEST_DEPENDS=	${JAVALIBDIR}/junit.jar:java/junit \
		${JAVALIBDIR}/hamcrest.jar:java/hamcrest \
		mvn:devel/maven

TESTING_UNSAFE=	Requires network access

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Needs upstream patch per arch

JAVA_VERSION=	21

GH_ACCOUNT=	bytedeco
NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}-${DISTVERSION}.jar \
		${JAVAJARDIR}/${PORTNAME}.jar

do-install:
	${INSTALL_DATA} -v ${DISTDIR}/${DISTNAME}.jar ${STAGEDIR}/${JAVAJARDIR}/
	${LN} -vsf ${DISTNAME}.jar ${STAGEDIR}/${JAVAJARDIR}/${PORTNAME}.jar

do-test:
# Only extract for test, not on build servers
	${TAR} xf ${DISTDIR}/${GH_ACCOUNT}-${DISTNAME}_GH0.tar.gz -C ${WRKDIR}
	cd ${WRKSRC} && mvn test

.include <bsd.port.mk>
