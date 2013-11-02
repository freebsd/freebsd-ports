# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hadoop
PORTVERSION=	1.2.1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	${PORTNAME}/core/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	apache-
DIST_SUBDIR=	hadoop

MAINTAINER=	pfg@apache.org
COMMENT=	Apache Map/Reduce framework

LICENSE=	AL2

BUILD_DEPENDS=	gmake:${PORTSDIR}/devel/gmake \
		gsed:${PORTSDIR}/textproc/gsed
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_JAVA=	yes
JAVA_VERSION=	1.6
USE_ANT=	yes
DESTDIRNAME=	-Ddestdir
ONLY_FOR_ARCHS= amd64 i386

OPTIONS_DEFINE=	DOCS

HADOOP_LOGDIR=	/var/log/${PORTNAME}
HADOOP_RUNDIR=	/var/run/${PORTNAME}

HADOOP_USER=	hadoop
HADOOP_GROUP=	hadoop
USERS=		${HADOOP_USER}
GROUPS=		${HADOOP_GROUP}

SUB_FILES=	hadoop 000.java_home.env
USE_RC_SUBR=	tasktracker jobtracker datanode namenode secondarynamenode

PLIST_SUB=	PORTVERSION="${PORTVERSION}" \
		HADOOP_LOGDIR="${HADOOP_LOGDIR}" \
		HADOOP_RUNDIR="${HADOOP_RUNDIR}" \
		HADOOP_USER="${HADOOP_USER}" \
		HADOOP_GROUP="${HADOOP_GROUP}"
SUB_LIST=	HADOOP_USER="${HADOOP_USER}" \
		HADOOP_GROUP="${HADOOP_GROUP}" \
		JAVA_HOME="${JAVA_HOME}"

PORTDOCS=	*

FIX_GCC=	src/c++/libhdfs/configure src/c++/pipes/configure \
		src/c++/task-controller/configure src/c++/utils/configure \
		src/examples/pipes/configure src/native/configure
FIX_PERMS=	src/c++/pipes/install-sh src/c++/utils/install-sh \
		src/c++/libhdfs/install-sh src/c++/libhdfs/tests/test-libhdfs.sh
FIX_DOCS=	docs/jdiff docs/skin/css docs/skin/scripts docs/skin/translations

DOC=		CHANGES.txt LICENSE.txt NOTICE.txt README.txt

DEFAULTS=	src/core/core-default.xml src/hdfs/hdfs-default.xml src/mapred/mapred-default.xml hadoop-examples-${PORTVERSION}.jar

DIST=		bin contrib hadoop-ant-${PORTVERSION}.jar hadoop-core-${PORTVERSION}.jar \
		hadoop-test-${PORTVERSION}.jar hadoop-tools-${PORTVERSION}.jar lib webapps
CONF=		capacity-scheduler.xml configuration.xsl core-site.xml hadoop-env.sh hadoop-metrics2.properties \
		hadoop-policy.xml hdfs-site.xml log4j.properties mapred-queue-acls.xml mapred-site.xml taskcontroller.cfg

MAKE_ARGS=	-Dbuild.classes=${WRKSRC}/hadoop-core-${PORTVERSION}.jar -Dversion=${PORTVERSION} -Dcompile.native=true \
		-Dcompile.c++=true -Dmake.cmd=${GMAKE} -Dlibhdfs=1 -Dlibrecordio=true  -Dskip.record-parser=true
ALL_TARGET=	compile-core-native compile-c++ compile-c++-libhdfs compile-c++-pipes compile-c++-utils

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
_HADOOP_ARCH=	FreeBSD-amd64-64
.else
_HADOOP_ARCH=	FreeBSD-${ARCH}-32
.endif
PLIST_SUB+=	HADOOP_ARCH=${_HADOOP_ARCH}

post-patch:
	@${REINPLACE_CMD} -e 's/ -DCPU=\\\\\\".*\\\\\\"//' \
		${WRKSRC}/src/c++/libhdfs/configure
.for f in ${FIX_GCC}
	@${REINPLACE_CMD} -e 's/`gcc/`$$LTCC/' ${WRKSRC}/${f}
.endfor
.for f in ${FIX_PERMS}
	@${CHMOD} +x ${WRKSRC}/${f}
.endfor
.for d in ${FIX_DOCS}
	@${TOUCH} ${WRKSRC}/${d}/.empty
.endfor

post-build:
	@cd ${WRKSRC} ;${ANT} FreeBSD-dist
	@${TAR} -cf - -C ${WRKSRC}/build/c++/ ${_HADOOP_ARCH}/lib ${_HADOOP_ARCH}/include | ${TAR} xf - -C ${WRKSRC}/c++/

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${TAR} -cf - -C ${WRKSRC} ${DIST} | ${TAR} -xf - -C ${STAGEDIR}${DATADIR}

	${MKDIR} ${STAGEDIR}${ETCDIR}/envvars.d
	${INSTALL_DATA} ${WRKDIR}/000.java_home.env ${STAGEDIR}${ETCDIR}/envvars.d
	${ECHO} "export HADOOP_PREFIX=${DATADIR}" > ${STAGEDIR}${ETCDIR}/envvars.d/001.hadoop_home.env
	${ECHO} "export HADOOP_CONF_DIR=${ETCDIR}" > ${STAGEDIR}${ETCDIR}/envvars.d/002.hadoop_conf.env
	${ECHO} "export HADOOP_LOG_DIR=${HADOOP_LOGDIR}" > ${STAGEDIR}${ETCDIR}/envvars.d/003.hadoop_log.env
	${ECHO} "export HADOOP_PID_DIR=${HADOOP_RUNDIR}" > ${STAGEDIR}${ETCDIR}/envvars.d/004.hadoop_run.env
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${TAR} -cf - -C ${WRKSRC}/c++/${_HADOOP_ARCH} include lib | ${TAR} xf - -C ${STAGEDIR}${PREFIX}

.for f in ${DEFAULTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}
.for f in ${DOC}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/hadoop ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} conf ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${HADOOP_LOGDIR}
	${MKDIR} ${STAGEDIR}${HADOOP_RUNDIR}

.include <bsd.port.mk>
