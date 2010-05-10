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

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	FSF gcc-4 for Windows cross-development

BUILD_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		mingwm10.dll:${PORTSDIR}/devel/${PKGNAMEPREFIX}bin-msvcrt
RUN_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils
LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp \
		mpfr.3:${PORTSDIR}/math/mpfr \
		mpc.2:${PORTSDIR}/math/mpc

GCCVERSION=	4.5.0
PATCH_WRKSRC=	${SRCDIR}
SRCDIR=		${WRKDIR}/${PORTNAME}-${GCCVERSION}
WRKSRC=		${WRKDIR}/build

USE_BISON=	build
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_PERL5_BUILD=	yes
MAKE_JOBS_SAFE=	yes

GCC_TARG=	${PKGNAMEPREFIX:S/-$//}

CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure
CONFIGURE_ARGS=	--target=${GCC_TARG} \
		--enable-languages=${LANGUAGES} \
		--enable-threads --disable-nls --disable-shared \
		--with-gmp=${LOCALBASE} --with-mpfr=${LOCALBASE} \
		--includedir=${PREFIX}/${GCC_TARG}/include \
		--datadir=${PREFIX}/${GCC_TARG}/share
LIBTOOLFILES=	configure gcc/configure
MAN1=		${PKGNAMEPREFIX}gcc.1 ${PKGNAMEPREFIX}cpp.1 \
		${PKGNAMEPREFIX}gcov.1

PLIST_SUB+=	PORTVERSION=${PORTVERSION} GCC_TARG=${GCC_TARG} \
		GCC_REV=${GCCVERSION}

INFO_PATH=	${GCC_TARG}/info

LANGUAGES=	c
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

LIBIBERTY_SUB=	"@comment "

.if defined(WITH_LANG_CXX)
DISTFILES+=	gcc-g++-${GCCVERSION}${EXTRACT_SUFX}
CONFIGURE_ARGS+=--with-gxx-include-dir=${PREFIX}/${GCC_TARG}/include/c++/${GCCVERSION} \
		--enable-sjlj-exceptions
PLIST_SUB+=	CXX=""
MAN1+=		${PKGNAMEPREFIX}g++.1
LANGUAGES:=	${LANGUAGES},c++
BINARIES+=	c++ g++
LIBIBERTY_SUB=	""
.else
PLIST_SUB+=	CXX="@comment "
.endif

.if defined(WITH_LANG_OBJC)
DISTFILES+=	gcc-objc-${GCCVERSION}${EXTRACT_SUFX}
PLIST_SUB+=	OBJC=""
LANGUAGES:=	${LANGUAGES},objc
LIBIBERTY_SUB=	""
.else
PLIST_SUB+=	OBJC="@comment "
.endif

.if defined(WITH_LANG_OBJCPP)
PLIST_SUB+=	OBJCXX=""
LANGUAGES:=	${LANGUAGES},obj-c++
.else
PLIST_SUB+=	OBJCXX="@comment "
.endif

.if defined(WITH_LANG_FORTRAN)
DISTFILES+=	gcc-fortran-${GCCVERSION}${EXTRACT_SUFX}
MAN1+=		${PKGNAMEPREFIX}gfortran.1
INFO+=		gfortran
PLIST_SUB+=	FORTRAN=""
LANGUAGES:=	${LANGUAGES},fortran
BINARIES+=	gfortran
LIBIBERTY_SUB=	""
.else
PLIST_SUB+=	FORTRAN="@comment "
.endif

.if defined(WITH_LANG_JAVA)
.if defined(WITH_LIBGCJ)
CONFIGURE_ARGS+=--enable-libgcj
PLIST_SUB+=	LIBGCJ=""
EXTRA_PATCHES+=	${PATCHDIR}/java-patch-libjava-gnu-java-security-jce-prng-natVMSecureRandomWin32.cc
MAN1+=		${PKGNAMEPREFIX}gappletviewer.1 ${PKGNAMEPREFIX}gcjh.1 \
		${PKGNAMEPREFIX}gjar.1 ${PKGNAMEPREFIX}gjarsigner.1 \
		${PKGNAMEPREFIX}gjavah.1 ${PKGNAMEPREFIX}gjdoc.1 \
		${PKGNAMEPREFIX}gkeytool.1 ${PKGNAMEPREFIX}gnative2ascii.1 \
		${PKGNAMEPREFIX}gorbd.1 ${PKGNAMEPREFIX}grmid.1 \
		${PKGNAMEPREFIX}grmiregistry.1 ${PKGNAMEPREFIX}gserialver.1 \
		${PKGNAMEPREFIX}gtnameserv.1
MAN3+=		${PKGNAMEPREFIX}ffi.3 ${PKGNAMEPREFIX}ffi_call.3 \
		${PKGNAMEPREFIX}ffi_prep_cif.3
INFO+=		cp-tools
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
MAN1+=		${PKGNAMEPREFIX}aot-compile.1 ${PKGNAMEPREFIX}gc-analyze.1 \
		${PKGNAMEPREFIX}gcj-dbtool.1 ${PKGNAMEPREFIX}gcj.1 \
		${PKGNAMEPREFIX}gij.1 ${PKGNAMEPREFIX}grmic.1 \
		${PKGNAMEPREFIX}jcf-dump.1 ${PKGNAMEPREFIX}jv-convert.1 \
		${PKGNAMEPREFIX}rebuild-gcj-db.1
INFO+=		gcj
PLIST_SUB+=	JAVA=""
USE_BISON=	build

LANGUAGES:=	${LANGUAGES},java
BINARIES+=	gcj jcf-dump
.else
PLIST_SUB+=	JAVA="@comment " \
		LIBGCJ="@comment "
.endif

.if defined(WITH_LIBSSP)
CONFIGURE_ARGS+=--enable-libssp
PLIST_SUB+=	LIBSSP=""
LIBIBERTY_SUB=	""
.else
CONFIGURE_ARGS+=--disable-libssp
PLIST_SUB+=	LIBSSP="@comment "
.endif

PLIST_SUB+=	LIBIBERTY_SUB=${LIBIBERTY_SUB}

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=x86_64-portbld-freebsd${OSREL}
.elif ${ARCH} == "ia64" || ${ARCH} == "powerpc"
BROKEN=		Does not compile on ia64 or powerpc
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
		${PREFIX}/${GCC_TARG}/bin/$F
.endfor

.include <bsd.port.post.mk>
