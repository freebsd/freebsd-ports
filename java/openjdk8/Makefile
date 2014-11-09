# $FreeBSD$

PORTNAME=	openjdk
PORTVERSION=	${JDK_MAJOR_VERSION}.${JDK_UPDATE_VERSION}.${JDK_BUILD_NUMBER:S/^0//}
CATEGORIES=	java devel
MASTER_SITES=	http://download.java.net/openjdk/jdk${JDK_MAJOR_VERSION}/promoted/b${DIST_BUILD_NUMBER}/:jdk \
		https://adopt-openjdk.ci.cloudbees.com/job/jtreg/${JTREG_JENKINS_BUILD}/artifact/:jtreg \
		LOCAL/jkim:jdk,jtreg
PKGNAMESUFFIX?=	${JDK_MAJOR_VERSION}
DISTNAME=	${PORTNAME}-${JDK_MAJOR_VERSION}-src-b${DIST_BUILD_NUMBER}-03_mar_2014
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:jdk

MAINTAINER=	java@FreeBSD.org
COMMENT?=	Java Development Kit ${JDK_MAJOR_VERSION}

LICENSE=	GPLv2

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		${LOCALBASE}/include/cups/cups.h:${PORTSDIR}/print/cups-client \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libgif.so:${PORTSDIR}/graphics/giflib
RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper \
		${LOCALBASE}/lib/X11/fonts/dejavu:${PORTSDIR}/x11-fonts/dejavu

USES=		compiler:features dos2unix gmake iconv pkgconfig shebangfix zip
USE_AUTOTOOLS=	autoconf
USE_XORG=	x11 xext xi xrender xt xtst

.if !exists(/usr/bin/unzip)
BUILD_DEPENDS+=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip
.endif

ONLY_FOR_ARCHS=	i386 amd64
WRKSRC=		${WRKDIR}/${PORTNAME}

DOS2UNIX_FILES=	jdk/src/share/classes/com/sun/org/apache/xml/internal/security/resource/xmlsecurity_en.properties \
		jdk/src/bsd/doc/man/java.1 \
		jdk/src/bsd/doc/man/javac.1 \
		jdk/src/bsd/doc/man/javap.1 \
		jdk/src/linux/doc/man/java.1 \
		jdk/src/linux/doc/man/javac.1 \
		jdk/src/linux/doc/man/javap.1 \
		jdk/src/solaris/doc/sun/man/man1/java.1 \
		jdk/src/solaris/doc/sun/man/man1/javac.1 \
		jdk/src/solaris/doc/sun/man/man1/javap.1 \
		nashorn/test/script/jfx.js
SHEBANG_FILES=	configure

_MAKE_JOBS=	#
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	LANG="C" LC_ALL="C"
MAKE_ENV+=	CLASSPATH="" JAVA_HOME="" LD_LIBRARY_PATH="" MAKEFLAGS=""
MAKE_ENV+=	IGNORE_OLD_CONFIG=true

JDK_BUILDDIR=	${WRKSRC}/build/${JDK_OSARCH}-normal-server-${JDK_BUILD_TYPE}
.if !defined(BUILD_JRE)
JDK_IMAGEDIR=	${JDK_BUILDDIR}/images/j2sdk-image
JRE_IMAGEDIR=	${JDK_BUILDDIR}/images/j2sdk-image/jre
.else
JRE_IMAGEDIR=	${JDK_BUILDDIR}/images/j2re-image
.endif
JDK_OSARCH=	bsd-${ARCH:S/i386/x86/:S/amd64/x86_64/}
INSTALLDIR=	${PREFIX}/${PKGBASE}

NO_CCACHE=		yes
NOPRECIOUSMAKEVARS=	yes

JDK_MAJOR_VERSION=	8
JDK_UPDATE_VERSION=	25
JDK_BUILD_NUMBER=	17
DIST_BUILD_NUMBER=	132
JTREG_VERSION=		4.1
JTREG_BUILD_NUMBER=	b08
JTREG_JENKINS_BUILD=	77

CONFIGURE_ARGS=		--with-boot-jdk=${BOOTSTRAPJDKDIR}
CONFIGURE_ARGS+=	--with-build-number="b${JDK_BUILD_NUMBER}"
.if ${JDK_UPDATE_VERSION} > 0
CONFIGURE_ARGS+=	--with-update-version=${JDK_UPDATE_VERSION}
.endif
CONFIGURE_ARGS+=	--disable-ccache \
			--disable-freetype-bundling \
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

OPTIONS_DEFINE=		POLICY TZUPDATE
OPTIONS_DEFAULT=	POLICY TZUPDATE
POLICY_DESC=		Install the Unlimited Strength Policy Files
TZUPDATE_DESC=		Update the time zone data

POLICY_CONFIGURE_ENABLE=unlimited-crypto
TZUPDATE_RUN_DEPENDS=	${LOCALBASE}/share/java/zi:${PORTSDIR}/java/java-zoneinfo

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

RELEASE_CONFIGURE_ON=	--disable-debug-symbols
TEST_ALL_TARGET=	test
TEST_CONFIGURE_ON=	--with-jtreg=${WRKDIR}/jtreg
TEST_DISTFILES=		jtreg${JTREG_VERSION}-${JTREG_BUILD_NUMBER}.tar.gz:jtreg
.else
CONFIGURE_ARGS+=	--disable-debug-symbols
JAVAVMS_COMMENT+=	JRE
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
JDK_BUILD_TYPE=	slowdebug
.elif ${PORT_OPTIONS:MDEBUGFAST}
JDK_BUILD_TYPE=	fastdebug
.else
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
	@${CP} ${FILESDIR}/jdk-test-javax-imageio-plugins-jpeg-truncated.jpg \
	    ${WRKSRC}/jdk/test/javax/imageio/plugins/jpeg/truncated.jpg
	@${CP} ${FILESDIR}/nashorn-test-script-jfx-flyingimage-golden-bsd.png \
	    ${WRKSRC}/nashorn/test/script/jfx/flyingimage/golden/bsd.png
	@${CP} ${FILESDIR}/nashorn-test-script-jfx-kaleidoscope-golden-bsd.png \
	    ${WRKSRC}/nashorn/test/script/jfx/kaleidoscope/golden/bsd.png
	@${CP} ${FILESDIR}/nashorn-test-script-jfx-spread-golden-bsd.png \
	    ${WRKSRC}/nashorn/test/script/jfx/spread/golden/bsd.png

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${RMDIR} ${WRKSRC}/jdk/src/macosx/classes/java/net \
	    ${WRKSRC}/jdk/src/macosx/native/sun/nio/ch \
	    ${WRKSRC}/jdk/src/macosx/native/sun/nio
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    ${FILESDIR}/bsd.fontconfig.properties.in > \
	    ${WRKSRC}/jdk/src/solaris/classes/sun/awt/fontconfigs/bsd.fontconfig.properties
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    ${WRKSRC}/common/autoconf/toolchain.m4 \
	    ${WRKSRC}/configure \
	    ${WRKSRC}/jdk/src/share/classes/com/sun/java/swing/plaf/gtk/Metacity.java \
	    ${WRKSRC}/jdk/src/share/classes/sun/print/PSPrinterJob.java \
	    ${WRKSRC}/jdk/src/solaris/classes/sun/nio/fs/BsdFileSystemProvider.java
	@${REINPLACE_CMD} -e 's|/usr/local/java/classes|${LOCALBASE}/share/java/classes|' \
	    ${WRKSRC}/jdk/src/bsd/doc/man/*.1
	@${REINPLACE_CMD} -e 's|%%ICONV_CPPFLAGS%%|${ICONV_CPPFLAGS}|' \
	    -e 's|%%ICONV_LDFLAGS%%|${ICONV_LDFLAGS}|' \
	    ${WRKSRC}/jdk/make/lib/Awt2dLibraries.gmk \
	    ${WRKSRC}/jdk/make/lib/CoreLibraries.gmk \
	    ${WRKSRC}/jdk/make/lib/ServiceabilityLibraries.gmk
	@${CHMOD} 755 ${WRKSRC}/configure

post-build:
.if !defined(BUILD_JRE)
	@${JDK_IMAGEDIR}/bin/jar cfe \
	    ${JRE_IMAGEDIR}/lib/compilefontconfig.jar \
	    build.tools.compilefontconfig.CompileFontConfig \
	    -C ${JDK_BUILDDIR}/jdk/btclasses build/tools/compilefontconfig
	@${JDK_IMAGEDIR}/bin/jar cfe \
	    ${JRE_IMAGEDIR}/lib/javazic.jar \
	    build.tools.tzdb.TzdbZoneRulesCompiler \
	    -C ${JDK_BUILDDIR}/jdk/btclasses build/tools/tzdb
.endif
.if ${PORT_OPTIONS:MTZUPDATE}
	@# Update time zones
	@${RM} -rf ${JRE_IMAGEDIR}/lib/zi
	@${LN} -sf ${LOCALBASE}/share/java/zi ${JRE_IMAGEDIR}/lib
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${INSTALLDIR}
.if !defined(BUILD_JRE)
	@cd ${JDK_IMAGEDIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${INSTALLDIR}
	@cd ${STAGEDIR}${INSTALLDIR} && \
	    ${FIND} bin jre/bin -type f -exec ${CHMOD} ${BINMODE} {} \; && \
	    ${CHMOD} ${BINMODE} jre/lib/${ARCH}/jexec \
	    jre/lib/${ARCH}/jspawnhelper lib/${ARCH}/jexec
.else
	@cd ${JRE_IMAGEDIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${INSTALLDIR}
	@cd ${STAGEDIR}${INSTALLDIR} && \
	    ${FIND} bin -type f -exec ${CHMOD} ${BINMODE} {} \; && \
	    ${CHMOD} ${BINMODE} lib/${ARCH}/jexec lib/${ARCH}/jspawnhelper
.endif
	@${ECHO} "@unexec ${LOCALBASE}/bin/unregistervm ${INSTALLDIR}/bin/java" >> ${TMPPLIST}
	@${FIND} -s ${STAGEDIR}${INSTALLDIR} -not -type d | ${SORT} | \
	    ${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	@${ECHO} "@exec ${LOCALBASE}/bin/registervm '${INSTALLDIR}/bin/java # ${JAVAVMS_COMMENT}'" >> ${TMPPLIST}

.include <bsd.port.post.mk>
