# New ports collection makefile for:	eclipse-devel
# Date created:				April 9, 2005
# Whom:					various members of freebsd-java
#
# $FreeBSD$
#

PORTNAME=	eclipse-devel
PORTVERSION=	3.4.1
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=	R-${PORTVERSION}-200809111700
DISTNAME=	eclipse-sourceBuild-srcIncluded-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	An open extensible IDE for anything and nothing in particular

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip
PATCH_DEPENDS+=	gpatch:${PORTSDIR}/devel/patch

ECLIPSE=	${PORTNAME}

ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
USE_ZIP=	yes
USE_GL=		glu

PATCH=		${LOCALBASE}/bin/gpatch

.if !defined(WITHOUT_MOZILLA)
USE_GECKO=	firefox xulrunner seamonkey
.endif

USE_JAVA=	yes
JAVA_VERSION=	1.6
JAVA_OS=	native

NO_WRKSUBDIR=	yes

PORTDESTDIR=	${PREFIX}/${ECLIPSE}

ECLIPSE_OS=	freebsd

ECLIPSE_WS=	gtk

IGNORE=		eclipse 3.4.x is now in java/eclipse, please use that instead

.if defined(WITHOUT_GNOMEVFS)
MAKE_GNOME=
USE_GNOME=	gtk20 pkgconfig desktopfileutils
.else
MAKE_GNOME=	make_gnome
USE_GNOME=	gtk20 gnomevfs2 libgnome libgnomeui pkgconfig desktopfileutils
.endif

.if defined(WITHOUT_CAIRO)
MAKE_CAIRO=
.else
LIB_DEPENDS+=	cairo.2:${PORTSDIR}/graphics/cairo
MAKE_CAIRO=	make_cairo
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
JAVA_VENDOR=	bsdjava
.endif

.if !defined(WITHOUT_MOZILLA)
MAKE_MOZILLA=	make_mozilla
BROWSER=	${GECKO}
.else
BROWSER=
MAKE_MOZILLA=
.endif

.if (${ARCH} == "amd64")
ECLIPSE_ARCH=	amd64
ECLIPSE_SWT=	gtk64
.else
ECLIPSE_ARCH=	x86
ECLIPSE_SWT=	gtk
.endif

MAKE_ENV+=	BROWSER=${BROWSER} \
		ECLIPSE_ARCH=${ECLIPSE_ARCH} \
		ECLIPSE_OS=${ECLIPSE_OS} \
		ECLIPSE_WS=${ECLIPSE_WS} \
		JAVA_HOME=${JAVA_HOME} \
		MAKE_GNOME=${MAKE_GNOME} \
		MAKE_MOZILLA=${MAKE_MOZILLA} \
		MAKE_CAIRO=${MAKE_CAIRO} \
		MACHINE_ARCH=${MACHINE_ARCH}

PLIST_FILES=	bin/${ECLIPSE} share/applications/${ECLIPSE}.desktop

SWTBASE=${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT
SWTGTK=${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT PI
SWTMOZ=${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT Mozilla

ECLIPSE_IU=FreeBSD Eclipse SDK
ECLIPSE_IU_VERSION=${PORTVERSION}.${PORTREVISION}

post-patch:
	@${PATCH} ${PATCH_DIST_ARGS} -d "${SWTBASE}" -i ${FILESDIR}/post-patch-plugins-org.eclipse.swt-Eclipse_SWT-gtk-org-eclipse-swt-widgets-FileDialog.java
	@${PATCH} ${PATCH_DIST_ARGS} -d "${SWTBASE}" -i ${FILESDIR}/post-patch-plugins-org.eclipse.swt-Eclipse_SWT-gtk-org-eclipse-swt-widgets-DirectoryDialog.java
	@${PATCH} ${PATCH_DIST_ARGS} -d "${SWTGTK}" -i ${FILESDIR}/post-patch-plugins-org.eclipse.swt-Eclipse_SWT_PI-gtk-library-build.sh
	@${PATCH} ${PATCH_DIST_ARGS} -d "${SWTGTK}" -i ${FILESDIR}/post-patch-plugins-org.eclipse.swt-Eclipse_SWT_PI-gtk-library-build.xml
	@${PATCH} ${PATCH_DIST_ARGS} -d "${SWTGTK}" -i ${FILESDIR}/post-patch-plugins-org.eclipse.swt-Eclipse_SWT_PI-gtk-library-make_freebsd.mak
	@${PATCH} ${PATCH_DIST_ARGS} -d "${SWTGTK}" -i ${FILESDIR}/post-patch-plugins-org.eclipse.swt-Eclipse_SWT_PI-gtk-org-eclipse-swt-internal-gtk-OS.java
	@${PATCH} ${PATCH_DIST_ARGS} -d "${SWTMOZ}" -i ${FILESDIR}/post-patch-plugins-org.eclipse.swt-Eclipse_SWT_Mozilla-gtk-org-eclipse-swt-browser-MozillaDelegate.java

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} \
	./build -os ${ECLIPSE_OS} -ws ${ECLIPSE_WS} -arch ${ECLIPSE_ARCH} -compilelibs)
	@${JAVA} \
	  -jar ${WRKSRC}/eclipse/plugins/org.eclipse.equinox.launcher_1.0.101.R34x_v20080819.jar \
	  -data ${WRKSRC}/workspace \
	  -application org.eclipse.equinox.p2.metadata.generator.EclipseGenerator \
	  -flavor tooling \
	  -metadataRepositoryName "FreeBSD Eclipse" \
	  -artifactRepositoryName "FreeBSD Eclipse" \
	  -metadataRepository "file:${WRKSRC}/eclipse/metadata" \
	  -artifactRepository "file:${WRKSRC}/eclipse/metadata" \
	  -root "${ECLIPSE_IU}" \
	  -rootVersion "${ECLIPSE_IU_VERSION}" \
	  -source ${WRKSRC}/eclipse \
	  -append \
	  -publishArtifacts

do-install:
	@${MKDIR} ${PORTDESTDIR}
	@${JAVA} \
	  -Declipse.p2.data.area="file:${PORTDESTDIR}/p2" \
	  -jar ${WRKSRC}/eclipse/plugins/org.eclipse.equinox.launcher_1.0.101.R34x_v20080819.jar \
	  -data ${WRKSRC}/workspace \
	  -application org.eclipse.equinox.p2.director.app.application \
	  -flavor tooling \
	  -metadataRepository "file:${WRKSRC}/eclipse/metadata" \
	  -artifactRepository "file:${WRKSRC}/eclipse/metadata" \
	  -installIU "${ECLIPSE_IU}" \
	  -version "${ECLIPSE_IU_VERSION}" \
	  -p2.os ${ECLIPSE_OS} \
	  -p2.ws ${ECLIPSE_WS} \
	  -p2.arch ${ECLIPSE_ARCH} \
	  -profile SDKProfile \
	  -profileProperties org.eclipse.update.install.features=true \
	  -destination "${PORTDESTDIR}" \
	  -bundlepool "${PORTDESTDIR}" \
	  -roaming
	(cd ${WRKSRC}/eclipse; \
	  ${CP} -R about.html epl-v10.html icon.xpm notice.html readme ${PORTDESTDIR})
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
	@${INSTALL_SCRIPT} ${WRKSRC}/eclipse.tmp ${PREFIX}/bin/${ECLIPSE}
	@${SED} \
	  -e "s+%%ECLIPSE_HOME%%+${PORTDESTDIR}+g" \
	  -e "s+%%ECLIPSE%%+${ECLIPSE}+g" \
	  -e "s+%%PREFIX%%+${PREFIX}+g" \
	  ${FILESDIR}/eclipse.desktop > ${WRKSRC}/eclipse.desktop.tmp
	@${MKDIR} ${PREFIX}/share/applications/ || ${TRUE}
	@${INSTALL_DATA} ${WRKSRC}/eclipse.desktop.tmp ${PREFIX}/share/applications/${ECLIPSE}.desktop
	@-update-desktop-database
	@(cd ${PREFIX}; ${FIND} -s ${ECLIPSE} -not -type d) >> ${TMPPLIST}
	@echo '@exec ${PREFIX}/bin/update-desktop-database > /dev/null || /usr/bin/true' >> ${TMPPLIST}
	@(cd ${PREFIX}; ${FIND} -s -d ${ECLIPSE} -type d) | ${SED} -ne 's,^,@dirrm ,p' >> ${TMPPLIST}
	@echo '@unexec ${PREFIX}/bin/update-desktop-database > /dev/null || /usr/bin/true' >> ${TMPPLIST}

setup-user:
	@echo 'Preparing Eclipse configuration for user ${USER}'
	@${PREFIX}/bin/${ECLIPSE} -initialize -clean -consoleLog
	@${FIND} ${HOME}/.eclipse -exec touch {} \;
	
.include <bsd.port.post.mk>
