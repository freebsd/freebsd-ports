PORTNAME=	eclipse
DISTVERSION=	4.36
CATEGORIES=	java devel
ECLIPSE_TAG=	R${DISTVERSION:S|.|_|g}

DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ngrundmann@gmx.de
COMMENT=	Eclipse IDE
WWW=		https://www.eclipse.org/

LICENSE=	EPL

ONLY_FOR_ARCHS=	aarch64 amd64

BUILD_DEPENDS=	git:devel/git \
		mvn:devel/maven39 \
		zip:archivers/zip
LIB_DEPENDS=	libsecret-1.so:security/libsecret
RUN_DEPENDS=	webkit2-gtk_41>=0:www/webkit2-gtk@41

USES=		compiler:c++17-lang gl gmake gnome java pkgconfig
# The github repositories.  The repository under NorbertXYZ is for a predefined maven
# download, so the build does not need to download while do-build is running
USE_GITHUB=	yes
GH_TUPLE=	chirontt:eclipse.platform.releng.aggregator:${ECLIPSE_TAG}_maintenance \
		eclipse-jdt:eclipse.jdt:${ECLIPSE_TAG}:a/eclipse.jdt \
		eclipse-jdt:eclipse.jdt.core:${ECLIPSE_TAG}:b/eclipse.jdt.core \
		eclipse-jdt:eclipse.jdt.core.binaries:${ECLIPSE_TAG}:c/eclipse.jdt.core.binaries \
		eclipse-jdt:eclipse.jdt.debug:${ECLIPSE_TAG}:d/eclipse.jdt.debug \
		eclipse-jdt:eclipse.jdt.ui:${ECLIPSE_TAG}:e/eclipse.jdt.ui \
		chirontt:eclipse.pde:${ECLIPSE_TAG}_maintenance:f/eclipse.pde \
		chirontt:eclipse.platform:${ECLIPSE_TAG}_maintenance:g/eclipse.platform \
		chirontt:eclipse.platform.swt:${ECLIPSE_TAG}_maintenance:i/eclipse.platform.swt \
		chirontt:eclipse.platform.ui:${ECLIPSE_TAG}_maintenance:j/eclipse.platform.ui \
		chirontt:equinox:${ECLIPSE_TAG}_maintenance:k/equinox \
		chirontt:equinox.binaries:${ECLIPSE_TAG}_maintenance:l/equinox.binaries \
		chirontt:p2:${ECLIPSE_TAG}_maintenance:m/equinox.p2 \
		NorbertXYZ:eclipse-maven:${DISTVERSION}:n
USE_GL=		gl glu
USE_GNOME=	gtk30 gtk40
JAVA_VERSION=	21+

DESKTOP_ENTRIES=	"Eclipse" \
			"${COMMENT}" \
			"${PORTNAME}" \
			"${PORTNAME}" \
			"Development;IDE;Java;" \
			"false"
PORTSCOUT=	ignore:1
SUB_FILES=	${PORTNAME}

.include <bsd.port.pre.mk>

MAVEN_ENV=	MAVEN_OPTS=-Xmx2048m CC=${CC} CFLAGS="${CFLAGS}" JAVA_HOME=${JAVA_HOME}

# To make the build working, set the (maven) architecture to x86_64 instead of amd64
# Finally there are problems with amd64
MAVEN_ARCH=	${ARCH:S|amd64|x86_64|}

MAVEN_PARAMS=	--offline \
		-Dmaven.repo.local=${WRKDIR}/eclipse-maven-${DISTVERSION} \
		-Dnative=gtk.freebsd.${MAVEN_ARCH} \
		-DskipTests clean verify

ECLIPSE_RESULT=	eclipse.platform.releng.tychoeclipsebuilder/eclipse.platform.repository/target/products/org.eclipse.sdk.ide-freebsd.gtk.${MAVEN_ARCH}.tar.gz

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-deprecated-non-prototype
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAVEN_ENV} mvn ${MAVEN_PARAMS}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${TAR} -x --directory ${STAGEDIR}${DATADIR}/.. --file ${WRKSRC}/${ECLIPSE_RESULT}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

# Generate dynamic plist, to cater for different ARCHS
post-install:
	cd ${STAGEDIR}${PREFIX} && ${FIND} -s bin/${PORTNAME} share/${PORTNAME} -not -type d >> ${TMPPLIST}
	cd ${STAGEDIR}${PREFIX} && ${FIND} -ds share/${PORTNAME} -type d | ${SED} -e 's,^,@dir ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
