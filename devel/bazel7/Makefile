PORTNAME=	bazel
DISTVERSION=	7.7.1
CATEGORIES=	devel java
MASTER_SITES=	https://github.com/bazelbuild/${PORTNAME}/releases/download/${DISTVERSION}/
PKGNAMESUFFIX=	7
DISTNAME=	bazel-${DISTVERSION}-dist

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast and correct build system (LTS 7)
WWW=		https://bazel.build/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386

BUILD_DEPENDS=	bash:shells/bash \
		zip:archivers/zip

USES=		cpe java python shebangfix zip
CPE_VENDOR=	google
JAVA_VERSION=	21
JAVA_VENDOR=	openjdk

SHEBANG_REGEX=	.*(sh|txt|_stub|stub_.*|bazel|get_workspace_status|protobuf_support|_so)

CONFLICTS_INSTALL=	bazel[0-9]*

# The bazel binary is also a zip archive (extracted by the elf part), it must not be stripped
STRIP=

NO_WRKSUBDIR=	YES

.include <bsd.port.pre.mk>

.if ${ARCH} == "aarch64"
BAZEL_JAVAC_OPTS+=	"-J-Xmx1g -J-Xms128m"
.endif

pre-patch:
	@${CP} ${FILESDIR}/extra-patch-abseil-cpp-cfe27e79cfcbefb2b4479e04f80cbb299bc46965 \
		${WRKSRC}/third_party/py/abseil/
	@${CP} ${FILESDIR}/extra-patch-abseil-cpp-cfe27e79cfcbefb2b4479e04f80cbb299bc46965 \
		${FILESDIR}/extra-patch-grpc_bazel_grpc__deps.bzl \
		${FILESDIR}/extra-patch-upb_bazel_build__defs.bzl \
		${WRKSRC}/third_party/grpc/

# Have the location of the system-wide rc file reside ${ETCDIR}.
# Also adapt the sample file to disable persistent java workers as they
# do not work reliably on FreeBSD.
post-patch:
	@${REINPLACE_CMD} -e "s|/etc/bazel.bazelrc|${ETCDIR}/bazel.bazelrc|" \
		${WRKSRC}/src/main/cpp/BUILD
	@${ECHO_CMD} build --strategy=Javac=standalone >> ${WRKSRC}/scripts/packages/bazel.bazelrc
	@${ECHO_CMD} build --java_runtime_version=${JAVA_PORT_VERSION} >> ${WRKSRC}/scripts/packages/bazel.bazelrc
	@${ECHO_CMD} build --tool_java_runtime_version=${JAVA_PORT_VERSION} >> ${WRKSRC}/scripts/packages/bazel.bazelrc
	@${ECHO_CMD} build --action_env=PATH=/bin:/usr/bin/:${LOCALBASE}/bin >> ${WRKSRC}/scripts/packages/bazel.bazelrc
	@${REINPLACE_CMD} \
		-e 's|^\(PYTHON_BIN=.*\)|if [ "%VERSION%" = "3" ] ; then PYTHON_BIN=${PYTHON_CMD}; else \1 ; fi|' \
		${WRKSRC}/tools/python/pywrapper_template.txt
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/tools/python/python_bootstrap_template.txt
	@${REINPLACE_CMD} -e 's|%%JAVA_HOME%%|${JAVA_HOME}|' \
		${WRKSRC}/src/main/cpp/blaze_util_bsd.cc
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKSRC}/src/main/starlark/builtins_bzl/common/python/providers.bzl \
		${WRKSRC}/src/main/starlark/builtins_bzl/common/python/py_executable_bazel.bzl \
		${WRKSRC}/src/main/java/com/google/devtools/build/lib/rules/python/PyRuntimeInfo.java \
		${WRKSRC}/tools/python/toolchain.bzl
	@${MKDIR} ${WRKSRC}/toolchain_local
	@${CP} ${FILESDIR}/toolchain_local-BUILD ${WRKSRC}/toolchain_local/BUILD
	@${CP} ${FILESDIR}/rules_python_freebsd.patch.in \
		${WRKSRC}/toolchain_local/rules_python_freebsd.patch
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		${WRKSRC}/toolchain_local/BUILD \
		${WRKSRC}/toolchain_local/rules_python_freebsd.patch

do-build:
	@${MKDIR} ${WRKDIR}/bazel_tmp
	(if [ -z "$${SOURCE_DATE_EPOCH}" ] ; \
	  then SOURCE_DATE_EPOCH=`grep TIMESTAMP ${DISTINFO_FILE} \
	    | ${SED} -e 's/[^0-9]//g'`; \
	fi ; \
	cd ${WRKSRC} && \
	${SETENV} BAZEL_SH=${LOCALBASE}/bin/bash \
	JAVA_HOME=${JAVA_HOME} \
	JAVA_VERSION=${JAVA_PORT_VERSION} \
	TMPDIR=${WRKDIR}/bazel_tmp \
	EMBED_LABEL='${PORTVERSION}' \
	BAZEL_DEV_VERSION_OVERRIDE='${PORTVERSION}' \
	PATH=${LOCALBASE}/bin:$$PATH \
	SOURCE_DATE_EPOCH=$${SOURCE_DATE_EPOCH} \
	BAZEL_JAVAC_OPTS=${BAZEL_JAVAC_OPTS} \
	EXTRA_BAZEL_ARGS='--host_javabase=@local_jdk//:jdk --tool_java_runtime_version=local_jdk --java_language_version=${JAVA_PORT_VERSION} --tool_java_language_version=${JAVA_PORT_VERSION} --extra_toolchains=//toolchain_local:freebsd_python3_toolchain,//toolchain_local:local_jdk_21_runtime,//toolchain_local:local_jdk_21_bootstrap --action_env=PATH=${LOCALBASE}/bin:/bin:/usr/bin:/sbin:/usr/sbin --host_linkopt=-lm' \
	${LOCALBASE}/bin/bash ./compile.sh)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/bazel ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/packages/bazel.bazelrc ${STAGEDIR}${ETCDIR}/bazel.bazelrc.sample

.include <bsd.port.post.mk>
