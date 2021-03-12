# $FreeBSD$

PORTNAME=	gatk
DISTVERSION=	4.2.0.0
CATEGORIES=	biology java
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Variant discovery in high-throughput sequencing data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BROKEN_FreeBSD_12_powerpc64=	fails to build: String index out of range: -1

BUILD_DEPENDS=	gradle62:devel/gradle62

USES=		gettext-runtime
USE_GITHUB=	yes
GH_ACCOUNT=	broadinstitute
USE_JAVA=	yes

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	PORTVERSION=${PORTVERSION} JAVA=${JAVA}

NO_ARCH=	yes

DEPS_CACHE_DIR=	${WRKDIR}

PLIST_FILES=	bin/${PORTNAME} \
		${JAVAJARDIR}/GenomeAnalysisTK-${PORTVERSION}.jar

# TODO additionally fetch git-lfs files: https://github.com/broadinstitute/gatk/issues/6395

# to rebuild the deps archive:
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum build
#   3. upload the *-deps archive
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum

DEV_UPDATE_MODE=	no

OPTIONS_DEFINE=			WITH_LARGE_FILES # probably should be default for tests, but the build doesn't seem to be affected contrary to what README says

WITH_LARGE_FILES_DESC=		Download large LFS files needed for build and tests
WITH_LARGE_FILES_FETCH_DEPENDS=	git:devel/git \
				git-lfs:devel/git-lfs

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWITH_LARGE_FILES}
do-fetch:
	@if [ "${FORCE_FETCH_ALL}" = "true" ] || ! [ -f "${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}" ]; then \
		${MKDIR} ${DISTDIR}/${DIST_SUBDIR} && \
		cd ${DISTDIR}/${DIST_SUBDIR} && \
		${ECHO} "==> Fetching ${PORTNAME} including large LFS files" && \
		( \
			${MKDIR} ${WRKDIR}; \
			HOME=${WRKDIR}; \
			git config --global filter.lfs.smudge "git-lfs smudge -- %f" && \
			git clone -q https://github.com/broadinstitute/gatk.git ${PORTNAME}-${DISTVERSION} && \
			(cd ${PORTNAME}-${DISTVERSION} && git reset -q --hard ${DISTVERSION} && ${RM} -r .git) && \
			${RM} -r ${WRKDIR} \
		) && \
		${FIND} ${PORTNAME}-${DISTVERSION} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
		${FIND} ${PORTNAME}-${DISTVERSION} -print0 | LC_ALL=C ${SORT} -z | \
		${TAR} czf ${DISTNAME}${EXTRACT_SUFX} --format=bsdtar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T - && \
		${RM} -r ${PORTNAME}-${DISTVERSION}; \
	fi
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
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gradle62 \
		--gradle-user-home ${DEPS_CACHE_DIR}/gradle-${PORTNAME} --project-cache-dir ${DEPS_CACHE_DIR}/gradle-${PORTNAME} \
		${GRADLE_ARGS} --build-cache localJar

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/build/libs/gatk-package-1.0-SNAPSHOT-local.jar ${STAGEDIR}${JAVAJARDIR}/GenomeAnalysisTK-${PORTVERSION}.jar

.include <bsd.port.mk>
