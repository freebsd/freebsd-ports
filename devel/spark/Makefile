PORTNAME=	spark
PORTVERSION=	3.3.0
CATEGORIES=	devel java
MASTER_SITES=	https://archive.apache.org/dist/${PORTNAME}/${PORTNAME}-${PORTVERSION}/
PKGNAMEPREFIX=	apache-
DISTFILES=	${PORTNAME}-${PORTVERSION}.tgz

MAINTAINER=	freebsd@sysctl.cz
COMMENT=	Fast big data processing engine

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/lib/libsnappyjava.so:archivers/snappy-java \
		bash:shells/bash \
		mvn:devel/maven

RUN_DEPENDS=	bash:shells/bash

USES=		cpe python shebangfix
CPE_VENDOR=	apache
USE_JAVA=	yes
MAKE_ENV+=	JAVA_HOME=${JAVA_HOME} \
		MAVEN_OPTS="-Xmx2g -XX:MaxPermSize=512M -XX:ReservedCodeCacheSize=512m"

SHEBANG_FILES=	bin/sparkR

USERS=		spark
GROUPS=		spark

USE_RC_SUBR=	spark_master spark_worker
PLIST_SUB+=	SPARK_GROUP=spark \
		SPARK_USER=spark \
		VER=${PORTVERSION}
SUB_LIST+=	SPARK_GROUP=spark \
		SPARK_USER=spark

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
JAVA_ARCH=	x86_64
.elif ${ARCH} == "i386"
JAVA_ARCH=	x86
.else
JAVA_ARCH=	${ARCH}
.endif

do-build:
	${MKDIR} ${WRKDIR}/snappy/org/xerial/snappy/native/${OPSYS}/${JAVA_ARCH}
	${CP} ${LOCALBASE}/lib/libsnappyjava.so \
		${WRKDIR}/snappy/org/xerial/snappy/native/${OPSYS}/${JAVA_ARCH}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LOCALBASE}/bin/mvn \
		-Dmaven.repo.local=${WRKDIR}/m2 clean package \
		-Dhadoop.version=3.3.1 -Pyarn -Phive -Phive-thriftserver -DskipTests \
		-Duser.home=${WRKDIR}
	${JAR} uvf ${WRKSRC}/assembly/target/scala*/jars/snappy-java-*.jar \
		-C ${WRKDIR}/snappy org

post-build:
	${RM} ${WRKSRC}/bin/*.cmd ${WRKSRC}/sbin/spark-daemon.sh.orig

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/lib ${STAGEDIR}${DATADIR}/examples/jars ${STAGEDIR}${DATADIR}/bin ${STAGEDIR}${DATADIR}/sbin ${STAGEDIR}${DATADIR}/conf
	${ECHO_CMD} "Spark ${PORTVERSION} built for Hadoop 3.3.1" > ${STAGEDIR}${DATADIR}/RELEASE
	(cd  ${WRKSRC}/assembly/target/scala* && ${COPYTREE_SHARE} jars  ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/examples/target/spark-examples*.jar ${STAGEDIR}${DATADIR}/examples/jars
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} src ${STAGEDIR}${DATADIR}/examples
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} * ${STAGEDIR}${DATADIR}/bin/
	cd ${WRKSRC}/sbin && ${INSTALL_SCRIPT} * ${STAGEDIR}${DATADIR}/sbin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} python ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/conf/*.template ${STAGEDIR}${DATADIR}/conf/
	${MKDIR} ${STAGEDIR}/var/run/spark
	${MKDIR} ${STAGEDIR}/var/log/spark

.include <bsd.port.post.mk>
