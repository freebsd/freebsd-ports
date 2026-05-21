PORTNAME=	openapi
DISTVERSION=	${QT6_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt HTTP client generator using OpenAPI

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cyclonedx-python-lib>0:textproc/py-cyclonedx-python-lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spdx-tools>=0.8.3:misc/py-spdx-tools@${PY_FLAVOR} \
		vulkan-headers>1.4:graphics/vulkan-headers \
		maven38>0:devel/maven38 \
		openapi-generator>0:devel/openapi-generator
RUN_DEPENDS=	openapi-generator>0:devel/openapi-generator

USES=		cmake compiler:c++17-lang gl java pkgconfig python:build qt-dist:6
JAVA_VERSION=	17+
USE_GL=		opengl
USE_QT=		base declarative

CMAKE_ARGS=	-DJava_JAR_PATHS:STRING="${JAVAJARDIR}"
MAVEN_ARGS=	-Dmaven.repo.local=${WRKDIR}/m2 \
		-Dmaven.test.skip=true \
		-T ${MAKE_JOBS_NUMBER}
.if !defined(QTOPENAPI_MAINTAINER_MODE)
MAVEN_ARGS+=	--offline
.endif
MAVEN_ENV=	JAVA_HOME=${JAVA_HOME}

BINARY_ALIAS=	mvn=${WRKDIR}/mvn-wrapper.sh \
		python3=${PYTHON_CMD}

_MAVEN_DEPS=	qt${PORTNAME}-maven-deps-${DISTVERSION}${EXTRACT_SUFX}

.include <bsd.port.pre.mk>

# Restrict Maven memory usage on 32-bit architectures to prevent OutOfMemory errors
.if ${ARCH:Marmv?} || ${ARCH} == i386 || ${ARCH} == powerpc
MAVEN_ENV+=	MAVEN_OPTS="-Xmx1024m"
.else
MAVEN_ENV+=	MAVEN_OPTS="-Xmx2048m"
.endif

post-patch:
# Wrap maven since it's usage within CMake does not accept the arguments we
# need without patches.
	${PRINTF} "#!/bin/sh\nexec ${SETENVI} ${MAVEN_ENV} ${LOCALBASE}/bin/mvn ${MAVEN_ARGS} \"\$$@\"\n" \
		> ${WRKDIR}/mvn-wrapper.sh
	${CHMOD} +x ${WRKDIR}/mvn-wrapper.sh

.if defined(QTOPENAPI_MAINTAINER_MODE)
# Maintainer helper target to generate the offline Maven dependencies tarball
# Run this manually with an active network connection before committing.
qtopenapi-create-maven-deps:
	@if [ ! -f ${DISTDIR}/${DIST_SUBDIR}/${_MAVEN_DEPS} ]; then \
	    ${ECHO_CMD} "===> Generating offline Maven dependencies tarball..."; \
	    ${MAKE} -C ${.CURDIR} patch; \
	    ${RM} -r ${WRKDIR}/m2; \
	    cd ${WRKSRC}/src/tools/qtopenapi-generator && \
		${WRKDIR}/mvn-wrapper.sh clean package; \
	    cd ${WRKDIR} && tar --uname qt --gname qt -cJf ${DISTDIR}/${DIST_SUBDIR}/${_MAVEN_DEPS} m2; \
	    ${MAKE} -C ${.CURDIR} clean; \
	    ${ECHO_CMD} "===> Maven deps tarball successfully created: ${DISTDIR}/${DIST_SUBDIR}/${_MAVEN_DEPS}}"; \
	else \
	    ${ECHO_CMD} "===> ${DISTDIR}/${DIST_SUBDIR}/${_MAVEN_DEPS} already exists. Skipping creation."; \
	fi
.if !make(qtopenapi-upload-maven-deps)
	@${ECHO_CMD} "===> Don't forget to upload this file to freefall! \`${MAKE} -C .${.CURDIR} qtopenapi-upload-maven-deps\`"
.endif

# Maintainer helper target to upload maven deps to freefall.
qtopenapi-upload-maven-deps: qtopenapi-create-maven-deps
	@${ECHO_CMD} "===> Uploading ${DISTDIR}/${DIST_SUBDIR}/${_MAVEN_DEPS} to freefall..."
	@ssh freefall.freebsd.org "${MKDIR} /home/kde/public_distfiles/${DIST_SUBDIR}"
	@scp ${DISTDIR}/${DIST_SUBDIR}/${_MAVEN_DEPS} freefall.freebsd.org:/home/kde/public_distfiles/KDE/Qt/${DISTVERSION}
	@ssh freefall.freebsd.org "${CHMOD} -R 775 /home/kde/public_distfiles/${DIST_SUBDIR}"
.endif

.include <bsd.port.post.mk>
