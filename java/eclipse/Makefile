# $FreeBSD$

PORTNAME=	eclipse
PORTVERSION=	3.7.1
PORTREVISION=	3
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/technology/linuxtools/eclipse-build/3.7.x_Indigo/:1 \
		http://download.eclipse.org/tools/orbit/downloads/drops/R20110523182458/repository/plugins/:2 \
		${MASTER_SITE_APACHE:S,%SUBDIR%/,ant/binaries/:4,} \
		${MASTER_SITE_SOURCEFORGE:S,%SUBDIR%/,junit/junit/${JUNIT3_VERSION}/:5,} \
		http://cloud.github.com/downloads/KentBeck/junit/:6 \
		${MASTER_SITE_APACHE_TOMCAT:S,%SUBDIR%/,tomcat-7/v${TOMCAT_VERSION}/bin/:7,} \
		${MASTER_SITE_APACHE_TOMCAT:S,%SUBDIR%/,tomcat-7/v${TOMCAT_VERSION}/bin/extras/:7,}
DISTFILES=	${ECLIPSE_BUILD_SRCFILE}:1 \
		${ECLIPSE_SRCFILE}:1 \
		${ANT_SRCFILE}:4 \
		${JUNIT3_SRCFILE}:5 \
		${JUNIT4_SRCFILE}:6 \
		${TOMCAT_SRCFILES:C,(.*),\\1:7,}
DIST_SUBDIR=	eclipse
EXTRACT_ONLY=	${ECLIPSE_BUILD_SRCFILE}

MAINTAINER=	eclipse@FreeBSD.org
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
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

OPTIONS_DEFINE=	TESTS
TESTS_DESC=	Build SDK test suite

ONLY_FOR_ARCHS=	i386 amd64

USE_ANT=	yes
USE_GECKO=	libxul19
USE_GL=		glu
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils gconf2 gtk20 gnomevfs2 libgnome libgnomeui
USE_PKGCONFIG=	build
USE_JAVA=	yes
USE_XZ=		yes
BZIP2_SUFX=	.tar.bz2
ZIP_CMD?=	${LOCALBASE}/bin/zip

JAVA_BUILD=	yes
JAVA_OS=	native
JAVA_RUN=	yes
JAVA_VERSION=	1.6
JAVA_VENDOR=	openjdk

ECLIPSE_BUILD_SRCFILE=	eclipse-build-914dc6de2bfc5ee5819a229cf4877f7043040a92${EXTRACT_SUFX}
ECLIPSE_SRCFILE=	eclipse-${PORTVERSION}-src${BZIP2_SUFX}
ECLIPSE_TEST_SRCFILE=	eclipse-sdktests-${PORTVERSION}-src${BZIP2_SUFX}
ECLIPSE_TEST_SCRIPTFILE=eclipse-sdktests-${PORTVERSION}-scripts${BZIP2_SUFX}
ECLIPSE_JAR_BUNDLES=	com.ibm.icu_4.4.2.v20110208.jar \
			com.jcraft.jsch_0.1.41.v201101211617.jar \
			org.apache.commons.codec_1.3.0.v201101211617.jar \
			org.apache.commons.el_1.0.0.v201101211617.jar \
			org.apache.commons.httpclient_3.1.0.v201012070820.jar \
			org.apache.commons.logging_1.0.4.v201101211617.jar \
			org.apache.lucene.core_2.9.1.v201101211721.jar \
			org.apache.lucene.analysis_2.9.1.v201101211721.jar \
			org.hamcrest.core_1.1.0.v20090501071000.jar \
			org.mortbay.jetty.util_6.1.23.v201012071420.jar \
			org.mortbay.jetty.server_6.1.23.v201012071420.jar \
			org.objectweb.asm_3.3.1.v201105211655.jar
ECLIPSE_SAT4J_BUNDLES=	org.sat4j.core_2.3.0.v20110329.jar \
			org.sat4j.pb_2.3.0.v20110329.jar
ANT_VERSION=		1.8.2
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
JUNIT3_VERSION=		3.8.2
JUNIT3_SRCFILE=		junit${JUNIT3_VERSION}.zip
JUNIT4_VERSION=		4.8.2
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
FBSD_SUPPORT_SRCFILE=	freebsd-support.patch
ECLIPSE_GENERATED_BUILDSCRIPTS=	eclipse-build-generatedScripts.tar.bz2

ALL_TARGET=	provision.cvs
INSTALL_TARGET=	installSDKinDropins
MAKE_ARGS=	-DbuildOs=freebsd -DbuildArch=${ARCH:C/amd64/x86_64/:C/i386/x86/} -Dprefix=${PREFIX} -Dlocalbase=${LOCALBASE} -Dlabel=${PORTVERSION}
MAKE_ENV+=	GRE_HOME=${PREFIX}/lib/${GECKO:S/19//} _JAVA_OPTIONS="-Xmx1024m" JAVA_VENDOR=${JAVA_VENDOR}

WRKSRC=		${WRKDIR}/${ECLIPSE_BUILD_SRCFILE:C/${EXTRACT_SUFX}//}
PATCH_STRIP=	-p1

BOOTCLASSPATH=	${JAVA_HOME}/jre/lib/rt.jar:${JAVA_HOME}/jre/lib/jce.jar:${JAVA_HOME}/jre/lib/jsse.jar
PORTDESTDIR=	${PREFIX}/lib/${PORTNAME}
DROPINS_DIR=	share/${PORTNAME}/dropins

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop \
		share/icons/hicolor/16x16/apps/${PORTNAME}.png \
		share/icons/hicolor/32x32/apps/${PORTNAME}.png \
		share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		share/pixmaps/${PORTNAME}.png

.for f in ${ECLIPSE_JAR_BUNDLES} ${ECLIPSE_SAT4J_BUNDLES}
DISTFILES+=	${f}:2
.endfor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTESTS}
DISTFILES+=	${ECLIPSE_TEST_SRCFILE}:1 ${ECLIPSE_TEST_SCRIPTFILE}:1

BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash \
		Xvnc:${PORTSDIR}/net/tightvnc

ALL_TARGET=	runTests
.endif

# Prepare Eclipse source, Ant, JUnit and Tomcat bundles
post-extract:
	@${MKDIR} ${BUILD_WRKSRC}/bundles

	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${ECLIPSE_SRCFILE} ${BUILD_WRKSRC}
	@${CP} ${FILESDIR}/${FBSD_SUPPORT_SRCFILE} ${BUILD_WRKSRC}/patches/
.for f in ${ECLIPSE_JAR_BUNDLES} ${ECLIPSE_SAT4J_BUNDLES}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${f} ${BUILD_WRKSRC}/bundles/
.endfor
	@(${MKDIR} ${BUILD_WRKSRC}/generatedScripts && cd ${BUILD_WRKSRC}/generatedScripts && ${BZIP2_CMD} ${EXTRACT_BEFORE_ARGS} ${BUILD_WRKSRC}/${ECLIPSE_GENERATED_BUILDSCRIPTS} ${EXTRACT_AFTER_ARGS})

	@(cd ${WRKDIR} && ${BZIP2_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${ANT_SRCFILE} ${EXTRACT_AFTER_ARGS})
.for f in ${ANT_BUNDLES}
	@${CP} ${WRKDIR}/apache-ant-${ANT_VERSION}/lib/${f} ${BUILD_WRKSRC}/bundles/
.endfor

	@${MKDIR} ${WRKDIR}/junit
	@${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${JUNIT3_SRCFILE} -d ${WRKDIR}/junit
	@${CP} ${WRKDIR}/junit/junit${JUNIT3_VERSION}/junit.jar ${BUILD_WRKSRC}/bundles/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${JUNIT4_SRCFILE} ${BUILD_WRKSRC}/bundles/junit4.jar

	@(cd ${WRKDIR} && ${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${TOMCAT_SRCFILES:Mapache-tomcat*.tar.gz} ${EXTRACT_AFTER_ARGS})
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${TOMCAT_SRCFILES:M*.jar} ${WRKDIR}/apache-tomcat-${TOMCAT_VERSION}/lib/
.for f in ${TOMCAT_BUNDLES}
	@${CP} ${WRKDIR}/apache-tomcat-${TOMCAT_VERSION}/lib/${f} ${BUILD_WRKSRC}/bundles/
.endfor

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
	@(cd ${BUILD_WRKSRC}/generatedScripts; tar cjf ${BUILD_WRKSRC}/${ECLIPSE_GENERATED_BUILDSCRIPTS} plugins)

	@${REINPLACE_CMD} -e "s+%%BOOTCLASSPATH%%+${BOOTCLASSPATH}+g" ${BUILD_WRKSRC}/build.properties
	@${REINPLACE_CMD} -e "s+%%BOOTCLASSPATH%%+${BOOTCLASSPATH}+g" ${BUILD_WRKSRC}/pdebuild.properties
	@${REINPLACE_CMD} -e "s+%%PORTNAME%%+${PORTNAME}+g" ${BUILD_WRKSRC}/build.xml
	@${REINPLACE_CMD} -e "s+%%PORTNAME%%+${PORTNAME}+g" ${BUILD_WRKSRC}/eclipse.desktop

	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} applyPatches)

.for f in ${ECLIPSE_JAR_BUNDLES}
	@${REINPLACE_CMD} -e "s+^${f}=\(.*\)+${f}=${BUILD_WRKSRC}/bundles/${f}+" ${BUILD_WRKSRC}/dependencies.properties
	@${REINPLACE_CMD} -e "s+^${f}=\(.*\)+${f}=${BUILD_WRKSRC}/bundles/${f}+" ${BUILD_WRKSRC}/jdtdependencies.properties
	@${REINPLACE_CMD} -e "s+^${f}=\(.*\)+${f}=${BUILD_WRKSRC}/bundles/${f}+" ${BUILD_WRKSRC}/sdkdependencies.properties
.endfor
.for f in ${ECLIPSE_SAT4J_BUNDLES}
	@${REINPLACE_CMD} -e "s+^${f}=\(.*\)+${f}=${BUILD_WRKSRC}/bundles/${f}+" ${BUILD_WRKSRC}/dependencies.properties
.endfor
.for f in ${ANT_BUNDLES}
	@${REINPLACE_CMD} -e "s+${f}=\(.*\)+${f}=${BUILD_WRKSRC}/bundles/${f}+" ${BUILD_WRKSRC}/nonosgidependencies.properties
.endfor
	@${REINPLACE_CMD} -e "s+=/usr/share/java/junit.jar+=${BUILD_WRKSRC}/bundles/junit.jar+" ${BUILD_WRKSRC}/jdtnonosgidependencies.properties
	@${REINPLACE_CMD} -e "s+=/usr/share/java/junit4.jar+=${BUILD_WRKSRC}/bundles/junit4.jar+" ${BUILD_WRKSRC}/jdtnonosgidependencies.properties
	@${REINPLACE_CMD} -e "s+/usr/share/java/junit4.jar+${BUILD_WRKSRC}/bundles/junit4.jar+" ${BUILD_WRKSRC}/build.xml

	@${REINPLACE_CMD} -e "s+^\(javax.el_2.2.0.jar\)=\(.*\)+\1=${BUILD_WRKSRC}/bundles/el-api.jar+" ${BUILD_WRKSRC}/dependencies.properties
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/javax.el_2.2.0.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/el-api.jar
	@${REINPLACE_CMD} -e "s+^\(org.apache.el_7.0.21.jar\)=\(.*\)+\1=${BUILD_WRKSRC}/bundles/jasper-el.jar+" ${BUILD_WRKSRC}/dependencies.properties
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/org.apache.el_7.0.21.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/jasper-el.jar
	@${REINPLACE_CMD} -e "s+^\(org.apache.jasper_7.0.21.jar\)=\(.*\)+\1=${BUILD_WRKSRC}/bundles/jasper.jar+" ${BUILD_WRKSRC}/dependencies.properties
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/org.apache.jasper_7.0.21.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/jasper.jar
	@${REINPLACE_CMD} -e "s+^\(javax.servlet.jsp_2.2.0.jar\)=\(.*\)+\1=${BUILD_WRKSRC}/bundles/jsp-api.jar+" ${BUILD_WRKSRC}/dependencies.properties
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/javax.servlet.jsp_2.2.0.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/jsp-api.jar
	@${REINPLACE_CMD} -e "s+^\(javax.servlet_3.0.0.jar\)=\(.*\)+\1=${BUILD_WRKSRC}/bundles/servlet-api.jar+" ${BUILD_WRKSRC}/dependencies.properties
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/javax.servlet_3.0.0.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/servlet-api.jar
	@${REINPLACE_CMD} -e "s+^\(org.apache.tomcat_7.0.21.jar\)=\(.*\)+\1=${BUILD_WRKSRC}/bundles/tomcat-api.jar+" ${BUILD_WRKSRC}/dependencies.properties
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/org.apache.tomcat_7.0.21.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/tomcat-api.jar
	@${REINPLACE_CMD} -e "s+^\(org.apache.juli_7.0.21.jar\)=\(.*\)+\1=${BUILD_WRKSRC}/bundles/tomcat-juli.jar+" ${BUILD_WRKSRC}/dependencies.properties
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/org.apache.juli_7.0.21.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/tomcat-juli.jar

	@${MV} ${BUILD_WRKSRC}/dependencyManifests/com.jcraft.jsch_0.1.41.v200903070017.jar ${BUILD_WRKSRC}/dependencyManifests/com.jcraft.jsch_0.1.41.v201101211617.jar
	@${MV} ${BUILD_WRKSRC}/dependencyManifests/org.apache.commons.el_1.0.0.v200806031608.jar ${BUILD_WRKSRC}/dependencyManifests/org.apache.commons.el_1.0.0.v201101211617.jar
	@${JAR} umf ${BUILD_WRKSRC}/dependencyManifests/org.apache.commons.el_1.0.0.v201101211617.jar/META-INF/MANIFEST.MF ${BUILD_WRKSRC}/bundles/org.apache.commons.el_1.0.0.v201101211617.jar
	@${ZIP_CMD} -qd ${BUILD_WRKSRC}/bundles/org.apache.commons.el_1.0.0.v201101211617.jar META-INF/ECLIPSEF.SF META-INF/ECLIPSEF.RSA
	@${MV} ${BUILD_WRKSRC}/dependencyManifests/org.apache.commons.httpclient_3.1.0.v201005080502.jar ${BUILD_WRKSRC}/dependencyManifests/org.apache.commons.httpclient_3.1.0.v201012070820.jar
	@${MV} ${BUILD_WRKSRC}/dependencyManifests/org.mortbay.jetty.server_6.1.23.v201004211559.jar ${BUILD_WRKSRC}/dependencyManifests/org.mortbay.jetty.server_6.1.23.v201012071420.jar
	@${MV} ${BUILD_WRKSRC}/dependencyManifests/org.mortbay.jetty.util_6.1.23.v201004211559.jar ${BUILD_WRKSRC}/dependencyManifests/org.mortbay.jetty.util_6.1.23.v201012071420.jar
	@${MV} ${BUILD_WRKSRC}/dependencyManifests/org.objectweb.asm_3.3.1.v201101071600.jar ${BUILD_WRKSRC}/dependencyManifests/org.objectweb.asm_3.3.1.v201105211655.jar

.if defined(WITH_TESTS)
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} applyTestPatches)
.endif

do-install:
	@${RM} -rf ${PORTDESTDIR}
	@${MKDIR} ${PORTDESTDIR}
	@${MKDIR} ${PREFIX}/${DROPINS_DIR}
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} ${INSTALL_TARGET})
	@${FIND} ${PORTDESTDIR}/plugins -type f -perm 600 -print0 | ${XARGS} -0 ${CHMOD} 644
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

.include <bsd.port.mk>
