PORTNAME=	javacpp
DISTVERSION=	1.5.13
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	https://repo1.maven.org/maven2/org/bytedeco/${PORTNAME}/${DISTVERSION}/
DISTFILES=	${DISTNAME}.jar
EXTRACT_ONLY=

MAINTAINER=	markus.graf@markusgraf.net
COMMENT=	Java-C++ bridge generator
WWW=		https://github.com/bytedeco/javacpp

LICENSE=	APACHE20

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	Needs upstream patch per arch

TEST_DEPENDS=	${JAVALIBDIR}/junit.jar:java/junit \
		${JAVALIBDIR}/hamcrest.jar:java/hamcrest \
		mvn:devel/maven

USES=		java

USE_GITHUB=	nodefault
GH_ACCOUNT=	bytedeco:test
GH_PROJECT=	${PORTNAME}:test

NO_BUILD=	yes

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}-${DISTVERSION}.jar \
		${JAVAJARDIR}/${PORTNAME}.jar

TESTING_UNSAFE=	Requires network access

do-install:
	${INSTALL_DATA} -v ${DISTDIR}/${DISTNAME}.jar ${STAGEDIR}/${JAVAJARDIR}/
	${LN} -vsf ${DISTNAME}.jar ${STAGEDIR}/${JAVAJARDIR}/${PORTNAME}.jar

do-test:
# Only extract for test, not on build servers
	${TAR} xf ${DISTDIR}/${DISTFILES:[2]:C/:.*//} -C ${WRKDIR}
	cd ${WRKSRC} && mvn test

.include <bsd.port.mk>
