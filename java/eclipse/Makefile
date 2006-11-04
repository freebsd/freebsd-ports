# New ports collection makefile for:	eclipse
# Date created:				March 7, 2003
# Whom:					various members of freebsd-java
#
# $FreeBSD$
#

PORTNAME=	eclipse
PORTVERSION=	3.2.1
#PORTREVISION=	0
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=	R-${PORTVERSION}-200609210945
DISTNAME=	${PORTNAME}-sourceBuild-srcIncluded-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	dsledge@appriss.com
COMMENT=	An open extensible IDE for anything and nothing in particular

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		zip:${PORTSDIR}/archivers/zip

BUILD_DEPENDS+=	${EXTRACT_DEPENDS}

ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
USE_ZIP=	yes
USE_GCC=	3.4+

USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native

NO_WRKSUBDIR=	yes

PORTDESTDIR=	${PREFIX}/eclipse

ECLIPSE_OS=	freebsd

ECLIPSE_WS=	gtk

.if !defined(WITHOUT_MOZILLA)
MAKE_MOZILLA=	make_mozilla
.if defined(WITH_MOZILLA) && ${WITH_MOZILLA} != "mozilla"
BROWSER=	${WITH_MOZILLA}
BUILD_DEPENDS+=	${BROWSER}:${PORTSDIR}/www/${BROWSER}
.else
BUILD_DEPENDS+=	mozilla:${PORTSDIR}/www/mozilla
BROWSER=	mozilla
.endif
.else
BROWSER=
MAKE_MOZILLA=
.endif
.if defined(WITHOUT_CAIRO)
MAKE_CAIRO=
.else
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo
MAKE_CAIRO=	make_cairo
.endif

.if defined(WITHOUT_GNOMEVFS)
MAKE_GNOME=
USE_GNOME=	gtk20 pkgconfig desktopfileutils
.else
MAKE_GNOME=	make_gnome
USE_GNOME=	gtk20 gnomevfs2 libgnome libgnomeui pkgconfig desktopfileutils
.endif

.include <bsd.port.pre.mk>

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

# Manually patch some files with spaces in the path
post-patch:
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTGTK}/build.sh" ${FILESDIR}/post-patch-plugins-swt-gtk-build.sh
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTGTK}/make_freebsd.mak" ${FILESDIR}/post-patch-plugins-swt-gtk-make_freebsd.mak
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTGTK}/os_custom.h" ${FILESDIR}/post-patch-plugins-swt-gtk-os_custom.h

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} \
	  ./build -os ${ECLIPSE_OS} -ws ${ECLIPSE_WS} -arch ${ECLIPSE_ARCH} -java5home ${JAVA_HOME} -compilelibs)

do-install:
	@${MKDIR} ${PORTDESTDIR}
	@${CP} -R ${WRKSRC}/eclipse ${PREFIX}
	@${SED} \
	  -e "s+%%ECLIPSE_HOME%%+${PORTDESTDIR}+g" \
	  -e "s+%%PREFIX%%+${PREFIX}+g" \
	  -e "s+%%X11BASE%%+${X11BASE}+g" \
	  -e "s+%%BROWSER%%+${BROWSER}+g" \
	  -e "s,%%JAVA_VERSION%%,${JAVA_VERSION},g" \
	  -e "s+%%JAVA_OS%%+${JAVA_OS}+g" \
	${FILESDIR}/eclipse.in > ${WRKSRC}/eclipse.tmp
	${INSTALL_SCRIPT} ${WRKSRC}/eclipse.tmp ${PREFIX}/bin/eclipse
	@${SED} \
	  -e "s+%%ECLIPSE_HOME%%+${PORTDESTDIR}+g" \
	  -e "s+%%PREFIX%%+${PREFIX}+g" \
	${FILESDIR}/eclipse.desktop > ${WRKSRC}/eclipse.desktop.tmp
	${INSTALL_DATA} ${WRKSRC}/eclipse.desktop.tmp ${PREFIX}/share/applications/eclipse.desktop
	${INSTALL_PROGRAM} ${WRKSRC}/launchertmp/eclipse ${PREFIX}/eclipse/eclipse
	@-update-desktop-database
	@(cd ${WRKSRC}; ${FIND} -s eclipse -not -type d) >> ${TMPPLIST}
	@echo '@exec ${PREFIX}/bin/update-desktop-database > /dev/null || /usr/bin/true' >> ${TMPPLIST}
	@(cd ${WRKSRC}; ${FIND} -s -d eclipse -type d) \
	  | ${SED} -ne 's,^,@dirrm ,p' >> ${TMPPLIST}
	@echo '@unexec ${PREFIX}/bin/update-desktop-database > /dev/null || /usr/bin/true' >> ${TMPPLIST}

.include <bsd.port.post.mk>
