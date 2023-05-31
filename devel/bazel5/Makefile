PORTNAME=	bazel
DISTVERSION=	5.4.1 # please make sure that science/py-tensorflow builds before updating
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/bazelbuild/${PORTNAME}/releases/download/${DISTVERSION}/
DISTNAME=	bazel-${DISTVERSION}-dist
PKGNAMESUFFIX=	5

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Fast and correct build system
WWW=		https://bazel.build/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
BROKEN_armv6=	fails to package: cp: bazel: No such file or directory
BROKEN_armv7=	fails to package: cp: bazel: No such file or directory
BROKEN_FreeBSD_12_powerpc64=	fails to compile: Action failed to execute: java.io.IOException: Cannot run program /usr/bin/clang

BUILD_DEPENDS=	bash:shells/bash \
		zip:archivers/zip

USES=		cpe python shebangfix zip

CPE_VENDOR=	google

USE_JAVA=	yes
JAVA_VERSION=	11
JAVA_VENDOR=	openjdk
JAVA_BUILD=	yes
JAVA_RUN=	yes

SHEBANG_REGEX=	.*(sh|txt|_stub|stub_.*|bazel|get_workspace_status|protobuf_support|_so)

CONFLICTS_INSTALL=	bazel[0-9]*

# The bazel binary is also a zip archive (extracted by the elf part), it must not be stripped
STRIP=

NO_WRKSUBDIR=	YES

# In bazel, a release is always code-wise identical to the final release candidate.
# Hence we can also download that one and so have a simple way to also test earlier release
# candidates.
FINALRC=	2

.include <bsd.port.pre.mk>

.if ${ARCH} == "aarch64"
BAZEL_JAVAC_OPTS+=	"-J-Xmx1g -J-Xms128m"
.endif

pre-patch:
	@${CP} ${FILESDIR}/extra-patch-abseil-cpp_absl_base_internal_unscaledcycleclock.cc \
		${FILESDIR}/extra-patch-abseil-cpp-cfe27e79cfcbefb2b4479e04f80cbb299bc46965 \
		${WRKSRC}/third_party/py/abseil/
	@${CP} ${FILESDIR}/extra-patch-grpc_bazel_grpc__deps.bzl \
		${FILESDIR}/extra-patch-upb_bazel_build__defs.bzl \
		${WRKSRC}/third_party/grpc/

# Have the location of the system-wide rc file reside ${ETCDIR}.
# Also adapt the sample file to disable persistent java workers as they
# do not work reliably on FreeBSD.
post-patch:
	@${REINPLACE_CMD} -e "s|/etc/bazel.bazelrc|${ETCDIR}/bazel.bazelrc|" \
		${WRKSRC}/src/main/cpp/BUILD
	@${ECHO_CMD} build --strategy=Javac=standalone >> ${WRKSRC}/scripts/packages/bazel.bazelrc
	@${ECHO_CMD} build --java_runtime_version=${JAVA_VERSION} >> ${WRKSRC}/scripts/packages/bazel.bazelrc
	@${ECHO_CMD} build --tool_java_runtime_version=${JAVA_VERSION} >> ${WRKSRC}/scripts/packages/bazel.bazelrc
	@${ECHO_CMD} build --action_env=PATH=/bin:/usr/bin/:${LOCALBASE}/bin >> ${WRKSRC}/scripts/packages/bazel.bazelrc
	@${REINPLACE_CMD} \
		-e 's|^\(PYTHON_BIN=.*\)|if [ "%VERSION%" = "3" ] ; then PYTHON_BIN=${PYTHON_CMD}; else \1 ; fi|' \
		${WRKSRC}/tools/python/pywrapper_template.txt
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKSRC}/src/main/java/com/google/devtools/build/lib/bazel/rules/python/BazelPythonSemantics.java
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/src/main/java/com/google/devtools/build/lib/bazel/rules/python/python_stub_template.txt
	@${REINPLACE_CMD} -e 's|%%JAVA_HOME%%|${JAVA_HOME}|' \
		${WRKSRC}/src/main/cpp/blaze_util_bsd.cc

do-build:
	@${MKDIR} ${WRKDIR}/bazel_tmp
	(if [ -z "$${SOURCE_DATE_EPOCH}" ] ; \
	  then SOURCE_DATE_EPOCH=`grep TIMESTAMP ${DISTINFO_FILE} \
	    | ${SED} -e 's/[^0-9]//g'`; \
	fi ; \
	cd ${WRKSRC} && \
	${SETENV} BAZEL_SH=${LOCALBASE}/bin/bash \
	JAVA_HOME=${JAVA_HOME} \
	JAVA_VERSION=${JAVA_VERSION} \
	TMPDIR=${WRKDIR}/bazel_tmp \
	EMBED_LABEL='${PORTVERSION}' \
	PATH=${LOCALBASE}/bin:$$PATH \
	SOURCE_DATE_EPOCH=$${SOURCE_DATE_EPOCH} \
	BAZEL_JAVAC_OPTS=${BAZEL_JAVAC_OPTS} \
	EXTRA_BAZEL_ARGS='--host_javabase=@local_jdk//:jdk --tool_java_runtime_version=local_jdk   --java_language_version=${JAVA_VERSION}  --tool_java_language_version=${JAVA_VERSION}' \
	${LOCALBASE}/bin/bash ./compile.sh)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/bazel ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/packages/bazel.bazelrc ${STAGEDIR}${ETCDIR}/bazel.bazelrc.sample

.include <bsd.port.post.mk>
