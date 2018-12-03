# $FreeBSD$

PORTNAME=	gatk
DISTVERSION=	4.0.11.0
CATEGORIES=	biology java
MASTER_SITES=	LOCAL/yuri/:deps
DISTFILES=	${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}:deps
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Variant discovery in high-throughput sequencing data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BUILD_DEPENDS=	gradle:devel/gradle

USES=		gettext-runtime
USE_GITHUB=	yes
GH_ACCOUNT=	broadinstitute
USE_JAVA=	yes

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	PORTVERSION=${PORTVERSION} JAVA=${JAVA}

NO_ARCH=	yes

DEPS_CACHE_DIR=	/tmp # should be ${WRKDIR}, but workaround for the gradle bug that dependency cache is not relocable: https://github.com/gradle/gradle/issues/1338

PLIST_FILES=	bin/${PORTNAME} \
		${JAVAJARDIR}/GenomeAnalysisTK-${PORTVERSION}.jar

post-extract: # to rebuild the deps archive: 1. remove post-extract: 2. remove --offline 3. build 4. package ${DEPS_CACHE_DIR}/gradle-${PORTNAME} into the deps archive
	@cd ${DEPS_CACHE_DIR} && ${TAR} xzf ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} gradle \
		--gradle-user-home ${DEPS_CACHE_DIR}/gradle-${PORTNAME} --project-cache-dir ${DEPS_CACHE_DIR}/gradle-${PORTNAME} \
		--offline --build-cache localJar

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/build/libs/gatk-package-1.0-SNAPSHOT-local.jar ${STAGEDIR}${JAVAJARDIR}/GenomeAnalysisTK-${PORTVERSION}.jar

.include <bsd.port.mk>
