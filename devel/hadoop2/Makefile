# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hadoop
PORTVERSION=	2.4.1
PORTREVISION=	4
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE} \
		LOCAL/demon/:maven \
		http://people.freebsd.org/~demon/:maven \
		http://archive.apache.org/dist/tomcat/tomcat-6/v${TOMCAT_VERSION}/bin/:tomcat \
		http://dist.codehaus.org/jetty/jetty-6.1.14/:jetty
MASTER_SITE_SUBDIR=${PORTNAME}/common/stable
PKGNAMESUFFIX=	2
DISTFILES=	${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX} FreeBSD-hadoop2-${PORTVERSION}-maven-repository.tar.gz:maven apache-tomcat-${TOMCAT_VERSION}.tar.gz:tomcat jetty-6.1.14.zip:jetty
DIST_SUBDIR=	hadoop

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Apache Map/Reduce framework

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/share/java/maven3/bin/mvn:${PORTSDIR}/devel/maven3 \
		cmake:${PORTSDIR}/devel/cmake \
		${LOCALBASE}/protobuf25/bin/protoc:${PORTSDIR}/devel/protobuf25
LIB_DEPENDS=	libsnappy.so:${PORTSDIR}/archivers/snappy
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

CONFLICTS_INSTALL=	apache-hadoop-1*

USES=		shebangfix
USE_JAVA=	yes
JAVA_VERSION=	1.7+
USE_LDCONFIG=	yes
SHEBANG_FILES=	hadoop-hdfs-project/hadoop-hdfs-httpfs/src/main/sbin/httpfs.sh hadoop-hdfs-project/hadoop-hdfs-httpfs/src/main/libexec/httpfs-config.sh
MAKE_ENV+=	HADOOP_PROTOC_PATH=${LOCALBASE}/protobuf25/bin/protoc
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

TOMCAT_VERSION=	6.0.36
HADOOP_DIST=	${WRKSRC}/hadoop-dist/target/hadoop-${PORTVERSION}

HADOOP_LOGDIR=	/var/log/hadoop
HADOOP_RUNDIR=	/var/run/hadoop

HDFS_USER=	hdfs
MAPRED_USER=	mapred
HADOOP_GROUP=	hadoop
USERS=		${HDFS_USER} ${MAPRED_USER}
GROUPS=		${HADOOP_GROUP}

SUB_FILES=	hadoop-layout.sh
USE_RC_SUBR=	historyserver nodemanager resourcemanager webappproxyserver datanode namenode secondarynamenode

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

post-patch:
	${REINPLACE_CMD} -e "s#/bin/bash#${LOCALBASE}/bin/bash#" ${WRKSRC}/hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/java/org/apache/hadoop/yarn/server/nodemanager/DefaultContainerExecutor.java ${WRKSRC}/hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-core/src/main/java/org/apache/hadoop/mapreduce/MRJobConfig.java ${WRKSRC}/hadoop-yarn-project/hadoop-yarn/hadoop-yarn-server/hadoop-yarn-server-nodemanager/src/main/java/org/apache/hadoop/yarn/server/nodemanager/containermanager/launcher/ContainerLaunch.java ${WRKSRC}/hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/util/Shell.java

do-build:
	${MKDIR} ${WRKSRC}/hadoop-hdfs-project/hadoop-hdfs-httpfs/downloads
	${CP} ${DISTDIR}/${DIST_SUBDIR}/apache-tomcat-${TOMCAT_VERSION}.tar.gz ${WRKSRC}/hadoop-hdfs-project/hadoop-hdfs-httpfs/downloads/
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/share/java/maven3/bin/mvn -Dmaven.repo.local=${WRKDIR}/m2 --offline clean package -Pdist,native -DskipTests -Drequire.snappy -Dsnappy.prefix=${LOCALBASE}

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
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/conf
	cd ${HADOOP_DIST}/etc/hadoop && ${COPYTREE_SHARE} "*" ${STAGEDIR}${EXAMPLESDIR}/conf/
	${INSTALL_DATA} ${WRKSRC}/hadoop-hdfs-project/hadoop-hdfs/target/classes/hdfs-default.xml ${WRKSRC}/hadoop-hdfs-project/hadoop-hdfs-httpfs/target/classes/httpfs-default.xml ${WRKSRC}/hadoop-yarn-project/hadoop-yarn/hadoop-yarn-common/target/classes/yarn-default.xml ${WRKSRC}/hadoop-common-project/hadoop-common/target/classes/core-default.xml ${WRKSRC}/hadoop-tools/hadoop-distcp/target/classes/distcp-default.xml ${WRKSRC}/hadoop-mapreduce-project/hadoop-mapreduce-client/hadoop-mapreduce-client-core/target/classes/mapred-default.xml ${STAGEDIR}/${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKDIR}/hadoop-layout.sh ${STAGEDIR}${PREFIX}/libexec/
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${HADOOP_LOGDIR}
	${MKDIR} ${STAGEDIR}${HADOOP_RUNDIR}

.include <bsd.port.mk>
