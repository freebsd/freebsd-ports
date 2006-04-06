# New ports collection makefile for:	diablo-jre15
# Date created:		February 26 2006
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jre
PORTVERSION=	${JRE_VERSION}.${RELEASE_VERSION}.${BUILD_VERSION}
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	diablo-
DISTNAME=	${PKGNAMEPREFIX}latte-freebsd${JRE_OSREL}-${JRE_VERSION}_${RELEASE_VERSION}-b${BUILD_VERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java Runtime Environment ${JRE_VERSION}_${RELEASE_VERSION}.${BUILD_VERSION}

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

RESTRICTED=	"License doesn't allow distribution with fee"

USE_BZIP2=	yes
USE_XLIB=	yes
ONLY_FOR_ARCHS=	i386
JRE_VERSION=	1.5.0
RELEASE_VERSION=06
BUILD_VERSION=	00
PLIST_SUB+=	JRE_VERSION=${JRE_VERSION}
DOWNLOAD_URL=	http://www.FreeBSDFoundation.org/cgi-bin/download?download=${DISTNAME}${EXTRACT_SUFX}
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}15

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}jre${JRE_VERSION}_${RELEASE_VERSION}
NO_BUILD=	yes

SUB_FILES+=	pkg-install \
		pkg-deinstall
PKG_IGNORE_DEPENDS=	'^[^x|^j]'

INSTALL_DIR=	${PREFIX}/${PKGNAMEPREFIX}jre${JRE_VERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
JRE_OSREL=6
.elif ${OSVERSION} >= 500000
JRE_OSREL=5
.else
IGNORE=		Only available for FreeBSD 5.x and later
.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE=	:\n\
Because of licensing restrictions, you must fetch the distribution\n\
manually.  Please access\n\
\n\
  ${DOWNLOAD_URL}\n\
\n\
with a web browser and \"Accept\" the End User License Agreement for\n\
\"Latte Diablo ${JRE_VERSION}\".  Please place the downloaded\n\
${DISTNAME}${EXTRACT_SUFX} in ${DISTDIR}.\n
.endif

do-install:
	${MKDIR} "${INSTALL_DIR}"
	cd "${WRKSRC}" && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} "${INSTALL_DIR}"

post-install:
	# Register the VM
	"${LOCALBASE}/bin/registervm" \
	  "${INSTALL_DIR}/bin/java # DiabloLatte${JRE_VERSION}"
	# Install cacerts
	${INSTALL_DATA} "${FILESDIR}/cacerts" \
	  "${INSTALL_DIR}/lib/security/cacerts"
	# Install the plugin
	${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
