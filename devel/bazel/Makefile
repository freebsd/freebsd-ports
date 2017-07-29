# Created by: Klaus Aehlig <aehlig@linta.de>
# $FreeBSD$

PORTNAME=		bazel
PORTVERSION=		0.5.3
CATEGORIES=		devel java
MASTER_SITES=		https://storage.googleapis.com/bazel/${PORTVERSION}/rc${FINALRC}/
DISTNAME=		bazel-${PORTVERSION}rc${FINALRC}-dist

MAINTAINER?=		aehlig@linta.de
COMMENT=		Fast and correct build system

LICENSE=		APACHE20
LICENSE_FILE=		${WRKSRC}/LICENSE

BUILD_DEPENDS=		bash:shells/bash \
			zip:archivers/zip

BROKEN_armv6=		fails to package: cp: bazel: No such file or directory

# In bazel, a release is always code-wise identical to the final release candidate.
# Hence we can also download that one and so have a simple way to also test earlier release
# candidates.
FINALRC=		4

NO_WRKSUBDIR=		YES
USES=			shebangfix zip
SHEBANG_REGEX=		.*(sh|txt|_stub|stub_.*|bazel|get_workspace_status|protobuf_support|_so)
USE_JAVA=		yes
JAVA_VENDOR=		openjdk
JAVA_VERSION=		1.8
JAVA_BUILD=		yes
JAVA_RUN=		yes

CONFLICTS_INSTALL?=	bazel-clang38

OPTIONS_DEFINE=	CLANG38
CLANG38_DESC=	Use clang38 as default crosstool
CLANG38_BUILD_DEPENDS=	clang38:devel/llvm38
CLANG38_RUN_DEPENDS=	clang38:devel/llvm38

# Have the location of the system-wide rc file reside ${ETCDIR}.
# Also adapt the sample file to disable persistent java workers as they
# do not work reliably on FreeBSD.
post-patch:
	@${REINPLACE_CMD} \
	-e "s|\"/etc/bazel.bazelrc\"|\"${ETCDIR}/bazel.bazelrc\"|" \
	${WRKSRC}/src/main/cpp/blaze_util_posix.cc
	@${ECHO_CMD} build --strategy=Javac=standalone >> ${WRKSRC}/scripts/packages/debian/bazel.bazelrc

post-patch-CLANG38-on:
	@${REINPLACE_CMD} -e 's=/usr/lib/clang=${LOCALBASE}/llvm38/lib/clang=' \
	-e 's=/usr/bin/clang=${LOCALBASE}/bin/clang38=' ${WRKSRC}/tools/cpp/CROSSTOOL

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
	SOURCE_DATE_EPOCH=$${SOURCE_DATE_EPOCH} \
	${LOCALBASE}/bin/bash ./compile.sh)

do-install:
	# The bazel binary is also a zip archive (extracted by the elf part), hence cannot be stripped
	${CP} ${WRKSRC}/output/bazel ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/packages/debian/bazel.bazelrc ${STAGEDIR}${ETCDIR}/bazel.bazelrc.sample

.include <bsd.port.mk>
