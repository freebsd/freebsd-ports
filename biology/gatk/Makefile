PORTNAME=	gatk
DISTVERSION=	4.6.2.0
CATEGORIES=	biology java
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Genome Analysis Toolkit
WWW=		https://gatk.broadinstitute.org/hc/en-us \
		https://github.com/broadinstitute/gatk

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	gradle8:devel/gradle8
RUN_DEPENDS=	${LOCALBASE}/lib/libfml.so:biology/fermi-lite \
		gkl>0:biology/gkl \
		mummer>0:biology/mummer

USES=		gettext-runtime java python:test
JAVA_VERSION=	17 # Java 8 fails on aarch64: Internal Error (assembler_aarch64.hpp:237), pid=76025, tid=0x000000000006e359 guarantee(val < (1U << nbits)) failed: Field too big for insn

USE_GITHUB=	yes
GH_ACCOUNT=	broadinstitute

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	PORTVERSION=${PORTVERSION} JAVA=${JAVA}

NO_ARCH=	yes

DEPS_CACHE_DIR=	${WRKDIR}

TEST_ENV=	${MAKE_ENV} \
		JAVA_TOOL_OPTIONS="-DLIBBWA_PATH=${PREFIX}/lib/libfml.so -DLIBFML_PATH=${PREFIX}/lib/libfml.so" \
		GATK_LOCAL_JAR=${STAGEDIR}${JAVAJARDIR}/GenomeAnalysisTK-${PORTVERSION}.jar

PLIST_FILES=	bin/${PORTNAME} \
		${JAVAJARDIR}/GenomeAnalysisTK-${PORTVERSION}.jar

BINARY_ALIAS=	java=${JAVA} \
		python=${PYTHON_CMD}

# to rebuild the deps archive:
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum build
#   3. upload the *-deps archive
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum

DEV_UPDATE_MODE=	no

OPTIONS_DEFINE=			WITH_LARGE_FILES
OPTIONS_DEFAULT=		WITH_LARGE_FILES # runtime requires large files, see the README

WITH_LARGE_FILES_DESC=		Download large LFS files needed for build and tests
WITH_LARGE_FILES_FETCH_DEPENDS=	git:devel/git \
				git-lfs:devel/git-lfs

# The large files under src/main/resources/large/ are required to build GATK, since they are packaged inside the GATK jar and used by tools at runtime. These are things like ML models and native C/C++ libraries used for acceleration of certain tools.
# The large files under src/test/resources/large/, on the other hand, are only required by the test suite when running tests.

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWITH_LARGE_FILES}
# fetch the main distfile including git-lsf files
do-fetch:
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}" ]; then \
		${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
		cd ${DISTDIR}/${DIST_SUBDIR} && \
		${ECHO} "==> Fetching ${PORTNAME} including large LFS files" && \
		( \
			${MKDIR} ${WRKDIR}; \
			HOME=${WRKDIR}; \
			git config --global filter.lfs.smudge "git-lfs smudge -- %f" && \
			GIT_CLONE_PROTECTION_ACTIVE=false git clone -nq https://github.com/broadinstitute/gatk.git ${PORTNAME}-${DISTVERSION} && \
			(cd ${PORTNAME}-${DISTVERSION} && git reset -q --hard ${DISTVERSION} && ${RM} -r .git) && \
			${RM} -r ${WRKDIR} \
		) && \
		${FIND} ${PORTNAME}-${DISTVERSION} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
		${FIND} ${PORTNAME}-${DISTVERSION} -print0 | LC_ALL=C ${SORT} -z | \
		${SETENV} -i ${TAR} czf ${DISTNAME}${EXTRACT_SUFX} --format=cpio --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T - && \
		${RM} -r ${PORTNAME}-${DISTVERSION}; \
	fi
# fetch the deps distfile
.  if (${DEV_UPDATE_MODE} == "no")
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}" ]; then \
		${ECHO} "==> Fetching the deps distfile for ${PORTNAME}" && \
		${SETENV} \
			${_DO_FETCH_ENV} ${_MASTER_SITES_ENV} \
			dp_SITE_FLAVOR=MASTER \
			${SH} ${SCRIPTSDIR}/do-fetch.sh ${DISTFILES:M*\:deps}; \
	fi
.  endif
.endif

.if (${DEV_UPDATE_MODE} == "yes")
post-build:
	@cd ${DEPS_CACHE_DIR} && ${TAR} czf ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX} gradle-${PORTNAME}
	@${ECHO} "(!!!) Please upload the gradle deps archive: ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}"
.else
MASTER_SITES=	LOCAL/yuri/:deps
DISTFILES=	${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}:deps
GRADLE_ARGS=	--offline

post-extract: # need a separate extract step because the cache is in /tmp, and not under work/ like with maven
	@cd ${DEPS_CACHE_DIR} && ${TAR} xzf ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}
.endif

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gradle8 \
		--gradle-user-home ${DEPS_CACHE_DIR}/gradle-${PORTNAME} --project-cache-dir ${DEPS_CACHE_DIR}/gradle-${PORTNAME} \
		${GRADLE_ARGS} --build-cache localJar

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/build/libs/gatk-package-1.0-SNAPSHOT-local.jar ${STAGEDIR}${JAVAJARDIR}/GenomeAnalysisTK-${PORTVERSION}.jar

do-test: # tests require WITH_LARGE_FILES=ON, and they use a lot of disk space
	@cd ${WRKSRC} && \
		${SETENV} ${TEST_ENV} gradle8 test

# tests as of 4.6.1.0: 288552 tests, 301 failures, 37 ignored, 1h55m5.63s duration, 99% successful, see https://github.com/broadinstitute/gatk/issues/8940
# tests as of 4.6.2.0: 288719 tests completed, 300 failed, 37 skipped
# see https://github.com/broadinstitute/gatk/issues/8939: Tests fail to find libgkl libraries in /usr/local/lib

.include <bsd.port.mk>
