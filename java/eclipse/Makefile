PORTNAME=	eclipse
DISTVERSION=	4.32
CATEGORIES=	java devel
ECLIPSE_TAG=	R${DISTVERSION:S|.|_|g}

DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ngrundmann@gmx.de
COMMENT=	Eclipse IDE
WWW=		https://www.eclipse.org/

LICENSE=	EPL

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le

BUILD_DEPENDS=	git:devel/git \
		mvn:devel/maven39 \
		zip:archivers/zip

LIB_DEPENDS=	libsecret-1.so:security/libsecret \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

USES=		compiler:c++17-lang gmake pkgconfig gnome

# The github repositories.  The repository under NorbertXYZ is for a predefined maven
# download, so the build does not need to download while do-build is running
USE_GITHUB=	yes
GH_TUPLE=	eclipse-platform:eclipse.platform.releng.aggregator:${ECLIPSE_TAG} \
		eclipse-jdt:eclipse.jdt:${ECLIPSE_TAG}:a/eclipse.jdt \
		eclipse-jdt:eclipse.jdt.core:${ECLIPSE_TAG}:b/eclipse.jdt.core \
		eclipse-jdt:eclipse.jdt.core.binaries:${ECLIPSE_TAG}:c/eclipse.jdt.core.binaries \
		eclipse-jdt:eclipse.jdt.debug:${ECLIPSE_TAG}:d/eclipse.jdt.debug \
		eclipse-jdt:eclipse.jdt.ui:${ECLIPSE_TAG}:e/eclipse.jdt.ui \
		eclipse-pde:eclipse.pde:${ECLIPSE_TAG}:f/eclipse.pde \
		eclipse-platform:eclipse.platform:${ECLIPSE_TAG}:g/eclipse.platform \
		eclipse-platform:eclipse.platform.runtime:fd42b6e331:h/eclipse.platform.runtime \
		eclipse-platform:eclipse.platform.swt:${ECLIPSE_TAG}:i/eclipse.platform.swt \
		eclipse-platform:eclipse.platform.ui:${ECLIPSE_TAG}:j/eclipse.platform.ui \
		eclipse-equinox:equinox:${ECLIPSE_TAG}:k/equinox \
		eclipse-equinox:equinox.binaries:${ECLIPSE_TAG}:l/rt.equinox.binaries \
		eclipse-equinox:p2:${ECLIPSE_TAG}:m/rt.equinox.p2 \
		NorbertXYZ:eclipse-maven:${DISTVERSION}:n
USE_GNOME=	gtk30
USE_JAVA=	17+

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

# Directories needed, but cannot be stored in git, because they are empty
EMPTY_DIRS=	eclipse.platform/resources/bundles/org.eclipse.core.filesystem.freebsd.%%ARCH%%/os/freebsd/%%ARCH%% \
		eclipse.platform/resources/bundles/org.eclipse.core.filesystem.freebsd.%%ARCH%%/target \
		eclipse.platform/team/bundles/org.eclipse.core.net.freebsd/target \
		rt.equinox.binaries/org.eclipse.equinox.executable/bin/gtk/freebsd/%%ARCH%% \
		rt.equinox.binaries/org.eclipse.equinox.launcher.gtk.freebsd.%%ARCH%%

pre-patch:
	${CP} -R ${FILESDIR}/addons/ ${WRKSRC}
.for DIR in ${EMPTY_DIRS}
. for _ARCH in aarch64 powerpc64 powerpc64le x86_64
	${MKDIR} ${WRKSRC}/${DIR:S|%%ARCH%%|${_ARCH}|g}
	${TOUCH} ${WRKSRC}/${DIR:S|%%ARCH%%|${_ARCH}|g}/.empty
. endfor
.endfor

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
