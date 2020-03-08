# Created by: Greg Lewis <glewis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openjdk
PORTVERSION=	${JDK_MAJOR_VERSION}.${JDK_UPDATE_VERSION}.${JDK_BUILD_NUMBER}.${BSD_JDK_VERSION}
PORTEPOCH=	1
CATEGORIES=	java devel
MASTER_SITES=	APACHE/ant/binaries/:ant
DISTFILES=	${ANT_DISTFILE}${EXTRACT_SUFX}:ant

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Java Development Kit 7

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	battleblow
GH_PROJECT=	jdk7u
GH_TAGNAME=	jdk${JDK_MAJOR_VERSION}u${JDK_UPDATE_VERSION}-b${JDK_BUILD_NUMBER}.${BSD_JDK_VERSION}

USES=		compiler dos2unix iconv gmake
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

JDK_MAJOR_VERSION=	7
JDK_UPDATE_VERSION=	251
JDK_BUILD_NUMBER=	02
BSD_JDK_VERSION=	1

# Use our own version of ant because
# a) this allows us to avoid circular dependencies
# b) ant 10.x requires jdk 8+
ANT_VERSION=		1.9.14
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
		PTHREAD_LIBS="-pthread" \
		MILESTONE="fcs" \
		JDK_MICRO_VERSION="0_${JDK_UPDATE_VERSION}" \
		BUILD_NUMBER="b${PORT_BUILD_NUMBER}"

MAKE_ENV+=	HOTSPOT_BUILD_JOBS=${MAKE_JOBS_NUMBER}

BOOTSTRAP_JDKS=	${LOCALBASE}/openjdk7 \
		${LOCALBASE}/bootstrap-openjdk6

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
BOOTSTRAPJDKDIR?=	${LOCALBASE}/bootstrap-openjdk6
BUILD_DEPENDS+=		${BOOTSTRAPJDKDIR}/bin/javac:java/bootstrap-openjdk6
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
# Fix the build for i386 when WITH_LLD_IS_LD is set
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225741
MAKE_ENV+=	LFLAGS="-Wl,-z,notext"
.endif

# GCC is broken with PCH: https://lists.freebsd.org/pipermail/svn-src-all/2015-March/101722.html
.if ${COMPILER_TYPE} == gcc
MAKE_ENV+=	USE_PRECOMPILED_HEADER=0
.endif

.if empty(ICONV_LIB)
ICONV_CPPFLAGS= -DLIBICONV_PLUG
.else
ICONV_CPPFLAGS= -I${LOCALBASE}/include
ICONV_LDFLAGS=  -L${LOCALBASE}/lib ${ICONV_LIB}
.endif

post-patch:
	@${REINPLACE_CMD} "s|%%LOCALBASE%%|${LOCALBASE}|" \
		${WRKSRC}/hotspot/src/os/bsd/vm/os_bsd.cpp \
		${WRKSRC}/jdk/src/share/classes/com/sun/java/swing/plaf/gtk/Metacity.java
	@${REINPLACE_CMD} -e 's|%%ICONV_CPPFLAGS%%|${ICONV_CPPFLAGS}|' \
		-e 's|%%ICONV_LDFLAGS%%|${ICONV_LDFLAGS}|' \
		${WRKSRC}/jdk/make/sun/splashscreen/Makefile \
		${WRKSRC}/jdk/make/java/npt/Makefile \
		${WRKSRC}/jdk/make/java/instrument/Makefile

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
