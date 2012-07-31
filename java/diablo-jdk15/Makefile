# New ports collection makefile for:	diablo-jdk15
# Date created:		February 26 2006
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}.${RELEASE_VERSION}.${BUILD_VERSION}
PORTREVISION=	29
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	diablo-
DISTNAME=	${PKGNAMEPREFIX}caffe-${JDK_OSREL}-${ARCH}-${JDK_VERSION}_${RELEASE_VERSION}-b${BUILD_VERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java Development Kit ${JDK_VERSION}_${RELEASE_VERSION}.${BUILD_VERSION}

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

RESTRICTED=	License does not allow distribution with fee

USE_BZIP2=	yes
USE_XORG+=	xi xp xt xtst
ONLY_FOR_ARCHS=	amd64 i386
JDK_VERSION=	1.5.0
RELEASE_VERSION=07
BUILD_VERSION=	01
PLIST_SUB+=	JDK_VERSION=${JDK_VERSION}
PLIST_SUB+=	ARCH=${ARCH}
DOWNLOAD_URL=	http://www.FreeBSDFoundation.org/cgi-bin/download?download=${DISTNAME}${EXTRACT_SUFX}
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}15

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}jdk${JDK_VERSION}_${RELEASE_VERSION}
NO_BUILD=	yes

OPTIONS=	TZUPDATE	"Update the time zone data"	on

SUB_FILES+=	pkg-install \
		pkg-deinstall
PKG_IGNORE_DEPENDS=	'^[^xj]'

INSTALL_DIR=	${PREFIX}/${PKGNAMEPREFIX}jdk${JDK_VERSION}

.include <bsd.port.pre.mk>

JDK_OSREL=	freebsd6

.if ${OSVERSION} >= 700000
LIB_DEPENDS=	z.3:${PORTSDIR}/misc/compat6x
.endif

.if !defined(WITHOUT_TZUPDATE)
RUN_DEPENDS+=	${LOCALBASE}/share/java/zi:${PORTSDIR}/java/java-zoneinfo
PLIST_SUB+=	TZORIGINAL="@comment "
PLIST_SUB+=	TZUPDATE=""
.else
PLIST_SUB+=	TZORIGINAL=""
PLIST_SUB+=	TZUPDATE="@comment "
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	WEB=""
PLIST_SUB+=	CLIENTVM=""
.else
PLIST_SUB+=	WEB="@comment "
PLIST_SUB+=	CLIENTVM="@comment "
.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING) && defined(JDK_OSREL)
DISTFILE_INSTRUCTIONS=\n\
Because of licensing restrictions, you must fetch the distribution\n\
manually.\n\n
.if (!exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}))
DISTFILE_INSTRUCTIONS += Please access\n\
\n\
  ${DOWNLOAD_URL}\n\
\n\
with a web browser and \"Accept\" the End User License Agreement for\n\
\"Caffe Diablo ${JDK_VERSION}\".  Please place the downloaded\n\
${DISTNAME}${EXTRACT_SUFX} in ${DISTDIR}.\n\n
.endif
.endif

pre-fetch:
.if defined(DISTFILE_INSTRUCTIONS)
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}"
	@exit 1
.endif

.if !defined(WITHOUT_TZUPDATE)
pre-install:
	@${ECHO_CMD} -n "Updating time zones..."
	@${RM} -rf ${WRKSRC}/jre/lib/zi
	@${LN} -s -f ${LOCALBASE}/share/java/zi ${WRKSRC}/jre/lib/
	@${ECHO_CMD} "done"
.endif

do-install:
	${MKDIR} "${INSTALL_DIR}"
	cd "${WRKSRC}" && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} "${INSTALL_DIR}"

post-install:
	# Register the VM
	"${LOCALBASE}/bin/registervm" \
		"${INSTALL_DIR}/bin/java # DiabloCaffe${JDK_VERSION}"
	# Install the plugin
	${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
