PORTNAME=	spark
DISTVERSION=	4.2.0
CATEGORIES=	devel java
MASTER_SITES=	https://archive.apache.org/dist/${PORTNAME}/${PORTNAME}-${DISTVERSION}/ \
		https://github.com/protocolbuffers/protobuf/releases/download/v${PROTOBUF_VERSION}/:protobuf \
		https://github.com/abseil/abseil-cpp/releases/download/${ABSEIL_VERSION}/:abseil
PKGNAMEPREFIX=	apache-
DISTFILES=	${PORTNAME}-${DISTVERSION}.tgz \
		protobuf-${PROTOBUF_VERSION}.tar.gz:protobuf \
		abseil-cpp-${ABSEIL_VERSION}.tar.gz:abseil

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Fast big data processing engine
WWW=		https://spark.apache.org/

LICENSE=	APACHE20

BROKEN_armv6=	fails to build: maven-assembly-plugin: Failed to retrieve numeric file attributes
BROKEN_armv7=	fails to build: maven-assembly-plugin: Failed to retrieve numeric file attributes
BROKEN_i386=	not enough memory on this architecture to build the port
BROKEN_powerpc=	not enough memory on this architecture to build the port

BUILD_DEPENDS=	${LOCALBASE}/lib/libsnappyjava.so:archivers/snappy-java \
		bash:shells/bash \
		maven39>0:devel/maven39
RUN_DEPENDS=	bash:shells/bash

USES=		cmake:indirect compiler:c++17-lang cpe java ninja:build python \
		shebangfix
CPE_VENDOR=	apache

# Maven Central has no protoc and protoc-gen-grpc-java for FreeBSD, so both
# are built here, linked statically against a libprotoc of the protobuf
# release below (the shared libprotoc of devel/protobuf does not export the
# java::ClassName() functions protoc-gen-grpc-java uses).
PROTOBUF_VERSION=	29.6
ABSEIL_VERSION=		20250127.1
USE_GITHUB=	nodefault
GH_TUPLE=	grpc:grpc-java:v1.76.0:grpcjava
JAVA_VERSION=	17+
USE_RC_SUBR=	spark_master spark_worker
SHEBANG_FILES=	bin/sparkR

PROTOC_BUILD=	${WRKDIR}/protoc-build
CMAKE_ARGS=	-DPROTOBUF_SOURCE_DIR=${WRKDIR}/protobuf-${PROTOBUF_VERSION} \
		-DABSL_ROOT_DIR=${WRKDIR}/abseil-cpp-${ABSEIL_VERSION} \
		-DGRPC_JAVA_SOURCE_DIR=${WRKSRC_grpcjava} \
		-DCMAKE_CXX_STANDARD=17 \
		-Dprotobuf_ABSL_PROVIDER=module
CMAKE_ON=	ABSL_PROPAGATE_CXX_STD
CMAKE_OFF=	protobuf_BUILD_CONFORMANCE protobuf_BUILD_EXAMPLES \
		protobuf_BUILD_LIBUPB protobuf_BUILD_SHARED_LIBS \
		protobuf_BUILD_TESTS protobuf_INSTALL
MAKE_ENV+=	SPARK_PROTOC_EXEC_PATH=${PROTOC_BUILD}/protobuf/protoc \
		CONNECT_PLUGIN_EXEC_PATH=${PROTOC_BUILD}/protoc-gen-grpc-java

NO_ARCH=	yes
SUB_LIST=	SPARK_GROUP=${GROUPS} \
		SPARK_USER=${USERS}
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}
PLIST_SUB=	SCALA=${SCALA_BINARY} \
		VER=${DISTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?} || ${ARCH} == "i386"
MAKE_ENV+=	MAVEN_OPTS="-Xss64m -Xmx1g -XX:ReservedCodeCacheSize=1g" \
		JAVA_HOME=${JAVA_HOME}
.else
MAKE_ENV+=	MAVEN_OPTS="-Xss64m -Xmx4g -XX:ReservedCodeCacheSize=1g" \
		JAVA_HOME=${JAVA_HOME}
.endif

JAVA_ARCH=	${ARCH:S|amd64|x86_64|:S|i386|x86|}

# Update ${PORTNAME}-${DISTVERSION}-deps.tgz if the hadoop version is changed!
HADOOP_VERSION=	3.5.0
SCALA_BINARY=	2.13

# To create the local maven repository (m2) run: make -DMAINTAINER_MODE build
# and then: make -DMAINTAINER_MODE make-deps
# The deps tarball is built by .github/workflows/spark-deps.yml and published
# in the spark-${DISTVERSION} release of github.com/Martinfx/FreeBSD-Ports.
.if !defined(MAINTAINER_MODE)
MASTER_SITES+=	https://github.com/Martinfx/FreeBSD-Ports/releases/download/spark-${DISTVERSION}/:deps
DISTFILES+=	${PORTNAME}-${DISTVERSION}-deps.tgz:deps
OFFLINE=	-o
.endif # !defined(MAINTAINER_MODE)

pre-build:
	${MKDIR} ${WRKDIR}/protoc-src
	${CP} ${FILESDIR}/protoc-CMakeLists.txt ${WRKDIR}/protoc-src/CMakeLists.txt
	${CMAKE_BIN} -S ${WRKDIR}/protoc-src -B ${PROTOC_BUILD} -G Ninja \
		${CMAKE_ARGS}
	${CMAKE_BIN} --build ${PROTOC_BUILD} -j ${MAKE_JOBS_NUMBER}

do-build:
	${MKDIR} ${WRKDIR}/snappy/org/xerial/snappy/native/${OPSYS}/${JAVA_ARCH}
	${CP} ${LOCALBASE}/lib/libsnappyjava.so \
		${WRKDIR}/snappy/org/xerial/snappy/native/${OPSYS}/${JAVA_ARCH}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn ${OFFLINE} \
		-Duser.home=${WRKDIR} \
		-Dmaven.repo.local=${WRKDIR}/m2 \
		-Dhadoop.version=${HADOOP_VERSION} \
		-Dmaven.version=3.9 \
		-Pyarn -Phive -Phive-thriftserver -Puser-defined-protoc \
		-DskipTests \
		clean package
	${JAR} uvf ${WRKSRC}/assembly/target/scala-${SCALA_BINARY}/jars/snappy-java-*.jar \
		-C ${WRKDIR}/snappy org

post-build:
	${RM} ${WRKSRC}/bin/*.cmd ${WRKSRC}/sbin/spark-daemon.sh.orig

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/lib \
		 ${STAGEDIR}${DATADIR}/examples/jars \
		 ${STAGEDIR}${DATADIR}/bin \
		 ${STAGEDIR}${DATADIR}/sbin \
		 ${STAGEDIR}${DATADIR}/conf
	${ECHO_CMD} "Spark ${DISTVERSION} built for Hadoop ${HADOOP_VERSION}" \
		> ${STAGEDIR}${DATADIR}/RELEASE
	(cd ${WRKSRC}/assembly/target/scala-${SCALA_BINARY} && \
		${COPYTREE_SHARE} "jars" ${STAGEDIR}${DATADIR})
	cd ${WRKSRC}/examples/target/scala-${SCALA_BINARY}/jars && \
		for f in *.jar; do \
			${TEST} -f ${WRKSRC}/assembly/target/scala-${SCALA_BINARY}/jars/$$f || \
			${INSTALL_DATA} $$f ${STAGEDIR}${DATADIR}/examples/jars; \
		done
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} "src" ${STAGEDIR}${DATADIR}/examples
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} * ${STAGEDIR}${DATADIR}/bin/
	cd ${WRKSRC}/sbin && ${INSTALL_SCRIPT} * ${STAGEDIR}${DATADIR}/sbin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "python" ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/conf/*.template ${STAGEDIR}${DATADIR}/conf/
	${MKDIR} ${STAGEDIR}/var/run/spark
	${MKDIR} ${STAGEDIR}/var/log/spark

make-deps:
	cd ${WRKDIR} && ${TAR} -czf ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps.tgz m2

.include <bsd.port.post.mk>
