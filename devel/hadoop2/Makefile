# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

# Please do not submit untested updates.  Be sure to start hadoop in
# distributed mode and to run few map/reduce.  Be sure there are no exception
# in any of it's log files.  This version was tested under the load and
# no problems encountered so far.  Thanks.
PORTNAME=	hadoop
PORTVERSION=	2.7.2
PORTREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	APACHE/${PORTNAME}/common/hadoop-${PORTVERSION} \
		LOCAL/demon/:maven \
		http://archive.apache.org/dist/tomcat/tomcat-6/v${TOMCAT_VERSION}/bin/:tomcat \
		LOCAL/demon/:jetty
PKGNAMESUFFIX=	2
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} FreeBSD-hadoop2-${PORTVERSION}-maven-repository.tar.gz:maven apache-tomcat-${TOMCAT_VERSION}.tar.gz:tomcat jetty-6.1.14.zip:jetty
DIST_SUBDIR=	hadoop
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} FreeBSD-hadoop2-${PORTVERSION}-maven-repository.tar.gz jetty-6.1.14.zip

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Apache Map/Reduce framework

LICENSE=	APACHE20

BROKEN_SSL=	openssl111
BROKEN_SSL_REASON_openssl111=	incomplete definition of type 'struct evp_cipher_ctx_st'

BUILD_DEPENDS=	${LOCALBASE}/share/java/maven3/bin/mvn:devel/maven3 \
		cmake:devel/cmake \
		${LOCALBASE}/protobuf25/bin/protoc:devel/protobuf25
LIB_DEPENDS=	libsnappy.so:archivers/snappy
RUN_DEPENDS=	bash:shells/bash \
		ssid:sysutils/ssid

CONFLICTS_INSTALL=	hadoop-1* yarn

USES=		cpe shebangfix
CPE_VENDOR=	apache
USE_JAVA=	yes
USE_LDCONFIG=	yes
SHEBANG_FILES=	hadoop-hdfs-project/hadoop-hdfs-httpfs/src/main/sbin/httpfs.sh hadoop-hdfs-project/hadoop-hdfs-httpfs/src/main/libexec/httpfs-config.sh hadoop-hdfs-project/hadoop-hdfs-httpfs/src/main/conf/httpfs-env.sh hadoop-common-project/hadoop-kms/src/main/sbin/kms.sh hadoop-common-project/hadoop-kms/src/main/libexec/kms-config.sh hadoop-common-project/hadoop-kms/src/main/conf/kms-env.sh hadoop-tools/hadoop-sls/src/main/bin/rumen2sls.sh hadoop-tools/hadoop-sls/src/main/bin/slsrun.sh
MAKE_ENV+=	JAVA_HOME=${JAVA_HOME} HADOOP_PROTOC_PATH=${LOCALBASE}/protobuf25/bin/protoc

OPTIONS_DEFINE=		EXAMPLES

TOMCAT_VERSION=	6.0.44
HADOOP_DIST=	${WRKSRC}/hadoop-dist/target/hadoop-${PORTVERSION}

HADOOP_LOGDIR=	/var/log/hadoop
HADOOP_RUNDIR=	/var/run/hadoop

HDFS_USER=	hdfs
MAPRED_USER=	mapred
HADOOP_GROUP=	hadoop
USERS=		${HDFS_USER} ${MAPRED_USER}
GROUPS=		${HADOOP_GROUP}

SUB_FILES=	hadoop-layout.sh httpfs-env.sh kms-env.sh
USE_RC_SUBR=	historyserver nodemanager resourcemanager webappproxyserver datanode namenode secondarynamenode journalnode zkfc

PLIST_SUB=	PORTVERSION="${PORTVERSION}" \
		HADOOP_LOGDIR="${HADOOP_LOGDIR}" \
		HADOOP_RUNDIR="${HADOOP_RUNDIR}" \
		HDFS_USER="${HDFS_USER}" \
		MAPRED_USER="${MAPRED_USER}" \
		HADOOP_GROUP="${HADOOP_GROUP}"
SUB_LIST=	HDFS_USER="${HDFS_USER}" \
		MAPRED_USER="${MAPRED_USER}" \
		HADOOP_GROUP="${HADOOP_GROUP}" \
		JAVA_HOME="${JAVA_HOME}" \
		HADOOP_LOGDIR="${HADOOP_LOGDIR}" \
		HADOOP_RUNDIR="${HADOOP_RUNDIR}"

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	incomplete definition of type 'struct evp_cipher_ctx_st'
BROKEN_FreeBSD_13=	incomplete definition of type 'struct evp_cipher_ctx_st'
.endif

post-patch:
	${REINPLACE_CMD} -e "s#/bin/bash#${LOCALBASE}/bin/bash#" ${WRKSRC}/hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/java/org/apache/hadoop/yarn/server/nodemanager/DefaultContainerExecutor.java ${WRKSRC}/hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-core/src/main/java/org/apache/hadoop/mapreduce/MRJobConfig.java ${WRKSRC}/hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/java/org/apache/hadoop/yarn/server/nodemanager/containermanager/launcher/ContainerLaunch.java ${WRKSRC}/hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/util/Shell.java ${WRKSRC}/hadoop-common-project/hadoop-common/src/main/bin/hadoop-daemon.sh

do-build:
	${MKDIR} ${WRKSRC}/hadoop-hdfs-project/hadoop-hdfs-httpfs/downloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/apache-tomcat-${TOMCAT_VERSION}.tar.gz ${WRKSRC}/hadoop-hdfs-project/hadoop-hdfs-httpfs/downloads/
	${MKDIR} ${WRKSRC}/hadoop-common-project/hadoop-kms/downloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/apache-tomcat-${TOMCAT_VERSION}.tar.gz ${WRKSRC}/hadoop-common-project/hadoop-kms/downloads/
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/share/java/maven3/bin/mvn -Dmaven.repo.local=${WRKDIR}/m2 --offline package -Pdist,native -DskipTests -Drequire.snappy -Dsnappy.prefix=${LOCALBASE} -Drequire.openssl

post-build:
	${RM} ${HADOOP_DIST}/etc/hadoop/*.cmd
	${MV} ${HADOOP_DIST}/bin/rcc ${HADOOP_DIST}/bin/hadoop-rcc
# With jetty-6.1.26 tasktracker's threads hung with the following error:
# org.mortbay.io.nio.SelectorManager$SelectSet@abdcc1c JVM BUG(s) - injecting delay 59 times
# See https://issues.apache.org/jira/browse/MAPREDUCE-2386
.for dir in share/hadoop/common/lib share/hadoop/hdfs/lib share/hadoop/yarn/lib share/hadoop/tools/lib
	${RM} ${HADOOP_DIST}/${dir}/jetty-util-6.1.26.jar ${HADOOP_DIST}/${dir}/jetty-6.1.26.jar
	${CP} ${WRKDIR}/jetty-6.1.14/lib/jetty-6.1.14.jar ${WRKDIR}/jetty-6.1.14/lib/jetty-util-6.1.14.jar ${HADOOP_DIST}/${dir}/
.endfor
.for dir in share/hadoop/httpfs/tomcat/webapps/webhdfs/WEB-INF/lib share/hadoop/kms/tomcat/webapps/kms/WEB-INF/lib
	${RM} ${HADOOP_DIST}/${dir}/jetty-util-6.1.26.jar
	${CP} ${WRKDIR}/jetty-6.1.14/lib/jetty-util-6.1.14.jar ${HADOOP_DIST}/${dir}/
.endfor

do-install:
	cd ${HADOOP_DIST}/bin && ${INSTALL_SCRIPT} hadoop hdfs mapred hadoop-rcc yarn ${STAGEDIR}${PREFIX}/bin/
	cd ${HADOOP_DIST} && ${COPYTREE_BIN} "libexec sbin" ${STAGEDIR}${PREFIX}/ "! -name *.cmd"
	cd ${HADOOP_DIST}/include && ${INSTALL_DATA} *h ${STAGEDIR}${PREFIX}/include/
	cd ${HADOOP_DIST}/lib/native && ${INSTALL_DATA} *.a ${STAGEDIR}${PREFIX}/lib/
	cd ${HADOOP_DIST}/lib/native && ${INSTALL_DATA} libhadoop.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/libhadoop.so.1
	cd ${HADOOP_DIST}/lib/native && ${INSTALL_DATA} libhdfs.so.0.0.0 ${STAGEDIR}${PREFIX}/lib/libhdfs.so.0
	${LN} -sf libhdfs.so.0 ${STAGEDIR}${PREFIX}/lib/libhdfs.so
	${LN} -sf libhadoop.so.1 ${STAGEDIR}${PREFIX}/lib/libhadoop.so
	cd ${HADOOP_DIST}/share/hadoop && ${COPYTREE_SHARE} "*" ${STAGEDIR}${DATADIR}/ "! -name *-sources.jar -and ! -name sources"
	${CHMOD} a+x ${STAGEDIR}${DATADIR}/kms/tomcat/bin/*.sh ${STAGEDIR}${DATADIR}/httpfs/tomcat/bin/*.sh
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/conf
	cd ${HADOOP_DIST}/etc/hadoop && ${COPYTREE_SHARE} "*" ${STAGEDIR}${EXAMPLESDIR}/conf/
	${INSTALL_DATA} ${WRKSRC}/hadoop-hdfs-project/hadoop-hdfs/target/classes/hdfs-default.xml ${WRKSRC}/hadoop-hdfs-project/hadoop-hdfs-httpfs/target/classes/httpfs-default.xml ${WRKSRC}/hadoop-yarn-project/hadoop-yarn/hadoop-yarn-common/target/classes/yarn-default.xml ${WRKSRC}/hadoop-common-project/hadoop-common/target/classes/core-default.xml ${WRKSRC}/hadoop-tools/hadoop-distcp/target/classes/distcp-default.xml ${WRKSRC}/hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-core/target/classes/mapred-default.xml ${STAGEDIR}/${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKDIR}/hadoop-layout.sh ${STAGEDIR}${PREFIX}/libexec/
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/httpfs-env.sh ${STAGEDIR}${PREFIX}/etc/hadoop/
	${INSTALL_DATA} ${WRKDIR}/kms-env.sh ${STAGEDIR}${PREFIX}/etc/hadoop/
	${MKDIR} ${STAGEDIR}${HADOOP_LOGDIR}
	${MKDIR} ${STAGEDIR}${HADOOP_RUNDIR}

.include <bsd.port.post.mk>
