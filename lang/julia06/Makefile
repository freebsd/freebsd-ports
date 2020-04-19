# Created by: Iblis Lin <iblis@hs.ntnu.edu.tw>
# $FreeBSD$

PORTNAME=	julia
PORTVERSION=	0.6.4
DISTVERSIONSUFFIX=	-full
PORTREVISION=	9
CATEGORIES=	lang math
MASTER_SITES=	https://github.com/JuliaLang/julia/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX=	06

MAINTAINER=	iblis@hs.ntnu.edu.tw
COMMENT=	Julia Language: A fresh approach to technical computing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgit2.so:devel/libgit2 \
		libgmp.so:math/gmp \
		libmbedtls.so:security/mbedtls \
		libmpfr.so:math/mpfr \
		libpcre2-8.so:devel/pcre2 \
		libssh2.so:security/libssh2 \
		libutf8proc.so:textproc/utf8proc
EXTRACT_DEPENDS=gmake:devel/gmake
BUILD_DEPENDS=	patchelf:sysutils/patchelf \
		pcre2-config:devel/pcre2 \
		cmake:devel/cmake

USES=		gmake compiler:c++11-lib fortran python:2.7,build perl5
USE_LDCONFIG=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}
INSTALLDIR=	julia/${PORTNAME}${PKGNAMESUFFIX}
MANDIRS+=	${PREFIX}/${INSTALLDIR}/man

ALL_TARGET=	default
INSTALL_TARGET=	install
TEST_TARGET=	test

PLIST_SUB=	VERSION="${PORTVERSION:R}" \
		SOVERSION="${PORTVERSION}" \
		JULIA="${INSTALLDIR}"

CXXFLAGS+=	-stdlib=libc++ -std=c++11
MAKE_ARGS+=	prefix=${PREFIX}/${INSTALLDIR} \
		JCXXFLAGS="${CXXFLAGS}" \
		FORCE_ASSERTIONS=${FORCE_ASSERTIONS} \
		USE_GPL_LIBS=${USE_GPL_LIBS} \
		USE_SYSTEM_CURL=1 \
		USE_SYSTEM_GMP=1 \
		USE_SYSTEM_LAPACK=1 \
		USE_SYSTEM_LIBGIT2=1 \
		USE_SYSTEM_LIBSSH2=1 \
		USE_SYSTEM_LIBUV=0 \
		USE_SYSTEM_MBEDTLS=1 \
		USE_SYSTEM_MPFR=1 \
		USE_SYSTEM_PATCHELF=1 \
		USE_SYSTEM_PCRE=1 \
		USE_SYSTEM_UTF8PROC=1 \
		NO_GIT=1

OPTIONS_DEFINE=	EXAMPLES DEBUG DOCS GPL_LIBS DESKTOP NATIVE
OPTIONS_DEFAULT=	OPENLIBM
OPTIONS_GROUP=	PRIVATE
OPTIONS_GROUP_PRIVATE=	ARPACK OPENBLAS
OPTIONS_SINGLE=	LIBM
OPTIONS_SINGLE_LIBM=	SYSLIBM OPENLIBM
OPTIONS_SUB=	yes

PRIVATE_DESC=	Build self-shipped private depends
LIBM_DESC=	Math library implementation

DEBUG_VARS=	FORCE_ASSERTIONS=1 \
		ALL_TARGET=all
DEBUG_MAKE_ARGS=	BUNDLE_DEBUG_LIBS=1

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
PORTDOCS=	html
DOCS_VARS=	INSTALL_TARGET+=install-docs

EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}
PORTEXAMPLES=	*
EXAMPLES_VARS=	INSTALL_TARGET+=install-examples

GPL_LIBS_DESC=	Build with GPL libs: FFTW and SUITESPARSE
GPL_LIBS_LIB_DEPENDS=	libfftw3.so:math/fftw3 \
			libfftw3f.so:math/fftw3-float
GPL_LIBS_MAKE_ARGS=	USE_SYSTEM_SUITESPARSE=0 USE_SYSTEM_FFTW=1
GPL_LIBS_VARS=	USE_GPL_LIBS=1

DESKTOP_DESC=	Install icon, .desktop and appdata files
DESKTOP_USES=	gnome
DESKTOP_VARS=	INSTALL_TARGET+=install-desktop \
		INSTALLS_ICONS=yes

ARPACK_DESC=	Build self-shipped private arpack-ng
ARPACK_MAKE_ARGS=	USE_SYSTEM_ARPACK=0
ARPACK_MAKE_ARGS_OFF=	USE_SYSTEM_ARPACK=1
ARPACK_LIB_DEPENDS_OFF=	libarpack.so:math/arpack-ng

SYSLIBM_DESC=	Build with system libm
SYSLIBM_MAKE_ARGS=	USE_SYSTEM_LIBM=1

OPENLIBM_DESC=	Build with OpenLibm (math/openlibm)
OPENLIBM_MAKE_ARGS=	USE_SYSTEM_OPENLIBM=1
OPENLIBM_LIB_DEPENDS=	libopenlibm.so:math/openlibm

OPENBLAS_DESC=	Private OpenBLAS v0.3.0\
		(ports tree: v${:!${MAKE} -C ${PORTSDIR}/math/openblas -V PORTVERSION!})
OPENBLAS_MAKE_ARGS=	USE_SYSTEM_BLAS=0 OPENBLAS_DYNAMIC_ARCH=1
OPENBLAS_MAKE_ARGS_OFF=	USE_SYSTEM_BLAS=1
OPENBLAS_LIB_DEPENDS_OFF=	libopenblas.so:math/openblas

.include <bsd.port.options.mk>

NATIVE_DESC=		Build with native CPU JIT tuning
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

# OPENBLAS plist
.if ${PORT_OPTIONS:MOPENBLAS}
.if ${ARCH} == "amd64"
PLIST_SUB+=	OPENBLAS64="64_"
.else
PLIST_SUB+=	OPENBLAS64=""
.endif
.endif  # .if ${PORT_OPTIONS:MOPENBLAS}

.if ${ARCH} == "i386"
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-ui_Makefile
.endif

post-extract:
	${GMAKE} -C ${WRKSRC}/deps extract

post-patch:
	echo "override TAGGED_RELEASE_BANNER=\"FreeBSD port lang/${PORTNAME}${PKGNAMESUFFIX} build\"" >> ${WRKSRC}/Make.user
	# unset ARCH for auto-detection
	# Julia build script uses the name x86_86/x86, which are different from ports framework
	echo "ARCH=" >> ${WRKSRC}/Make.user

post-patch-OPENBLAS-on:
	${CP} ${FILESDIR}/extra-patch-openblas-fix-arch.patch ${WRKSRC}/deps/patches/openblas-fix-arch.patch

post-patch-OPENBLAS-off:
	echo "LIBBLAS= -lopenblas -L${LOCALBASE}/lib" >> ${WRKSRC}/Make.user
	echo "LIBBLASNAME=libopenblas" >> ${WRKSRC}/Make.user
	echo 'LIBLAPACK= $$(LIBBLAS)' >> ${WRKSRC}/Make.user
	echo 'LIBLAPACKNAME= $$(LIBBLASNAME)' >> ${WRKSRC}/Make.user

post-configure-OPENBLAS-off:
	${CC} ${CFLAGS} -lopenblas ${LDFLAGS} -o ${WRKSRC}/check_openblas \
		${FILESDIR}/check_openblas.c
	${WRKSRC}/check_openblas && ( \
		echo "USE_BLAS64=1" >> ${WRKSRC}/Make.user \
	) || ( \
		echo "USE_BLAS64=0" >> ${WRKSRC}/Make.user \
	)

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/${INSTALLDIR}/bin/julia ${STAGEDIR}${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}
	${RLN} ${STAGEDIR}${PREFIX}/${INSTALLDIR}/man/man1/julia.1 ${STAGEDIR}${PREFIX}/man/man1/${PORTNAME}${PKGNAMESUFFIX}.1

	# clean up for Pkg3.jl
.for file in .codecov.yml .travis.yml appveyor.yml bors.toml .gitignore source-extracted
	${RM} ${STAGEDIR}${PREFIX}/${INSTALLDIR}/share/julia/stdlib/v${PORTVERSION:R}/Pkg/${file}
	${RM} ${STAGEDIR}${PREFIX}/${INSTALLDIR}/share/julia/stdlib/v${PORTVERSION:R}/Pkg/ext/TOML/${file}
.endfor

post-install-DEBUG-on:
	${RLN} ${STAGEDIR}${PREFIX}/${INSTALLDIR}/bin/julia-debug ${STAGEDIR}${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}-debug

post-install-DOCS-on:
	${MV} ${STAGEDIR}${PREFIX}/${INSTALLDIR}/share/doc/julia ${STAGEDIR}${DOCSDIR}
	${RMDIR} ${STAGEDIR}${PREFIX}/${INSTALLDIR}/share/doc

post-install-DOCS-off:
	# remove empty dir
	${RM} -r ${STAGEDIR}${PREFIX}/${INSTALLDIR}/share/doc

post-install-EXAMPLES-on:
	${MV} ${STAGEDIR}${PREFIX}/${INSTALLDIR}/share/examples/julia ${STAGEDIR}${EXAMPLESDIR}
	${RMDIR} ${STAGEDIR}${PREFIX}/${INSTALLDIR}/share/examples

.include <bsd.port.mk>
