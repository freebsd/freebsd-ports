PORTNAME=	javacpp
DISTVERSION=	1.5.13
CATEGORIES=	java devel

MAINTAINER=	markus.graf@markusgraf.net
COMMENT=	Java-C++ bridge generator
WWW=		https://github.com/bytedeco/javacpp

LICENSE=	APACHE20

USES=		java

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:java/junit \
		${JAVALIBDIR}/hamcrest.jar:java/hamcrest

JAVA_VERSION=	11+
JAVA_ARCH=      ${ARCH:S/^amd64/x86_64/}

USE_GITHUB=	yes
GH_ACCOUNT=	bytedeco

do-build:
# Compile to JVM bytecode
	@cd ${WRKSRC} && ${JAVAC} -encoding UTF-8 -d bin \
		-sourcepath src/main/java:stubs \
		$$(find src/main/java -name "*.java" \
		! -name "*Mojo.java" \
		! -name "package-info.java")
# Remove stubs
	${RM} -rf ${WRKSRC}/bin/org/osgi
	${RM} -rf ${WRKSRC}/bin/org/slf4j
# Put into jar and add freebsd-*.properties
	@cd ${WRKSRC} && \
		${JAR} cvfe ${PORTNAME}.jar org.bytedeco.javacpp.tools.Builder -C bin . \
		&& cd src/main/resources \
		&& ${JAR} uvf ../../../${PORTNAME}.jar org/bytedeco/javacpp/properties/freebsd-*.properties

do-test:
# Build a blank bridge. This is what the tests will do.
#	@cd ${WRKSRC} && ${JAVA} -cp ${PORTNAME}.jar \
#		org.bytedeco.javacpp.tools.Builder \
#		org.bytedeco.javacpp.Pointer

# Compile tests
	@cd ${WRKSRC} && ${JAVAC} -encoding UTF-8 \
		-classpath "javacpp.jar:${JAVAJARDIR}/junit.jar" \
		-d bin-tests \
		$$(find src/test/java -name "*.java")

# Run unit tests.  maxbytes and maxretries seem to be hardcoded in the tests
	@cd ${WRKSRC} && ${JAVA} -Djava.library.path=./ \
		-Dorg.bytedeco.javacpp.maxphysicalbytes=2147483648 \
		-Dorg.bytedeco.javacpp.maxbytes=1073741824 \
		-Dorg.bytedeco.javacpp.maxretries=3 \
		-Xmx2048m \
		-classpath "javacpp.jar:bin-tests:${JAVAJARDIR}/junit.jar:${JAVAJARDIR}/hamcrest.jar" \
		org.junit.runner.JUnitCore org.bytedeco.javacpp.PointerTest

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/

.include <bsd.port.mk>
