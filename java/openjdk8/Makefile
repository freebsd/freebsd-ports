PORTNAME=	openjdk
PORTVERSION=	${JDK_MAJOR_VERSION}.${JDK_UPDATE_VERSION}.${JDK_BUILD_NUMBER}.${BSD_JDK_VERSION}
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	LOCAL/jkim:jtreg
PKGNAMESUFFIX?=	${JDK_MAJOR_VERSION}

MAINTAINER=	java@FreeBSD.org
COMMENT?=	Java Development Kit ${JDK_MAJOR_VERSION}
WWW=		https://openjdk.java.net/

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le

BUILD_DEPENDS=	zip:archivers/zip \
		autoconf>0:devel/autoconf \
		${LOCALBASE}/include/cups/cups.h:print/cups \
		bash:shells/bash
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libinotify.so:devel/libinotify
RUN_DEPENDS=	javavm:java/javavmwrapper \
		dejavu>0:x11-fonts/dejavu

USES=		compiler:features cpe gmake iconv pkgconfig

CPE_VENDOR=	oracle

USE_GITHUB=	yes
GH_ACCOUNT=	battleblow
GH_PROJECT=	jdk8u
GH_TAGNAME=	jdk${JDK_MAJOR_VERSION}u${JDK_UPDATE_VERSION}-b${JDK_BUILD_NUMBER}.${BSD_JDK_VERSION}

USE_LDCONFIG=	${INSTALLDIR}/lib/${ARCH}
_MAKE_JOBS=	#
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	CLASSPATH="" JAVA_HOME="" LD_LIBRARY_PATH=""
MAKE_ENV+=	IGNORE_OLD_CONFIG=true
MAKE_ENV+=	COMPILER_WARNINGS_FATAL="false"

JDK_BUILDDIR=	${WRKSRC}/build/${JDK_OSARCH}-normal-${JDK_BUILD_JVM}-${JDK_BUILD_TYPE}
.if !defined(BUILD_JRE)
JDK_IMAGEDIR=	${JDK_BUILDDIR}/images/j2sdk-image
JRE_IMAGEDIR=	${JDK_BUILDDIR}/images/j2sdk-image/jre
.else
JRE_IMAGEDIR=	${JDK_BUILDDIR}/images/j2re-image
.endif
JDK_JVMDIR=	lib/${ARCH:C/armv.*/arm/:S/powerpc/ppc/}
JDK_OSARCH=	bsd-${ARCH:S/amd64/x86_64/:C/armv.*/arm/:S/i386/x86/:S/powerpc/ppc/}
INSTALLDIR=	${PREFIX}/${PKGBASE}

NOPRECIOUSMAKEVARS=	yes

JDK_MAJOR_VERSION=	8
JDK_UPDATE_VERSION=	452
JDK_BUILD_NUMBER=	09
BSD_JDK_VERSION=	1
JTREG_VERSION=		4.1
JTREG_BUILD_NUMBER=	b08

JDK_BUG_URL=		https://bugs.freebsd.org/bugzilla/enter_bug.cgi?product=Ports%20%26%20Packages&component=Individual%20Port(s)&short_desc=java/${PORTNAME}${JDK_MAJOR_VERSION}%3A%20

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-boot-jdk=${BOOTSTRAPJDKDIR}
CONFIGURE_ARGS+=	--with-build-number="b${JDK_BUILD_NUMBER}"
.if ${JDK_UPDATE_VERSION} > 0
CONFIGURE_ARGS+=	--with-update-version=${JDK_UPDATE_VERSION}
.endif
CONFIGURE_ARGS+=	--with-vendor-name="OpenJDK BSD Porting Team" \
			--with-vendor-url="https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/" \
			--with-vendor-bug-url="${JDK_BUG_URL}" \
			--with-vendor-vm-bug-url="${JDK_BUG_URL}"
.if defined(NO_CCACHE)
CONFIGURE_ARGS+=	--disable-ccache
.endif
CONFIGURE_ARGS+=	--disable-freetype-bundling \
			--disable-zip-debug-info \
			--with-cups=${LOCALBASE} \
			--with-debug-level=${JDK_BUILD_TYPE} \
			--with-freetype=${LOCALBASE} \
			--with-freetype-include=${LOCALBASE}/include/freetype2 \
			--with-jobs=${MAKE_JOBS_NUMBER} \
			--with-jvm-variants=${JDK_BUILD_JVM} \
			--with-milestone=fcs \
			--with-package-path=${LOCALBASE} \
			--with-zlib=system \
			--with-extra-ldflags="-Wl,--undefined-version"
CONFIGURE_SCRIPT=	../../configure
CONFIGURE_WRKSRC=	${WRKSRC}/common/autoconf

OPTIONS_DEFINE=		ALSA POLICY TZUPDATE X11 FONTCONFIG
OPTIONS_DEFINE_armv6=	FPUHACK
OPTIONS_DEFINE_armv7=	FPUHACK
OPTIONS_DEFAULT=	ALSA POLICY TZUPDATE X11
OPTIONS_DEFAULT_armv6=	FPUHACK
OPTIONS_DEFAULT_armv7=	FPUHACK
FPUHACK_DESC=		Hack denormalized numbers in flush-to-zero mode
POLICY_DESC=		Install the Unlimited Strength Policy Files
TZUPDATE_DESC=		Update the time zone data

ALSA_CONFIGURE_ENV_OFF=	ALSA_NOT_NEEDED=yes
ALSA_CONFIGURE_ON=	--with-alsa=${LOCALBASE}
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
FPUHACK_EXTRA_PATCHES=	${PATCHDIR}/fpuhack.patch
POLICY_CONFIGURE_ENABLE=	unlimited-crypto
TZUPDATE_RUN_DEPENDS=	java-zoneinfo>0:java/java-zoneinfo
X11_BUILD_DEPENDS_OFF=	${LOCALBASE}/include/X11/Xlib.h:x11/libX11 \
			${LOCALBASE}/include/X11/extensions/Xdbe.h:x11/libXext \
			${LOCALBASE}/include/X11/extensions/Xrender.h:x11/libXrender \
			${LOCALBASE}/include/X11/Intrinsic.h:x11-toolkits/libXt
X11_CONFIGURE_OFF=	--disable-headful
X11_CONFIGURE_ON=	--with-giflib=system \
			--x-includes=${LOCALBASE}/include \
			--x-libraries=${LOCALBASE}/lib
X11_LIB_DEPENDS=	libgif.so:graphics/giflib
X11_MAKE_ENV_OFF=	BUILD_HEADLESS_ONLY=1 \
			MAKEFLAGS=X_CFLAGS="-I${LOCALBASE}/include"
X11_USES=		xorg
X11_USE=		XORG=x11,xext,xi,xrender,xt,xtst
FONTCONFIG_EXTRA_PATCHES=	${PATCHDIR}/fontconfig.patch
FONTCONFIG_IMPLIES=	X11

JAVAVMS_COMMENT=	OpenJDK${JDK_MAJOR_VERSION}

.if !defined(BUILD_JRE)
OPTIONS_DEFINE+=	TEST
OPTIONS_DEFAULT+=	RELEASE
OPTIONS_SINGLE=		BUILD
OPTIONS_SINGLE_BUILD=	DEBUG DEBUGFAST RELEASE
BUILD_DESC=		Select OpenJDK build type
DEBUG_DESC=		Build for debugging (without optimizations)
DEBUGFAST_DESC=		Build for debugging (with optimizations)
RELEASE_DESC=		Build for release (default)
TEST_DESC=		Run regression tests

DEBUG_VARS=		JDK_BUILD_TYPE=slowdebug
DEBUGFAST_VARS=		JDK_BUILD_TYPE=fastdebug
RELEASE_BUILD_DEPENDS_OFF=	${LOCALBASE}/bin/objcopy:devel/binutils
RELEASE_CONFIGURE_ON=	--disable-debug-symbols
RELEASE_VARS=		JDK_BUILD_TYPE=release
RELEASE_VARS_OFF=	OBJCOPY=${LOCALBASE}/bin/objcopy
TEST_ALL_TARGET=	test
TEST_ALL_TARGET_OFF=	images
TEST_CONFIGURE_ON=	--with-jtreg=${WRKDIR}/jtreg
TEST_DISTFILES=		jtreg${JTREG_VERSION}-${JTREG_BUILD_NUMBER}${EXTRACT_SUFX}:jtreg
.else
ALL_TARGET=		images
CONFIGURE_ARGS+=	--disable-debug-symbols
JAVAVMS_COMMENT+=	JRE
JDK_BUILD_TYPE=		release
.endif

# XXX configure script rejects CC/CPP/CXX with absolute paths.
.for t in CC CPP CXX
.if defined(${t}) && ${${t}:M/*}
BUILD_${t}=	${${t}:C|.*/||g}
CONFIGURE_ENV+=	${t}="${BUILD_${t}}"
TOOLS_DIR+=	${${t}:S|/${BUILD_${t}}$||}
.endif
.endfor
.if defined(TOOLS_DIR)
CONFIGURE_ARGS+=	--with-tools-dir="${TOOLS_DIR:u:S/ /:/g}"
.endif

.include <bsd.port.pre.mk>

BOOTSTRAP_JDKS=	${LOCALBASE}/openjdk8 \
		${LOCALBASE}/openjdk7 \
		${LOCALBASE}/bootstrap-openjdk8

# do we have valid native jdk installed?
.for BJDK in ${BOOTSTRAP_JDKS}
.  if !defined(BOOTSTRAPJDKDIR) && exists(${BJDK}/bin/javac)
BOOTSTRAPJDKDIR=	${BJDK}
.  endif
.endfor

# if no valid jdk found, set dependency
.if !defined(BOOTSTRAPJDKDIR)
BOOTSTRAPJDKDIR?=	${LOCALBASE}/bootstrap-openjdk8
BUILD_DEPENDS+=		${BOOTSTRAPJDKDIR}/bin/javac:java/bootstrap-openjdk8
.endif

.if ${ARCH} == armv6 || ${ARCH} == armv7 || ${ARCH} == i386 || ${ARCH} == powerpc
# XXX We must limit max heap size for 32-bit targets.
CONFIGURE_ARGS+=	--with-boot-jdk-jvmargs="-Xmx768m"
MAKE_ENV+=	JAVADOC_CMD_MEM="-Xmx768m"
.endif

.if ${ARCH} == i386
CONFIGURE_ARGS+=	--disable-jfr
# Fix the build for i386 when WITH_LLD_IS_LD is set
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=225741
MAKE_ENV+=	LFLAGS="-Wl,-z,notext"
.endif

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH:Mpowerpc64*}
JDK_BUILD_JVM=	server
.else
JDK_BUILD_JVM=	zero
LIB_DEPENDS+=	libffi.so:devel/libffi
.endif

.if ${COMPILER_TYPE} == clang
MAKE_ENV+=	USE_CLANG=true
CONFIGURE_ENV+=	LIBCXX="-lc++"
# clang 16 defaults to C++17, which no longer allows the 'register' keyword.
# There is an upstream commit that removes all the individual 'register'
# keywords, but it has not yet been backported to OpenJDK 8.
# NOTE: passing this option via --with-extra-cflags does not work.
CFLAGS+=		-Dregister=
.endif

# GCC is broken with PCH: https://lists.freebsd.org/pipermail/svn-src-all/2015-March/101722.html
.if ${COMPILER_TYPE} == gcc
CONFIGURE_ARGS+=	--with-toolchain-type=gcc
.if ${ARCH} == "powerpc64"
MAKE_ARGS+=	USE_PRECOMPILED_HEADER=1
.else
MAKE_ARGS+=	USE_PRECOMPILED_HEADER=0
.endif
.endif

.if ${ARCH:Mpowerpc64*}
MAKE_ARGS+=	USE_PRECOMPILED_HEADER=0
.endif

.if empty(ICONV_LIB)
ICONV_CPPFLAGS=	-DLIBICONV_PLUG
.else
ICONV_CPPFLAGS=	-I${LOCALBASE}/include
ICONV_LDFLAGS=	-L${LOCALBASE}/lib ${ICONV_LIB}
.endif

post-extract-TEST-on:
	@${LN} -sf ${WRKDIR}/jtreg/linux/bin ${WRKDIR}/jtreg/

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    ${FILESDIR}/bsd.fontconfig.properties.in > \
	    ${WRKSRC}/jdk/src/solaris/classes/sun/awt/fontconfigs/bsd.fontconfig.properties
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    -e 's|%%OBJCOPY%%|${OBJCOPY}|' \
	    ${WRKSRC}/configure \
	    ${WRKSRC}/common/autoconf/toolchain.m4 \
	    ${WRKSRC}/jdk/make/lib/Awt2dLibraries.gmk \
	    ${WRKSRC}/jdk/make/lib/NioLibraries.gmk \
	    ${WRKSRC}/jdk/src/share/classes/com/sun/java/swing/plaf/gtk/Metacity.java \
	    ${WRKSRC}/jdk/src/share/classes/sun/print/PSPrinterJob.java \
	    ${WRKSRC}/jdk/src/solaris/classes/sun/nio/fs/BsdFileSystemProvider.java
	@${REINPLACE_CMD} -e 's|%%ICONV_CPPFLAGS%%|${ICONV_CPPFLAGS}|' \
	    -e 's|%%ICONV_LDFLAGS%%|${ICONV_LDFLAGS}|' \
	    ${WRKSRC}/jdk/make/lib/Awt2dLibraries.gmk \
	    ${WRKSRC}/jdk/make/lib/CoreLibraries.gmk \
	    ${WRKSRC}/jdk/make/lib/ServiceabilityLibraries.gmk
.if defined(BUILD_JRE)
	@${REINPLACE_CMD} -e 's|-f Images.gmk$$|& jre-image|' \
	    -e 's|-f Images.gmk overlay-images$$|-f Images.gmk jre-overlay-image|' \
	    ${WRKSRC}/jdk/make/BuildJdk.gmk
.endif
	@${CHMOD} 755 ${WRKSRC}/configure

post-patch-ALSA-off:
	@${REINPLACE_CMD} '/EXTRA_SOUND_JNI_LIBS += jsoundalsa/d' \
	    ${WRKSRC}/jdk/make/lib/SoundLibraries.gmk

post-build:
.if !defined(BUILD_JRE)
	@${BOOTSTRAPJDKDIR}/bin/jar cfe \
	    ${JRE_IMAGEDIR}/lib/compilefontconfig.jar \
	    build.tools.compilefontconfig.CompileFontConfig \
	    -C ${JDK_BUILDDIR}/jdk/btclasses build/tools/compilefontconfig
	@${BOOTSTRAPJDKDIR}/bin/jar cfe \
	    ${JRE_IMAGEDIR}/lib/javazic.jar \
	    build.tools.tzdb.TzdbZoneRulesCompiler \
	    -C ${JDK_BUILDDIR}/jdk/btclasses build/tools/tzdb
.endif
.if defined(OPENJDK_SYMLINK_CACERTS)
	@${RM} ${JRE_IMAGEDIR}/lib/security/cacerts
	@${LN} -sf ${OPENJDK_SYMLINK_CACERTS} ${JRE_IMAGEDIR}/lib/security/cacerts
.endif

post-build-TZUPDATE-on:
	@${RM} -r ${JRE_IMAGEDIR}/lib/zi
	@${LN} -sf ${LOCALBASE}/share/java/zi ${JRE_IMAGEDIR}/lib

do-install:
	@${MKDIR} ${STAGEDIR}${INSTALLDIR}
.if !defined(BUILD_JRE)
	@cd ${JDK_IMAGEDIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${INSTALLDIR}
	@cd ${STAGEDIR}${INSTALLDIR} && \
	${FIND} bin jre/bin -type f -exec ${CHMOD} ${BINMODE} {} \; && \
	${CHMOD} ${BINMODE} jre/${JDK_JVMDIR}/jexec \
	    jre/${JDK_JVMDIR}/jspawnhelper ${JDK_JVMDIR}/jexec
	@${ECHO_CMD} "@dir ${INSTALLDIR}/jre/lib/applet" >> ${TMPPLIST}
.else
	@cd ${JRE_IMAGEDIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${INSTALLDIR}
	@cd ${STAGEDIR}${INSTALLDIR} && \
	${FIND} bin -type f -exec ${CHMOD} ${BINMODE} {} \; && \
	${CHMOD} ${BINMODE} ${JDK_JVMDIR}/jexec ${JDK_JVMDIR}/jspawnhelper
	@${ECHO_CMD} "@dir ${INSTALLDIR}/lib/applet" >> ${TMPPLIST}
.endif
	@${ECHO_CMD} "@javavm ${INSTALLDIR}/bin/java" >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${INSTALLDIR} -not -type d | ${SORT} | \
	    ${SED} -e 's|^${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}

.include <bsd.port.post.mk>
