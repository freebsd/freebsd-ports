# New ports collection makefile for:	eclipse-devel
# Date created:				April 9, 2005
# Whom:					various members of freebsd-java
#
# $FreeBSD$
#

PORTNAME=	eclipse-devel
PORTVERSION=	3.5.2
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/technology/linuxtools/eclipse-build/:1 \
		http://download.eclipse.org/tools/orbit/downloads/drops/R20090825191606/bundles/:2 \
		http://download.eclipse.org/tools/orbit/downloads/drops/S20100308015149/bundles/:3 \
		${MASTER_SITE_APACHE:S,%SUBDIR%/,ant/binaries/:4,} \
		${MASTER_SITE_SOURCEFORGE:S,%SUBDIR%/,junit/junit/${JUNIT3_VERSION}/:5,} \
		${MASTER_SITE_SOURCEFORGE:S,%SUBDIR%/,junit/junit/${JUNIT4_VERSION}/:6,}
DISTFILES=	${ECLIPSE_BUILD_SRCFILE}:1 \
		${ECLIPSE_SRCFILE}:1 \
		${ANT_SRCFILE}:4 \
		${JUNIT3_SRCFILE}:5 \
		${JUNIT4_SRCFILE}:6
DIST_SUBDIR=	eclipse
EXTRACT_ONLY=	${ECLIPSE_BUILD_SRCFILE} ${ANT_SRCFILE}

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	An open extensible IDE for anything and nothing in particular

EXTRACT_DEPENDS=${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip
PATCH_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		gpatch:${PORTSDIR}/devel/patch \
		zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS=	gpatch:${PORTSDIR}/devel/patch \
		unzip:${PORTSDIR}/archivers/unzip \
		zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

OPTIONS=	TESTS	"Build SDK test suite"	off

ONLY_FOR_ARCHS=	i386 amd64

USE_ANT=	yes
USE_GECKO=	libxul
USE_GL=		glu
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils gconf2 gtk20 gnomevfs2 libgnome libgnomeui pkgconfig
USE_JAVA=	yes
USE_BZIP2=	yes

JAVA_BUILD=	yes
JAVA_OS=	native
JAVA_RUN=	yes
JAVA_VERSION=	1.6

ECLIPSE_BUILD_SRCFILE=	eclipse-build-0.5.0${EXTRACT_SUFX}
ECLIPSE_SRCFILE=	eclipse-${PORTVERSION}-src${EXTRACT_SUFX}
ECLIPSE_TEST_SRCFILE=	eclipse-sdktests-${PORTVERSION}-src${EXTRACT_SUFX}
ECLIPSE_TEST_SCRIPTFILE=eclipse-sdktests-${PORTVERSION}-scripts${EXTRACT_SUFX}
ECLIPSE_JAR_BUNDLES=	com.ibm.icu_4.0.1.v20090822.jar \
			com.jcraft.jsch_0.1.41.v200903070017.jar \
			javax.servlet_2.5.0.v200806031605.jar \
			javax.servlet.jsp_2.0.0.v200806031607.jar \
			org.apache.commons.codec_1.3.0.v20080530-1600.jar \
			org.apache.commons.el_1.0.0.v200806031608.jar \
			org.apache.commons.httpclient_3.1.0.v20080605-1935.jar \
			org.apache.commons.logging_1.0.4.v200904062259.jar \
			org.apache.jasper_5.5.17.v200903231320.jar \
			org.apache.lucene_1.9.1.v20080530-1600.jar \
			org.apache.lucene.analysis_1.9.1.v20080530-1600.jar \
			org.hamcrest.core_1.1.0.v20090501071000.jar \
			org.mortbay.jetty.server_6.1.15.v200905151201.jar \
			org.mortbay.jetty.util_6.1.15.v200905182336.jar \
			org.objectweb.asm_3.1.0.v200803061910.jar
ECLIPSE_SAT4J_BUNDLES=	org.sat4j.core_2.1.1.v20090825.jar \
			org.sat4j.pb_2.1.1.v20090825.jar
ANT_VERSION=		1.7.1
ANT_SRCFILE=		apache-ant-${ANT_VERSION}-bin${EXTRACT_SUFX}
ANT_BUNDLES=		ant-antlr.jar \
			ant-apache-bcel.jar \
			ant-apache-bsf.jar \
			ant-apache-log4j.jar \
			ant-apache-oro.jar \
			ant-apache-regexp.jar \
			ant-apache-resolver.jar \
			ant-commons-logging.jar \
			ant-commons-net.jar \
			ant.jar \
			ant-javamail.jar \
			ant-jdepend.jar \
			ant-jsch.jar \
			ant-junit.jar \
			ant-launcher.jar \
			ant-nodeps.jar \
			ant-swing.jar \
			ant-trax.jar
JUNIT3_VERSION=		3.8.2
JUNIT3_SRCFILE=		junit${JUNIT3_VERSION}.zip
JUNIT4_VERSION=		4.8.1
JUNIT4_SRCFILE=		junit-${JUNIT4_VERSION}.jar
FBSD_SUPPORT_SRCFILE=	freebsd-support.patch

MAKE_ARGS=	-DbuildOs=freebsd -DbuildArch=${ARCH:C/amd64/x86_64/:C/i386/x86/} -Dprefix=${PREFIX} -Dlocalbase=${LOCALBASE}
MAKE_ENV+=	GRE_HOME=${PREFIX}/lib/${GECKO} _JAVA_OPTIONS="-Xmx1024m"
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

.for f in ${ECLIPSE_JAR_BUNDLES}
DISTFILES+=	${f}:2
.endfor

.for f in ${ECLIPSE_SAT4J_BUNDLES}
DISTFILES+=	${f}:3
.endfor

.include <bsd.port.pre.mk>

.if defined(WITH_TESTS)
DISTFILES+=	${ECLIPSE_TEST_SRCFILE}:1 ${ECLIPSE_TEST_SCRIPTFILE}:1

BUILD_DEPENDS+=	bash:${PORTSDIR}/shells/bash \
		Xvnc:${PORTSDIR}/net/tightvnc

ALL_TARGET=	provision.tests
.endif

.if ${OSVERSION} >= 800000
JAVA_VENDOR=	bsdjava
.endif

# Copy the eclipse source file to the work area
post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${ECLIPSE_SRCFILE} ${BUILD_WRKSRC}
	@${CP} ${FILESDIR}/${FBSD_SUPPORT_SRCFILE} ${BUILD_WRKSRC}/patches/
	@${MKDIR} ${BUILD_WRKSRC}/bundles
.for f in ${ECLIPSE_JAR_BUNDLES}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${f} ${BUILD_WRKSRC}/bundles/
.endfor
.for f in ${ECLIPSE_SAT4J_BUNDLES}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${f} ${BUILD_WRKSRC}/bundles/
.endfor
.for f in ${ANT_BUNDLES}
	@${CP} ${WRKDIR}/apache-ant-${ANT_VERSION}/lib/${f} ${BUILD_WRKSRC}/bundles/
.endfor
	@${MKDIR} ${WRKDIR}/junit
	@${UNZIP_CMD} -qo ${DISTDIR}/${DIST_SUBDIR}/${JUNIT3_SRCFILE} -d ${WRKDIR}/junit
	@${CP} ${WRKDIR}/junit/junit${JUNIT3_VERSION}/junit.jar ${BUILD_WRKSRC}/bundles/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${JUNIT4_SRCFILE} ${BUILD_WRKSRC}/bundles/junit4.jar
.if defined(WITH_TESTS)
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
	@${REINPLACE_CMD} -e "s+%%PORTNAME%%+${PORTNAME}+g" ${BUILD_WRKSRC}/build.xml
	@${REINPLACE_CMD} -e "s+%%BOOTCLASSPATH%%+${BOOTCLASSPATH}+g" ${BUILD_WRKSRC}/pdebuild.properties
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} applyPatches)
.for f in ${ECLIPSE_JAR_BUNDLES}
	@${REINPLACE_CMD} -e "s+^${f}=\(.*\)+${f}=${BUILD_WRKSRC}/bundles/${f}+" ${BUILD_WRKSRC}/dependencies.properties
.endfor
.for f in ${ECLIPSE_SAT4J_BUNDLES}
	@${REINPLACE_CMD} -e "s+^${f}=\(.*\)+${f}=${BUILD_WRKSRC}/bundles/${f}+" ${BUILD_WRKSRC}/dependencies.properties
.endfor
.for f in ${ANT_BUNDLES}
	@${REINPLACE_CMD} -e "s+${f}=\(.*\)+${f}=${BUILD_WRKSRC}/bundles/${f}+" ${BUILD_WRKSRC}/nonosgidependencies.properties
.endfor
	@${REINPLACE_CMD} -e "s+=/usr/share/java/junit.jar+=${BUILD_WRKSRC}/bundles/junit.jar+" ${BUILD_WRKSRC}/nonosgidependencies.properties
	@${REINPLACE_CMD} -e "s+=/usr/share/java/junit4.jar+=${BUILD_WRKSRC}/bundles/junit4.jar+" ${BUILD_WRKSRC}/nonosgidependencies.properties
.if defined(WITH_TESTS)
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} applyTestPatches)
.endif

do-install:
	@${RM} -rf ${PORTDESTDIR}
	@${MKDIR} ${PORTDESTDIR}
	@${MKDIR} ${PREFIX}/${DROPINS_DIR}
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} ${INSTALL_TARGET})
	@${SED} \
	  -e "s+%%BROWSER%%+${GECKO}+g" \
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
	@cd ${BUILD_WRKSRC}/bundles && \
		${COPYTREE_SHARE} . ${PORTDESTDIR}/plugins/
	@${PREFIX}/bin/${PORTNAME} -initialize -consolelog
	-@update-desktop-database
	@(cd ${PREFIX}; ${FIND} -s lib/${PORTNAME} -not -type d) >> ${TMPPLIST}
	@(cd ${PREFIX}; ${FIND} -s -d lib/${PORTNAME} -type d) | ${SED} -ne "s,^,@dirrm ,p" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/share/${PORTNAME}/dropins 2>/dev/null || true " >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/share/${PORTNAME} 2>/dev/null || true " >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${PREFIX}/bin/update-desktop-database > /dev/null || /usr/bin/true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${PREFIX}/bin/update-desktop-database > /dev/null || /usr/bin/true" >> ${TMPPLIST}

.if defined(WITH_TESTS)
tests: build
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${ANT} ${MAKE_ARGS} runTests)
.else
tests:
	@${ECHO_CMD} "Tests are not enabled!"
.endif

.include <bsd.port.post.mk>
