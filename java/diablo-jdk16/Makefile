# New ports collection makefile for:	diablo-jdk16
# Date created:		July 26 2008
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}.${RELEASE_VERSION}.${BUILD_VERSION}
PORTREVISION=	19
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	diablo-
DISTNAME=	${PKGNAMEPREFIX}caffe-${JDK_OSREL}-${ARCH}-${JDK_VERSION}_${RELEASE_VERSION}-b${BUILD_VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java Development Kit ${JDK_VERSION}_${RELEASE_VERSION}.${BUILD_VERSION}

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

RESTRICTED=	License does not allow distribution with fee

USE_BZIP2=	yes
USE_XORG+=	xi xp xt xtst
ONLY_FOR_ARCHS=	amd64 i386
JDK_VERSION=	1.6.0
RELEASE_VERSION=07
BUILD_VERSION=	02
PLIST_SUB+=	JDK_VERSION=${JDK_VERSION}
PLIST_SUB+=	ARCH=${ARCH}
DOWNLOAD_URL=	http://www.FreeBSDFoundation.org/cgi-bin/download?download=${DISTNAME}${EXTRACT_SUFX}
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}16

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}jdk${JDK_VERSION}_${RELEASE_VERSION}
NO_BUILD=	yes

OPTIONS=	POLICY	"Install the Unlimited Strength Policy Files" off \
		TZUPDATE	"Update the time zone data"	on

SUB_FILES+=	pkg-install \
		pkg-deinstall
SUB_LIST+=	ARCH="${ARCH}" \
		JDK_VERSION="${JDK_VERSION}"

PKG_IGNORE_DEPENDS=	'^[^xj]'

INSTALL_DIR=	${PREFIX}/${PKGNAMEPREFIX}jdk${JDK_VERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800105
LIB_DEPENDS=	z.4:${PORTSDIR}/misc/compat7x
.endif

.if ${OSVERSION} >= 700000
JDK_OSREL=	freebsd7
PLIST_SUB+=	RELEASENOTE="@comment "
.else
JDK_OSREL=	freebsd6
PLIST_SUB+=	RELEASENOTE=""
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	CLIENTVM=""
.else
PLIST_SUB+=	CLIENTVM="@comment "
.endif

.if defined(WITH_POLICY)
EXTRACT_DEPENDS+=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
.endif

POLICYFILE=	jce_policy-6.zip
.if defined(WITH_POLICY)
DISTFILES+=	${POLICYFILE}
.endif

.if !defined(WITHOUT_TZUPDATE)
RUN_DEPENDS+=		${LOCALBASE}/share/java/zi:${PORTSDIR}/java/java-zoneinfo
PLIST_SUB+=		TZORIGINAL="@comment "
PLIST_SUB+=		TZUPDATE=""
.else
PLIST_SUB+=		TZORIGINAL=""
PLIST_SUB+=		TZUPDATE="@comment "
.endif

.if !defined(PACKAGE_BUILDING) && defined(JDK_OSREL) && (!exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) || (defined(WITH_POLICY) && !exists(${DISTDIR}/${POLICYFILE})))#{
DISTFILE_INSTRUCTIONS=\n\
Because of licensing restrictions, you must fetch the distribution\n\
manually.\n\n
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})#{
DISTFILE_INSTRUCTIONS+=Please access\n\n\
\ \ \ \ ${DOWNLOAD_URL}\n\n\
with a web browser and \"Accept\" the End User License Agreement for\n\
\"Caffe Diablo ${JDK_VERSION}\".\n\n
.endif#}
.if defined(WITH_POLICY) && !exists(${DISTDIR}/${POLICYFILE})#{
DISTFILE_INSTRUCTIONS+=Please open\n\n\
\ \ \ \ http://www.oracle.com/technetwork/java/javase/downloads/index.html\n\n\
in a web browser and follow the \"Download\" link for \"Java\n\
Cryptography Extension (JCE) Unlimited Strength Jurisdiction\n\
Policy Files 6\" to obtain the JCE policy file, ${POLICYFILE}.\n\n
.endif#}
DISTFILE_INSTRUCTIONS+=Please place the downloaded file(s) in ${DISTDIR}.\n\n
.endif#}

pre-fetch:
.if defined(DISTFILE_INSTRUCTIONS)
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}"
	@exit 1
.endif

post-extract:
.if defined(WITH_POLICY)
	@${UNZIP_CMD} -qo ${DISTDIR}/${POLICYFILE} -d ${WRKDIR}
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
	${INSTALL_DATA} ${FILESDIR}/cacerts \
		${PREFIX}/${PKGNAMEPREFIX}jdk${JDK_VERSION}/jre/lib/security/cacerts
.if defined(WITH_POLICY)
	${INSTALL_DATA} ${WRKDIR}/jce/*.jar ${PREFIX}/${PKGNAMEPREFIX}jdk${JDK_VERSION}/jre/lib/security
.endif

post-install:
	# Register the VM
	"${LOCALBASE}/bin/registervm" \
		"${INSTALL_DIR}/bin/java # DiabloCaffe${JDK_VERSION}"
	# Install the shared archives and plugin
	${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
