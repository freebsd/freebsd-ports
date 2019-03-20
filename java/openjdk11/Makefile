# $FreeBSD$

PORTNAME=	openjdk
PORTVERSION=	${JDK_MAJOR_VERSION}.${JDK_MINOR_VERSION}.${JDK_PATCH_VERSION}.${JDK_BUILD_NUMBER}.${BSD_JDK_VERSION}
CATEGORIES=	java devel
MASTER_SITES=	https://github.com/battleblow/openjdk-jdk11u/archive/
PKGNAMESUFFIX?=	${JDK_MAJOR_VERSION}
DISTNAME=	jdk-${JDK_MAJOR_VERSION}.${JDK_MINOR_VERSION}.${JDK_PATCH_VERSION}+${JDK_BUILD_NUMBER}-${BSD_JDK_VERSION}

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java Development Kit ${JDK_MAJOR_VERSION}

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64

BUILD_DEPENDS=	zip:archivers/zip \
		autoconf>0:devel/autoconf \
		${LOCALBASE}/include/cups/cups.h:print/cups \
		bash:shells/bash
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		liblcms2.so:graphics/lcms2 \
		libgif.so:graphics/giflib \
		libpng16.so:graphics/png

USES=		compiler:features gmake iconv jpeg pkgconfig
USE_XORG=	xext x11 xrender xtst xi xt

WRKSRC=		${WRKDIR}/${PORTNAME}-jdk${JDK_MAJOR_VERSION}u-jdk-${JDK_MAJOR_VERSION}.${JDK_MINOR_VERSION}.${JDK_PATCH_VERSION}-${JDK_BUILD_NUMBER}-${BSD_JDK_VERSION}

_MAKE_JOBS=	#
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	LANG="C" \
		LC_ALL="C" \
		CLASSPATH="" \
		JAVA_HOME="" \
		LD_LIBRARY_PATH="" \
		LDFLAGS=-L${LOCALBASE}/lib \
		CC=/usr/bin/cc \
		CXX=/usr/bin/c++ \
		MAKEFLAGS="" \
		USE_CLANG=true

JDK_OSARCH=	bsd-${ARCH:S/amd64/x86_64/}
JDK_BUILDDIR=	${WRKSRC}/build/${JDK_OSARCH}-normal-${JDK_BUILD_JVM}-${JDK_BUILD_TYPE}
JDK_IMAGEDIR=	${JDK_BUILDDIR}/images/jdk
INSTALLDIR=	${PREFIX}/${PKGBASE}

NOPRECIOUSMAKEVARS=	yes

JDK_MAJOR_VERSION=	11
JDK_MINOR_VERSION=	0
JDK_PATCH_VERSION=	2
JDK_BUILD_NUMBER=	9
BSD_JDK_VERSION=	2

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC=/usr/bin/cc \
		CXX=/usr/bin/c++
CONFIGURE_ARGS=	--with-boot-jdk=${BOOTSTRAPJDKDIR} \
		--disable-ccache \
		--disable-dtrace \
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
		--with-libpng=system \
		--with-zlib=system \
		--with-lcms=system \
		--with-extra-cflags=-I${LOCALBASE}/include \
		--with-extra-cxxflags=-I${LOCALBASE}/include \
		--with-extra-ldflags=-L${LOCALBASE}/lib \
		--with-toolchain-type=clang \
		--x-includes=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib \
		--with-package-path=${LOCALBASE} \
		--with-cacerts-file=${FILESDIR}/cacerts \
		--with-version-string=${JDK_MAJOR_VERSION}.${JDK_MINOR_VERSION}.${JDK_PATCH_VERSION}+${JDK_BUILD_NUMBER}-${BSD_JDK_VERSION} \
		--with-native-debug-symbols=none \
		--with-debug-level=release

JAVAVMS_COMMENT=	OpenJDK${JDK_MAJOR_VERSION}

ALL_TARGET=		images
JDK_BUILD_TYPE=		release

.include <bsd.port.pre.mk>

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

JDK_BUILD_JVM=	server

.if empty(ICONV_LIB)
ICONV_CPPFLAGS=	-DLIBICONV_PLUG
.else
ICONV_CPPFLAGS=	-I${LOCALBASE}/include
ICONV_LDFLAGS=	-L${LOCALBASE}/lib ${ICONV_LIB}
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${CHMOD} 755 ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		 ${WRKSRC}/configure

do-install:
	@${MKDIR} ${STAGEDIR}${INSTALLDIR}
	@cd ${JDK_IMAGEDIR} && ${COPYTREE_SHARE} . ${STAGEDIR}${INSTALLDIR}
	@cd ${STAGEDIR}${INSTALLDIR} && \
		${FIND} bin -type f -exec ${CHMOD} ${BINMODE} {} \;
	@${FIND} ${STAGEDIR}${INSTALLDIR} -not -type d | ${SORT} | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}

.include <bsd.port.post.mk>
