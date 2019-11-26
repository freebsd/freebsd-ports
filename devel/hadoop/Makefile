# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hadoop
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	devel java
MASTER_SITES=	APACHE/${PORTNAME}/core/${PORTNAME}-${PORTVERSION} \
		http://dist.codehaus.org/jetty/jetty-6.1.14/:jetty
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} jetty-6.1.14.zip:jetty
DIST_SUBDIR=	hadoop

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	Apache Map/Reduce framework

LICENSE=	APACHE20

BROKEN_SSL=	openssl111
BROKEN_SSL_REASON_openssl111=	variable has incomplete type 'HMAC_CTX' (aka 'hmac_ctx_st')

BUILD_DEPENDS=	gmake:devel/gmake \
		gsed:textproc/gsed
RUN_DEPENDS=	bash:shells/bash

CONFLICTS_INSTALL=	hadoop2-2*

USES=		cpe libtool ssl:build
CPE_VENDOR=	apache
USE_JAVA=	yes
USE_ANT=	yes
ONLY_FOR_ARCHS=	amd64 i386
USE_LDCONFIG=	yes
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

OPTIONS_DEFINE=	DOCS

HADOOP_LOGDIR=	/var/log/${PORTNAME}
HADOOP_RUNDIR=	/var/run/${PORTNAME}

HDFS_USER=	hdfs
MAPRED_USER=	mapred
HADOOP_GROUP=	hadoop
USERS=		${HDFS_USER} ${MAPRED_USER}
GROUPS=		${HADOOP_GROUP}

SUB_FILES=	hadoop 000.java_home.env
USE_RC_SUBR=	tasktracker jobtracker datanode namenode secondarynamenode

PLIST_SUB=	PORTVERSION="${PORTVERSION}" \
		HADOOP_LOGDIR="${HADOOP_LOGDIR}" \
		HADOOP_RUNDIR="${HADOOP_RUNDIR}" \
		HDFS_USER="${HDFS_USER}" \
		MAPRED_USER="${MAPRED_USER}" \
		HADOOP_GROUP="${HADOOP_GROUP}"
SUB_LIST=	HDFS_USER="${HDFS_USER}" \
		MAPRED_USER="${MAPRED_USER}" \
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
		-Dcompile.c++=true -Dmake.cmd=gmake -Dlibhdfs=1 -Dlibrecordio=true  -Dskip.record-parser=true
ALL_TARGET=	compile-core-native compile-c++ compile-c++-libhdfs compile-c++-pipes compile-c++-utils

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	variable has incomplete type 'HMAC_CTX' (aka 'hmac_ctx_st')
BROKEN_FreeBSD_13=	variable has incomplete type 'HMAC_CTX' (aka 'hmac_ctx_st')
.endif

# The ssl.mk helper can augment MAKE_ARGS and break the build.  Filter out
# the OPENSSL_CFLAGS if it exists to prevent that from happening.
MAKE_ARGS:=	${MAKE_ARGS:NOPENSSL_CFLAGS=*}

.if ${ARCH} == "amd64"
_HADOOP_ARCH=	FreeBSD-amd64-64
.else
_HADOOP_ARCH=	FreeBSD-${ARCH}-32
.endif
PLIST_SUB+=	HADOOP_ARCH=${_HADOOP_ARCH}

post-patch:
	@${REINPLACE_CMD} -e 's/ -DCPU=\\\\\\".*\\\\\\"//' \
		${WRKSRC}/src/c++/libhdfs/configure
	@${REINPLACE_CMD} 's/-lssl/-lcrypto/' \
		${WRKSRC}/src/c++/pipes/configure \
		${WRKSRC}/src/examples/pipes/configure
.for f in ${FIX_GCC}
	@${REINPLACE_CMD} -e 's/`gcc/`$$LTCC/' ${WRKSRC}/${f}
.endfor
.for f in ${FIX_PERMS}
	@${CHMOD} +x ${WRKSRC}/${f}
.endfor
.for d in ${FIX_DOCS}
	@${TOUCH} ${WRKSRC}/${d}/.empty
.endfor
# With jetty-6.1.26 tasktracker's threads hung with the following error:
# org.mortbay.io.nio.SelectorManager$SelectSet@abdcc1c JVM BUG(s) - injecting delay 59 times
# See https://issues.apache.org/jira/browse/MAPREDUCE-2386
	${RM} ${WRKSRC}/lib/jetty-6.1.26.jar ${WRKSRC}/lib/jetty-util-6.1.26.jar
	${CP} ${WRKDIR}/jetty-6.1.14/lib/jetty-6.1.14.jar ${WRKDIR}/jetty-6.1.14/lib/jetty-util-6.1.14.jar ${WRKSRC}/lib/

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
	${INSTALL_DATA} ${WRKSRC}/src/c++/libhdfs/hdfs.h ${STAGEDIR}${PREFIX}/include/hadoop/

.for f in ${DEFAULTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

	${INSTALL_SCRIPT} ${WRKDIR}/hadoop ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} conf ${STAGEDIR}${EXAMPLESDIR}
	${MKDIR} ${STAGEDIR}${HADOOP_LOGDIR}
	${MKDIR} ${STAGEDIR}${HADOOP_RUNDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}
.for f in ${DOC}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
