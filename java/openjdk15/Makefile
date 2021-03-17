# $FreeBSD$

PORTNAME=	openjdk
DISTVERSIONPREFIX=	jdk-
DISTVERSION=	${JDK_MAJOR_VERSION}.${JDK_MINOR_VERSION}.${JDK_PATCH_VERSION}+${JDK_BUILD_NUMBER}-${BSD_JDK_VERSION}
PORTREVISION=	1
CATEGORIES=	java devel
PKGNAMESUFFIX?=	${JDK_MAJOR_VERSION}

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java Development Kit ${JDK_MAJOR_VERSION}

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386 powerpc64 powerpc64le

BUILD_DEPENDS=	zip:archivers/zip \
		autoconf>0:devel/autoconf \
		${LOCALBASE}/include/cups/cups.h:print/cups \
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

USES=		compiler:features gmake iconv jpeg pkgconfig xorg
USE_XORG=	x11 xext xi xrandr xrender xt xtst

USE_GITHUB=	yes
GH_ACCOUNT=	battleblow
GH_PROJECT=	jdk15u

NO_CCACHE=	yes

_MAKE_JOBS=	#
MAKE_ENV=	LANG="C" \
		LC_ALL="C" \
		CLASSPATH="" \
		JAVA_HOME="" \
		LD_LIBRARY_PATH="" \
		CC=${CC} \
		CXX=${CXX} \
		CPP=${CPP} \
		MAKEFLAGS=""

JDK_OSARCH=	bsd-${ARCH:S/amd64/x86_64/:S/i386/x86/:S/powerpc64/ppc64/}
JDK_BUILDDIR=	${WRKSRC}/build/${JDK_OSARCH}-${JDK_BUILD_JVM}-${JDK_BUILD_TYPE}
JDK_IMAGEDIR=	${JDK_BUILDDIR}/images/jdk
INSTALLDIR=	${PREFIX}/${PKGBASE}

NOPRECIOUSMAKEVARS=	yes

JDK_MAJOR_VERSION=	15
JDK_MINOR_VERSION=	0
JDK_PATCH_VERSION=	2
JDK_BUILD_NUMBER=	7
BSD_JDK_VERSION=	1

JDK_BUG_URL=	https://bugs.freebsd.org/bugzilla/enter_bug.cgi?product=Ports%20%26%20Packages&component=Individual%20Port(s)&short_desc=java/${PORTNAME}${JDK_MAJOR_VERSION}%3A%20

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC=${CC} \
		CXX=${CXX} \
		CPP=${CPP} \
		ac_cv_path_SED=${LOCALBASE}/bin/gsed
CONFIGURE_ARGS=	--with-boot-jdk=${BOOTSTRAPJDKDIR} \
		--disable-ccache \
		--disable-javac-server \
		--disable-hotspot-gtest \
		--with-alsa=${LOCALBASE} \
		--with-cups=${LOCALBASE} \
		--with-fontconfig=${LOCALBASE} \
		--with-freetype=system \
		--with-freetype-include=${LOCALBASE}/include/freetype2 \
		--with-freetype-lib=${LOCALBASE}/lib \
		--with-libjpeg=system \
		--with-giflib=system \
		--with-giflib-include=${LOCALBASE}/include \
		--with-giflib-lib=${LOCALBASE}/lib \
		--with-libpng=system \
		--with-zlib=system \
		--with-lcms=system \
		--x-includes=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib \
		--with-cacerts-file=${FILESDIR}/cacerts \
		--with-version-string=${JDK_MAJOR_VERSION}.${JDK_MINOR_VERSION}.${JDK_PATCH_VERSION}+${JDK_BUILD_NUMBER}-${BSD_JDK_VERSION} \
		--with-native-debug-symbols=none \
		--with-debug-level=release \
		--with-vendor-name="OpenJDK BSD Porting Team" \
		--with-vendor-url="https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/" \
		--with-vendor-bug-url="${JDK_BUG_URL}" \
		--with-vendor-vm-bug-url="${JDK_BUG_URL}"

JAVAVMS_COMMENT=	OpenJDK${JDK_MAJOR_VERSION}

ALL_TARGET=		images
JDK_BUILD_TYPE=		release

.include <bsd.port.pre.mk>

# Support aarch64 on FreeBSD 12 and up
.if ${OSVERSION} >= 1200500
ONLY_FOR_ARCHS+=aarch64
.endif

BOOTSTRAP_JDKS=	${LOCALBASE}/openjdk15 \
		${LOCALBASE}/openjdk14

# do we have valid native jdk installed?
.for BJDK in ${BOOTSTRAP_JDKS}
.  if !defined(BOOTSTRAPJDKDIR) && exists(${BJDK}/bin/javac)
BOOTSTRAPJDKDIR=	${BJDK}
.  endif
.endfor

# if no valid jdk found, set dependency
.if !defined(BOOTSTRAPJDKDIR)
BOOTSTRAPJDKDIR?=	${LOCALBASE}/openjdk14
BUILD_DEPENDS+=		${BOOTSTRAPJDKDIR}/bin/javac:java/openjdk14
.endif

JDK_BUILD_JVM=	server

MAKE_ENV+=		--with-toolchain-type=${COMPILER_TYPE}
CONFIGURE_ARGS+=	--with-toolchain-type=${COMPILER_TYPE}

.if ${COMPILER_TYPE} == gcc
USE_GCC=	yes
CONFIGURE_ARGS+=	--with-extra-ldflags="-Wl,-rpath=${LOCALBASE}/lib/gcc${GCC_DEFAULT} -L/usr/local/lib/gcc${GCC_DEFAULT}" \
			--with-extra-cflags="-Wl,-rpath=${LOCALBASE}/lib/gcc${GCC_DEFAULT}" \
			--with-extra-cxxflags="-Wl,-rpath=${LOCALBASE}/lib/gcc${GCC_DEFAULT}"
.else
MAKE_ENV+=	USE_CLANG=true
.endif

.if ${ARCH} == aarch64 || ${ARCH:Mpowerpc64*}
CONFIGURE_ARGS+=	--disable-warnings-as-errors
.endif
.if ${ARCH} == aarch64 || (defined(PPC_ABI) && ${PPC_ABI} == ELFv1)
CONFIGURE_ARGS+=	--disable-dtrace
.endif
.if (defined(PPC_ABI) && ${PPC_ABI} == ELFv2) || ${ARCH} == powerpc64le
CONFIGURE_ARGS+=	--disable-precompiled-headers
.endif
.if ${ARCH} != amd64
CONFIGURE_ARGS+=	--enable-aot=no
.endif
.if ${ARCH} == powerpc64 && ${OSREL:C/\.[0-9]//} == 12
EXTRA_PATCHES=		${PATCHDIR}/extra-patch-src_hotspot_cpu_ppc_vm__version__ppc.hpp
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
