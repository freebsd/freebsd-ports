# New ports collection makefile for:	diablo-jdk13
# Date created:		March 10 2003
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}.${RELEASE_VERSION}
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	diablo-
DISTNAME=	${PKGNAMEPREFIX}caffe-${JDK_VERSION}-${RELEASE_VERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java Development Kit 1.3.1

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${X11BASE}/lib/X11/fonts/URW/fonts.dir:${PORTSDIR}/x11-fonts/urwfonts
.if !defined(WITHOUT_PLUGIN)
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
JDK_VERSION=	1.3.1
RELEASE_VERSION=0
PLIST_SUB+=	JDK_VERSION=${JDK_VERSION}
DOWNLOAD_URL=	http://www.FreeBSDFoundation.org/cgi-bin/download.cgi?package=${DISTNAME}${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}jdk${JDK_VERSION}
NO_BUILD=	yes

INSTALL_DIR=	${PREFIX}/${PKGNAMEPREFIX}jdk${JDK_VERSION}

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
\"Caffe Diablo ${JRE_VERSION}\".  Please place the downloaded\n\
${DISTNAME}${EXTRACT_SUFX} in ${DISTDIR}.\n
.endif

do-install:
	${MKDIR} ${INSTALL_DIR}
	cd ${WRKSRC} && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} ${INSTALL_DIR}
	${MKDIR} ${PREFIX}/diablo-jdk${JDK_VERSION}/jre/lib/ext
	${MKDIR} ${PREFIX}/share/doc/java
.if defined(WITHOUT_PLUGIN)
	${RM} -rf `${FIND} ${PREFIX}/diablo-jdk${JDK_VERSION} \
		\( -name '*plugin*' -o -name '*locale*' -o \
		   -name 'java_vm' -o -name 'ControlPanel*' -o \
		   -name 'HtmlConverter' \) -print | \
		${SORT} -r`
.endif

post-install:
	# Register the VM
	${LOCALBASE}/bin/registervm "${INSTALL_DIR}/bin/java # DiabloCaffe${JDK_VERSION}"
.if !defined(WITHOUT_PLUGIN)
	# Install the plugin
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
