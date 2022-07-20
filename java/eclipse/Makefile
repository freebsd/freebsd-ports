PORTNAME=	eclipse
PORTVERSION=	4.24
CATEGORIES=	java devel

# Tag's Timestamp on eclipse-platform/eclipse.platform.releng.aggregator github.com
ECLIPSE_TAG=	R4_24
ECLIPSE_TSTAMP=	20220616-0004

DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jonc@chen.org.nz
COMMENT=	Eclipse IDE 2022-06

LICENSE=	EPL

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le

BUILD_DEPENDS=	git:devel/git@lite \
		${LOCALBASE}/share/java/maven/bin/mvn:devel/maven \
		zip:archivers/zip
LIB_DEPENDS=	libsecret-1.so:security/libsecret \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

PORTSCOUT=	ignore:1

USES=		compiler:c++11-lang gmake pkgconfig gnome
USE_GNOME=	gtk30

USE_GITHUB=	yes
GH_TUPLE=	eclipse-platform:eclipse.platform.releng.aggregator:${ECLIPSE_TAG} \
		eclipse-jdt:eclipse.jdt:${ECLIPSE_TAG}:a/eclipse.jdt \
		eclipse-jdt:eclipse.jdt.core:${ECLIPSE_TAG}:b/eclipse.jdt.core \
		eclipse-jdt:eclipse.jdt.core.binaries:${ECLIPSE_TAG}:c/eclipse.jdt.core.binaries \
		eclipse-jdt:eclipse.jdt.debug:${ECLIPSE_TAG}:d/eclipse.jdt.debug \
		eclipse-jdt:eclipse.jdt.ui:${ECLIPSE_TAG}:e/eclipse.jdt.ui \
		eclipse-pde:eclipse.pde:${ECLIPSE_TAG}:f/eclipse.pde \
		eclipse-platform:eclipse.platform:${ECLIPSE_TAG}:g/eclipse.platform \
		eclipse-platform:eclipse.platform.common:${ECLIPSE_TAG}:h/eclipse.platform.common \
		eclipse-platform:eclipse.platform.debug:${ECLIPSE_TAG}:i/eclipse.platform.debug \
		eclipse-platform:eclipse.platform.releng:${ECLIPSE_TAG}:j/eclipse.platform.releng \
		eclipse-platform:eclipse.platform.resources:${ECLIPSE_TAG}:k/eclipse.platform.resources \
		eclipse-platform:eclipse.platform.runtime:fd42b6e331:l/eclipse.platform.runtime \
		eclipse-platform:eclipse.platform.swt:${ECLIPSE_TAG}:m/eclipse.platform.swt \
		eclipse-platform:eclipse.platform.swt.binaries:${ECLIPSE_TAG}:n/eclipse.platform.swt.binaries \
		eclipse-platform:eclipse.platform.team:${ECLIPSE_TAG}:o/eclipse.platform.team \
		eclipse-platform:eclipse.platform.text:${ECLIPSE_TAG}:p/eclipse.platform.text \
		eclipse-platform:eclipse.platform.ua:${ECLIPSE_TAG}:q/eclipse.platform.ua \
		eclipse-platform:eclipse.platform.ui:${ECLIPSE_TAG}:r/eclipse.platform.ui \
		eclipse-platform:eclipse.platform.ui.tools:${ECLIPSE_TAG}:s/eclipse.platform.ui.tools \
		eclipse-equinox:equinox.binaries:${ECLIPSE_TAG}:t/rt.equinox.binaries \
		eclipse-equinox:equinox.bundles:${ECLIPSE_TAG}:u/rt.equinox.bundles \
		eclipse-equinox:equinox.framework:${ECLIPSE_TAG}:v/rt.equinox.framework \
		eclipse-equinox:p2:${ECLIPSE_TAG}:w/rt.equinox.p2 \
		daemonblade:eclipse-maven-repo:${PORTVERSION}:x

USE_JAVA=	11+

DESKTOP_ENTRIES="Eclipse" \
		"${COMMENT}" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Development;IDE;Java;" \
		"false"

SUB_FILES=	${PORTNAME}

MAVEN_ENV=	MAVEN_OPTS=-Xmx1024m CC=${CC} JAVA_HOME=${JAVA_HOME} HOME=${WRKDIR}/githome
MAVEN_ECLIPSE=	-Dmaven.repo.local=${WRKDIR}/eclipse-maven-repo-${PORTVERSION} \
		-Dnative=gtk.freebsd.${ARCH} \
		-DforceContextQualifier=v${ECLIPSE_TSTAMP}

ECLIPSE_RESULT=	eclipse.platform.releng.tychoeclipsebuilder/eclipse.platform.repository/target/products/org.eclipse.sdk.ide-freebsd.gtk.${ARCH}.tar.gz

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAVEN_ENV} mvn --offline ${MAVEN_ECLIPSE} -DskipTests clean verify

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${TAR} -x --directory ${STAGEDIR}${DATADIR}/.. --file ${WRKSRC}/${ECLIPSE_RESULT}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

# generate dynamic plist, to cater for different ARCHS
post-install:
	cd ${STAGEDIR}${PREFIX} && ${FIND} -s bin/${PORTNAME} share/${PORTNAME} -not -type d >> ${TMPPLIST}
	cd ${STAGEDIR}${PREFIX} && ${FIND} -ds share/${PORTNAME} -type d | ${SED} -e 's,^,@dir ,' >> ${TMPPLIST}

.include <bsd.port.mk>
