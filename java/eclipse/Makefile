# New ports collection makefile for:	eclipse
# Date created:				March 7, 2003
# Whom:					various members of freebsd-java
#
# $FreeBSD$
#

PORTNAME=	eclipse
PORTVERSION=	${ECLIPSE_RELEASE:C/(.*)\.[A-Z][0-9]{8}-[0-9]{4}/\1/}
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=	R-${PORTVERSION}-${ECLIPSE_TIMESTAMP}
DISTNAME=	eclipse-sourceBuild-srcIncluded-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	sepotvin@FreeBSD.org
COMMENT=	An open extensible IDE for anything and nothing in particular

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip

ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
USE_ZIP=	yes
USE_GL=		glu
USE_JAVA=	yes
JAVA_VERSION=	1.6
JAVA_OS=	native

.if !defined(WITHOUT_MOZILLA)
USE_GECKO=	libxul firefox xulrunner seamonkey
.endif

USE_GNOME=	gtk20 pkgconfig desktopfileutils gconf2
.if defined(WITHOUT_GNOMEVFS)
MAKE_GNOME=
.else
MAKE_GNOME=	make_gnome
USE_GNOME+=	gnomevfs2 libgnome libgnomeui
.endif

.if defined(WITHOUT_CAIRO)
MAKE_CAIRO=
.else
LIB_DEPENDS+=	cairo.2:${PORTSDIR}/graphics/cairo
MAKE_CAIRO=	make_cairo
.endif

PORTDESTDIR=	${PREFIX}/${PORTNAME}
NO_WRKSUBDIR=	yes

ECLIPSE_RELEASE=3.4.2.M20090211-1700
ECLIPSE_VERSION=${ECLIPSE_RELEASE}-${PORTREVISION}
ECLIPSE_BUILDID=${ECLIPSE_VERSION:C/.*\.([MIS][0-9]{8}-[0-9]{4}-[0-9]+)/\1/}
ECLIPSE_BUILDTYPE=${ECLIPSE_BUILDID:C/(.).*/\1/}
ECLIPSE_TIMESTAMP=${ECLIPSE_BUILDID:C/.([0-9]{8})-([0-9]{4})-[0-9]+/\1\2/}
ECLIPSE_PDE_BUILD_VERSION=3.4.1.R34x_v20081217
ECLIPSE_LAUNCHER_VERSION=1.0.101.R34x_v20081125

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
JAVA_VENDOR=	bsdjava
.endif

.if ${OSVERSION} < 800086
PATCH_DEPENDS+=	gpatch:${PORTSDIR}/devel/patch
PATCH=		${LOCALBASE}/bin/gpatch
.endif

.if !defined(WITHOUT_MOZILLA)
MAKE_MOZILLA=	make_mozilla
BROWSER=	${GECKO}
.else
BROWSER=
MAKE_MOZILLA=
.endif

ECLIPSE_OS=	freebsd
ECLIPSE_WS=	gtk
.if (${ARCH} == "amd64")
ECLIPSE_ARCH=	x86_64
ECLIPSE_SWT=	gtk64
.else
ECLIPSE_ARCH=	x86
ECLIPSE_SWT=	gtk
.endif
ECLIPSE_ARCH_ALL=	x86 x86_64

MAKE_ENV+=	BROWSER=${BROWSER} \
		ECLIPSE_ARCH=${ECLIPSE_ARCH} \
		ECLIPSE_OS=${ECLIPSE_OS} \
		ECLIPSE_WS=${ECLIPSE_WS} \
		JAVA_HOME=${JAVA_HOME} \
		MAKE_GNOME=${MAKE_GNOME} \
		MAKE_MOZILLA=${MAKE_MOZILLA} \
		MAKE_CAIRO=${MAKE_CAIRO} \
		MACHINE_ARCH=${MACHINE_ARCH}

PLIST_FILES=	bin/${PORTNAME} share/applications/${PORTNAME}.desktop

SWTBASE=${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT
SWTGTK=${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT PI
SWTMOZ=${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT Mozilla

JAVA_BOOTCLASSES=${JAVA_HOME}/jre/lib/rt.jar;${JAVA_HOME}/jre/lib/jce.jar;${JAVA_HOME}/jre/lib/jsse.jar
ECLIPSE_LAUNCHER=${WRKSRC}/eclipse/plugins/org.eclipse.equinox.launcher_${ECLIPSE_LAUNCHER_VERSION}.jar
ECLIPSE_PDE_BUILD=${WRKSRC}/eclipse/plugins/org.eclipse.pde.build_${ECLIPSE_PDE_BUILD_VERSION}

post-patch:
	@${PATCH} ${PATCH_DIST_ARGS} -d "${SWTBASE}" -i ${FILESDIR}/post-patch-plugins-org.eclipse.swt-Eclipse_SWT-gtk-org-eclipse-swt-widgets-FileDialog.java
	@${PATCH} ${PATCH_DIST_ARGS} -d "${SWTBASE}" -i ${FILESDIR}/post-patch-plugins-org.eclipse.swt-Eclipse_SWT-gtk-org-eclipse-swt-widgets-DirectoryDialog.java
	@${PATCH} ${PATCH_DIST_ARGS} -d "${SWTGTK}" -i ${FILESDIR}/post-patch-plugins-org.eclipse.swt-Eclipse_SWT_PI-gtk-library-build.sh
	@${PATCH} ${PATCH_DIST_ARGS} -d "${SWTGTK}" -i ${FILESDIR}/post-patch-plugins-org.eclipse.swt-Eclipse_SWT_PI-gtk-library-build.xml
	@${PATCH} ${PATCH_DIST_ARGS} -d "${SWTGTK}" -i ${FILESDIR}/post-patch-plugins-org.eclipse.swt-Eclipse_SWT_PI-gtk-library-make_freebsd.mak
	@${PATCH} ${PATCH_DIST_ARGS} -d "${SWTGTK}" -i ${FILESDIR}/post-patch-plugins-org.eclipse.swt-Eclipse_SWT_PI-gtk-org-eclipse-swt-internal-gtk-OS.java
	@${PATCH} ${PATCH_DIST_ARGS} -d "${SWTMOZ}" -i ${FILESDIR}/post-patch-plugins-org.eclipse.swt-Eclipse_SWT_Mozilla-gtk-org-eclipse-swt-browser-MozillaDelegate.java
	@${MKDIR} ${WRKSRC}/packager
	@${CP} ${WRKSRC}/plugins/org.eclipse.pde.build/templates/packager/customTargets.xml ${WRKSRC}/packager/
	@${PATCH} ${PATCH_DIST_ARGS} -d "${WRKSRC}" -i ${FILESDIR}/post-patch-packager-customTargets.xml
	@${SED} -e "s+%%JAVA_BOOTCLASSES%%+${JAVA_BOOTCLASSES}+g" ${FILESDIR}/build.properties.in > ${WRKSRC}/build.properties
	@${SED} \
	  -e "s/%%ECLIPSE_ARCH%%/${ECLIPSE_ARCH}/g" \
	  -e "s/%%ECLIPSE_BUILDID%%/${ECLIPSE_BUILDID}/g" \
	  -e "s/%%ECLIPSE_BUILDTYPE%%/${ECLIPSE_BUILDTYPE}/g" \
	  -e "s/%%ECLIPSE_TIMESTAMP%%/${ECLIPSE_TIMESTAMP}/g" \
	  ${FILESDIR}/packager-packager.properties.in > ${WRKSRC}/packager/packager.properties
	@${REINPLACE_CMD} -E \
	  -e "/buildId/ s/(.*)/\1-${PORTREVISION}/" \
	  -e "/buildLabel/ s/(.*)/\1-${PORTREVISION}/" \
	  ${WRKSRC}/label.properties
	@${SED} \
	  -e "s/%%ECLIPSE_ARCH%%/${ECLIPSE_ARCH}/g" \
	  -e "s+%%WRKSRC%%+${WRKSRC}+g" \
	  ${FILESDIR}/packager-packaging.map.in > ${WRKSRC}/packager/packaging.map
	@${SED} \
	  -e "s/%%ECLIPSE_VERSION%%/${ECLIPSE_VERSION}/g" \
	  ${FILESDIR}/packager-sdk.product.in > ${WRKSRC}/packager/sdk.product
	@${CP} ${FILESDIR}/packager-packaging.properties ${WRKSRC}/packager/packaging.properties
	@${RM} ${WRKSRC}/plugins/org.eclipse.platform/launchersrc.zip
	@(cd ${WRKSRC}/features/org.eclipse.equinox.executable; ${LOCALBASE}/bin/zip -q -9 -r ${WRKSRC}/plugins/org.eclipse.platform/launchersrc.zip library)
#	@${REINPLACE_CMD} -e "s/win32\.win32\.x86/${ECLIPSE_WS}.${ECLIPSE_OS}.${ECLIPSE_ARCH}/" ${WRKSRC}/plugins/org.eclipse.jdt.doc.isv/jdtOptions.txt
#	@${REINPLACE_CMD} -e "s/win32\.win32\.x86/${ECLIPSE_WS}.${ECLIPSE_OS}.${ECLIPSE_ARCH}/" ${WRKSRC}/plugins/org.eclipse.pde.doc.user/pdeOptions.txt
#	@${REINPLACE_CMD} \
#	  -e "/[. ]ole/I n" \
#	  -e "s/win32/${ECLIPSE_WS}/" \
#	  ${WRKSRC}/plugins/org.eclipse.platform.doc.isv/platformOptions.txt
	@${FIND} ${WRKSRC} -type f -name \*.xml -exec ${REINPLACE_CMD} -E "s/output=\".*(txt|log).*\"//g" "{}" \;
	@${FIND} ${WRKSRC} -name \*.so -delete
	@${FIND} ${WRKSRC}/features/org.eclipse.equinox.executable -type f -name eclipse -delete
	@(cd ${WRKSRC}/features; \
	  for f in */build.xml; do \
	    for platform in win32 macosx carbon cocoa hpux solaris aix qnx motif linux; do \
	      ${REINPLACE_CMD} -E \
	        -e "/<ant antfile=\"build\.xml\" dir=.*$${platform}.*target=\"/,/<\/ant>/ d" \
	        -e "/idReplacer/ s/org.eclipse\.([a-z0-9A-Z_]+\.)+$${platform}(\.[a-z0-9A-Z_]+)*:0\.0\.0,([0-9]+\.?){3}[a-z0-9A-Z_-]*,//g" \
	        $${f}; \
	    done; \
	    for arch in `echo ${ECLIPSE_ARCH_ALL} | ${SED} -e "s/${ECLIPSE_ARCH}//"`; do \
	      ${REINPLACE_CMD} -E \
	        -e "/<ant antfile=\"build\.xml\" dir=.*$${arch}\" target=\"/,/<\/ant>/ d" \
	        -e "/idReplacer/ s/org.eclipse\.([a-z0-9A-Z_]+\.)+$${arch}:0\.0\.0,([0-9]+\.?){3}[a-z0-9A-Z_-]*,//g" \
	        $${f}; \
	    done; \
	  done; \
	  for f in *.source/feature.xml; do \
	    for platform in win32 macosx carbon cocoa hpux solaris aix qnx motif linux; do \
	      ${REINPLACE_CMD} -E -e "/<plugin id=\"org\.eclipse\..*$${platform}.*\/>/ d" $${f}; \
	    done; \
	  done; \
	)
	@(cd ${WRKSRC}/plugins; \
	  for f in */build.xml; do \
	    ${REINPLACE_CMD} -E \
	      -e "/<pathelement.*\/>/ s/org\.eclipse\.core\.filesystem\.linux\.${ECLIPSE_ARCH}/org.eclipse.core.filesystem.${ECLIPSE_OS}.${ECLIPSE_ARCH}/" \
	      -e "/<pathelement.*\/>/ s/org\.eclipse\.core\.net\.linux\.x86/org.eclipse.core.net.${ECLIPSE_OS}.${ECLIPSE_ARCH}/" \
	      -e "/<pathelement.*\/>/ s/org\.eclipse\.equinox\.launcher\.${ECLIPSE_WS}\.linux\.${ECLIPSE_ARCH}/org.eclipse.equinox.launcher.${ECLIPSE_WS}.${ECLIPSE_OS}.${ECLIPSE_ARCH}/" \
	      -e "/<pathelement.*\/>/ s/org\.eclipse\.swt\.${ECLIPSE_WS}\.linux\.${ECLIPSE_ARCH}/org.eclipse.swt.${ECLIPSE_WS}.${ECLIPSE_OS}.${ECLIPSE_ARCH}/" \
	      -e "/<pathelement.*\/>/ s/org\.eclipse\.update\.core\.linux/org.eclipse.update.core.${ECLIPSE_OS}/" \
	      $${f}; \
	    for platform in win32 macosx carbon cocoa hpux solaris aix qnx motif linux; do \
	      ${REINPLACE_CMD} -E -e "/<pathelement.*$${platform}.*\/>/ d" $${f}; \
	    done; \
	  done; \
	)
	@${RM} \
	  ${WRKSRC}/plugins/org.eclipse.swt/extra_jars/exceptions.jar \
	  ${WRKSRC}/plugins/org.eclipse.osgi/osgi/osgi.cmpn.jar \
	  ${WRKSRC}/plugins/org.eclipse.osgi/osgi/osgi.core.jar \
	  ${WRKSRC}/plugins/org.eclipse.osgi/supplement/osgi/osgi.jar
	@${FIND} ${WRKSRC} -name "*.bak" -delete

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} \
	./build -os ${ECLIPSE_OS} -ws ${ECLIPSE_WS} -arch ${ECLIPSE_ARCH} -compilelibs)
	@${JAVA} \
	  -jar ${ECLIPSE_LAUNCHER} \
	  -data ${WRKSRC}/workspace \
	  -application org.eclipse.ant.core.antRunner \
	  -consoleLog \
	  -nosplash \
	  -buildfile ${ECLIPSE_PDE_BUILD}/scripts/package.xml \
	  -DpackagingInfo=${WRKSRC}/packager \
	  -quiet

do-install:
	@${RM} -rf ${PORTDESTDIR}/configuration
	@${MKDIR} ${PORTDESTDIR}
	@${RM} -rf ${WRKSRC}/eclipse/configuration/.settings
	@${JAVA} \
	  -Declipse.p2.data.area=file:${PORTDESTDIR}/p2 \
	  -jar ${ECLIPSE_LAUNCHER} \
	  -data ${WRKSRC}/workspace \
	  -application org.eclipse.equinox.p2.director.app.application \
	  -consoleLog \
	  -nosplash \
	  -flavor tooling \
	  -metadataRepository file:${WRKSRC}/packager/repo \
	  -artifactRepository file:${WRKSRC}/packager/repo \
	  -installIU org.eclipse.sdk.ide \
	  -version ${ECLIPSE_VERSION} \
	  -p2.os ${ECLIPSE_OS} \
	  -p2.ws ${ECLIPSE_WS} \
	  -p2.arch ${ECLIPSE_ARCH} \
	  -profile SDKProfile \
	  -profileProperties org.eclipse.update.install.features=true \
	  -destination "${PORTDESTDIR}" \
	  -bundlepool "${PORTDESTDIR}" \
	  -roaming
	@${RM} -rf ${PORTDESTDIR}/p2/org.eclipse.equinox.p2.core/cache
	@${RM} -f ${PORTDESTDIR}/p2/org.eclipse.equinox.p2.director/rollback/content.xml
	@${SED} \
	  -e "s+%%ECLIPSE_HOME%%+${PORTDESTDIR}+g" \
	  -e "s+%%PREFIX%%+${PREFIX}+g" \
	  -e "s+%%LOCALBASE%%+${LOCALBASE}+g" \
	  -e "s+%%LOCALBASE%%+${LOCALBASE}+g" \
	  -e "s+%%BROWSER%%+${BROWSER}+g" \
	  -e "s,%%JAVA_VERSION%%,${JAVA_VERSION},g" \
	  -e "s+%%JAVA_OS%%+${JAVA_OS}+g" \
	  ${FILESDIR}/eclipse.in > ${WRKSRC}/eclipse.tmp
.if defined(JAVA_VENDOR)
	@${REINPLACE_CMD} \
	  -e "s+%%JAVA_VENDOR_SPECIFICATION%%+JAVA_VENDOR=\"${JAVA_VENDOR}\"+g" \
	  ${WRKSRC}/eclipse.tmp
.else
	@${REINPLACE_CMD} \
	  -e "s+%%JAVA_VENDOR_SPECIFICATION%%++g" \
	  ${WRKSRC}/eclipse.tmp
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/eclipse.tmp ${PREFIX}/bin/${PORTNAME}
	@${PREFIX}/bin/${PORTNAME} -initialize -consoleLog
	@${SED} \
	  -e "s+%%ECLIPSE_HOME%%+${PORTDESTDIR}+g" \
	  -e "s+%%ECLIPSE%%+${PORTNAME}+g" \
	  -e "s+%%PREFIX%%+${PREFIX}+g" \
	  ${FILESDIR}/eclipse.desktop > ${WRKSRC}/eclipse.desktop.tmp
	@${MKDIR} ${PREFIX}/share/applications/ || ${TRUE}
	@${INSTALL_DATA} ${WRKSRC}/eclipse.desktop.tmp ${PREFIX}/share/applications/${PORTNAME}.desktop
	@-update-desktop-database
	@(cd ${PREFIX}; ${FIND} -s ${PORTNAME} -not -type d) >> ${TMPPLIST}
	@echo '@exec ${PREFIX}/bin/update-desktop-database > /dev/null || /usr/bin/true' >> ${TMPPLIST}
	@(cd ${PREFIX}; ${FIND} -s -d ${PORTNAME} -type d) | ${SED} -ne 's,^,@dirrm ,p' >> ${TMPPLIST}
	@echo '@unexec ${PREFIX}/bin/update-desktop-database > /dev/null || /usr/bin/true' >> ${TMPPLIST}

setup-user:
	@echo 'Preparing Eclipse configuration for user ${USER}'
	@${FIND} ${HOME}/.eclipse -exec ${TOUCH} {} \;

.include <bsd.port.post.mk>
