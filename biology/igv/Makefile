# $FreeBSD$

PORTNAME=	igv
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.13
CATEGORIES=	biology java
MASTER_SITES=	http://software.broadinstitute.org/software/igv/sites/cancerinformatics.org.igv/files/images/:img
DISTFILES=	tools.png:img
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Visualization tool for genomic datasets

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	openjfx14>0:java/openjfx14 \
		gradle:devel/gradle
RUN_DEPENDS=	openjfx14>0:java/openjfx14

USES=		gettext-runtime
USE_JAVA=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	igvteam

JAVA_VERSION=	11

NO_ARCH=	yes

MAKE_ENV+=	GRADLE_USER_HOME=${WRKDIR}

SUB_FILES=	${PORTNAME}.sh

DESKTOP_ENTRIES="IGV" "Integrative Genomics Viewer" "${PREFIX}/share/pixmaps/igv.xpm" "${PORTNAME}" \
		"Biology;Science;" true

# to rebuild the deps archive:
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum build
#   3. upload the *-deps archive
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum

DEV_UPDATE_MODE=	no

DEPS_CACHE_DIR=	${WRKDIR}

MAKE_ENV+=	JAVA_HOME=${JAVA_HOME}
SUB_LIST=	JAVA_HOME=${JAVA_HOME}

.if (${DEV_UPDATE_MODE} == "yes")
post-build:
	@cd ${DEPS_CACHE_DIR} && ${TAR} czf ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX} gradle-${PORTNAME}
	@${ECHO} "(!!!) Please upload the deps archive: ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}"
.else
MASTER_SITES+=	LOCAL/yuri/:deps
DISTFILES+=	${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}:deps
GRADLE_ARGS=	--offline

post-extract: # need a separate extract step because the cache is in /tmp, and not under work/ like with maven
	@cd ${DEPS_CACHE_DIR} && ${TAR} xzf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gradle \
		--gradle-user-home ${DEPS_CACHE_DIR}/gradle-${PORTNAME} --project-cache-dir ${DEPS_CACHE_DIR}/gradle-${PORTNAME} \
		${GRADLE_ARGS} --build-cache --stacktrace createDist

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC}/build/IGV-dist/lib && ${COPYTREE_SHARE} ./ ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/tools.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
