# New ports collection makefile for:	eclipse-devel
# Date created:				April 9, 2005
# Whom:					various members of freebsd-java
#
# $FreeBSD$
#

PORTNAME=	eclipse
PORTVERSION=	3.3
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE}/R-${PORTVERSION}-200706251500/:0 \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|glewis/eclipse|}:1
DISTFILES=	${PORTNAME}-sourceBuild-srcIncluded-${PORTVERSION}${EXTRACT_SUFX}:0 \
		launchersrc${EXTRACT_SUFX}:1
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	An open extensible IDE for anything and nothing in particular

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS+=	${EXTRACT_DEPENDS}

ECLIPSE_SUFX=	-devel
ECLIPSE=	${PORTNAME}${ECLIPSE_SUFX}

ONLY_FOR_ARCHS=	i386
USE_GMAKE=	yes
USE_ZIP=	yes
USE_GCC=	3.4+
USE_GL=		yes

.if !defined(WITHOUT_MOZILLA)
USE_GECKO=	xulrunner firefox mozilla seamonkey
.endif

USE_JAVA=	yes
JAVA_VERSION=	1.6+
JAVA_OS=	native

NO_WRKSUBDIR=	yes

PORTDESTDIR=	${PREFIX}/${ECLIPSE}

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
LIB_DEPENDS+=	cairo.2:${PORTSDIR}/graphics/cairo
MAKE_CAIRO=	make_cairo
.endif

.include <bsd.port.pre.mk>

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

SWTCAIRO=${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT PI/cairo/library
SWTGTK=${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT PI
SWTMOZ=${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT Mozilla

post-patch:
	@${PATCH} ${PATCH_DIST_ARGS} "${WRKSRC}/plugins/org.eclipse.core.filesystem/natives/unix/freebsd/Makefile" ${FILESDIR}/post-patch-plugins-org.eclipse.core.filesystem-natives-unix-freebsd-Makefile
	@${PATCH} ${PATCH_DIST_ARGS} "${WRKSRC}/plugins/org.eclipse.update.core.freebsd/src/update.c" ${FILESDIR}/post-patch-plugins-org.eclipse.update.core.freebsd-src-update.c
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTGTK}/gtk/library/build.sh" ${FILESDIR}/post-patch-plugins-swt-gtk-build.sh
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTGTK}/gtk/library/build.xml" ${FILESDIR}/post-patch-plugins-swt-PI-gtk-library-build.xml
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTGTK}/gtk/library/make_freebsd.mak" ${FILESDIR}/post-patch-plugins-swt-gtk-make_freebsd.mak
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTMOZ}/gtk/org/eclipse/swt/browser/MozillaDelegate.java" ${FILESDIR}/post-patch-plugins-swt-mozilla-gtk-swt-browser-MozillaDelegate.java
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTGTK}/gtk/org/eclipse/swt/internal/gtk/OS.java" ${FILESDIR}/post-patch-plugins-swt-gtk-swt-internal-gtk-OS.java
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTGTK}/gtk/library/os.c" ${FILESDIR}/post-patch-plugins-swt-gtk-library-os.c

	@${REINPLACE_CMD} -e 's|%%GECKO%%|${GECKO}|g' \
		"${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/build.sh" \
		"${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library/make_freebsd.mak"
	@${RM} ${WRKSRC}/plugins/org.eclipse.platform/launchersrc${EXTRACT_SUFX}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/launchersrc${EXTRACT_SUFX} ${WRKSRC}/plugins/org.eclipse.platform/
	@${RM} ${WRKSRC}/features/org.eclipse.platform/build.xml
	@${CP} ${FILESDIR}/org.eclipse.platform-build.xml ${WRKSRC}/features/org.eclipse.platform/build.xml
	@${RM} ${WRKSRC}/features/org.eclipse.rcp/build.xml
	@${CP} ${FILESDIR}/org.eclipse.rcp-build.xml ${WRKSRC}/features/org.eclipse.rcp/build.xml

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} \
	./build -os ${ECLIPSE_OS} -ws ${ECLIPSE_WS} -arch ${ECLIPSE_ARCH}  -compilelibs)
	@${CP} ${WRKSRC}/launchertmp/library/${ECLIPSE_WS}/eclipse_1017a.so \
	  ${WRKSRC}/eclipse/plugins/org.eclipse.equinox.launcher.${ECLIPSE_WS}.${ECLIPSE_OS}.${ECLIPSE_ARCH}_1.0.0.v20070606

do-install:
	@${MKDIR} ${PORTDESTDIR}
	@${CP} -R ${WRKSRC}/eclipse/ ${PORTDESTDIR}
	@${SED} \
	  -e "s+%%ECLIPSE_HOME%%+${PORTDESTDIR}+g" \
	  -e "s+%%PREFIX%%+${PREFIX}+g" \
	  -e "s+%%X11BASE%%+${X11BASE}+g" \
	  -e "s+%%LOCALBASE%%+${LOCALBASE}+g" \
	  -e "s+%%BROWSER%%+${BROWSER}+g" \
	  -e "s,%%JAVA_VERSION%%,${JAVA_VERSION},g" \
	  -e "s+%%JAVA_OS%%+${JAVA_OS}+g" \
	${FILESDIR}/eclipse.in > ${WRKSRC}/eclipse.tmp
	${INSTALL_SCRIPT} ${WRKSRC}/eclipse.tmp ${PREFIX}/bin/${ECLIPSE}
	@${SED} \
	  -e "s+%%ECLIPSE_HOME%%+${PORTDESTDIR}+g" \
	  -e "s+%%PREFIX%%+${PREFIX}+g" \
	  -e "s+/bin/eclipse+/bin/eclipse-europa+g" \
	${FILESDIR}/eclipse.desktop > ${WRKSRC}/eclipse.desktop.tmp
	${MKDIR} ${PREFIX}/share/applications/ || ${TRUE}
	${INSTALL_DATA} ${WRKSRC}/eclipse.desktop.tmp ${PREFIX}/share/applications/${ECLIPSE}.desktop
	${INSTALL_PROGRAM} ${WRKSRC}/launchertmp/eclipse ${PORTDESTDIR}/eclipse
	@-update-desktop-database
	@(cd ${WRKSRC}; ${FIND} -s eclipse -not -type d) \
	  | ${SED} -e "s+^eclipse+${ECLIPSE}+g" >> ${TMPPLIST}
	@echo '@exec ${PREFIX}/bin/update-desktop-database > /dev/null || /usr/bin/true' >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} -s -d eclipse -type d) \
	  | ${SED} -e "s+^eclipse+${ECLIPSE}+g" \
	    -ne 's,^,@dirrm ,p' >> ${TMPPLIST}
	@echo '@unexec ${PREFIX}/bin/update-desktop-database > /dev/null || /usr/bin/true' >> ${TMPPLIST}

.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
