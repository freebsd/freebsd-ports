# Created by: Iblis Lin <iblis@hs.ntnu.edu.tw>
# $FreeBSD$

PORTNAME=	julia
PORTVERSION=	0.6.0
PORTREVISION=	1
DISTVERSIONSUFFIX=	-full
CATEGORIES=	lang math
MASTER_SITES=	https://github.com/JuliaLang/julia/releases/download/v${PORTVERSION}/

MAINTAINER=	iblis@hs.ntnu.edu.tw
COMMENT=	Julia Language: A fresh approach to technical computing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libunwind.so:devel/libunwind \
		libutf8proc.so:textproc/utf8proc \
		libopenblasp.so:math/openblas \
		libgit2.so:devel/libgit2 \
		libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libpcre2-8.so:devel/pcre2
BUILD_DEPENDS=	llvm-config40:devel/llvm40 \
		pcre2-config:devel/pcre2 \
		patchelf:sysutils/patchelf

ONLY_FOR_ARCHS=	amd64 i386

USES=		gmake compiler:c++11-lib fortran
USE_LDCONFIG=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

ALL_TARGET=	default
INSTALL_TARGET=	install
TEST_TARGET=	test

PLIST_SUB=	VERSION="${PORTVERSION:R}" \
		SOVERSION="${PORTVERSION}"

CXXFLAGS+=	-stdlib=libc++ -std=c++11
MAKE_ARGS+=	prefix=${PREFIX} JCXXFLAGS="${CXXFLAGS}" \
		FORCE_ASSERTIONS=${FORCE_ASSERTIONS} \
		USE_GPL_LIBS=${USE_GPL_LIBS}

OPTIONS_DEFINE=	EXAMPLES DEBUG DOCS GPL_LIBS DESKTOP NATIVE
OPTIONS_DEFAULT=	SYSLIBM
OPTIONS_GROUP=	PRIVATE
OPTIONS_GROUP_PRIVATE=	ARPACK
OPTIONS_SINGLE=	LIBM
OPTIONS_SINGLE_LIBM=	SYSLIBM OPENLIBM
OPTIONS_SUB=	yes

PRIVATE_DESC=	Build self-shipped private depends
LIBM_DESC=	Math library implementation

DEBUG_VARS=	FORCE_ASSERTIONS=1 \
		ALL_TARGET=all

PORTDOCS=	html
DOCS_VARS=	INSTALL_TARGET+=install-docs

PORTEXAMPLES=	*
EXAMPLES_VARS=	INSTALL_TARGET+=install-examples

GPL_LIBS_DESC=	Build with GPL libs: FFTW and SUITESPARSE
GPL_LIBS_LIB_DEPENDS=	libfftw3.so:math/fftw3 \
			libfftw3f.so:math/fftw3-float
GPL_LIBS_MAKE_ARGS=	USE_SYSTEM_SUITESPARSE=0
GPL_LIBS_VARS=	USE_GPL_LIBS=1

DESKTOP_DESC=	Install icon, .desktop and appdata files
DESKTOP_VARS=	INSTALL_TARGET+=install-desktop \
		INSTALLS_ICONS=yes

ARPACK_DESC=	Build self-shipped private arpack-ng
ARPACK_MAKE_ARGS=	USE_SYSTEM_ARPACK=0
ARPACK_LIB_DEPENDS_OFF=	libarpack.so:math/arpack-ng
ARPACK_MAKE_ARGS_OFF=	USE_SYSTEM_ARPACK=1

SYSLIBM_DESC=	Build with system libm
SYSLIBM_MAKE_ARGS=	USE_SYSTEM_LIBM=1

OPENLIBM_DESC=	Build with OpenLibm (math/openlibm)
OPENLIBM_MAKE_ARGS=	USE_SYSTEM_OPENLIBM=1
OPENLIBM_LIB_DEPENDS=	libopenlibm.so:math/openlibm

.include <bsd.port.options.mk>

NATIVE_DESC=		Build with native CPU jit tuning
.if ${PORT_OPTIONS:MNATIVE}
MAKE_ARGS+=	JULIA_CPU_TARGET=native
.else
.if ${ARCH} == "amd64"
MAKE_ARGS+=	JULIA_CPU_TARGET=x86-64
.elif ${ARCH} == "i386"
MAKE_ARGS+=	JULIA_CPU_TARGET=pentium4
.else
MAKE_ARGS+=	JULIA_CPU_TARGET=generic
.endif
.endif  # .if ${PORT_OPTIONS:MNATIVE}

.if ${ARCH} == "i386"
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ui_Makefile
.endif

post-configure:
	${CC} ${CFLAGS} -lopenblas ${LDFLAGS} -o ${WRKSRC}/check_openblas \
		${FILESDIR}/check_openblas.c
	${WRKSRC}/check_openblas && ( \
		echo "USE_BLAS64=1" >> ${WRKSRC}/Make.user \
	) || ( \
		echo "USE_BLAS64=0" >> ${WRKSRC}/Make.user \
	)

.include <bsd.port.mk>
