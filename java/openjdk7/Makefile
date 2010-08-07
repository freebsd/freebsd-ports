# New ports collection makefile for:	openjdk7
# Date created:				2 January 2010
# Whom:					Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	openjdk
PORTVERSION=	${JDK_MAJOR_VERSION}.${JDK_MINOR_VERSION}.${JDK_BUILD_NUMBER}
CATEGORIES=	java devel
MASTER_SITES=	http://download.java.net/openjdk/jdk7/promoted/b${JDK_BUILD_NUMBER}/ \
		${MASTER_SITE_APACHE:S,%SUBDIR%/,ant/binaries/:ant,}
DISTFILES=	${JDK_SRC_DISTFILE}${EXTRACT_SUFX} \
		${ANT_DISTFILE}${EXTRACT_SUFX}:ant

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java Development Kit 7
LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ZIP=	YES

JDK_MAJOR_VERSION=	7
JDK_MINOR_VERSION=	0
JDK_BUILD_NUMBER=	100
JDK_BUILD_DATE=		09_jul_2010
JDK_SRC_DISTFILE=	${PORTNAME}-${JDK_MAJOR_VERSION}-ea-src-b${JDK_BUILD_NUMBER}-${JDK_BUILD_DATE}

# Use our own version of ant to avoid circular dependencies
ANT_VERSION=		1.7.1
ANT_DISTFILE=		apache-ant-${ANT_VERSION}-bin

LATEST_LINK=		openjdk7

USE_GMAKE=	YES
USE_ICONV=	YES
USE_XORG+=	x11 xext xi xrender xt xtst

LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip \
		${LOCALBASE}/include/cups/cups.h:${PORTSDIR}/print/cups-client
RUN_DEPENDS+=	javavm:${PORTSDIR}/java/javavmwrapper

OPENJDK_OSARCH=	bsd-${ARCH:S/i386/i586/}
INSTALLDIR=	${PREFIX}/${PORTNAME}${JDK_MAJOR_VERSION}

NOPRECIOUSMAKEVARS=	yes

ONLY_FOR_ARCHS=	i386 amd64

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
		ANT_HOME="${WRKDIR}/apache-ant-${ANT_VERSION}" \
		X11DIR="${LOCALBASE}" \
		LOCALDIR="${LOCALBASE}" \
		NO_DOCS="true" \
		SKIP_COMPARE_IMAGES="true" \
		SKIP_FASTDEBUG_BUILD="true" \
		SKIP_DEBUG_BUILD="true" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		MILESTONE="fcs"

.if defined(HOTSPOT_BUILD_JOBS)
MAKE_ENV+=	HOTSPOT_BUILD_JOBS="${HOTSPOT_BUILD_JOBS}"
.endif

BOOTSTRAP_JDKS=	${LOCALBASE}/openjdk7 \
		${LOCALBASE}/openjdk6 \
		${LOCALBASE}/jdk1.6.0 \
		${LOCALBASE}/diablo-jdk1.6.0

.include <bsd.port.pre.mk>

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

post-extract:
	@for dir in `${FIND} ${WRKSRC} -name '*[Ll][Ii][Nn][Uu][Xx]*' -type d`; do \
		${MKDIR} `echo $$dir | ${SED} -e 's/linux/bsd/g' -e 's/Linux/Bsd/g' -e 's/LINUX/BSD/g'`; \
		for subdir in `${FIND} $$dir -type d`; do \
			${MKDIR} `echo $$subdir | ${SED} -e 's/linux/bsd/g' -e 's/Linux/Bsd/g' -e 's/LINUX/BSD/g'`; \
		done; \
		for file in `${FIND} $$dir -type f`; do \
			newfile=`echo $$file | ${SED} -e 's/linux/bsd/g' -e 's/Linux/Bsd/g' -e 's/LINUX/BSD/g'`; \
			${SED} -e 's/linux/bsd/g' -e 's/Linux/Bsd/g' -e 's/LINUX/BSD/g' $$file > $$newfile; \
		done; \
	done
	@for file in `${FIND} ${WRKSRC} -name '*[Ll][Ii][Nn][Uu][Xx]*' -type f | ${GREP} -v '\/[^/]*[Ll][Ii][Nn][Uu][Xx][^/]*\/'`; do \
		newfile=`echo $$file | ${SED} -e 's/linux/bsd/g' -e 's/Linux/Bsd/g' -e 's/LINUX/BSD/g'`; \
		${SED} -e 's/linux/bsd/g' -e 's/Linux/Bsd/g' -e 's/LINUX/BSD/g' $$file > $$newfile; \
	done

post-patch:
	@${REINPLACE_CMD} "s|%%LOCALBASE%%|${LOCALBASE}|" \
		${WRKSRC}/hotspot/src/os/bsd/vm/os_bsd.cpp
	@${REINPLACE_CMD} 's|build-policy install-limited|build-policy install-unlimited|' \
		${WRKSRC}/jdk/make/javax/crypto/Makefile

do-install:
	@${MKDIR} ${INSTALLDIR}
	@cd ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image && \
		${COPYTREE_SHARE} . ${INSTALLDIR}
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
