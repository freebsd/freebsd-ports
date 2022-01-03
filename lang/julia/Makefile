# Created by: Iblis Lin <iblis@hs.ntnu.edu.tw>

PORTNAME=	julia
DISTVERSION=	1.7.1
DISTVERSIONSUFFIX=	-full
CATEGORIES=	lang math
MASTER_SITES=	https://github.com/JuliaLang/julia/releases/download/v${DISTVERSION}/

MAINTAINER=	rizor.reardon@yahoo.com
COMMENT=	Implementation of Julia, a language for technical computing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	Has not been ported to this platform for freebsd

MY_DEPENDS=	7z:archivers/p7zip
BUILD_DEPENDS=	patchelf:sysutils/patchelf \
		cmake:devel/cmake \
		${MY_DEPENDS}
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgit2.so:devel/libgit2 \
		libgmp.so:math/gmp \
		libmbedtls.so:security/mbedtls \
		libmpfr.so:math/mpfr \
		libpcre2-8.so:devel/pcre2 \
		libssh2.so:security/libssh2 \
		libutf8proc.so:textproc/utf8proc \
		libnghttp2.so:www/libnghttp2 \
		libunwind.so:devel/libunwind \
		libopenlibm.so:math/openlibm
RUN_DEPENDS=	${MY_DEPENDS}

USES=		gmake compiler:c++14-lang cpe fortran python perl5 \
		shebangfix blaslapack:openblas

CPE_VENDOR=	julialang

BINARY_ALIAS=	python3=${PYTHON_CMD} gfortran=gfortran${_GCC_VER}
USE_LDCONFIG=	yes
CFLAGS+=	-fpic

SHEBANG_GLOB=	*.sh

WRKSRC=		${WRKDIR}/julia-${DISTVERSION}

ALL_TARGET=	default
INSTALL_TARGET=	install
TEST_TARGET=	test

PORTDOCS=	html
PLIST_SUB=	VERSION="${PORTVERSION:R}"

CXXFLAGS+=	-std=c++14
MAKE_ARGS+=	NO_GIT=1 \
		USE_BINARYBUILDER=0 \
		prefix=${PREFIX} \
		JCXXFLAGS="${CXXFLAGS}" \
		USE_GPL_LIBS=0 \
		ARCH=x86_64 \
		USE_SYSTEM_CURL=1 \
		USE_SYSTEM_GMP=1 \
		USE_SYSTEM_OPENLIBM=1 \
		USE_SYSTEM_LAPACK=1 \
		USE_SYSTEM_LIBGIT2=1 \
		USE_SYSTEM_LIBSSH2=1 \
		USE_SYSTEM_MBEDTLS=1 \
		USE_SYSTEM_MPFR=1 \
		USE_SYSTEM_PATCHELF=1 \
		USE_SYSTEM_PCRE=1 \
		USE_SYSTEM_UTF8PROC=1 \
		USE_SYSTEM_P7ZIP=1 \
		USE_SYSTEM_BLAS=1 \
		USE_SYSTEM_NGHTTP2=1 \
		USE_SYSTEM_CSL=1 \
		USE_SYSTEM_LIBUNWIND=1

OPTIONS_DEFINE=		DEBUG DOCS NATIVE GPL_LIBS
OPTIONS_DEFAULT=	DOCS GPL_LIBS
OPTIONS_SUB=		yes

DEBUG_MAKE_ARGS=	FORCE_ASSERTIONS=1 \
			ALL_TARGET=all \
			BUNDLE_DEBUG_LIBS=1

DOCS_VARS=		INSTALL_TARGET+=install-docs

GPL_LIBS_DESC=		Build with GPL library suitesparse
GPL_LIBS_LIB_DEPENDS=	libspqr.so:math/suitesparse-spqr \
			libumfpack.so:math/suitesparse-umfpack
GPL_LIBS_MAKE_ARGS=	USE_SYSTEM_LIBSUITESPARSE=1 \
			USE_GPL_LIBS=1

NATIVE_DESC=		Build with native CPU JIT tuning
NATIVE_MAKE_ARGS=	MARCH=native

post-patch:
	echo "override TAGGED_RELEASE_BANNER=\"FreeBSD port lang/${PORTNAME} build\"" >> ${WRKSRC}/Make.user
	# unset ARCH for auto-detection
	# Julia build script uses the name x86_86/x86, which are different from ports framework
	echo "ARCH=" >> ${WRKSRC}/Make.user
	echo "LIBBLAS=-lopenblas -L${LOCALBASE}/lib" >> ${WRKSRC}/Make.user
	echo "LIBBLASNAME=libopenblas" >> ${WRKSRC}/Make.user
	echo 'LIBLAPACK= $$(LIBBLAS)' >> ${WRKSRC}/Make.user
	echo 'LIBLAPACKNAME= $$(LIBBLASNAME)' >> ${WRKSRC}/Make.user

post-configure:
	${CC} ${CFLAGS} -lopenblas ${LDFLAGS} -o ${WRKSRC}/check_openblas \
		${FILESDIR}/check_openblas.c
	${WRKSRC}/check_openblas && ( \
		echo "USE_BLAS64=1" >> ${WRKSRC}/Make.user \
	) || ( \
		echo "USE_BLAS64=0" >> ${WRKSRC}/Make.user \
	)

post-install:
	# clean up for Pkg3.jl
.for file in .codecov.yml .travis.yml appveyor.yml bors.toml .gitignore source-extracted
	${FIND} ${STAGEDIR}${PREFIX}/share/julia/ -name ${file} -delete
.endfor
.for dir in Statistics SuiteSparse ArgTools Pkg Downloads LibCURL NetworkOptions Tar
	${RM} -fr ${STAGEDIR}${PREFIX}/share/julia/stdlib/v${PORTVERSION:R}/${dir}/.github/
.endfor

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${PREFIX}/${INSTALLDIR}/share/doc

post-install-DEBUG-off:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/julia*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libjulia.so*
.for bin in libccalltest.so libllvmcalltest.so libjulia-internal.so* libblastrampoline.so libdSFMT.so libuv.so* libz.so* libLLVM* sys.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/julia/${bin}
.endfor

.include <bsd.port.mk>
