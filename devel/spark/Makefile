PORTNAME=	spark
PORTVERSION=	3.3.4
CATEGORIES=	devel java
MASTER_SITES=	https://archive.apache.org/dist/${PORTNAME}/${PORTNAME}-${PORTVERSION}/ \
		LOCAL/vvd:deps
PKGNAMEPREFIX=	apache-
DISTFILES=	${PORTNAME}-${PORTVERSION}.tgz \
		${PORTNAME}-${PORTVERSION}-deps.tgz:deps

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Fast big data processing engine
WWW=		http://spark.apache.org/

LICENSE=	APACHE20

BROKEN_armv6=	fails to build: maven-assembly-plugin: Failed to retrieve numeric file attributes
BROKEN_armv7=	fails to build: maven-assembly-plugin: Failed to retrieve numeric file attributes

BUILD_DEPENDS=	${LOCALBASE}/lib/libsnappyjava.so:archivers/snappy-java \
		bash:shells/bash \
		maven>0:devel/maven
RUN_DEPENDS=	bash:shells/bash

USES=		cpe python shebangfix
CPE_VENDOR=	apache
USE_JAVA=	yes
JAVA_VERSION=	8 11 17

USE_RC_SUBR=	spark_master spark_worker
SHEBANG_FILES=	bin/sparkR

NO_ARCH=	yes

SUB_LIST=	SPARK_GROUP=spark \
		SPARK_USER=spark

USERS=		spark
GROUPS=		spark

PLIST_SUB=	VER=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?} || ${ARCH} == "i386"
MAKE_ENV+=	MAVEN_OPTS="-Xmx1g -XX:ReservedCodeCacheSize=1g" \
		JAVA_HOME=${JAVA_HOME}
.else
MAKE_ENV+=	MAVEN_OPTS="-Xmx2g -XX:ReservedCodeCacheSize=2g" \
		JAVA_HOME=${JAVA_HOME}
.endif

.if ${ARCH} == "amd64"
JAVA_ARCH=	x86_64
.elif ${ARCH} == "i386"
JAVA_ARCH=	x86
.else
JAVA_ARCH=	${ARCH}
.endif

# Update spark-*-dist.tgz if the hadoop version is changed!
HADOOP_VERSION=	3.3.4
# Comment out next line for download m2 and update ${PORTNAME}-${PORTVERSION}-deps.tgz
OFFLINE=	-o

do-build:
	${MKDIR} ${WRKDIR}/snappy/org/xerial/snappy/native/${OPSYS}/${JAVA_ARCH}
	${CP} ${LOCALBASE}/lib/libsnappyjava.so \
		${WRKDIR}/snappy/org/xerial/snappy/native/${OPSYS}/${JAVA_ARCH}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn ${OFFLINE} \
		-Duser.home=${WRKDIR} \
		-Dmaven.repo.local=${WRKDIR}/m2 \
		-Dhadoop.version=${HADOOP_VERSION} \
		-Pyarn -Phive -Phive-thriftserver -DskipTests \
		clean package
	${JAR} uvf ${WRKSRC}/assembly/target/scala*/jars/snappy-java-*.jar \
		-C ${WRKDIR}/snappy org

post-build:
	${RM} ${WRKSRC}/bin/*.cmd ${WRKSRC}/sbin/spark-daemon.sh.orig

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/lib ${STAGEDIR}${DATADIR}/examples/jars ${STAGEDIR}${DATADIR}/bin ${STAGEDIR}${DATADIR}/sbin ${STAGEDIR}${DATADIR}/conf
	${ECHO_CMD} "Spark ${PORTVERSION} built for Hadoop ${HADOOP_VERSION}" > ${STAGEDIR}${DATADIR}/RELEASE
	(cd  ${WRKSRC}/assembly/target/scala* && ${COPYTREE_SHARE} jars  ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/examples/target/spark-examples*.jar ${STAGEDIR}${DATADIR}/examples/jars
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} src ${STAGEDIR}${DATADIR}/examples
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} * ${STAGEDIR}${DATADIR}/bin/
	cd ${WRKSRC}/sbin && ${INSTALL_SCRIPT} * ${STAGEDIR}${DATADIR}/sbin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "python" ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/conf/*.template ${STAGEDIR}${DATADIR}/conf/
	${MKDIR} ${STAGEDIR}/var/run/spark
	${MKDIR} ${STAGEDIR}/var/log/spark

.include <bsd.port.post.mk>
