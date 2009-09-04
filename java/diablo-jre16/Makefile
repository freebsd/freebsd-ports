# New ports collection makefile for:	diablo-jre16
# Date created:		July 26 2008
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jre
PORTVERSION=	${JRE_VERSION}.${RELEASE_VERSION}.${BUILD_VERSION}
PORTREVISION=	5
CATEGORIES=	java devel
MASTER_SITES=	#
PKGNAMEPREFIX=	diablo-
DISTNAME=	${PKGNAMEPREFIX}latte-${JRE_OSREL}-${ARCH}-${JRE_VERSION}_${RELEASE_VERSION}-b${BUILD_VERSION}
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java Runtime Environment ${JRE_VERSION}_${RELEASE_VERSION}.${BUILD_VERSION}

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

RESTRICTED=	License does not allow distribution with fee

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

OPTIONS=	POLICY	"Install the Unlimited Strength Policy Files"	off \
		TZUPDATE	"Update the time zone data"	on

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
.else
JRE_OSREL=	freebsd6
PLIST_SUB+=	RELEASENOTE=""
.endif

.if ${ARCH} == "i386"
PLIST_SUB+=	CLIENTVM=""
.else
PLIST_SUB+=	CLIENTVM="@comment "
.endif

.if defined(WITH_POLICY) || !defined(WITHOUT_TZUPDATE)
EXTRACT_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
.endif

POLICYFILE=	jce_policy-6.zip
.if defined(WITH_POLICY)
DISTFILES+=	${POLICYFILE}
.endif

TZUPDATE_VERSION=	1_3_18
TZUPDATE_TZVERSION=	2009k
TZUPDATEFILE=		tzupdater-${TZUPDATE_VERSION}-${TZUPDATE_TZVERSION}.zip
.if !defined(WITHOUT_TZUPDATE)
DISTFILES+=		${TZUPDATEFILE}
PLIST_SUB+=		TZORIGINAL="@comment "
PLIST_SUB+=		TZUPDATE=""
.else
PLIST_SUB+=		TZORIGINAL=""
PLIST_SUB+=		TZUPDATE="@comment "
.endif

.if !defined(PACKAGE_BUILDING) && defined(JRE_OSREL) && (!exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) || (defined(WITH_POLICY) && !exists(${DISTDIR}/${POLICYFILE})) || (!defined(WITHOUT_TZUPDATE) && !exists(${DISTDIR}/${TZUPDATEFILE})))#{
DISTFILE_INSTRUCTIONS=\n\
Because of licensing restrictions, you must fetch the distribution\n\
manually.\n\n
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})#{
Please access\n\
\n\
  ${DOWNLOAD_URL}\n\
\n\
with a web browser and \"Accept\" the End User License Agreement for\n\
\"Latte Diablo ${JRE_VERSION}\".  Please place the downloaded\n\
${DISTNAME}${EXTRACT_SUFX} in ${DISTDIR}.\n\n
.endif#}
.if defined(WITH_POLICY) && !exists(${DISTDIR}/${POLICYFILE})#{
DISTFILE_INSTRUCTIONS+=Please open\n\n\
\ \ \ \ http://java.sun.com/javase/downloads/\n\n\
in a web browser and follow the \"Download\" link for \"Java\n\
Cryptography Extension (JCE) Unlimited Strength Jurisdiction\n\
Policy Files 6\" to obtain the JCE policy file, ${POLICYFILE}.\n\n
.endif#}
.if !defined(WITHOUT_TZUPDATE) && !exists(${DISTDIR}/${TZUPDATEFILE})#{
DISTFILE_INSTRUCTIONS += Please open http://java.sun.com/javase/downloads/index.jsp\n\
in a web browser and follow the \"Download\" link for\n\
\"JDK US DST Timezone Update Tool - ${TZUPDATE_VERSION}\" to obtain the\n\
time zone update file, ${TZUPDATEFILE}.\n\n
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
	@${UNZIP_CMD} -qo ${DISTDIR}/${TZUPDATEFILE} -d ${WRKDIR}
	@${UNZIP_CMD} -qo ${WRKDIR}/tzupdater-${TZUPDATE_VERSION:S/_/./g}-${TZUPDATE_TZVERSION}/tzupdater.jar -d ${WRKDIR}/tzupdater-${TZUPDATE_VERSION:S/_/./g}-${TZUPDATE_TZVERSION}/
	@${MKDIR} ${WRKDIR}/tzupdater-${TZUPDATE_VERSION:S/_/./g}-${TZUPDATE_TZVERSION}/zi
	@${UNZIP_CMD} -qo ${WRKDIR}/tzupdater-${TZUPDATE_VERSION:S/_/./g}-${TZUPDATE_TZVERSION}/data/tzdata${TZUPDATE_TZVERSION}.zip -d ${WRKDIR}/tzupdater-${TZUPDATE_VERSION:S/_/./g}-${TZUPDATE_TZVERSION}/zi

pre-install:
	@${ECHO_CMD} -n "Updating time zones..."
	@${RM} -rf ${WRKSRC}/lib/zi
	@${MV} -f ${WRKDIR}/tzupdater-${TZUPDATE_VERSION:S/_/./g}-${TZUPDATE_TZVERSION}/zi ${WRKSRC}/lib/
	@${ECHO_CMD} "done"
	@-${RM} -rf ${WRKSRC}/lib/zi.tzdata*
.endif

do-install:
	${MKDIR} "${INSTALL_DIR}"
	cd "${WRKSRC}" && ${FIND} . \
	  | ${CPIO} -pdmu -R ${LIBOWN}:${LIBGRP} "${INSTALL_DIR}"
	${INSTALL_DATA} ${FILESDIR}/cacerts \
		${PREFIX}/${PKGNAMEPREFIX}jre${JRE_VERSION}/lib/security/cacerts
.if defined(WITH_POLICY)
	${INSTALL_DATA} ${WRKDIR}/jce/*.jar ${PREFIX}/${PKGNAMEPREFIX}jre${JRE_VERSION}/lib/security
.endif

post-install:
	# Register the VM
	"${LOCALBASE}/bin/registervm" \
		"${INSTALL_DIR}/bin/java # DiabloLatte${JRE_VERSION}"
	# Install the shared archives and plugin
	${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
