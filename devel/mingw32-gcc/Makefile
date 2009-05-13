# New ports collection makefile for:	mingw32-gcc
# Date created:		24 October 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	${GCCVERSION}
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${PORTNAME}-${GCCVERSION}
PKGNAMEPREFIX=	mingw32-
DISTFILES=	gcc-core-${GCCVERSION}${EXTRACT_SUFX}

MAINTAINER=	lev@FreeBSD.org
COMMENT=	FSF gcc-4.2 for Windows cross-development

BUILD_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		mingwm10.dll:${PORTSDIR}/devel/${PKGNAMEPREFIX}bin-msvcrt
RUN_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils

GCCVERSION=	4.2.1
PATCH_WRKSRC=	${SRCDIR}
SRCDIR=		${WRKDIR}/${PORTNAME}-${GCCVERSION}
WRKSRC=		${WRKDIR}/build

USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_ICONV=	yes

CONFIGURE_SCRIPT= ../${SRCDIR:C/${WRKDIR}//}/configure
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} \
		--enable-languages=${LANGUAGES} \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--enable-threads --disable-nls \
		--disable-win32-registry --disable-shared \
		--includedir=${PREFIX}/${PKGNAMEPREFIX:S/-$//}/include \
		--datadir=${PREFIX}/${PKGNAMEPREFIX:S/-$//}/share
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}
LIBTOOLFILES=	configure gcc/configure
MAN1=		${PKGNAMEPREFIX}gcc.1 ${PKGNAMEPREFIX}cpp.1 \
		${PKGNAMEPREFIX}gcov.1

PLIST_SUB+=	PORTVERSION=${PORTVERSION} GCC_TARG=${PKGNAMEPREFIX:S/-$//} \
		GCC_REV=${GCCVERSION}

INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

LANGUAGES=	c
WITH_LANG_C=	true
BINARIES=	cpp gcc gcov
INFO=		cpp cppinternals gcc gccinstall gccint

.if make(makesum)
WITH_LANG_CXX=true
WITH_LANG_OBJC=true
WITH_LANG_OBJCPP=true
WITH_LANG_FORTRAN=true
WITH_LANG_JAVA=true
OPTIONS=
.else
OPTIONS=	LANG_CXX     "Enable C++ compiler"                   on  \
		LANG_OBJC    "Enable ObjectC compiler"               off \
		LANG_OBJCPP  "Enable ObjectC++ compiler"             off \
		LANG_FORTRAN "Enable FORTRAN95 compiler"             off \
		LANG_JAVA    "Enable Java compiler"                  off \
		LIBSSP       "Enable libssp build"                   on  \
		LIBGCJ       "Enable libgcj build (needs LANG_JAVA)" on
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_LANG_OBJCPP)
WITH_LANG_OBJC=true
WITH_LANG_CXX=true
.endif

.if defined(WITH_LANG_JAVA)
WITH_LANG_CXX=true
.endif

.if defined(WITH_LANG_CXX)
DISTFILES+=	gcc-g++-${GCCVERSION}${EXTRACT_SUFX}
CONFIGURE_ARGS+=--with-gxx-include-dir=${PREFIX}/${PKGNAMEPREFIX:S/-$//}/include/c++/${GCCVERSION} \
		--enable-sjlj-exceptions
PLIST_SUB+=	CXX=""
MAN1+=		${PKGNAMEPREFIX}g++.1
LANGUAGES:=	${LANGUAGES},c++
BINARIES+=	c++ g++
.else
PLIST_SUB+=	CXX="@comment "
.endif

.if defined(WITH_LANG_OBJC)
DISTFILES+=	gcc-objc-${GCCVERSION}${EXTRACT_SUFX}
PLIST_SUB+=	OBJC=""
LANGUAGES:=	${LANGUAGES},objc
.else
PLIST_SUB+=	OBJC="@comment "
.endif

.if defined(WITH_LANG_OBJCPP)
DISTFILES+=	gcc-objc-${GCCVERSION}${EXTRACT_SUFX}
PLIST_SUB+=	OBJCXX=""
LANGUAGES:=	${LANGUAGES},obj-c++
.else
PLIST_SUB+=	OBJCXX="@comment "
.endif

.if defined(WITH_LANG_FORTRAN)
DISTFILES+=	gcc-fortran-${GCCVERSION}${EXTRACT_SUFX}
LIB_DEPENDS+=	gmp.8:${PORTSDIR}/math/libgmp4 \
		mpfr.3:${PORTSDIR}/math/mpfr
CONFIGURE_ARGS+=--with-gmp=${LOCALBASE} \
		--with-mpfr=${LOCALBASE}
MAN1+=		${PKGNAMEPREFIX}gfortran.1
INFO+=		gfortran
PLIST_SUB+=	FORTRAN=""
LANGUAGES:=	${LANGUAGES},fortran
BINARIES+=	gfortran
.else
PLIST_SUB+=	FORTRAN="@comment "
.endif

.if defined(WITH_LANG_JAVA)
.if defined(WITH_LIBGCJ)
CONFIGURE_ARGS+=--enable-libgcj
PLIST_SUB+=	LIBGCJ=""
BINARIES+=	addr2name.awk
.else
CONFIGURE_ARGS+=--disable-libgcj
PLIST_SUB+=	LIBGCJ="@comment "
.endif
DISTFILES+=	gcc-java-${GCCVERSION}${EXTRACT_SUFX}
BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip
EXTRA_PATCHES+=	${PATCHDIR}/java-patch-libjava--Makefile.in \
		${PATCHDIR}/java-patch-libjava--classpath--resource--Makefile.in
CONFIGURE_ARGS+=--without-x --disable-java-awt \
		--enable-hash-synchronization --with-interpreter \
		--enable-java-gc=boehm
MAN1+=		${PKGNAMEPREFIX}gcj-dbtool.1 ${PKGNAMEPREFIX}gcj.1 \
		${PKGNAMEPREFIX}gcjh.1 ${PKGNAMEPREFIX}gij.1 \
		${PKGNAMEPREFIX}gjnih.1 ${PKGNAMEPREFIX}grmic.1 \
		${PKGNAMEPREFIX}grmiregistry.1 ${PKGNAMEPREFIX}jcf-dump.1 \
		${PKGNAMEPREFIX}jv-convert.1 ${PKGNAMEPREFIX}jv-scan.1
INFO+=		gcj
PLIST_SUB+=	JAVA=""
USE_BISON=	build

LANGUAGES:=	${LANGUAGES},java
BINARIES+=	gcj gcjh gjnih jcf-dump jv-scan
.else
PLIST_SUB+=	JAVA="@comment " \
		LIBGCJ="@comment "
.endif

.if defined(WITH_LIBSSP)
CONFIGURE_ARGS+=--enable-libssp
PLIST_SUB+=	LIBSSP=""
.else
CONFIGURE_ARGS+=--disable-libssp
PLIST_SUB+=	LIBSSP="@comment "
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=${ARCH}-portbld-freebsd${OSREL}
.endif

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${MKDIR} ${CONFIGURE_WRKSRC}
.if defined(WITH_LIBGCJ)
	@${ECHO_MSG} "You have selected to have libgcj built. This will require at least 2GB of RAM + swap if not more"
	@${ECHO_MSG} "and will likely add extra time to the build (on the scale of hours)."
.endif

post-install:
.for F in ${BINARIES}
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor

.include <bsd.port.post.mk>
