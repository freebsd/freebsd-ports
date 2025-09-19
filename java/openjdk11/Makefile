PORTNAME=	openjdk
DISTVERSIONPREFIX=	jdk-
DISTVERSION=	${JDK_MAJOR_VERSION}.${JDK_MINOR_VERSION}.${JDK_PATCH_VERSION}+${JDK_BUILD_NUMBER}-${BSD_JDK_VERSION}
PORTREVISION=	2
CATEGORIES=	java devel
PKGNAMESUFFIX?=	${JDK_MAJOR_VERSION}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/

MAINTAINER=	java@FreeBSD.org
COMMENT?=	Java Development Kit ${JDK_MAJOR_VERSION}
WWW=		https://openjdk.java.net/

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 powerpc powerpc64 powerpc64le

BUILD_DEPENDS=	zip:archivers/zip \
		autoconf>0:devel/autoconf \
		bash:shells/bash \
		gsed:textproc/gsed
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgif.so:graphics/giflib \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png
RUN_DEPENDS=	javavm:java/javavmwrapper \
		xorg-fonts-truetype>0:x11-fonts/xorg-fonts-truetype

USES=		compiler:features cpe gmake iconv jpeg pkgconfig xorg
USE_XORG=	x11 xext xi xrandr xrender xt xtst
USE_LDCONFIG=	${INSTALLDIR}/lib/server

CPE_VENDOR=	oracle

USE_GITHUB=	yes
GH_ACCOUNT=	battleblow
GH_PROJECT=	jdk11u

NO_CCACHE=	yes

# Suppress passing -j to do-build target via Mk/bsd.port.mk
# In the JDK build the number of parallel jobs is passed in via configure --with-num-cores=N
_MAKE_JOBS=	#
MAKE_ENV=	LANG="C" \
		LC_ALL="C" \
		CLASSPATH="" \
		JAVA_HOME="" \
		LD_LIBRARY_PATH="" \
		CC=${CC} \
		CXX=${CXX} \
		CPP=${CPP} \
		LOG=cmdlines \
		MAKEFLAGS=""

JDK_OSARCH=	bsd-${ARCH:S/amd64/x86_64/:C/armv.*/arm/:S/i386/x86/:S/powerpc/ppc/}
JDK_BUILDDIR=	${WRKSRC}/build/${JDK_OSARCH}-normal-${JDK_BUILD_JVM}-${JDK_BUILD_TYPE}
.if defined(BUILD_JRE)
JDK_IMAGEDIR=	${JDK_BUILDDIR}/images/jre
.else
JDK_IMAGEDIR=	${JDK_BUILDDIR}/images/jdk
.endif
INSTALLDIR=	${PREFIX}/${PKGBASE}

NOPRECIOUSMAKEVARS=	yes

JDK_MAJOR_VERSION=	11
JDK_MINOR_VERSION=	0
JDK_PATCH_VERSION=	27
JDK_BUILD_NUMBER=	6
BSD_JDK_VERSION=	1

JDK_BUG_URL=	https://bugs.freebsd.org/bugzilla/enter_bug.cgi?product=Ports%20%26%20Packages&component=Individual%20Port(s)&short_desc=java/${PORTNAME}${JDK_MAJOR_VERSION}%3A%20

OPTIONS_DEFINE=		CUPS
OPTIONS_DEFAULT=	CUPS

CUPS_CONFIGURE_ON=	--with-cups=${LOCALBASE}
CUPS_CONFIGURE_OFF=	--with-cups-include=${WRKDIR}/cups-${CUPS_INC_VER}
CUPS_BUILD_DEPENDS=	${LOCALBASE}/include/cups/cups.h:print/cups
CUPS_INC_VER=		2.4.2
CUPS_DISTFILES_OFF=	OpenPrinting-cups-v${CUPS_INC_VER}_GH0.tar.gz:cups

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC=${CC} \
		CXX=${CXX} \
		CPP=${CPP} \
		ac_cv_path_SED=${LOCALBASE}/bin/gsed
CONFIGURE_ARGS=	--with-boot-jdk=${BOOTSTRAPJDKDIR} \
		--disable-ccache \
		--disable-javac-server \
		--disable-hotspot-gtest \
		--with-jvm-features=shenandoahgc \
		--with-alsa=${LOCALBASE} \
		--with-extra-cflags="${CFLAGS}" \
		--with-extra-cxxflags="${CXXFLAGS}" \
		--with-extra-ldflags="${LDFLAGS}" \
		--with-fontconfig=${LOCALBASE} \
		--with-freetype=system \
		--with-freetype-include=${LOCALBASE}/include/freetype2 \
		--with-freetype-lib=${LOCALBASE}/lib \
		--with-libjpeg=system \
		--with-giflib=system \
		--with-giflib-include=${LOCALBASE}/include \
		--with-giflib-lib=${LOCALBASE}/lib \
		--with-libpng=system \
		--with-num-cores=${MAKE_JOBS_NUMBER} \
		--with-zlib=system \
		--with-lcms=system \
		--x-includes=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib \
		--with-version-string=${JDK_MAJOR_VERSION}.${JDK_MINOR_VERSION}.${JDK_PATCH_VERSION}+${JDK_BUILD_NUMBER}-${BSD_JDK_VERSION} \
		--with-native-debug-symbols=none \
		--with-debug-level=release \
		--with-vendor-name="OpenJDK BSD Porting Team" \
		--with-vendor-url="https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/" \
		--with-vendor-bug-url="${JDK_BUG_URL}" \
		--with-vendor-vm-bug-url="${JDK_BUG_URL}"

JAVAVMS_COMMENT=	OpenJDK${JDK_MAJOR_VERSION}

.if defined(BUILD_JRE)
ALL_TARGET=		legacy-images
.else
ALL_TARGET=		images
.endif
JDK_BUILD_TYPE=		release

.include <bsd.port.pre.mk>

# portsfallout.com shows flapping builds on 13.5 and 14.2
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1403000
MAKE_JOBS_UNSAFE=	yes
.endif

.if !${PORT_OPTIONS:MCUPS}
MASTER_SITES+=	https://codeload.github.com/OpenPrinting/cups/tar.gz/v${CUPS_INC_VER}?dummy=/:cups
.endif

BOOTSTRAP_JDKS=	${LOCALBASE}/openjdk11 \
		${LOCALBASE}/bootstrap-openjdk11

# do we have valid native jdk installed?
.for BJDK in ${BOOTSTRAP_JDKS}
.  if !defined(BOOTSTRAPJDKDIR) && exists(${BJDK}/bin/javac)
BOOTSTRAPJDKDIR=	${BJDK}
.  endif
.endfor

# if no valid jdk found, set dependency
.if !defined(BOOTSTRAPJDKDIR)
BOOTSTRAPJDKDIR?=	${LOCALBASE}/bootstrap-openjdk11
BUILD_DEPENDS+=		${BOOTSTRAPJDKDIR}/bin/javac:java/bootstrap-openjdk11
.endif

.if ${ARCH} == powerpc
CONFIGURE_ARGS+=	--with-jvm-variants=zero
JDK_BUILD_JVM=	zero
.else
JDK_BUILD_JVM=	server
.endif

MAKE_ENV+=		--with-toolchain-type=${COMPILER_TYPE}
CONFIGURE_ARGS+=	--with-toolchain-type=${COMPILER_TYPE}
CONFIGURE_ARGS+=	--disable-warnings-as-errors

.if ${COMPILER_TYPE} == gcc
USE_GCC=	yes
LDFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/gcc${GCC_DEFAULT} -L${LOCALBASE}/lib/gcc${GCC_DEFAULT}
CFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/gcc${GCC_DEFAULT}
CXXFLAGS+=	-Wl,-rpath=${LOCALBASE}/lib/gcc${GCC_DEFAULT}
CONFIGURE_ARGS+=--disable-precompiled-headers
.else
MAKE_ENV+=	USE_CLANG=true
.if ${ARCH:Mpowerpc64*}
LLVM_VER=	12
BUILD_DEPENDS+=	clang${LLVM_VER}:devel/llvm${LLVM_VER}
CC=		${LOCALBASE}/bin/clang${LLVM_VER}
CXX=		${LOCALBASE}/bin/clang++${LLVM_VER}
.endif
.endif

.if ${ARCH} == aarch64 || ${ARCH:Marmv*}
CONFIGURE_ARGS+=	--disable-dtrace
.endif
.if ${ARCH:Mpowerpc64*}
CONFIGURE_ARGS+=	--disable-precompiled-headers
.endif
.if ${ARCH} != amd64
CONFIGURE_ARGS+=	--enable-aot=no
.endif

.if empty(ICONV_LIB)
ICONV_CFLAGS=	-DLIBICONV_PLUG
.else
ICONV_CFLAGS=	-I${LOCALBASE}/include
ICONV_LDFLAGS=	-L${LOCALBASE}/lib
ICONV_LIBS=	${ICONV_LIB}
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${CHMOD} 755 ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/configure \
		${WRKSRC}/src/hotspot/os/bsd/os_bsd.cpp
	@${REINPLACE_CMD} -e 's|%%ICONV_CFLAGS%%|${ICONV_CFLAGS}|' \
		-e 's|%%ICONV_LDFLAGS%%|${ICONV_LDFLAGS}|' \
		-e 's|%%ICONV_LIBS%%|${ICONV_LIBS}|' \
		${WRKSRC}/make/autoconf/libraries.m4

post-build:
.if defined(OPENJDK_SYMLINK_CACERTS)
	@${RM} ${JDK_IMAGEDIR}/lib/security/cacerts
	@${LN} -sf ${OPENJDK_SYMLINK_CACERTS} ${JDK_IMAGEDIR}/lib/security/cacerts
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${INSTALLDIR}
	@cd ${JDK_IMAGEDIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${INSTALLDIR}
	@cd ${STAGEDIR}${INSTALLDIR} && \
		${FIND} bin -type f -exec ${CHMOD} ${BINMODE} {} \;
	@${CHMOD} ${BINMODE} ${STAGEDIR}${INSTALLDIR}/lib/jspawnhelper
	@${ECHO} "@javavm ${INSTALLDIR}/bin/java" >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${INSTALLDIR} -not -type d | ${SORT} | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}

.include <bsd.port.post.mk>
