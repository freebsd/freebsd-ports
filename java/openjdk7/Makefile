# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openjdk
PORTVERSION=	${JDK_MAJOR_VERSION}.${PORT_MINOR_VERSION}.${PORT_BUILD_NUMBER}
PORTEPOCH=	1
CATEGORIES=	java devel
MASTER_SITES=	http://download.java.net/openjdk/jdk${JDK_MAJOR_VERSION}u${JDK_MINOR_VERSION}/promoted/b${JDK_BUILD_NUMBER}/ \
		http://download.java.net/jaxp/1.4.5/:jaxp \
		http://icedtea.classpath.org/download/drops/:jaxp \
		http://download.java.net/glassfish/components/jax-ws/openjdk/jdk7/:jaxws \
		http://icedtea.classpath.org/download/drops/:jaxws \
		https://java.net/downloads/jax-ws/JDK7/:jaf \
		http://icedtea.classpath.org/download/drops/:jaf \
		APACHE/ant/binaries/:ant
PATCH_SITES=	LOCAL/glewis/openjdk7
DISTFILES=	${JDK_SRC_DISTFILE}${EXTRACT_SUFX} \
		${ANT_DISTFILE}${EXTRACT_SUFX}:ant
EXTRACT_ONLY=	${JDK_SRC_DISTFILE}${EXTRACT_SUFX} \
		${ANT_DISTFILE}${EXTRACT_SUFX}
PATCHFILES=	patch-7u45-b30.xz \
		patch-7u51-b30.xz \
		patch-7u55-b31.xz \
		patch-7u60-b30.xz \
		patch-7u65-b31.xz \
		patch-7u71-b14.xz \
		patch-7u76-b31.xz \
		patch-7u80-b32.xz \
		patch-7u85-b02.xz \
		patch-7u91-b02.xz \
		patch-7u95-b00.xz \
		patch-7u101-b00.xz \
		patch-7u111-b01.xz \
		patch-7u121-b00.xz \
		patch-7u131-b00.xz \
		patch-7u141-b02.xz \
		patch-7u151-b01.xz

MAINTAINER?=	glewis@FreeBSD.org
COMMENT?=	Java Development Kit 7

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		compiler dos2unix iconv gmake zip
# Even when not building with X11 support, openjdk7 requires Xrender, X11, and
# Xt headers.
X11_BUILD_DEPENDS_OFF+=	${LOCALBASE}/libdata/pkgconfig/x11.pc:x11/libX11
X11_BUILD_DEPENDS_OFF+=	${LOCALBASE}/libdata/pkgconfig/xext.pc:x11/libXext
X11_BUILD_DEPENDS_OFF+=	${LOCALBASE}/libdata/pkgconfig/xrender.pc:x11/libXrender
X11_BUILD_DEPENDS_OFF+=	${LOCALBASE}/libdata/pkgconfig/xt.pc:x11-toolkits/libXt
# Add more X11 build deps and runtime deps when X11 is enabled
X11_LIB_DEPENDS+=	libX11.so.6:x11/libX11
X11_LIB_DEPENDS+=	libXext.so.6:x11/libXext
X11_LIB_DEPENDS+=	libXi.so.6:x11/libXi
X11_LIB_DEPENDS+=	libXrender.so.1:x11/libXrender
X11_LIB_DEPENDS+=	libXt.so.6:x11-toolkits/libXt
X11_LIB_DEPENDS+=	libXtst.so.6:x11/libXtst
X11_MAKE_ENV_OFF=	BUILD_HEADLESS_ONLY=1

MAKE_ARGS=	CC=${CC:Q} CXX=${CXX:Q} HOST_CC=${CC:Q}

OPTIONS_DEFINE=		POLICY TZUPDATE X11
OPTIONS_DEFAULT=	POLICY TZUPDATE X11
DEBUG_DESC=		Enable extra debugging info
POLICY_DESC=		Install the Unlimited Strength Policy Files
TZUPDATE_DESC=		Update the time zone data

JAVAVMS_COMMENT=	OpenJDK${JDK_MAJOR_VERSION}

.if !defined(BUILD_JRE)
OPTIONS_DEFINE+=	DEBUG
INSTALLDIR=	${PREFIX}/${PORTNAME}${JDK_MAJOR_VERSION}
.else
JAVAVMS_COMMENT+=	JRE
INSTALLDIR=	${PREFIX}/${PORTNAME}${JDK_MAJOR_VERSION}-jre
.endif

PORT_MINOR_VERSION=	151
PORT_BUILD_NUMBER=	01
JDK_MAJOR_VERSION=	7
JDK_MINOR_VERSION=	40
JDK_BUILD_NUMBER=	43
JDK_BUILD_DATE=		26_aug_2013
JDK_SRC_DISTFILE=	${PORTNAME}-${JDK_MAJOR_VERSION}u${JDK_MINOR_VERSION}-fcs-src-b${JDK_BUILD_NUMBER}-${JDK_BUILD_DATE}

# Use our own version of ant to avoid circular dependencies
ANT_VERSION=		1.9.7
ANT_DISTFILE=		apache-ant-${ANT_VERSION}-bin

LIB_DEPENDS+=	libasound.so:audio/alsa-lib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
BUILD_DEPENDS+=	zip:archivers/zip \
		${UNZIP_CMD}:archivers/unzip \
		${LOCALBASE}/include/cups/cups.h:print/cups
RUN_DEPENDS+=	javavm:java/javavmwrapper \
		dejavu>0:x11-fonts/dejavu

DOS2UNIX_FILES=	jdk/src/share/classes/com/sun/org/apache/xml/internal/security/resource/xmlsecurity_en.properties

OPENJDK_OSARCH=	bsd-${ARCH:S/i386/i586/}

NOPRECIOUSMAKEVARS=	yes

ONLY_FOR_ARCHS=	i386 amd64

_MAKE_JOBS=	#
MAKE_ENV+=	JAVA_HOME="" \
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
		JAVACMD=${BOOTSTRAPJDKDIR}/bin/java \
		X11DIR="${LOCALBASE}" \
		LOCALDIR="${LOCALBASE}" \
		COMPILER_WARNINGS_FATAL="false" \
		NO_DOCS="true" \
		SKIP_COMPARE_IMAGES="true" \
		SKIP_FASTDEBUG_BUILD="true" \
		SKIP_DEBUG_BUILD="true" \
		ZIP_DEBUGINFO_FILES=0 \
		ENABLE_FULL_DEBUG_SYMBOLS=0 \
		PTHREAD_LIBS="-lpthread" \
		MILESTONE="fcs" \
		JDK_MICRO_VERSION="0_${PORT_MINOR_VERSION}" \
		BUILD_NUMBER="b${PORT_BUILD_NUMBER}"

MAKE_ENV+=	HOTSPOT_BUILD_JOBS=${MAKE_JOBS_NUMBER}

BOOTSTRAP_JDKS=	${LOCALBASE}/openjdk7 \
		${LOCALBASE}/openjdk6 \
		${LOCALBASE}/bootstrap-openjdk

DEBUG_MAKE_ENV=	ALT_OBJCOPY=${NONEXISTENT}
POLICY_MAKE_ENV=	UNLIMITED_CRYPTO=1
TZUPDATE_RUN_DEPENDS=	java-zoneinfo>0:java/java-zoneinfo

.include <bsd.port.options.mk>

# do we have valid native jdk installed?
.for BJDK in ${BOOTSTRAP_JDKS}
.  if !defined(BOOTSTRAPJDKDIR) && exists(${BJDK}/bin/javac)
BOOTSTRAPJDKDIR=	${BJDK}
.  endif
.endfor

# if no valid jdk found, set dependency
.if !defined(BOOTSTRAPJDKDIR)
BOOTSTRAPJDKDIR?=	${LOCALBASE}/bootstrap-openjdk
BUILD_DEPENDS+=		${BOOTSTRAPJDKDIR}/bin/javac:java/bootstrap-openjdk
.endif

.include <bsd.port.pre.mk>

# GCC is broken with PCH: https://lists.freebsd.org/pipermail/svn-src-all/2015-March/101722.html
.if ${COMPILER_TYPE} == gcc
MAKE_ENV+=	USE_PRECOMPILED_HEADER=0
.endif

.if empty(ICONV_LIB)
MAKE_ENV+=	EXTRA_CFLAGS=-DLIBICONV_PLUG
.endif

post-patch:
	@${REINPLACE_CMD} "s|%%LOCALBASE%%|${LOCALBASE}|" \
		${WRKSRC}/hotspot/src/os/bsd/vm/os_bsd.cpp \
		${WRKSRC}/jdk/src/share/classes/sun/print/PSPrinterJob.java
.if empty(ICONV_LIB)
	@${REINPLACE_CMD} 's| -liconv||' \
		${WRKSRC}/Makefile \
		${WRKSRC}/jdk/make/sun/splashscreen/Makefile \
		${WRKSRC}/jdk/make/java/npt/Makefile \
		${WRKSRC}/jdk/make/java/instrument/Makefile
.endif

.if ${PORT_OPTIONS:MTZUPDATE}
pre-install:
	@# Update time zones
.if !defined(BUILD_JRE)
	@${RM} -r ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image/jre/lib/zi
	@${LN} -s -f ${LOCALBASE}/share/java/zi \
	    ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image/jre/lib
.else
	@${RM} -r ${WRKSRC}/build/${OPENJDK_OSARCH}/j2re-image/lib/zi
	@${LN} -s -f ${LOCALBASE}/share/java/zi \
	    ${WRKSRC}/build/${OPENJDK_OSARCH}/j2re-image/lib
.endif
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${INSTALLDIR}
.if !defined(BUILD_JRE)
	cd ${WRKSRC}/build/${OPENJDK_OSARCH}/j2sdk-image && \
	    ${PAX} -rw . ${STAGEDIR}${INSTALLDIR}
	${INSTALL_DATA} \
	    ${WRKSRC}/build/${OPENJDK_OSARCH}/btjars/compilefontconfig.jar \
	    ${WRKSRC}/build/${OPENJDK_OSARCH}/btjars/javazic.jar \
	    ${STAGEDIR}${INSTALLDIR}/jre/lib/
	${INSTALL_DATA} ${FILESDIR}/cacerts \
	    ${STAGEDIR}${INSTALLDIR}/jre/lib/security/cacerts
.else
	cd ${WRKSRC}/build/${OPENJDK_OSARCH}/j2re-image && \
	    ${PAX} -rw . ${STAGEDIR}${INSTALLDIR}
	${INSTALL_DATA} ${FILESDIR}/cacerts \
	    ${STAGEDIR}${INSTALLDIR}/lib/security/cacerts
.endif
	@${ECHO} "@javavm ${INSTALLDIR}/bin/java" >> ${TMPPLIST}
	@${FIND} -s ${STAGEDIR}${INSTALLDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${INSTALLDIR} -type d -empty | ${SORT} -r | \
		${SED} -e 's,^${STAGEDIR}${PREFIX}/,@dir ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
