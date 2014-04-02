# $FreeBSD$

PORTNAME=	openjdk
PORTVERSION=	${JDK_MAJOR_VERSION}.${PORT_MINOR_VERSION}.${PORT_BUILD_NUMBER:S/^0//}
CATEGORIES=	java devel
MASTER_SITES=	http://download.java.net/openjdk/jdk${JDK_MAJOR_VERSION}/promoted/b${JDK_BUILD_NUMBER}/:jdk \
		https://adopt-openjdk.ci.cloudbees.com/job/jtreg/${JTREG_JENKINS_BUILD}/artifact/:jtreg \
		LOCAL/jkim:jdk,jtreg
PKGNAMESUFFIX=	${JDK_MAJOR_VERSION}
DISTNAME=	${PORTNAME}-${JDK_MAJOR_VERSION}-src-b${JDK_BUILD_NUMBER}-${JDK_BUILD_DATE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:jdk

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java Development Kit ${JDK_MAJOR_VERSION}

LICENSE=	GPLv2

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		${LOCALBASE}/include/cups/cups.h:${PORTSDIR}/print/cups-client \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libgif.so:${PORTSDIR}/graphics/giflib
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/lib/X11/fonts/dejavu:${PORTSDIR}/x11-fonts/dejavu

USES=		compiler:features dos2unix gmake iconv pkgconfig shebangfix zip
USE_AUTOTOOLS=	autoconf
USE_XORG=	x11 xext xi xrender xt xtst

ONLY_FOR_ARCHS=	i386 amd64
WRKSRC=		${WRKDIR}/${PORTNAME}

DOS2UNIX_FILES=	jdk/src/share/classes/com/sun/org/apache/xml/internal/security/resource/xmlsecurity_en.properties
SHEBANG_FILES=	configure

_MAKE_JOBS=	#
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	LANG="C" LC_ALL="C"
MAKE_ENV+=	CLASSPATH="" JAVA_HOME="" LD_LIBRARY_PATH="" MAKEFLAGS=""
MAKE_ENV+=	IGNORE_OLD_CONFIG=true

JDK_BUILDDIR=	${WRKSRC}/build/${JDK_OSARCH}-normal-server-${JDK_BUILD_TYPE}
JDK_IMAGEDIR=	${JDK_BUILDDIR}/images/j2sdk-image
JDK_OSARCH=	bsd-${ARCH:S/i386/x86/:S/amd64/x86_64/}
INSTALLDIR=	${PREFIX}/${PORTNAME}${JDK_MAJOR_VERSION}

NOPRECIOUSMAKEVARS=	yes

JDK_MAJOR_VERSION=	8
JDK_BUILD_NUMBER=	132
JDK_BUILD_DATE=		03_mar_2014
JTREG_VERSION=		4.1
JTREG_BUILD_NUMBER=	b08
JTREG_JENKINS_BUILD=	77
PORT_MINOR_VERSION=	0
PORT_BUILD_NUMBER=	${JDK_BUILD_NUMBER}

CONFIGURE_ARGS=		--with-boot-jdk=${BOOTSTRAPJDKDIR}
CONFIGURE_ARGS+=	--with-build-number="b${PORT_BUILD_NUMBER}"
.if ${PORT_MINOR_VERSION} > 0
CONFIGURE_ARGS+=	--with-update-version=${PORT_MINOR_VERSION}
.endif
CONFIGURE_ARGS+=	--disable-freetype-bundling \
			--disable-zip-debug-info \
			--with-alsa=${LOCALBASE} \
			--with-cacerts-file=${FILESDIR}/cacerts \
			--with-cups=${LOCALBASE} \
			--with-debug-level=${JDK_BUILD_TYPE} \
			--with-freetype=${LOCALBASE} \
			--with-freetype-include=${LOCALBASE}/include/freetype2 \
			--with-giflib=system \
			--with-jobs=${MAKE_JOBS_NUMBER} \
			--with-milestone=fcs \
			--with-zlib=system
CONFIGURE_SCRIPT=	../../configure
CONFIGURE_WRKSRC=	${WRKSRC}/common/autoconf

OPTIONS_DEFINE=		POLICY TEST TZUPDATE
OPTIONS_DEFAULT=	POLICY RELEASE TZUPDATE
OPTIONS_SINGLE=		BUILD
OPTIONS_SINGLE_BUILD=	DEBUG DEBUGFAST RELEASE
BUILD_DESC=		Select OpenJDK build type
DEBUG_DESC=		Build for debugging (without optimizations)
DEBUGFAST_DESC=		Build for debugging (with optimizations)
POLICY_DESC=		Install the Unlimited Strength Policy Files
RELEASE_DESC=		Build for release (default)
TEST_DESC=		Run regression tests
TZUPDATE_DESC=		Update the time zone data

POLICY_CONFIGURE_ENABLE=unlimited-crypto
RELEASE_CONFIGURE_ON=	--disable-debug-symbols
TEST_ALL_TARGET=	test
TEST_CONFIGURE_ON=	--with-jtreg=${WRKDIR}/jtreg
TEST_DISTFILES=		jtreg${JTREG_VERSION}-${JTREG_BUILD_NUMBER}.tar.gz:jtreg
TZUPDATE_RUN_DEPENDS=	${LOCALBASE}/share/java/zi:${PORTSDIR}/java/java-zoneinfo

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
JDK_BUILD_TYPE=	slowdebug
.elif ${PORT_OPTIONS:MDEBUGFAST}
JDK_BUILD_TYPE=	fastdebug
.elif ${PORT_OPTIONS:MRELEASE}
JDK_BUILD_TYPE=	release
.endif

.include <bsd.port.pre.mk>

BOOTSTRAP_JDKS=	${LOCALBASE}/openjdk8 \
		${LOCALBASE}/openjdk7

# do we have valid native jdk installed?
.for BJDK in ${BOOTSTRAP_JDKS}
.  if !defined(BOOTSTRAPJDKDIR) && exists(${BJDK}/bin/javac)
BOOTSTRAPJDKDIR=	${BJDK}
.  endif
.endfor

# if no valid jdk found, set dependency
.if !defined(BOOTSTRAPJDKDIR)
BOOTSTRAPJDKDIR?=	${LOCALBASE}/openjdk7
BUILD_DEPENDS+=		${BOOTSTRAPJDKDIR}/bin/javac:${PORTSDIR}/java/openjdk7
.endif

.if ${COMPILER_TYPE} == clang
MAKE_ENV+=	USE_CLANG=true
.if ${COMPILER_FEATURES:Mlibc++}
CONFIGURE_ENV=	LIBCXX="-lc++"
.endif
.endif

.if empty(ICONV_LIB)
ICONV_CPPFLAGS=	-DLIBICONV_PLUG
.else
ICONV_CPPFLAGS=	-I${LOCALBASE}/include
ICONV_LDFLAGS=	-L${LOCALBASE}/lib ${ICONV_LIB}
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/jdk/src/bsd/classes/java/net \
	    ${WRKSRC}/jdk/src/bsd/classes/sun/nio/ch
	@${MV} -f ${WRKSRC}/jdk/src/macosx/classes/java/net/DefaultInterface.java \
	    ${WRKSRC}/jdk/src/bsd/classes/java/net
	@${MV} -f ${WRKSRC}/jdk/src/macosx/classes/sun/nio/ch/DefaultSelectorProvider.java \
	    ${WRKSRC}/jdk/src/bsd/classes/sun/nio/ch
	@${MV} -f ${WRKSRC}/jdk/src/macosx/classes/sun/nio/ch/KQueue*.java \
	    ${WRKSRC}/jdk/src/solaris/classes/sun/nio/ch
	@${MV} -f ${WRKSRC}/jdk/src/macosx/native/sun/nio/ch/KQueue*.c \
	    ${WRKSRC}/jdk/src/solaris/native/sun/nio/ch
	@${RMDIR} ${WRKSRC}/jdk/src/macosx/classes/java/net \
	    ${WRKSRC}/jdk/src/macosx/native/sun/nio/ch \
	    ${WRKSRC}/jdk/src/macosx/native/sun/nio

post-patch:
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    ${FILESDIR}/bsd.fontconfig.properties.in > \
	    ${WRKSRC}/jdk/src/solaris/classes/sun/awt/fontconfigs/bsd.fontconfig.properties
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    ${WRKSRC}/configure \
	    ${WRKSRC}/hotspot/src/os/bsd/vm/os_bsd.cpp \
	    ${WRKSRC}/jdk/make/lib/SoundLibraries.gmk \
	    ${WRKSRC}/jdk/src/share/classes/com/sun/java/swing/plaf/gtk/Metacity.java \
	    ${WRKSRC}/jdk/src/solaris/bin/java_md_solinux.h \
	    ${WRKSRC}/jdk/src/solaris/classes/sun/nio/fs/BsdFileSystemProvider.java
	@${REINPLACE_CMD} -e 's|%%ICONV_CPPFLAGS%%|${ICONV_CPPFLAGS}|' \
	    -e 's|%%ICONV_LDFLAGS%%|${ICONV_LDFLAGS}|' \
	    ${WRKSRC}/jdk/make/lib/CoreLibraries.gmk \
	    ${WRKSRC}/jdk/make/lib/ServiceabilityLibraries.gmk
	@${CHMOD} 755 ${WRKSRC}/configure

post-build:
	@${JDK_IMAGEDIR}/bin/jar cfe \
	    ${JDK_IMAGEDIR}/jre/lib/compilefontconfig.jar \
	    build.tools.compilefontconfig.CompileFontConfig \
	    -C ${JDK_BUILDDIR}/jdk/btclasses build/tools/compilefontconfig
	@${JDK_IMAGEDIR}/bin/jar cfe \
	    ${JDK_IMAGEDIR}/jre/lib/javazic.jar \
	    build.tools.tzdb.TzdbZoneRulesCompiler \
	    -C ${JDK_BUILDDIR}/jdk/btclasses build/tools/tzdb
.if ${PORT_OPTIONS:MTZUPDATE}
	@# Update time zones
	@${RM} -rf ${JDK_IMAGEDIR}/jre/lib/zi
	@${LN} -sf ${LOCALBASE}/share/java/zi ${JDK_IMAGEDIR}/jre/lib
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${INSTALLDIR}
	@cd ${JDK_IMAGEDIR} && \
	    ${COPYTREE_SHARE} . ${STAGEDIR}${INSTALLDIR} \
	    "-not ( -type d -name bin -prune )"
	@cd ${JDK_IMAGEDIR} && \
	    ${COPYTREE_BIN} "bin jre/bin" ${STAGEDIR}${INSTALLDIR}
	@cd ${JDK_IMAGEDIR} && \
	    ${INSTALL_PROGRAM} jre/lib/jspawnhelper \
	    ${STAGEDIR}${INSTALLDIR}/jre/lib
	@cd ${JDK_IMAGEDIR} && \
	    ${INSTALL_PROGRAM} jre/lib/${ARCH}/jexec \
	    ${STAGEDIR}${INSTALLDIR}/jre/lib/${ARCH}
	@cd ${JDK_IMAGEDIR} && \
	    ${INSTALL_PROGRAM} lib/${ARCH}/jexec \
	    ${STAGEDIR}${INSTALLDIR}/lib/${ARCH}
	@${ECHO} "@unexec ${LOCALBASE}/bin/unregistervm ${INSTALLDIR}/bin/java" >> ${TMPPLIST}
	@${FIND} -s ${STAGEDIR}${INSTALLDIR} -not -type d | ${SORT} | \
	    ${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${INSTALLDIR} -type d | ${SORT} -r | \
	    ${SED} -e 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${ECHO} "@exec ${LOCALBASE}/bin/registervm '${INSTALLDIR}/bin/java # OpenJDK${JDK_MAJOR_VERSION}'" >> ${TMPPLIST}

.include <bsd.port.post.mk>
