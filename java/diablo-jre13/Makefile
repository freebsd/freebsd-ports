# New ports collection makefile for:	diablo-jre13
# Date created:		March 12 2003
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jre
PORTVERSION=	${JRE_VERSION}.${RELEASE_VERSION}
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	diablo-
DISTNAME=	${PKGNAMEPREFIX}latte-${JRE_VERSION}-${RELEASE_VERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java Runtime Environment 1.3.1

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${X11BASE}/lib/X11/fonts/URW/fonts.dir:${PORTSDIR}/x11-fonts/urwfonts
.if !defined(WITHOUT_PLUGIN)
FORBIDDEN=	Vulnerabilities in the browser plugin
RUN_DEPENDS+=	${LOCALBASE}/lib/libglib12.so:${PORTSDIR}/devel/glib12 \
		${X11BASE}/lib/libgtk12.so:${PORTSDIR}/x11-toolkits/gtk12 \
		${LOCALBASE}/lib/libnspr4.so:${PORTSDIR}/devel/nspr
.endif
.if defined(WITH_JAPANESE_FONTS)
RUN_DEPENDS+=   ${X11BASE}/lib/X11/fonts/TrueType/fonts.dir.kochi:${PORTSDIR}/japanese/kochi-ttfonts
.endif
.if defined(WITH_RUSSIAN_FONTS)
RUN_DEPENDS+=   ${X11BASE}/lib/X11/fonts/webfonts/fonts.dir:${PORTSDIR}/x11-fonts/webfonts
.endif
.if defined(WITH_CHINESE_FONTS)
RUN_DEPENDS+=   ${LOCALBASE}/share/fonts/TrueType/arphic:${PORTSDIR}/chinese/arphicttf
.endif

RESTRICTED=	"License doesn't allow distribution with fee"

USE_BZIP2=	yes
USE_XLIB=	yes
ONLY_FOR_ARCHS=	i386
JRE_VERSION=	1.3.1
RELEASE_VERSION=0
PLIST_SUB+=	JRE_VERSION=${JRE_VERSION}
DOWNLOAD_URL=	http://www.FreeBSDFoundation.org/cgi-bin/download.cgi?package=${DISTNAME}${EXTRACT_SUFX}
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}13

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}jre${JRE_VERSION}
NO_BUILD=	yes

INSTALL_DIR=	${PREFIX}/${PKGNAMEPREFIX}jre${JRE_VERSION}

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

.if defined(WITHOUT_PLUGIN)
PLIST_SUB+=	PLUGIN:="@comment "
PKGNAMESUFFIX=	-noplugin
PKG_IGNORE_DEPENDS=	'^[^X|^j]'
.else
PLIST_SUB+=	PLUGIN:=""
PKG_IGNORE_DEPENDS=	'^[^X|^l|^g|^j]|glib|gtk'
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE= :\n\
Because of licensing restrictions, you must fetch the distribution\n\
manually.  Please access\n\
\n\
  ${DOWNLOAD_URL}\n\
\n\
with a web browser and \"Accept\" the End User License Agreement for\n\
\"Latte Diablo ${JRE_VERSION}\".  Please place the downloaded\n\
${DISTNAME}${EXTRACT_SUFX} in ${DISTDIR}.\n
.endif

.if ${OSVERSION} >= 502112
ECHO_MSG=	${ECHO_CMD}
IGNORE=		does not run on FreeBSD >= 5.x
.endif


do-install:
	${MKDIR} ${INSTALL_DIR}
	cd ${WRKSRC} && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${INSTALL_DIR}
	${MKDIR} ${PREFIX}/diablo-jre${JRE_VERSION}/lib/ext
	${MKDIR} ${PREFIX}/share/doc/java
.if defined(WITHOUT_PLUGIN)
	${RM} -rf `${FIND} ${PREFIX}/diablo-jre${JRE_VERSION} \
		\( -name '*plugin*' -o -name '*locale*' -o \
		   -name 'java_vm' -o -name 'ControlPanel*' \) -print | \
		${SORT} -r`
.endif

post-install:
	# Register the VM
	${LOCALBASE}/bin/registervm \
	  "${INSTALL_DIR}/bin/java # DiabloLatte${JRE_VERSION}"
.if !defined(WITHOUT_PLUGIN)
	# Create pkg-(de)install
	${SED} -e "s:%%X11BASE%%:${X11BASE}:g" < ${FILESDIR}/pkg-install.in \
	  > ${PKGINSTALL}
	${SED} -e "s:%%X11BASE%%:${X11BASE}:g" < ${FILESDIR}/pkg-deinstall.in \
	  > ${PKGDEINSTALL}
	# Install the plugin
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
