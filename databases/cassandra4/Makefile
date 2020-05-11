# $FreeBSD$

PORTNAME=	cassandra
DISTVERSION=	4.0-alpha4
CATEGORIES=	databases java
MASTER_SITES=	APACHE/cassandra/${DISTVERSION}:apache \
		https://repo1.maven.org/maven2/com/github/luben/zstd-jni/1.4.4-9/:maven \
		LOCAL/pi:repo
PKGNAMESUFFIX=	4
DISTNAME=	apache-${PORTNAME}-${DISTVERSION}-src
DISTFILES=	${DISTNAME}.tar.gz:apache \
		zstd-jni-1.4.4-9-freebsd_amd64.jar:maven \
		apache-${PORTNAME}-${DISTVERSION}-repo.tar.gz:repo
EXTRACT_ONLY=	${DISTNAME}.tar.gz \
		apache-${PORTNAME}-${DISTVERSION}-repo.tar.gz

MAINTAINER=	language.devel@gmail.com
COMMENT=	Highly scalable distributed database

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	snappyjava>=0:archivers/snappy-java \
		netty>0:java/netty

USES=		python:3.7
USE_JAVA=	yes
USE_ANT=	yes
USE_RC_SUBR=	cassandra
TEST_TARGET=	test

CONFLICTS=	cassandra3

JAVA_VERSION=	8 11
JAVA_VENDOR=	openjdk

REINPLACE_ARGS=	-i ''
SUB_LIST=	JAVA_HOME=${JAVA_HOME}

USERS=		cassandra
GROUPS=		cassandra

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
BUILD_DIST_DIR=	${WRKSRC}/build/dist
REPO_DIR=	${WRKDIR}/repository

CONFIG_FILES=	cassandra-env.sh \
		cassandra-jaas.config \
		cassandra-rackdc.properties \
		cassandra-topology.properties \
		cassandra.yaml \
		commitlog_archiving.properties \
		hotspot_compiler \
		logback-tools.xml \
		logback.xml \
		jvm8-clients.options \
		jvm8-server.options \
		jvm11-clients.options \
		jvm11-server.options \
		jvm-clients.options \
		jvm-server.options

SCRIPT_FILES=	cassandra \
		nodetool \
		sstableloader \
		sstablescrub \
		sstableupgrade \
		sstableutil \
		sstableverify

PLIST_SUB=	DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=		SIGAR DOCS
OPTIONS_DEFAULT=	SIGAR
OPTIONS_SUB=		yes

SIGAR_DESC=		Use SIGAR to collect system information
SIGAR_RUN_DEPENDS=	java-sigar>=1.6.4:java/sigar

DOCS_BUILD_DEPENDS=	${PY_SPHINX} \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR}

PORTDOCS=		*

do-build:
	@${DO_NADA} # Do nothing: Prevent USE_ANT from running a default build target.

do-build-DOCS-on:
	cd ${WRKSRC} && ${SETENV} CASSANDRA_LOG_DIR=${WRKDIR}/gen-doc-log ${ANT} -Dmaven.repo.local=${REPO_DIR} -Dlocalm2=${REPO_DIR} ${USEJDK11} -Dpycmd=${PYTHON_CMD} -Dpyver=${PYTHON_VER} freebsd-stage-doc

do-build-DOCS-off:
	cd ${WRKSRC} && ${ANT} -Dmaven.repo.local=${REPO_DIR} -Dlocalm2=${REPO_DIR} ${USEJDK11} freebsd-stage

post-build:
.for f in ${SCRIPT_FILES}
	@${REINPLACE_CMD} -e 's|/usr/share/cassandra|${DATADIR}/bin|' ${BUILD_DIST_DIR}/bin/${f}
.endfor
	@${REINPLACE_CMD} -e 's|\`dirname "\$$\0"\`/..|${DATADIR}|' ${BUILD_DIST_DIR}/bin/cassandra.in.sh
	@${REINPLACE_CMD} -e 's|\$$\CASSANDRA_HOME/lib/sigar-bin|${JAVAJARDIR}|' ${BUILD_DIST_DIR}/bin/cassandra.in.sh
	@${REINPLACE_CMD} -e 's|\$$\CASSANDRA_HOME/lib/sigar-bin|${JAVAJARDIR}|' ${BUILD_DIST_DIR}/conf/cassandra-env.sh
	@${REINPLACE_CMD} -e 's|\$$\CASSANDRA_HOME/conf|${ETCDIR}|' ${BUILD_DIST_DIR}/bin/cassandra.in.sh
.for f in ${CONFIG_FILES}
	@${MV} ${BUILD_DIST_DIR}/conf/${f} ${BUILD_DIST_DIR}/conf/${f}.sample
.endfor
	@${RM} ${BUILD_DIST_DIR}/lib/licenses/sigar*
	@${RMDIR} ${BUILD_DIST_DIR}/lib/sigar-bin
	@${RM} ${BUILD_DIST_DIR}/lib/zstd-jni*
	@${RM} ${BUILD_DIST_DIR}/lib/licenses/zstd-jni*

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
.for f in CHANGES LICENSE NEWS NOTICE
	cd ${BUILD_DIST_DIR} && ${INSTALL_DATA} ${f}.txt ${STAGEDIR}${DATADIR}/
.endfor
.for d in lib pylib tools
	cd ${BUILD_DIST_DIR} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR}/ "! -path '*/bin/*'"
.endfor
	${MKDIR} ${STAGEDIR}${ETCDIR}
	cd ${BUILD_DIST_DIR}/conf && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR}/
	cd ${BUILD_DIST_DIR} && ${COPYTREE_BIN} bin ${STAGEDIR}${DATADIR}
	cd ${BUILD_DIST_DIR} && ${INSTALL_DATA} bin/cassandra.in.sh ${STAGEDIR}${DATADIR}/bin/
	cd ${BUILD_DIST_DIR} && ${COPYTREE_BIN} tools/bin ${STAGEDIR}${DATADIR}/
	cd ${BUILD_DIST_DIR} && ${INSTALL_DATA} tools/bin/cassandra.in.sh ${STAGEDIR}${DATADIR}/tools/bin/
.for f in ${SCRIPT_FILES}
	${RLN} ${STAGEDIR}${DATADIR}/bin/${f} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
	${RLN} ${STAGEDIR}${DATADIR}/bin/cqlsh ${STAGEDIR}${PREFIX}/bin/cqlsh
	${LN} -s ${JAVAJARDIR}/snappy-java.jar ${STAGEDIR}${DATADIR}/lib/snappy-java.jar

do-test:
	@cd ${WRKSRC} && ${ANT} -Dmaven.repo.local=${REPO_DIR} -Dlocalm2=${REPO_DIR} ${USEJDK11} -Dstagedlib=${STAGEDIR}${DATADIR}/lib test

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION} == 11
USEJDK11=	-Duse.jdk11=true
.endif

.if ${ARCH} == amd64
PLIST_SUB+=		AMD64ONLY=""
.else
PLIST_SUB+=		AMD64ONLY="@comment "
.endif

post-install:
	${LN} -s ${JAVAJARDIR}/netty.jar ${STAGEDIR}${DATADIR}/lib/netty.jar
.if ${ARCH} == amd64
	${CP} ${DISTDIR}/zstd-jni-1.4.4-9-freebsd_amd64.jar ${STAGEDIR}${DATADIR}/lib/
.endif

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for d in doc javadoc
	cd ${BUILD_DIST_DIR} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DOCSDIR}/
.endfor

post-install-SIGAR-on:
	${LN} -s ${JAVAJARDIR}/sigar.jar ${STAGEDIR}${DATADIR}/lib/sigar.jar

.include <bsd.port.post.mk>
