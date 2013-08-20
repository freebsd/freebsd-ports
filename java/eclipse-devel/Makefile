# Created by: various members of freebsd-java
# $FreeBSD$

PORTNAME=	eclipse-devel
PORTVERSION=	4.2.0
PORTREVISION=	4
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/technology/linuxtools/eclipse-build/4.2.x/:1 \
		http://download.eclipse.org/tools/orbit/downloads/drops/R20120119162704/repository/plugins/:2 \
		${MASTER_SITE_APACHE:S,%SUBDIR%/,ant/binaries/:4,} \
		http://cloud.github.com/downloads/KentBeck/junit/:6 \
		${MASTER_SITE_APACHE_TOMCAT:S,%SUBDIR%/,tomcat-7/v${TOMCAT_VERSION}/bin/:7,} \
		${MASTER_SITE_APACHE_TOMCAT:S,%SUBDIR%/,tomcat-7/v${TOMCAT_VERSION}/bin/extras/:7,} \
		http://archive.eclipse.org/jetty/8.1.0.v20120127/dist/:8 \
		http://repo2.maven.org/maven2/org/apache/geronimo/specs/geronimo-annotation_1.1_spec/1.0/:9 \
		http://artfiles.org/apache.org/felix/:10
DISTFILES=	${ECLIPSE_BUILD_SRCFILE}:1 \
		${ECLIPSE_SRCFILE}:1 \
		${ANT_SRCFILE}:4 \
		${JUNIT4_SRCFILE}:6 \
		${TOMCAT_SRCFILES:C,(.*),\\1:7,} \
		${ECLIPSE_JETTY_SRCFILE}:8 \
		${GERONIMO_ANNOTATION_BUNDLE}:9
DIST_SUBDIR=	eclipse
EXTRACT_ONLY=	${ECLIPSE_BUILD_SRCFILE}

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	An open extensible IDE for anything and nothing in particular

EXTRACT_DEPENDS=${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
PATCH_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		gpatch:${PORTSDIR}/devel/patch \
		zip:${PORTSDIR}/archivers/zip \
		${DEPEND_JAVA}
BUILD_DEPENDS=	gpatch:${PORTSDIR}/devel/patch \
		rsync:${PORTSDIR}/net/rsync \
		unzip:${PORTSDIR}/archivers/unzip \
		zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		webkitgtk-1.0.0:${PORTSDIR}/www/webkit-gtk2

OPTIONS_DEFINE=	TESTS
TESTS_DESC= 	"Build SDK test suite"

ONLY_FOR_ARCHS=	i386 amd64

USE_ANT=	yes
USE_GL=		glu
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils gconf2 gtk20 gnomevfs2 libgnome libgnomeui pkgconfig
USE_JAVA=	yes
USE_XZ=		yes
BZIP2_SUFX=	.tar.bz2
ZIP_CMD?=	${LOCALBASE}/bin/zip

JAVA_BUILD=	yes
JAVA_OS=	native
JAVA_RUN=	yes
JAVA_VERSION=	1.6
JAVA_VENDOR=	openjdk

ECLIPSE_RELEASE_VERSION=I20120608-1400
ECLIPSE_BUILD_SRCFILE=	eclipse-build-7b07d10488eb9d6e2880eac320b09c16d1ae78e3${EXTRACT_SUFX}
ECLIPSE_SRCFILE=	eclipse-${PORTVERSION}-${ECLIPSE_RELEASE_VERSION}-src${BZIP2_SUFX}
ECLIPSE_TEST_SRCFILE=	eclipse-sdktests-${PORTVERSION}-src${BZIP2_SUFX}
ECLIPSE_TEST_SCRIPTFILE=eclipse-sdktests-${PORTVERSION}-scripts${BZIP2_SUFX}
ECLIPSE_JAR_BUNDLES=	com.ibm.icu_4.4.2.v20110823.jar \
			com.ibm.icu.source_4.4.2.v20110823.jar \
			com.jcraft.jsch_0.1.44.v201101211721.jar \
			javax.inject_1.0.0.v20091030.jar \
			javax.xml_1.3.4.v201005080400.jar \
			org.apache.batik.css_1.6.0.v201011041432.jar \
			org.apache.batik.util_1.6.0.v201011041432.jar \
			org.apache.batik.util.gui_1.6.0.v201011041432.jar \
			org.apache.commons.codec_1.3.0.v201101211617.jar \
			org.apache.commons.el_1.0.0.v201101211617.jar \
			org.apache.commons.httpclient_3.1.0.v201012070820.jar \
			org.apache.commons.logging_1.0.4.v201101211617.jar \
			org.apache.lucene.core_2.9.1.v201101211721.jar \
			org.apache.lucene.analysis_2.9.1.v201101211721.jar \
			org.hamcrest.core_1.1.0.v20090501071000.jar \
			org.mortbay.jetty.util_6.1.23.v201012071420.jar \
			org.mortbay.jetty.server_6.1.23.v201012071420.jar \
			org.objectweb.asm_3.3.1.v201105211655.jar \
			org.w3c.css.sac_1.3.1.v200903091627.jar \
			org.w3c.dom.svg_1.1.0.v201011041433.jar
ECLIPSE_SAT4J_BUNDLES=	org.sat4j.core_2.3.0.v20110329.jar \
			org.sat4j.pb_2.3.0.v20110329.jar
ECLIPSE_JETTY_VERSION=	8.1.0.v20120127
ECLIPSE_JETTY_SRCFILE=	jetty-distribution-${ECLIPSE_JETTY_VERSION}.tar.gz
ECLIPSE_JETTY_BUNDLES=	jetty-util-${ECLIPSE_JETTY_VERSION}.jar \
			jetty-server-${ECLIPSE_JETTY_VERSION}.jar \
			jetty-http-${ECLIPSE_JETTY_VERSION}.jar \
			jetty-continuation-${ECLIPSE_JETTY_VERSION}.jar \
			jetty-io-${ECLIPSE_JETTY_VERSION}.jar \
			jetty-security-${ECLIPSE_JETTY_VERSION}.jar \
			jetty-servlet-${ECLIPSE_JETTY_VERSION}.jar
ANT_VERSION=		1.8.3
ANT_SRCFILE=		apache-ant-${ANT_VERSION}-bin${BZIP2_SUFX}
ANT_BUNDLES=		ant-antlr.jar \
			ant-apache-bcel.jar \
			ant-apache-bsf.jar \
			ant-apache-log4j.jar \
			ant-apache-oro.jar \
			ant-apache-regexp.jar \
			ant-apache-resolver.jar \
			ant-apache-xalan2.jar \
			ant-commons-logging.jar \
			ant-commons-net.jar \
			ant.jar \
			ant-javamail.jar \
			ant-jdepend.jar \
			ant-jmf.jar \
			ant-jsch.jar \
			ant-junit.jar \
			ant-junit4.jar \
			ant-launcher.jar \
			ant-swing.jar \
			ant-testutil.jar
JUNIT4_VERSION=		4.10
JUNIT4_SRCFILE=		junit-${JUNIT4_VERSION}.jar
TOMCAT_VERSION=		7.0.25
TOMCAT_SRCFILES=	apache-tomcat-${TOMCAT_VERSION}.tar.gz tomcat-juli.jar
TOMCAT_BUNDLES=		el-api.jar \
			jasper-el.jar \
			jasper.jar \
			jsp-api.jar \
			servlet-api.jar \
			tomcat-api.jar \
			tomcat-juli.jar
GERONIMO_ANNOTATION_BUNDLE=	geronimo-annotation_1.1_spec-1.0.jar
FELIX_BUNDLES=		org.apache.felix.gogo.command-0.12.0.jar \
			org.apache.felix.gogo.runtime-0.10.0.jar \
			org.apache.felix.gogo.shell-0.10.0.jar
FBSD_SUPPORT_SRCFILE=	freebsd-support.patch
BUILD_DEPSDIR=		${BUILD_WRKSRC}/dependencies

ALL_TARGET=	provisionSDKinDropins
INSTALL_TARGET=	installSDKinDropins
MAKE_ARGS=	-DbuildOs=freebsd -DbuildArch=${ARCH:C/amd64/x86_64/:C/i386/x86/} -Dprefix=${PREFIX} -Dlocalbase=${LOCALBASE} -Dlabel=${PORTVERSION}-${ECLIPSE_RELEASE_VERSION}
MAKE_ENV+=	GRE_HOME=${PREFIX}/lib/${GECKO:S/19//} _JAVA_OPTIONS="-Xmx1024m" JAVA_VENDOR=${JAVA_VENDOR}

WRKSRC=		${WRKDIR}/${ECLIPSE_BUILD_SRCFILE:C/${EXTRACT_SUFX}//}
PATCH_STRIP=	-p1

BOOTCLASSPATH=	${JAVA_HOME}/jre/lib/rt.jar:${JAVA_HOME}/jre/lib/jce.jar
PORTDESTDIR=	${PREFIX}/lib/${PORTNAME}
DROPINS_DIR=	share/${PORTNAME}/dropins

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/32x32/apps/${PORTNAME}.png \
		share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		share/icons/hicolor/256x256/apps/${PORTNAME}.png \
		share/pixmaps/${PORTNAME}.png

.for f in ${ECLIPSE_JAR_BUNDLES} ${ECLIPSE_SAT4J_BUNDLES}
DISTFILES+=	${f}:2
.endfor
.for f in ${FELIX_BUNDLES}
DISTFILES+=	${f}:10
.endfor

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTESTS}
DISTFILES+=	${ECLIPSE_TEST_SRCFILE}:1 ${ECLIPSE_TEST_SCRIPTFILE}:1

BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash \
		Xvnc:${PORTSDIR}/net/tightvnc

ALL_TARGET=	runTests
.endif

# Prepare Eclipse source, Ant, JUnit, Tomcat, Jetty and Geronimo bundles
post-extract:
	@${MKDIR} ${BUILD_WRKSRC}/bundles

	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${ECLIPSE_SRCFILE} ${BUILD_WRKSRC}
	@${CP} ${FILESDIR}/${FBSD_SUPPORT_SRCFILE} ${BUILD_WRKSRC}/patches/
.for f in ${ECLIPSE_JAR_BUNDLES} ${ECLIPSE_SAT4J_BUNDLES} ${FELIX_BUNDLES}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${f} ${BUILD_WRKSRC}/bundles/
.endfor

	@(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${ANT_SRCFILE} ${EXTRACT_AFTER_ARGS})
.for f in ${ANT_BUNDLES}
	@${CP} ${WRKDIR}/apache-ant-${ANT_VERSION}/lib/${f} ${BUILD_WRKSRC}/bundles/
.endfor

	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${JUNIT4_SRCFILE} ${BUILD_WRKSRC}/bundles/junit4.jar

	@(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${TOMCAT_SRCFILES:Mapache-tomcat*.tar.gz} ${EXTRACT_AFTER_ARGS})
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${TOMCAT_SRCFILES:M*.jar} ${WRKDIR}/apache-tomcat-${TOMCAT_VERSION}/lib/
.for f in ${TOMCAT_BUNDLES}
	@${CP} ${WRKDIR}/apache-tomcat-${TOMCAT_VERSION}/lib/${f} ${BUILD_WRKSRC}/bundles/
.endfor

	@(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${ECLIPSE_JETTY_SRCFILE} ${EXTRACT_AFTER_ARGS})
.for f in ${ECLIPSE_JETTY_BUNDLES}
	@${CP} ${WRKDIR}/jetty-distribution-${ECLIPSE_JETTY_VERSION}/lib/${f} ${BUILD_WRKSRC}/bundles/
.endfor

	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${GERONIMO_ANNOTATION_BUNDLE} ${BUILD_WRKSRC}/bundles/

.if ${PORT_OPTIONS:MTESTS}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${ECLIPSE_TEST_SRCFILE} ${BUILD_WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${ECLIPSE_TEST_SCRIPTFILE} ${BUILD_WRKSRC}
.endif

# Apply patches that have been pushed upstream
pre-patch:
	@${PATCH} -d ${BUILD_WRKSRC} --forward --quiet --suffix .orig -E -p0 -i ${PATCHDIR}/eclipse-build-upstream.patch
	@${PATCH} -d ${BUILD_WRKSRC}/eclipse-build-config --forward --quiet --suffix .orig -E -p0 -i ${PATCHDIR}/eclipse-build-config-upstream.patch

# Fixup boot classes path
post-patch:
	@${REINPLACE_CMD} -e "s+%%BOOTCLASSPATH%%+${BOOTCLASSPATH}+g" ${BUILD_WRKSRC}/build.properties
	@${REINPLACE_CMD} -e "s+%%BOOTCLASSPATH%%+${BOOTCLASSPATH}+g" ${BUILD_WRKSRC}/pdebuild.properties
	@${REINPLACE_CMD} -e "s+%%PORTNAME%%+${PORTNAME}+g" ${BUILD_WRKSRC}/build.xml
	@${REINPLACE_CMD} -e "s+%%PORTNAME%%+${PORTNAME}+g" ${BUILD_WRKSRC}/eclipse.desktop

	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} applyPatches)

.for f in ${ECLIPSE_JAR_BUNDLES}
	@${REINPLACE_CMD} -e "s+^${f}=\(.*\)+${f}=${BUILD_WRKSRC}/bundles/${f}+" ${BUILD_DEPSDIR}/dependencies.properties
	@${REINPLACE_CMD} -e "s+^${f}=\(.*\)+${f}=${BUILD_WRKSRC}/bundles/${f}+" ${BUILD_DEPSDIR}/jdtdependencies.properties
	@${REINPLACE_CMD} -e "s+^${f}=\(.*\)+${f}=${BUILD_WRKSRC}/bundles/${f}+" ${BUILD_DEPSDIR}/sdkdependencies.properties
.endfor
.for f in ${ECLIPSE_SAT4J_BUNDLES}
	@${REINPLACE_CMD} -e "s+^${f}=\(.*\)+${f}=${BUILD_WRKSRC}/bundles/${f}+" ${BUILD_DEPSDIR}/dependencies.properties
.endfor
.for f in ${ECLIPSE_JETTY_BUNDLES}
	@${REINPLACE_CMD} -e "s+^${f:C/(jetty)-([a-z]+)-(.*)$/org.eclipse.\\1.\\2_\\3/}=\(.*\)+${f:C/(jetty)-([a-z]+)-(.*)$/org.eclipse.\\1.\\2_\\3/}=${BUILD_WRKSRC}/bundles/${f}+" ${BUILD_DEPSDIR}/dependencies.properties
.endfor
.for f in ${ANT_BUNDLES}
	@${REINPLACE_CMD} -e "s+${f}=\(.*\)+${f}=${BUILD_WRKSRC}/bundles/${f}+" ${BUILD_DEPSDIR}/nonosgidependencies.properties
.endfor

	@${REINPLACE_CMD} -e "s+=/usr/share/java/junit.jar+=${BUILD_WRKSRC}/bundles/junit4.jar+" ${BUILD_DEPSDIR}/jdtnonosgidependencies.properties
	@${JAR} umf ${FILESDIR}/MANIFEST.MF.junit4 ${BUILD_WRKSRC}/bundles/junit4.jar

	@${REINPLACE_CMD} -e "s+^\(javax.el_2.2.0.v201108011116.jar\)=\(.*\)+\1=${BUILD_WRKSRC}/bundles/el-api.jar+" ${BUILD_DEPSDIR}/dependencies.properties
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/javax.el_2.2.0.v201108011116.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/el-api.jar
	@${REINPLACE_CMD} -e "s+^\(org.apache.el_7.0.21.jar\)=\(.*\)+\1=${BUILD_WRKSRC}/bundles/jasper-el.jar+" ${BUILD_DEPSDIR}/dependencies.properties
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/org.apache.el_7.0.21.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/jasper-el.jar
	@${REINPLACE_CMD} -e "s+^\(org.apache.jasper_7.0.21.jar\)=\(.*\)+\1=${BUILD_WRKSRC}/bundles/jasper.jar+" ${BUILD_DEPSDIR}/dependencies.properties
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/org.apache.jasper_7.0.21.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/jasper.jar
	@${REINPLACE_CMD} -e "s+^\(javax.servlet.jsp_2.2.0.v201112011158.jar\)=\(.*\)+\1=${BUILD_WRKSRC}/bundles/jsp-api.jar+" ${BUILD_DEPSDIR}/dependencies.properties
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/javax.servlet.jsp_2.2.0.v201112011158.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/jsp-api.jar
	@${REINPLACE_CMD} -e "s+^\(javax.servlet_3.0.0.v201112011016.jar\)=\(.*\)+\1=${BUILD_WRKSRC}/bundles/servlet-api.jar+" ${BUILD_DEPSDIR}/dependencies.properties
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/javax.servlet_3.0.0.v201112011016.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/servlet-api.jar
	@${REINPLACE_CMD} -e "s+^\(org.apache.tomcat_7.0.21.jar\)=\(.*\)+\1=${BUILD_WRKSRC}/bundles/tomcat-api.jar+" ${BUILD_DEPSDIR}/dependencies.properties
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/org.apache.tomcat_7.0.21.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/tomcat-api.jar
	@${REINPLACE_CMD} -e "s+^\(org.apache.juli_7.0.21.jar\)=\(.*\)+\1=${BUILD_WRKSRC}/bundles/tomcat-juli.jar+" ${BUILD_DEPSDIR}/dependencies.properties
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/org.apache.juli_7.0.21.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/tomcat-juli.jar

	@${REINPLACE_CMD} -e "s+^\(org.apache.geronimo.specs.geronimo-annotation_1.1_spec.jar\)=.*+\1=${BUILD_WRKSRC}/bundles/${GERONIMO_ANNOTATION_BUNDLE}+" ${BUILD_DEPSDIR}/dependencies.properties
	@${REINPLACE_CMD} -e "s+^\(org.apache.felix.gogo.command\)\(_0.8.0.v201108120515.jar\)=.*+\1\2=${BUILD_WRKSRC}/bundles/\1-0.12.0.jar+" ${BUILD_DEPSDIR}/dependencies.properties
	@${REINPLACE_CMD} -e "s+^\(org.apache.felix.gogo.runtime\)\(_0.8.0.v201108120515.jar\)=.*+\1\2=${BUILD_WRKSRC}/bundles/\1-0.10.0.jar+" ${BUILD_DEPSDIR}/dependencies.properties
	@${REINPLACE_CMD} -e "s+^\(org.apache.felix.gogo.shell\)\(_0.8.0.v201110170705.jar\)=.*+\1\2=${BUILD_WRKSRC}/bundles/\1-0.10.0.jar+" ${BUILD_DEPSDIR}/dependencies.properties

	@${MV} ${BUILD_WRKSRC}/dependencyManifests/javax.xml_1.0.1.v200903091627.jar ${BUILD_WRKSRC}/dependencyManifests/javax.xml_1.3.4.v201005080400.jar
	@${MV} ${BUILD_WRKSRC}/dependencyManifests/org.apache.commons.el_1.0.0.v200806031608.jar ${BUILD_WRKSRC}/dependencyManifests/org.apache.commons.el_1.0.0.v201101211617.jar
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/org.apache.commons.el_1.0.0.v201101211617.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/org.apache.commons.el_1.0.0.v201101211617.jar
	@${ZIP_CMD} -qd ${BUILD_WRKSRC}/bundles/org.apache.commons.el_1.0.0.v201101211617.jar META-INF/ECLIPSEF.SF META-INF/ECLIPSEF.RSA
	@${MV} ${BUILD_WRKSRC}/dependencyManifests/org.mortbay.jetty.server_6.1.23.v201004211559.jar ${BUILD_WRKSRC}/dependencyManifests/org.mortbay.jetty.server_6.1.23.v201012071420.jar
	@${MV} ${BUILD_WRKSRC}/dependencyManifests/org.mortbay.jetty.util_6.1.23.v201004211559.jar ${BUILD_WRKSRC}/dependencyManifests/org.mortbay.jetty.util_6.1.23.v201012071420.jar
	@${MV} ${BUILD_WRKSRC}/dependencyManifests/org.objectweb.asm_3.3.1.v201101071600.jar ${BUILD_WRKSRC}/dependencyManifests/org.objectweb.asm_3.3.1.v201105211655.jar
	@${ZIP_CMD} -qd ${BUILD_WRKSRC}/bundles/org.w3c.dom.svg_1.1.0.v201011041433.jar META-INF/ECLIPSEF.SF META-INF/ECLIPSEF.RSA META-INF/MANIFEST.MF
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/org.w3c.dom.svg_1.1.0.v201011041433.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/org.w3c.dom.svg_1.1.0.v201011041433.jar

.if ${PORT_OPTIONS:MTESTS}
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} applyTestPatches)
.endif

pre-build:
	@${CP} ${BUILD_WRKSRC}/build/eclipse-4.2.0-I20120608-1400-src/plugins/org.eclipse.ui.workbench/Eclipse\ UI/org/eclipse/ui/internal/keys/model/BindingModel.java ${BUILD_WRKSRC}
	@${PATCH} -d ${BUILD_WRKSRC} -E -p0 -i ${PATCHDIR}/BindingModel.java.patch
	@${CP} ${BUILD_WRKSRC}/BindingModel.java ${BUILD_WRKSRC}/build/eclipse-4.2.0-I20120608-1400-src/plugins/org.eclipse.ui.workbench/Eclipse\ UI/org/eclipse/ui/internal/keys/model/BindingModel.java

do-install:
	@${RM} -rf ${PORTDESTDIR}
	@${MKDIR} ${PORTDESTDIR}
	@${MKDIR} ${PREFIX}/${DROPINS_DIR}
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} ${INSTALL_TARGET})
.for d in plugins dropins/jdt/plugins
	@${FIND} ${PORTDESTDIR}/${d} -type f -perm 600 -print0 | ${XARGS} -0 ${CHMOD} 644
.endfor
	@${SED} \
	  -e "s+%%BROWSER%%+${GECKO:S/19//}+g" \
	  -e "s+%%ECLIPSE_HOME%%+${PORTDESTDIR}+g" \
	  -e "s+%%JAVA_HOME%%+${JAVA_HOME}+g" \
	  -e "s+%%JAVA_OS%%+${JAVA_OS}+g" \
	  -e "s+%%JAVA_VERSION%%+${JAVA_VERSION}+g" \
	  -e "s+%%LOCALBASE%%+${LOCALBASE}+g" \
	  ${FILESDIR}/eclipse.in > ${BUILD_WRKSRC}/eclipse.tmp
.if defined(JAVA_VENDOR)
	@${REINPLACE_CMD} -e "s+%%JAVA_VENDOR_SPECIFICATION%%+JAVA_VENDOR=\"${JAVA_VENDOR}\"+g" \
	  ${BUILD_WRKSRC}/eclipse.tmp
.else
	@${REINPLACE_CMD} -e "s+%%JAVA_VENDOR_SPECIFICATION%%++g" \
	  ${BUILD_WRKSRC}/eclipse.tmp
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/eclipse.tmp ${PREFIX}/bin/${PORTNAME}
	@${PREFIX}/bin/${PORTNAME} -initialize -consolelog
	-@update-desktop-database
	@(cd ${PREFIX}; ${FIND} -s lib/${PORTNAME} -not -type d) >> ${TMPPLIST}
	@(cd ${PREFIX}; ${FIND} -s -d lib/${PORTNAME} -type d) | ${SED} -ne "s,^,@dirrm ,p" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${MKDIR} %D/share/${PORTNAME}/dropins 2>/dev/null || true " >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/share/${PORTNAME}/dropins 2>/dev/null || true " >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/share/${PORTNAME} 2>/dev/null || true " >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${PREFIX}/bin/update-desktop-database > /dev/null || /usr/bin/true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${PREFIX}/bin/update-desktop-database > /dev/null || /usr/bin/true" >> ${TMPPLIST}

.if ${PORT_OPTIONS:MTESTS}
tests: build
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} runTests)
.else
tests:
	@${ECHO_CMD} "Tests are not enabled!"
.endif

.include <bsd.port.post.mk>
