# New ports collection makefile for:	eclipse-devel
# Date created:				April 9, 2005
# Whom:					various members of freebsd-java
#
# $FreeBSD$
#

PORTNAME=	eclipse
PORTVERSION=	3.1M7
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=	S-${PORTVERSION}-200505131415
DISTNAME=	${PORTNAME}-sourceBuild-srcIncluded-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	An open extensible IDE for anything and nothing in particular

IGNORE=		"Out-of-date, use java/eclipse instead for now"

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS+=	${EXTRACT_DEPENDS}

CONFLICTS=	eclipse-3.1*
LATEST_LINK=	${PORTNAME}-devel

ONLY_FOR_ARCHS=	i386 amd64
USE_GMAKE=	yes
USE_ZIP=	yes
USE_GCC=	3.4

USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native

NO_WRKSUBDIR=	yes

PORTDESTDIR=	${PREFIX}/eclipse

ECLIPSE_OS=	freebsd

.if defined(WITH_MOTIF)
ECLIPSE_WS=	motif
USE_ICONV=	yes
USE_MOTIF=	yes
.else
ECLIPSE_WS=	gtk
.if defined(WITH_MOZILLA)
BROWSER=	${WITH_MOZILLA}
BUILD_DEPENDS+=	${BROWSER}:${PORTSDIR}/www/${BROWSER}
.else
BUILD_DEPENDS+=	mozilla:${PORTSDIR}/www/mozilla
BROWSER=	mozilla
.endif
.endif

.if defined(WITHOUT_GNOMEVFS)
MAKE_GNOME=
USE_GNOME=	gtk20 pkgconfig
.else
MAKE_GNOME=	make_gnome
USE_GNOME=	gtk20 gnomevfs2 libgnome libgnomeui pkgconfig
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_MOTIF)
BROKEN=	No motif support yet
.endif

.if (${ARCH} == "amd64")
ECLIPSE_ARCH=	amd64
ECLIPSE_SWT=	gtk64
.else
ECLIPSE_ARCH=	x86
ECLIPSE_SWT=	gtk
.endif

.if (!defined(WITH_MOTIF) && ${BROWSER} == "firefox")
BROKEN=	Firefox integration doesn\'t work yet
.endif

MAKE_ENV+=	BROWSER=${BROWSER} \
		ECLIPSE_ARCH=${ECLIPSE_ARCH} \
		ECLIPSE_OS=${ECLIPSE_OS} \
		ECLIPSE_WS=${ECLIPSE_WS} \
		JAVA_HOME=${JAVA_HOME} \
		MAKE_GNOME=${MAKE_GNOME} \
		MOTIF_HOME=${X11_HOME} \
		QT_HOME=${X11_HOME}

PLIST_FILES=	bin/eclipse

SWTGTK=${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT PI/gtk/library
SWTMOTIF=${WRKSRC}/plugins/org.eclipse.swt/Eclipse SWT PI/motif/library

# Manually patch some files with spaces in the path
post-patch:
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTMOTIF}/build.sh" \
	  ${FILESDIR}/manualpatch-plugins-swt-motif-build.sh
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTMOTIF}/make_freebsd.mak" \
	  ${FILESDIR}/manualpatch-plugins-swt-motif-make_freebsd.mak
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTGTK}/make_freebsd.mak" \
	  ${FILESDIR}/manualpatch-plugins-swt-gtk-make_freebsd.mak
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTGTK}/build.sh" \
	  ${FILESDIR}/manualpatch-plugins-swt-gtk-build.sh
	@${PATCH} ${PATCH_DIST_ARGS} "${SWTGTK}/os_custom.h" \
	  ${FILESDIR}/manualpatch-plugins-swt-gtk-os_custom.h

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} \
	  ./build -os ${ECLIPSE_OS} -ws ${ECLIPSE_WS} -arch ${ECLIPSE_ARCH} -compilelibs)

do-install:
	@${MKDIR} ${PORTDESTDIR}
	@${TAR} -xvzf ${WRKSRC}/result/*.tar.gz -C ${PREFIX}
	@${SED} \
	  -e "s+%%ECLIPSE_HOME%%+${PORTDESTDIR}+g" \
	  -e "s+%%JAVA_HOME%%+${JAVA_HOME}+g" \
	  -e "s+%%X11BASE%%+${X11BASE}+g" \
	  -e "s+%%BROWSER%%+${BROWSER}+g" \
	${FILESDIR}/eclipse.in > ${WRKSRC}/eclipse.tmp
	${INSTALL_SCRIPT} ${WRKSRC}/eclipse.tmp ${PREFIX}/bin/eclipse
	${INSTALL_PROGRAM} ${WRKSRC}/launchertmp/eclipse ${PREFIX}/eclipse/eclipse
	@(cd ${WRKSRC}/tmp; ${FIND} -s eclipse -not -type d | ${GREP} -v tmp.tar) >> ${TMPPLIST}
	@(cd ${WRKSRC}/tmp; ${FIND} -s -d eclipse -type d) \
	  | ${SED} -ne 's,^,@dirrm ,p' >> ${TMPPLIST}

.include <bsd.port.post.mk>
