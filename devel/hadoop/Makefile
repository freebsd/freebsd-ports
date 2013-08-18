# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hadoop
PORTVERSION=	1.0.0
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	${PORTNAME}/core/${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	hadoop

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache Map/Reduce framework

LICENSE=	AL2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_JAVA=	yes
JAVA_VERSION=	1.6
USE_ANT=	yes
ONLY_FOR_ARCHS=	amd64 i386

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

BUILD_DEPENDS+=	${LOCALBASE}/bin/gmake:${PORTSDIR}/devel/gmake \
		${LOCALBASE}/bin/gsed:${PORTSDIR}/textproc/gsed
RUN_DEPENDS+=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

_HADOOP_DIR=	share/${PORTNAME}
_HADOOP_ETC=	etc/${PORTNAME}
HADOOP_HOME=	${PREFIX}/${_HADOOP_DIR}
HADOOP_ETC=	${PREFIX}/${_HADOOP_ETC}

HADOOP_LOGDIR=	/var/log/${PORTNAME}
HADOOP_RUNDIR=	/var/run/${PORTNAME}
HADOOP_BIN=	${PREFIX}/bin/${PORTNAME}

USERS=		hadoop
GROUPS=		hadoop
HADOOP_USER=	${USERS}
HADOOP_GROUP=	${GROUPS}

SUB_FILES+=	pkg-install pkg-deinstall hadoop 000.java_home.env
USE_RC_SUBR+=	tasktracker jobtracker datanode namenode secondarynamenode

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"\
		HADOOP_HOME="${_HADOOP_DIR}" \
		HADOOP_ETC="${_HADOOP_ETC}"
SUB_LIST=	HADOOP_LOGDIR="${HADOOP_LOGDIR}" \
		HADOOP_RUNDIR="${HADOOP_RUNDIR}" \
		HADOOP_USER="${HADOOP_USER}" \
		HADOOP_GROUP="${HADOOP_GROUP}" \
		HADOOP_UID="${HADOOP_UID}" \
		HADOOP_GID="${HADOOP_GID}" \
		HADOOP_HOME="${HADOOP_HOME}" \
		HADOOP_ETC="${HADOOP_ETC}" \
		JAVA_HOME="${JAVA_HOME}"

PORTDOCS=	*
FIX_PERMS=	src/c++/pipes/install-sh src/c++/utils/install-sh src/c++/libhdfs/install-sh \
		src/c++/libhdfs/tests/test-libhdfs.sh

FIX_DOCS=	docs/cn/skin/css docs/cn/skin/scripts docs/cn/skin/translations \
		docs/jdiff docs/skin/css docs/skin/scripts docs/skin/translations

DOC=		CHANGES.txt LICENSE.txt NOTICE.txt README.txt

DEFAULTS=	src/core/core-default.xml src/hdfs/hdfs-default.xml src/mapred/mapred-default.xml hadoop-examples-${PORTVERSION}.jar

DIST=		bin contrib hadoop-ant-${PORTVERSION}.jar hadoop-core-${PORTVERSION}.jar \
		hadoop-test-${PORTVERSION}.jar hadoop-tools-${PORTVERSION}.jar lib webapps
CONF=		capacity-scheduler.xml configuration.xsl core-site.xml hadoop-env.sh hadoop-metrics2.properties \
		hadoop-policy.xml hdfs-site.xml log4j.properties mapred-queue-acls.xml mapred-site.xml taskcontroller.cfg

MAKE_ARGS=	-Dbuild.classes=${WRKSRC}/hadoop-core-${PORTVERSION}.jar -Dversion=${PORTVERSION} -Dcompile.native=true \
		-Dcompile.c++=true -Dmake.cmd=${GMAKE} -Dlibhdfs=1 -Dlibrecordio=true  -Dskip.record-parser=true
ALL_TARGET=	compile-core-native compile-c++ compile-c++-libhdfs compile-c++-pipes compile-c++-utils

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
_HADOOP_ARCH=	FreeBSD-amd64-64
.else
_HADOOP_ARCH=	FreeBSD-i386-32
.endif
PLIST_SUB+=	HADOOP_ARCH=${_HADOOP_ARCH}

pre-build:
.for f in ${FIX_PERMS}
	@${CHMOD} +x ${WRKSRC}/${f}
.endfor
.for d in ${FIX_DOCS}
	@${TOUCH} ${WRKSRC}/${d}/.empty
.endfor

#do-build:
#	@cd ${WRKSRC}; \
#	${ANT} -Dbuild.classes=${WRKSRC}/hadoop-core-${PORTVERSION}.jar -Dversion=${PORTVERSION} -Dcompile.native=true \
#	-Dcompile.c++=true -Dmake.cmd=${GMAKE} compile-core-native compile-c++ compile-c++-libhdfs compile-c++-pipes \
#	compile-c++-utils -Dlibhdfs=1 -Dlibrecordio=true  -Dskip.record-parser=true

post-build:
	@cd ${WRKSRC} ;${ANT} FreeBSD-dist
	@${TAR} -cf - -C ${WRKSRC}/build/c++/ ${_HADOOP_ARCH}/lib ${_HADOOP_ARCH}/include | ${TAR} xf - -C ${WRKSRC}/c++/

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${HADOOP_HOME}
	@${TAR} -cf - -C ${WRKSRC}/ ${DIST}  | ${TAR} -xf - -C ${HADOOP_HOME}

	@${MKDIR} ${HADOOP_ETC} ${HADOOP_ETC}/envvars.d
	@${INSTALL_DATA} ${WRKDIR}/000.java_home.env ${HADOOP_ETC}/envvars.d/
	@${ECHO} "export HADOOP_HOME=${HADOOP_HOME}" > ${HADOOP_ETC}/envvars.d/001.hadoop_home.env
	@${ECHO} "export HADOOP_CONF_DIR=${HADOOP_ETC}" > ${HADOOP_ETC}/envvars.d/002.hadoop_conf.env
	@${ECHO} "export HADOOP_LOG_DIR=${HADOOP_LOGDIR}" > ${HADOOP_ETC}/envvars.d/003.hadoop_log.env
	@${ECHO} "export HADOOP_PID_DIR=${HADOOP_RUNDIR}" > ${HADOOP_ETC}/envvars.d/004.hadoop_run.env
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} -cf - -C ${WRKSRC}/c++/${_HADOOP_ARCH}/  include lib| ${TAR} xf - -C ${PREFIX}

.for f in ${DEFAULTS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${EXAMPLESDIR}
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${TAR} -cf - -C ${WRKSRC}/ docs | ${TAR} -xf - -C ${DOCSDIR}
.for f in ${DOC}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${INSTALL_SCRIPT} ${WRKDIR}/hadoop ${PREFIX}/bin/
	@cd ${WRKSRC}; ${COPYTREE_SHARE} conf ${EXAMPLESDIR}
.for f in ${CONF}
	@[ -f ${HADOOP_ETC}/${f} ] || ${INSTALL_DATA} ${EXAMPLESDIR}/conf/${f} ${HADOOP_ETC}
.endfor

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
