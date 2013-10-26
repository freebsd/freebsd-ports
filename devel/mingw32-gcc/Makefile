# Created by: Lev Serebryakov <lev@serebryakov.spb.ru>
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	${GCCVERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GCC
PKGNAMEPREFIX=	mingw32-

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	FSF gcc-4 for Windows cross-development

BUILD_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		mingwm10.dll:${PORTSDIR}/devel/${PKGNAMEPREFIX}bin-msvcrt
RUN_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils
LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		mpfr:${PORTSDIR}/math/mpfr \
		mpc:${PORTSDIR}/math/mpc

GCCVERSION=	4.7.2

SSP_UNSAFE=	yes

ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64 sparc64
USE_LDCONFIG=	yes
USES=		bison iconv gmake perl5
USE_BZIP2=	yes
USE_PERL5=	build

GCC_TARG=	${PKGNAMEPREFIX:S/-$//}

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure

BINARIES=	c++ cpp g++ gcc gcov gfortran

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

.if ${ARCH} == powerpc64
CONFIGURE_ENV+=	UNAME_m="powerpc64"
.endif

LANGUAGES:=	c,c++,fortran,objc,obj-c++
SRCDIR=		${WRKDIR}/${PORTNAME}-${GCCVERSION}
WRKSRC=		${WRKDIR}/build
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--disable-nls --target=${GCC_TARG} \
		--enable-languages=${LANGUAGES} \
		--with-gxx-include-dir=${PREFIX}/${GCC_TARG}/include/c++/${GCCVERSION} \
		--disable-sjlj-exceptions \
		--with-dwarf2 --enable-shared \
		--with-gmp=${LOCALBASE} \
		--disable-win32-registry \
		--enable-libstdcxx-debug \
		--disable-build-poststage1-with-cxx \
		--enable-version-specific-runtime-libs \
		${ICONV_CONFIGURE_ARG} \
		--includedir=${PREFIX}/${GCC_TARG}/include \
		--datadir=${PREFIX}/${GCC_TARG}/share \
		--with-system-zlib
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
PLIST_SUB+=	GCC_TARG=${GCC_TARG} GCC_REV=${GCCVERSION}
MAN1=		${PKGNAMEPREFIX}cpp.1 ${PKGNAMEPREFIX}g++.1 \
		${PKGNAMEPREFIX}gcc.1 ${PKGNAMEPREFIX}gcov.1 \
		${PKGNAMEPREFIX}gfortran.1
INFO_PATH=	${GCC_TARG}/info
INFO=		cpp cppinternals gcc gccinstall gccint gfortran
.if ${ARCH} == "i386" || ${ARCH} == "amd64"
INFO+=		libquadmath
.endif

post-patch:
	${REINPLACE_CMD} -e "s,# include <sys/sysctl.h>,," \
		${SRCDIR}/libiberty/physmem.c

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${RM} -f ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-install:
.for F in ${BINARIES}
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${GCC_TARG}/bin/$F
.endfor

.include <bsd.port.post.mk>
