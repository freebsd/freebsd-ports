PORTNAME=	igv
DISTVERSIONPREFIX=	v
DISTVERSION=	2.19.8
CATEGORIES=	biology java
MASTER_SITES=	http://software.broadinstitute.org/software/igv/sites/cancerinformatics.org.igv/files/images/:img
DISTFILES=	tools.png:img
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Visualization tool for genomic datasets
WWW=		https://software.broadinstitute.org/software/igv/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	gradle${GRADLE_VER}:devel/gradle${GRADLE_VER}

USES=		gettext-runtime java

USE_GITHUB=	yes
GH_ACCOUNT=	igvteam

JAVA_VERSION=	21
GRADLE_VER=	8

NO_ARCH=	yes

MAKE_ENV+=	GRADLE_USER_HOME=${WRKDIR}

SUB_FILES=	${PORTNAME}.sh

DESKTOP_ENTRIES="IGV" "Integrative Genomics Viewer" "${PREFIX}/share/pixmaps/igv.png" "${PORTNAME}" \
		"Biology;Science;" true

# How to update (deps archive and pkg-plist are version-specific):
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum build  (the *-deps archive is created in ${DISTDIR}/${DIST_SUBDIR})
#   3. upload the *-deps archive
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum
#   6. make stage && make makeplist to regenerate pkg-plist (jar names contain versions)

DEV_UPDATE_MODE=	no

DEPS_CACHE_DIR=	${WRKDIR}

MAKE_ENV+=	JAVA_HOME=${JAVA_HOME}
SUB_LIST=	JAVA_HOME=${JAVA_HOME}

.if (${DEV_UPDATE_MODE} != "yes")
MASTER_SITES+=	LOCAL/yuri/:deps
DISTFILES+=	${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}:deps
GRADLE_ARGS=	--offline

post-extract: # need a separate extract step because the cache is in /tmp, and not under work/ like with maven
	@cd ${DEPS_CACHE_DIR} && ${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gradle${GRADLE_VER} --no-daemon \
		--gradle-user-home ${DEPS_CACHE_DIR}/gradle-${PORTNAME} --project-cache-dir ${DEPS_CACHE_DIR}/gradle-${PORTNAME} \
		-Porg.gradle.java.installations.paths=${JAVA_HOME} -Porg.gradle.java.installations.auto-download=false \
		${GRADLE_ARGS} --build-cache --stacktrace createDist

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gradle${GRADLE_VER} --no-daemon \
		--gradle-user-home ${DEPS_CACHE_DIR}/gradle-${PORTNAME} --project-cache-dir ${DEPS_CACHE_DIR}/gradle-${PORTNAME} \
		-Porg.gradle.java.installations.paths=${JAVA_HOME} -Porg.gradle.java.installations.auto-download=false \
		${GRADLE_ARGS} --no-build-cache test

.if (${DEV_UPDATE_MODE} == "yes")
post-build: do-test
	@cd ${DEPS_CACHE_DIR} && ${TAR} czf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX} gradle-${PORTNAME}
	@${ECHO} "(!!!) Please upload the deps archive: ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}"
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC}/build/IGV-dist/lib && ${COPYTREE_SHARE} ./ ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/tools.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

# tests as of 2.19.8: 554 tests, 0 failures, 0 errors, 123 skipped

.include <bsd.port.mk>
