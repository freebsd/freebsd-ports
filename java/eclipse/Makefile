# New ports collection makefile for:	eclipse
# Date created:				March 7, 2003
# Whom:					various members of freebsd-java
#
# $FreeBSD$
#

PORTNAME=	eclipse
PORTVERSION=	3.2.2
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=	R-${PORTVERSION}-200702121330
DISTNAME=	${PORTNAME}-sourceBuild-srcIncluded-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@freebsd.org
COMMENT=	An open extensible IDE for anything and nothing in particular

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		zip:${PORTSDIR}/archivers/zip

BUILD_DEPENDS+=	${EXTRACT_DEPENDS}

ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
USE_ZIP=	yes
USE_GL=		yes

.if !defined(WITHOUT_MOZILLA)
USE_GECKO=	xulrunner firefox mozilla seamonkey
.endif

USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native

NO_WRKSUBDIR=	yes

PORTDESTDIR=	${PREFIX}/eclipse

ECLIPSE_OS=	freebsd

ECLIPSE_WS=	gtk

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
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo
MAKE_CAIRO=	make_cairo
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
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

PLIST_FILES=	bin/eclipse share/applications/eclipse.desktop

SWTCAIRO=${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT PI/cairo/library
SWTGTK=${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library
SWTMOZ=${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT Mozilla

# Manually patch some files with spaces in the path
post-patch:
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTGTK}/build.sh" ${FILESDIR}/post-patch-plugins-swt-gtk-build.sh
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTGTK}/make_freebsd.mak" ${FILESDIR}/post-patch-plugins-swt-gtk-make_freebsd.mak
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTMOZ}/gtk/org/eclipse/swt/browser/Browser.java" ${FILESDIR}/post-patch-plugins-swt-mozilla-Browser.java
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTMOZ}/common/org/eclipse/swt/internal/mozilla/XPCOM.java" ${FILESDIR}/post-patch-plugins-swt-mozilla-XPCOM.java
	@${PATCH} ${PATCH_DIST_ARGS} "${WRKSRC}/plugins/org.eclipse.swt.tools/JNI Generation/org/eclipse/swt/tools/internal/org.eclipse.swt.internal.mozilla.XPCOM.properties" ${FILESDIR}/post-patch-plugins-swt-mozilla-XPCOM.properties
	@${PATCH} ${PATCH_DIST_ARGS} "${WRKSRC}/plugins/org.eclipse.swt.tools/JNI Generation/org/eclipse/swt/tools/internal/org.eclipse.swt.internal.mozilla.XPCOM_PROFILE.properties" ${FILESDIR}/post-patch-plugins-swt-mozilla-XPCOM_PROFILE.properties
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTMOZ}/common/library/xpcom.cpp" ${FILESDIR}/post-patch-plugins-swt-mozilla-xpcom.cpp
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTMOZ}/common/library/xpcom.h" ${FILESDIR}/post-patch-plugins-swt-mozilla-xpcom.h
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTMOZ}/common/library/xpcom_profile.h" ${FILESDIR}/post-patch-plugins-swt-mozilla-xpcom_profile.h
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTMOZ}/common/library/xpcom_stats.cpp" ${FILESDIR}/post-patch-plugins-swt-mozilla-xpcom_stats.cpp
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTMOZ}/common/library/xpcom_stats.h" ${FILESDIR}/post-patch-plugins-swt-mozilla-xpcom_stats.h
	@${REINPLACE_CMD} -e 's|%%GECKO%%|${GECKO}|g' \
		"${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/build.sh" \
		"${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/make_freebsd.mak"

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} \
	  ./build -os ${ECLIPSE_OS} -ws ${ECLIPSE_WS} -arch ${ECLIPSE_ARCH} -java5home ${JAVA_HOME} -compilelibs)

do-install:
	@${MKDIR} ${PORTDESTDIR}
	@${CP} -R ${WRKSRC}/eclipse ${PREFIX}
	@${SED} \
	  -e "s+%%ECLIPSE_HOME%%+${PORTDESTDIR}+g" \
	  -e "s+%%PREFIX%%+${PREFIX}+g" \
	  -e "s+%%LOCALBASE%%+${LOCALBASE}+g" \
	  -e "s+%%BROWSER%%+${BROWSER}+g" \
	  -e "s,%%JAVA_VERSION%%,${JAVA_VERSION},g" \
	  -e "s+%%JAVA_OS%%+${JAVA_OS}+g" \
	${FILESDIR}/eclipse.in > ${WRKSRC}/eclipse.tmp
.if defined(JAVA_VENDOR)
	${REINPLACE_CMD} \
	  -e "s+%%JAVA_VENDOR_SPECIFICATION%%+JAVA_VENDOR=\"${JAVA_VENDOR}\"+g" \
	  ${WRKSRC}/eclipse.tmp
.else
	${REINPLACE_CMD} \
	  -e "s+%%JAVA_VENDOR_SPECIFICATION%%++g" \
	  ${WRKSRC}/eclipse.tmp
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/eclipse.tmp ${PREFIX}/bin/eclipse
	@${SED} \
	  -e "s+%%ECLIPSE_HOME%%+${PORTDESTDIR}+g" \
	  -e "s+%%PREFIX%%+${PREFIX}+g" \
	${FILESDIR}/eclipse.desktop > ${WRKSRC}/eclipse.desktop.tmp
	${MKDIR} ${PREFIX}/share/applications/ || ${TRUE}
	${INSTALL_DATA} ${WRKSRC}/eclipse.desktop.tmp ${PREFIX}/share/applications/eclipse.desktop
	${INSTALL_PROGRAM} ${WRKSRC}/launchertmp/eclipse ${PREFIX}/eclipse/eclipse
	@-update-desktop-database
	@(cd ${WRKSRC}; ${FIND} -s eclipse -not -type d) >> ${TMPPLIST}
	@echo '@exec ${PREFIX}/bin/update-desktop-database > /dev/null || /usr/bin/true' >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} -s -d eclipse -type d) \
	  | ${SED} -ne 's,^,@dirrm ,p' >> ${TMPPLIST}
	@echo '@unexec ${PREFIX}/bin/update-desktop-database > /dev/null || /usr/bin/true' >> ${TMPPLIST}

.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
