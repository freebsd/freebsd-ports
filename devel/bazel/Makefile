# Created by: Klaus Aehlig <aehlig@linta.de>
# $FreeBSD$

PORTNAME=		bazel
DISTVERSION=		0.23.0
CATEGORIES=		devel java
MASTER_SITES=		https://storage.googleapis.com/bazel/${PORTVERSION}/rc${FINALRC}/
DISTNAME=		bazel-${PORTVERSION}rc${FINALRC}-dist

MAINTAINER?=		aehlig@linta.de
COMMENT=		Fast and correct build system

LICENSE=		APACHE20
LICENSE_FILE=		${WRKSRC}/LICENSE

BROKEN_aarch64=		fails to build: java.lang.OutOfMemoryError: Java heap space
BROKEN_armv6=		fails to package: cp: bazel: No such file or directory
BROKEN_armv7=		fails to package: cp: bazel: No such file or directory
BROKEN_powerpc64=	fails to compile: Action failed to execute: java.io.IOException: Cannot run program /usr/bin/clang

BUILD_DEPENDS=		bash:shells/bash \
			zip:archivers/zip

# In bazel, a release is always code-wise identical to the final release candidate.
# Hence we can also download that one and so have a simple way to also test earlier release
# candidates.
FINALRC=		3

USES=			shebangfix zip:infozip python
SHEBANG_REGEX=		.*(sh|txt|_stub|stub_.*|bazel|get_workspace_status|protobuf_support|_so)
USE_JAVA=		yes
JAVA_VENDOR=		openjdk
JAVA_VERSION=		1.8
JAVA_BUILD=		yes
JAVA_RUN=		yes

NO_WRKSUBDIR=		YES

STRIP=	# The bazel binary is also a zip archive (extracted by the elf part), it must not be stripped

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
EXTRA_PATCHES+=	${FILESDIR}/extra-i386_src_BUILD ${FILESDIR}/extra-i386_tools_cpp_BUILD.static.freebsd
.endif

# Have the location of the system-wide rc file reside ${ETCDIR}.
# Also adapt the sample file to disable persistent java workers as they
# do not work reliably on FreeBSD.
post-patch:
	@${REINPLACE_CMD} \
	-e "s|/etc/bazel.bazelrc|${ETCDIR}/bazel.bazelrc|" \
	${WRKSRC}/src/main/cpp/blaze_util_posix.cc \
	${WRKSRC}/src/main/cpp/BUILD
	@${ECHO_CMD} build --strategy=Javac=standalone >> ${WRKSRC}/scripts/packages/bazel.bazelrc
	@${ECHO_CMD} build --python_path=${PYTHON_CMD} >> ${WRKSRC}/scripts/packages/bazel.bazelrc
	@${ECHO_CMD} build --host_javabase=@local_jdk//:jdk >> ${WRKSRC}/scripts/packages/bazel.bazelrc
	@${ECHO_CMD} build --action_env=PATH=/bin:/usr/bin/:${LOCALBASE}/bin >> ${WRKSRC}/scripts/packages/bazel.bazelrc
	@${REINPLACE_CMD} \
	-e 's|\$$command|$$command --python_path=${PYTHON_CMD}|' \
	${WRKSRC}/scripts/bootstrap/bootstrap.sh
	@${REINPLACE_CMD} \
	-e 's|/usr/bin/env python|${PYTHON_CMD}|' \
	${WRKSRC}/src/main/java/com/google/devtools/build/lib/bazel/rules/python/BazelPythonSemantics.java

do-build:
	@${MKDIR} ${WRKDIR}/bazel_tmp
	(if [ -z "$${SOURCE_DATE_EPOCH}" ] ; \
	  then SOURCE_DATE_EPOCH=`grep TIMESTAMP ${DISTINFO_FILE} \
	    | ${SED} -e 's/[^0-9]//g'`; \
	fi ; \
	cd ${WRKSRC} && \
	${SETENV} BAZEL_SH=${LOCALBASE}/bin/bash \
	TMPDIR=${WRKDIR}/bazel_tmp \
	EMBED_LABEL='${PORTVERSION}' \
	PATH=${LOCALBASE}/bin:$$PATH \
	SOURCE_DATE_EPOCH=$${SOURCE_DATE_EPOCH} \
	EXTRA_BAZEL_ARGS=--host_javabase=@local_jdk//:jdk \
	${LOCALBASE}/bin/bash ./compile.sh)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/bazel ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/packages/bazel.bazelrc ${STAGEDIR}${ETCDIR}/bazel.bazelrc.sample

.include <bsd.port.post.mk>
