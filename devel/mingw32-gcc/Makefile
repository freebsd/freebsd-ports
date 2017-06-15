# Created by: Lev Serebryakov <lev@serebryakov.spb.ru>
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	${GCCVERSION}
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GCC
PKGNAMEPREFIX=	mingw32-

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	FSF gcc-4 for Windows cross-development

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BUILD_DEPENDS=	${PKGNAMEPREFIX}as:devel/${PKGNAMEPREFIX}binutils \
		mingwm10.dll:devel/${PKGNAMEPREFIX}bin-msvcrt
RUN_DEPENDS=	${PKGNAMEPREFIX}as:devel/${PKGNAMEPREFIX}binutils
LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc

GCCVERSION=	4.8.1

SSP_UNSAFE=	yes

ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64 sparc64
USE_LDCONFIG=	yes
USES=		bison iconv gmake libtool makeinfo perl5 tar:bzip2
USE_PERL5=	build

GCC_TARG=	${PKGNAMEPREFIX:S/-$//}

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure

BINARIES=	c++ cpp g++ gcc gcov gfortran

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-${OPSYS:tl}${OSREL}
.endif

.if ${ARCH} == powerpc64
CONFIGURE_ENV+=	UNAME_m="powerpc64"
.endif

LANGUAGES:=	c,c++,fortran,objc,obj-c++
SRCDIR=		${WRKDIR}/${PORTNAME}-${GCCVERSION}
WRKSRC=		${WRKDIR}/build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls --target=${GCC_TARG} \
		--with-gxx-include-dir=${PREFIX}/${GCC_TARG}/include/c++/${GCCVERSION} \
		--disable-build-poststage1-with-cxx \
		--includedir=${PREFIX}/${GCC_TARG}/include \
		--datadir=${PREFIX}/${GCC_TARG}/share \
		--enable-shared --with-gnu-ld \
		--enable-lto --disable-multilib \
		--enable-languages=${LANGUAGES} \
		--disable-sjlj-exceptions \
		--with-dwarf2 --disable-win32-registry \
		--enable-libstdcxx-debug \
		--enable-version-specific-runtime-libs \
		--with-gmp=${LOCALBASE} \
		--with-system-zlib --with-gnu-as \
		--enable-decimal-float=yes \
		--disable-libgomp --disable-threads \
		${ICONV_CONFIGURE_ARG} \
		--disable-bootstrap
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
PLIST_SUB+=	GCC_TARG=${GCC_TARG} GCC_REV=${GCCVERSION}
INFO_PATH=	${GCC_TARG}/info
INFO=		cpp cppinternals gcc gccinstall gccint gfortran
.if ${ARCH} == "i386" || ${ARCH} == "amd64"
INFO+=		libquadmath
.endif
INSTALL_TARGET=	install-strip

post-patch:
	${REINPLACE_CMD} -e "s,# include <sys/sysctl.h>,," \
		${SRCDIR}/libiberty/physmem.c

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${RM} ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/libiberty.a
	@${MKDIR} ${STAGEDIR}${PREFIX}/${GCC_TARG}/bin
.for F in ${BINARIES}
	@${LN} -f ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${STAGEDIR}${PREFIX}/${GCC_TARG}/bin/$F
.endfor

.include <bsd.port.post.mk>
