# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hadoop
PORTVERSION=	2.4.1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=${PORTNAME}/common/stable
PKGNAMEPREFIX=	apache-
PKGNAMESUFFIX=	2
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DIST_SUBDIR=	hadoop

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Apache Map/Reduce framework

LICENSE=	APACHE20

BUILD_DEPENDS=	mvn:${PORTSDIR}/devel/maven3 \
		cmake:${PORTSDIR}/devel/cmake \
		protoc:${PORTSDIR}/devel/protobuf
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

CONFLICTS_INSTALL=	apache-hadoop-1*

USES=		shebangfix
USE_JAVA=	yes
JAVA_VERSION=	1.7+
USE_LDCONFIG=	yes
SHEBANG_FILES=	hadoop-hdfs-project/hadoop-hdfs-httpfs/src/main/sbin/httpfs.sh hadoop-hdfs-project/hadoop-hdfs-httpfs/src/main/libexec/httpfs-config.sh
MAKE_ENV+=	HADOOP_PROTOC_PATH=${LOCALBASE}/bin/protoc

MANUAL_PACKAGE_BUILD=	maven fetches files during build

HADOOP_DIST=	${WRKSRC}/hadoop-dist/target/hadoop-${PORTVERSION}

HADOOP_LOGDIR=  /var/log/hadoop
HADOOP_RUNDIR=  /var/run/hadoop

HDFS_USER=      hdfs
MAPRED_USER=    mapred
HADOOP_GROUP=   hadoop
USERS=          ${HDFS_USER} ${MAPRED_USER}
GROUPS=         ${HADOOP_GROUP}

SUB_FILES=	hadoop-layout.sh
USE_RC_SUBR=    historyserver nodemanager resourcemanager webappproxyserver datanode namenode secondarynamenode

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
	${MKDIR} ${WRKDIR}/m2
	${CP} ${FILESDIR}/settings.xml ${WRKDIR}
	${REINPLACE_CMD} -e "s|WORK|${WRKDIR}|" ${WRKDIR}/settings.xml

do-build:
	cd ${WRKSRC} && ${LOCALBASE}/bin/mvn -gs "${WRKDIR}/settings.xml" clean package -Pdist,native -DskipTests

post-build:
	${RM} ${HADOOP_DIST}/etc/hadoop/*.cmd

do-install:
	cd ${HADOOP_DIST}/bin && ${INSTALL_SCRIPT} hadoop hdfs mapred rcc yarn ${STAGEDIR}${PREFIX}/bin/
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
