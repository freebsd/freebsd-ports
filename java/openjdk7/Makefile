# New ports collection makefile for:	openjdk7
# Date created:				2 January 2010
# Whom:					Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openjdk
PORTVERSION=	${JDK_MAJOR_VERSION}.${PORT_MINOR_VERSION}.${PORT_BUILD_NUMBER}
CATEGORIES=	java devel
MASTER_SITES=	http://download.java.net/openjdk/jdk${JDK_MAJOR_VERSION}u${JDK_MINOR_VERSION}/promoted/b${JDK_BUILD_NUMBER}/ \
		http://download.java.net/jaxp/1.4.5/:jaxp \
		http://icedtea.classpath.org/download/drops/:jaxp \
		http://download.java.net/glassfish/components/jax-ws/openjdk/jdk7/:jaxws \
		http://icedtea.classpath.org/download/drops/:jaxws \
		https://java.net/downloads/jax-ws/JDK7/:jaf \
		http://icedtea.classpath.org/download/drops/:jaf \
		${MASTER_SITE_APACHE:S,%SUBDIR%/,ant/binaries/:ant,}
DISTFILES=	${JDK_SRC_DISTFILE}${EXTRACT_SUFX} \
		${JAXPFILE}:jaxp \
		${JAXWSFILE}:jaxws \
		${JAFFILE}:jaf \
		${ANT_DISTFILE}${EXTRACT_SUFX}:ant
EXTRACT_ONLY=	${JDK_SRC_DISTFILE}${EXTRACT_SUFX} \
		${ANT_DISTFILE}${EXTRACT_SUFX}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java Development Kit 7

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	YES
MAKE_JOBS_UNSAFE=	YES

OPTIONS=	POLICY   "Install the Unlimited Strength Policy Files"      on \
		TZUPDATE "Update the time zone data"                        on

PORT_MINOR_VERSION=	5
PORT_BUILD_NUMBER=	06
JDK_MAJOR_VERSION=	7
JDK_MINOR_VERSION=	4
JDK_BUILD_NUMBER=	22
JDK_BUILD_DATE=		02_may_2012
JDK_SRC_DISTFILE=	${PORTNAME}-${JDK_MAJOR_VERSION}u${JDK_MINOR_VERSION}-fcs-src-b${JDK_BUILD_NUMBER}-${JDK_BUILD_DATE}

# Use our own version of ant to avoid circular dependencies
ANT_VERSION=		1.8.3
ANT_DISTFILE=		apache-ant-${ANT_VERSION}-bin

LATEST_LINK=		openjdk7

USE_GMAKE=	YES
USE_ICONV=	YES
USE_XORG+=	x11 xext xi xrender xt xtst
MAKE_JOBS_UNSAFE=	yes

JAXPFILE=	jaxp145_01.zip
JAXWSFILE=	jdk7-jaxws2_2_4-b04-2011_06_01.zip
JAFFILE=	jdk7-jaf-2010_08_19.zip

LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2 \
		asound.2:${PORTSDIR}/audio/alsa-lib
BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		${LOCALBASE}/include/cups/cups.h:${PORTSDIR}/print/cups-client
RUN_DEPENDS+=	javavm:${PORTSDIR}/java/javavmwrapper

OPENJDK_OSARCH=	bsd-${ARCH:S/i386/i586/}
INSTALLDIR=	${PREFIX}/${PORTNAME}${JDK_MAJOR_VERSION}

NOPRECIOUSMAKEVARS=	yes

ONLY_FOR_ARCHS=	i386 amd64

FETCH_ARGS=	-Fpr
MAKE_ENV+=	LANG="C" \
		LC_ALL="C" \
		JAVA_HOME="" \
		CLASSPATH="" \
		LD_LIBRARY_PATH="" \
		MAKEFLAGS="" \
		ALT_BOOTDIR="${BOOTSTRAPJDKDIR}" \
		ALT_FREETYPE_HEADERS_PATH="${LOCALBASE}/include" \
		ALT_FREETYPE_LIB_PATH="${LOCALBASE}/lib" \
		ALT_CUPS_HEADERS_PATH="${LOCALBASE}/include" \
		ALT_X11_PATH="${LOCALBASE}" \
		ALT_PKG_PATH="${LOCALBASE}" \
		ALT_PACKAGE_PATH="${LOCALBASE}" \
		ALT_DROPS_DIR="${DISTDIR}" \
		ANT_HOME="${WRKDIR}/apache-ant-${ANT_VERSION}" \
		X11DIR="${LOCALBASE}" \
		LOCALDIR="${LOCALBASE}" \
		NO_DOCS="true" \
		SKIP_COMPARE_IMAGES="true" \
		SKIP_FASTDEBUG_BUILD="true" \
		SKIP_DEBUG_BUILD="true" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		MILESTONE="fcs" \
		JDK_MICRO_VERSION="0_0${PORT_MINOR_VERSION}" \
		BUILD_NUMBER="b${PORT_BUILD_NUMBER}"

.if !defined(DISABLE_MAKE_JOBS)
.if defined(MAKE_JOBS_NUMBER)
BUILD_JOBS_NUMBER=	${MAKE_JOBS_NUMBER}
.else
BUILD_JOBS_NUMBER=	`${SYSCTL} -n kern.smp.cpus`
.endif
MAKE_ENV+=	HOTSPOT_BUILD_JOBS=${BUILD_JOBS_NUMBER}
.endif

BOOTSTRAP_JDKS=	${LOCALBASE}/openjdk7 \
		${LOCALBASE}/openjdk6 \
		${LOCALBASE}/jdk1.6.0 \
		${LOCALBASE}/diablo-jdk1.6.0

.include <bsd.port.pre.mk>

.if defined(WITH_TZUPDATE)
RUN_DEPENDS+=  ${LOCALBASE}/share/java/zi:${PORTSDIR}/java/java-zoneinfo
.endif

# do we have valid native jdk installed?
.for BJDK in ${BOOTSTRAP_JDKS}
.  if !defined(BOOTSTRAPJDKDIR) && exists(${BJDK}/bin/javac)
BOOTSTRAPJDKDIR=	${BJDK}
.  endif
.endfor

# if no valid jdk found, set dependency
.if !defined(BOOTSTRAPJDKDIR)
BOOTSTRAPJDKDIR?=	${LOCALBASE}/diablo-jdk1.6.0
BUILD_DEPENDS+=		${BOOTSTRAPJDKDIR}/bin/javac:${PORTSDIR}/java/diablo-jdk16
.endif

post-patch:
	@${REINPLACE_CMD} "s|%%LOCALBASE%%|${LOCALBASE}|" \
		${WRKSRC}/hotspot/src/os/bsd/vm/os_bsd.cpp
	@${REINPLACE_CMD} 's|build-policy install-limited|build-policy install-unlimited|' \
		${WRKSRC}/jdk/make/javax/crypto/Makefile
.if defined(WITH_POLICY)
	@${REINPLACE_CMD} 's|build-policy install-limited|build-policy install-unlimited|' \
		${WRKSRC}/jdk/make/javax/crypto/Makefile
.endif

.if defined(WITH_TZUPDATE)
pre-install:
	@# Update time zones
	@${RM} -rf ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image/jre/lib/zi
	@${LN} -s -f ${LOCALBASE}/share/java/zi \
		${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image/jre/lib
.endif

do-install:
	@${MKDIR} ${INSTALLDIR}
	@cd ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image && \
		${COPYTREE_SHARE} . ${INSTALLDIR}
	@${INSTALL_DATA} ${WRKSRC}/build/${OPENJDK_OSARCH}/btjars/compilefontconfig.jar ${WRKSRC}/build/${OPENJDK_OSARCH}/btjars/javazic.jar ${INSTALLDIR}/jre/lib/
	@for dir in `${FIND} ${INSTALLDIR} -name bin -type d`; do \
		${CHOWN} -h -R ${BINOWN}:${BINGRP} $$dir; \
		${FIND} $$dir -type f -exec ${CHMOD} ${BINMODE} "{}" \; ; \
	done
	@${INSTALL_DATA} ${FILESDIR}/cacerts ${INSTALLDIR}/jre/lib/security/cacerts
	@${ECHO} "@unexec ${LOCALBASE}/bin/unregistervm ${INSTALLDIR}/bin/java" >> ${TMPPLIST}
	@${FIND} -s ${INSTALLDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} ${INSTALLDIR} -type d | ${SORT} -r | \
		${SED} -e 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${ECHO} "@exec ${LOCALBASE}/bin/registervm '${INSTALLDIR}/bin/java # OpenJDK${JDK_MAJOR_VERSION}'" >> ${TMPPLIST}

post-install:
	# Register the VM
	"${LOCALBASE}/bin/registervm" "${INSTALLDIR}/bin/java # OpenJDK${JDK_MAJOR_VERSION}"

.include <bsd.port.post.mk>
