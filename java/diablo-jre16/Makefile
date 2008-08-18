# New ports collection makefile for:	diablo-jre16
# Date created:		July 26 2008
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jre
PORTVERSION=	${JRE_VERSION}.${RELEASE_VERSION}.${BUILD_VERSION}
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	diablo-
DISTNAME=	${PKGNAMEPREFIX}latte-${JRE_OSREL}-${ARCH}-${JRE_VERSION}_${RELEASE_VERSION}-b${BUILD_VERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java Runtime Environment ${JRE_VERSION}_${RELEASE_VERSION}.${BUILD_VERSION}

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

RESTRICTED=	"License doesn't allow distribution with fee"

USE_BZIP2=	yes
USE_XORG+=	xi xp xt xtst
ONLY_FOR_ARCHS=	amd64 i386
JRE_VERSION=	1.6.0
RELEASE_VERSION=07
BUILD_VERSION=	02
PLIST_SUB+=	JRE_VERSION=${JRE_VERSION}
PLIST_SUB+=	ARCH=${ARCH}
DOWNLOAD_URL=	http://www.FreeBSDFoundation.org/cgi-bin/download?download=${DISTNAME}${EXTRACT_SUFX}
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}16

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}jre${JRE_VERSION}_${RELEASE_VERSION}
NO_BUILD=	yes

SUB_FILES+=	pkg-install \
		pkg-deinstall
SUB_LIST+=	ARCH="${ARCH}" \
		JRE_VERSION="${JRE_VERSION}"

PKG_IGNORE_DEPENDS=	'^[^x|^j]'

INSTALL_DIR=	${PREFIX}/${PKGNAMEPREFIX}jre${JRE_VERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
JRE_OSREL=	freebsd7
PLIST_SUB+=	RELEASENOTE="@comment "
.elif ${OSVERSION} >= 600000
JRE_OSREL=	freebsd6
PLIST_SUB+=	RELEASENOTE=""
.else
IGNORE=		Only available for FreeBSD 6.x/i386 and FreeBSD 6.x/amd64 and later
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	CLIENTVM=""
.else
PLIST_SUB+=	CLIENTVM="@comment "
.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING) && defined(JRE_OSREL)
DISTFILE_INSTRUCTIONS=	:\n\
Because of licensing restrictions, you must fetch the distribution\n\
manually.\n\n
Please access\n\
\n\
  ${DOWNLOAD_URL}\n\
\n\
with a web browser and \"Accept\" the End User License Agreement for\n\
\"Latte Diablo ${JRE_VERSION}\".  Please place the downloaded\n\
${DISTNAME}${EXTRACT_SUFX} in ${DISTDIR}.\n\n
.endif

pre-fetch:
.if defined(DISTFILE_INSTRUCTIONS)
	@printf "${DISTFILE_INSTRUCTIONS}"
	@exit 1
.endif

do-install:
	${MKDIR} "${INSTALL_DIR}"
	cd "${WRKSRC}" && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} "${INSTALL_DIR}"

post-install:
	# Register the VM
	"${LOCALBASE}/bin/registervm" \
		"${INSTALL_DIR}/bin/java # DiabloLatte${JRE_VERSION}"
	# Install the shared archives and plugin
	${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
