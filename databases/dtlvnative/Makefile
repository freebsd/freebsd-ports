PORTNAME=	dtlvnative
DISTVERSION=	0.16.4
CATEGORIES=	databases java

MAINTAINER=	markus.graf@markusgraf.net
COMMENT=	Datalevin native dependency

LICENSE=	EPL

BUILD_DEPENDS=	${JAVALIBDIR}/javacpp.jar:java/javacpp

USES=		java

LIB_DEPENDS=	libusearch_c.so:math/usearch \
		libdlmdb.so:databases/dlmdb

JAVA_VERSION=	21+
JAVA_ARCH=      ${ARCH:S/^amd64/x86_64/}

ONLY_FOR_ARCHS=	amd64

USE_GITHUB=	yes
GH_ACCOUNT=	datalevin

LDFLAGS+=	-L${PREFIX}/lib -L..
CFLAGS+=	-I${PREFIX}/include

do-build:
#  Compile libdtlv.so
		cd ${WRKSRC}/src && \
		${CC} ${CFLAGS} -pthread -fPIC -O2 -Wall -g -c dtlv.c -o dtlv.o

		cd ${WRKSRC}/src && \
		${CXX} ${CXXFLAGS} ${LDFLAGS} -pthread -shared -fPIC -o libdtlv.so dtlv.o -L. -ldlmdb -lomp -lusearch_c

# Build libjniDTLV.so
		cd ${WRKSRC}/src/java && ${JAVA} -jar ${JAVAJARDIR}/javacpp.jar datalevin/dtlvnative/DTLV.java

# Compile jar
		cd ${WRKSRC} && ${JAVAC} -encoding UTF-8 -d bin \
			-sourcepath src/java \
			-classpath ${JAVAJARDIR}/javacpp.jar \
			$$(find src/java -name "*.java")

		cd ${WRKSRC} && ${JAR} cvf ${PORTNAME}.jar -C bin .

do-test:
		cd ${WRKSRC} && ${JAVA} \
			--enable-native-access=ALL-UNNAMED \
			--add-opens=java.base/java.nio=ALL-UNNAMED \
			--add-opens=java.base/sun.nio.ch=ALL-UNNAMED \
			-classpath bin:${JAVAJARDIR}/javacpp.jar \
			-Djava.library.path="src/java/datalevin/dtlvnative/freebsd-x86_64" \
			datalevin.dtlvnative.Test

do-install:
		${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${DISTVERSION}.jar
		${LN} -sf ${PORTNAME}-${DISTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
		${INSTALL_LIB} ${WRKSRC}/src/libdtlv.so ${STAGEDIR}${PREFIX}/lib/
		${INSTALL_LIB} ${WRKSRC}/src/java/datalevin/dtlvnative/freebsd-${JAVA_ARCH}/libjniDTLV.so ${STAGEDIR}${PREFIX}/lib/
.include <bsd.port.mk>
