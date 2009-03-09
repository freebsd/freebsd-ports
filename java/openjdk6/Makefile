# New ports collection makefile for:    openjdk6
# Date created:         2009/2/21
# Whom:                 Brian Gardner <brian@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	openjdk6
PORTVERSION=	b14
CATEGORIES=	java devel
MASTER_SITES=	http://filedb.experts-exchange.com/incoming/2009/02_w07/104611/ \
		http://filedb.experts-exchange.com/incoming/2009/02_w08/108800/
DISTNAME=	openjdk-6-src-${PORTVERSION}-${OPENJDK_BUILDDATE}
DISTFILES=	${DISTNAME}.zip ${CUSTOM_PATCH_NAME}.zip

MAINTAINER=	brian@experts-exchange.com
COMMENT=	Sun\'s java 6 virtual machine release under the GNUV2 license

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

PATCHVERSION=	0.2.1
OPENJDK_BUILDDATE=10-feb-2009
CUSTOM_PATCHES_PREFIX=	jdk7_bsd_changes_20090203
CUSTOM_PATCH_NAME=	patch-${PORTNAME}-freebsd-${PATCHVERSION}
CUSTOM_UNZIPPED_PATCH_NAME=	patch_${PORTNAME}_freebsd_${PATCHVERSION}
CUSTOM_PATCH_WRKSRC=	${WRKDIR}/${CUSTOM_UNZIPPED_PATCH_NAME}

OPTIONS=	DEBUG   "Enable debugging support"	off \
		IPV6    "Enable IPv6 support"	off \
		WEB "Enable the browser plugin and Java Web Start"	on \
		POLICY  "Install the Unlimited Strength Policy Files"	off \

# java extracts directly to the cwd
WRKSRC=	${WRKDIR}

USE_GMAKE=	yes
USE_JAVA=	yes
JAVA_VENDOR=	freebsd bsdjava
JAVA_VERSION=	1.6
USE_MOTIF=	yes
USE_XORG=	xtst xi xt x11

LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS+=	ant:${PORTSDIR}/devel/apache-ant
BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS+=	${JAVAJARDIR}/jdk-7-icedtea-plugs/jre/lib/rt-closed.jar:${PORTSDIR}/java/icedtea6-stubs

.include <bsd.port.pre.mk>

.if ${OSVERSION} <= 700000
BROKEN=		does not compile, including unistd.h is needed
.endif

.if defined(WITH_IPV6)
CATEGORIES+=	ipv6
.endif

# we set the arch to i586 to simulate linux.
# there is probably a better way to due this
.if ${ARCH} == "i386"
ARCH=	i586
.endif

OPENJDK_OSARCH=	bsd-${ARCH}

ONLY_FOR_ARCHS=	amd64 i586

BOOTSTRAP_JDKS=	${LOCALBASE}/diablo-jdk1.6.0

MAKE_ENV=	LANG=C LC_ALL=C ALT_BOOTDIR=${BOOTSTRAP_JDKS} \
		ALT_HOTSPOT_IMPORT_PATH=${BOOTSTRAP_JDKS} \
		ALT_JDK_IMPORT_PATH=${BOOTSTRAP_JDKS} \
		ALT_FREETYPE_HEADERS_PATH=${LOCALBASE}/include \
		ALT_FREETYPE_LIB_PATH=${LOCALBASE}/lib \
		ALT_X11_PATH=${LOCALBASE} \
		ALT_BINARY_PLUGS_PATH=${JAVAJARDIR}/jdk-7-icedtea-plugs \
		ANT_HOME=${LOCALBASE} NO_DOCS=true ALT_CUPS_HEADERS_PATH=${LOCALBASE}/include

.if !defined(WITH_IPV6)
MAKE_ENV+=	DONT_ENABLE_IPV6="YES"
.endif

.if defined(WITH_DEBUG)
MAKE_ENV+=	SKIP_DEBUG_BUILD="false"
.endif

# perhaps we could check to see how many processors are availble and set this equivelent to that
MAKE_ENV+=	HOTSPOT_BUILD_JOBS=4

JDK_MAJOR_VERSION=	6
POLICYFILE=	jce_policy-${JDK_MAJOR_VERSION}.zip

.if defined(WITH_POLICY)
DISTFILES+=	${POLICYFILE}
.endif

.if defined(WITH_POLICY) && !exists(${DISTDIR}/${POLICYFILE})#{
DISTFILE_INSTRUCTIONS =\n\
Due to licensing restrictions, certain files must be fetched manually.\n\n
DISTFILE_INSTRUCTIONS += Please open http://java.sun.com/javase/downloads/index.jsp\n\
in a web browser and follow the \"Download\" link for\n\
\"Other Downloads\" to obtain the JCE policy file, ${POLICYFILE}.\n\
This file must be placed is ${PORTSDIR}/distfiles\n\n
.endif#}

pre-fetch:
.if defined(DISTFILE_INSTRUCTIONS)
	@${PRINTF} "${DISTFILE_INSTRUCTIONS}"
	@exit 1
.endif

pre-patch:
	(cd ${CUSTOM_PATCH_WRKSRC}/${CUSTOM_PATCHES_PREFIX}.newfiles/ && ${CP} -Rp ./ ${WRKSRC})
	(cd ${CUSTOM_PATCH_WRKSRC}/${CUSTOM_PATCHES_PREFIX}.linuxfiles/ && ${CP} -Rp ./ ${WRKSRC})
	(cd ${CUSTOM_PATCH_WRKSRC}/${CUSTOM_PATCHES_PREFIX}.linuxmakefiles/ && ${CP} -Rp ./ ${WRKSRC})
	# these are expected to fail
	((cd ${WRKSRC} && ${CAT} ${CUSTOM_PATCH_WRKSRC}/${CUSTOM_PATCHES_PREFIX}.makepatches/*.patch | ${PATCH} -p1) || true)
	((cd ${WRKSRC} && ${CAT} ${CUSTOM_PATCH_WRKSRC}/${CUSTOM_PATCHES_PREFIX}.linuxpatches/*.patch | ${PATCH} -p1) || true)
	((cd ${WRKSRC} && ${CAT} ${CUSTOM_PATCH_WRKSRC}/${CUSTOM_PATCHES_PREFIX}.patches/*.patch | ${PATCH} -p1) || true)
	# these patches should apply cleanly
	((cd ${WRKSRC} && ${CAT} ${CUSTOM_PATCH_WRKSRC}/custom_patches_${PATCHVERSION}/*.patch | ${PATCH} -p1) || true)

do-install:
	${MKDIR} ${PREFIX}/openjdk6/
	${CP} -Rp ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image/ ${PREFIX}/openjdk6/
	${INSTALL_DATA} ${FILESDIR}/cacerts \
	      ${PREFIX}/openjdk6/jre/lib/security/cacerts
.if defined(WITH_POLICY)
	${INSTALL_DATA} ${WRKDIR}/jce/*.jar ${PREFIX}/openjdk6/jre/lib/security
.endif
	@${FIND} -s ${PREFIX}/openjdk6 -not -type d | \
	${SED} -e 's#^${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/openjdk6 -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
