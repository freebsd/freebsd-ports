PORTNAME=	julia
DISTVERSION=	1.10.5
PORTREVISION=	1
DISTVERSIONSUFFIX=	-full
CATEGORIES=	lang math
MASTER_SITES=	https://github.com/JuliaLang/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of Julia, a language for technical computing
WWW=		https://julialang.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	Has not been ported to this platform for freebsd

MY_DEPENDS=	7zz:archivers/7-zip \
		ca_root_nss>=0:security/ca_root_nss \
		gfortran${_GCC_VER}:lang/gcc${_GCC_VER}
BUILD_DEPENDS=	patchelf:sysutils/patchelf \
		cmake:devel/cmake-core \
		${MY_DEPENDS}
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libdSFMT.so:math/dsfmt \
		libgit2.so:devel/libgit2 \
		libgmp.so:math/gmp \
		libnghttp2.so:www/libnghttp2 \
		libmpfr.so:math/mpfr \
		libopenlibm.so:math/openlibm \
		libpcre2-8.so:devel/pcre2 \
		libssh2.so:security/libssh2 \
		libmbedcrypto.so:security/mbedtls3 \
		libspqr.so:math/suitesparse-spqr \
		libumfpack.so:math/suitesparse-umfpack \
		libutf8proc.so:textproc/utf8proc \
		libunwind.so:devel/libunwind \
		libzstd.so:archivers/zstd \
		libelf.so:devel/elfutils
RUN_DEPENDS=	${MY_DEPENDS}

BUILD_DEPENDS_amd64=	ittapi>0:devel/ittapi
BUILD_DEPENDS_i386=	ittapi>0:devel/ittapi

# Do not set USES=fortran to avoid extra-linkage
USES=		blaslapack:openblas compiler:c++17-lang cpe elfctl gmake \
		libedit perl5 python shebangfix
_GCC_VER=	${GCC_DEFAULT:S/.//}

DOCS_DISTFILES=	UnicodeData.txt:unicode \
		Expat.v2.6.2.x86_64-unknown-freebsd.tar.gz:afexpat \
		Git.v2.44.0.x86_64-unknown-freebsd.tar.gz:afgit \
		Libiconv.v1.17.0.x86_64-unknown-freebsd.tar.gz:aflibiconv \
		OpenSSL.v3.0.13.x86_64-unknown-freebsd.tar.gz:afopenssl \
		${JPKGSHA1}:jpkg
DOCS_MASTER_SITES=	https://www.unicode.org/Public/${UNICODE_DATA_VERSION}/ucd/:unicode \
		https://jp.pkg.julialang.org/registry/${JPKGUUID}/:jpkg \
		https://github.com/JuliaBinaryWrappers/Expat_jll.jl/releases/download/Expat-v2.6.2+0/:afexpat \
		https://github.com/JuliaBinaryWrappers/Git_jll.jl/releases/download/Git-v2.44.0+2/:afgit \
		https://github.com/JuliaBinaryWrappers/Libiconv_jll.jl/releases/download/Libiconv-v1.17.0+0/:aflibiconv \
		https://github.com/JuliaBinaryWrappers/OpenSSL_jll.jl/releases/download/OpenSSL-v3.0.13+1/:afopenssl

CPE_VENDOR=	julialang

ELF_FEATURES=	+wxneeded:usr/bin/julia

USE_LDCONFIG=	${PREFIX}/lib/julia

GMP_VER=	6.3.0	# Version of math/gmp
MPFR_VER=	4.2.2	# Version of math/mpfr

MAKE_ARGS+=	JULIA_DEBUG=Documenter \
		VERBOSE=1 \
		NO_GIT=1 \
		USE_BINARYBUILDER=0 \
		prefix=${PREFIX} \
		USE_GPL_LIBS=0 \
		ARCH=x86_64 \
		JULIA_CPU_TARGET=generic \
		USE_SYSTEM_BLAS=1 \
		USE_SYSTEM_CSL=1 \
		USE_SYSTEM_CURL=1 \
		USE_SYSTEM_DSFMT=1 \
		USE_SYSTEM_GMP=1 \
		USE_SYSTEM_OPENLIBM=1 \
		USE_SYSTEM_LAPACK=1 \
		USE_SYSTEM_LIBGIT2=1 \
		USE_SYSTEM_LIBSSH2=1 \
		USE_SYSTEM_LIBUNWIND=1 \
		USE_SYSTEM_LLD=1 \
		USE_SYSTEM_MPFR=1 \
		USE_SYSTEM_NGHTTP2=1 \
		USE_SYSTEM_P7ZIP=1 \
		USE_SYSTEM_PATCHELF=1 \
		USE_SYSTEM_PCRE=1 \
		USE_SYSTEM_UTF8PROC=1 \
		USE_SYSTEM_ZLIB=0 \
		CC=${CC} \
		CXX=${CXX}
ALL_TARGET=	default
INSTALL_TARGET=	install
TEST_TARGET=	test

CFLAGS+=	-fpic

BINARY_ALIAS=	python3=${PYTHON_CMD} gfortran=gfortran${_GCC_VER}

WRKSRC=		${WRKDIR}/julia-${DISTVERSION}

PLIST_SUB=	VERSION="${PORTVERSION}" \
		MINOR="${PORTVERSION:R}"
PORTDOCS=	html

OPTIONS_DEFINE=		DEBUG DOCS NATIVE
OPTIONS_DEFAULT=	DOCS
OPTIONS_SUB=		yes

NATIVE_DESC=		Build with native CPU JIT tuning
NATIVE_MAKE_ARGS=	JULIA_CPU_TARGET=native

DEBUG_VARS=		ALL_TARGET=all
DEBUG_MAKE_ARGS=	FORCE_ASSERTIONS=1 \
			BUNDLE_DEBUG_LIBS=1

DOCS_MAKE_ENV+=		JULIA_PKG_OFFLINE="true"
DOCS_VARS=		ALL_TARGET+=docs  \
			INSTALL_TARGET+=install-docs

TEST_ENV+=		OMP_NUM_THREADS=1

LATE_SHEBANG_GLOB=	compile.jl generator.jl

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
MAKE_ARGS+=	USE_SYSTEM_ITTAPI=1
.endif

.if ${PORT_OPTIONS:MDOCS}
USE_GITHUB=	nodefault
UNICODE_DATA_VERSION=	13.0.0
GH_TUPLE=	JuliaDocs:Documenter.jl:v1.4.1:documenter \
	JuliaDocs:ANSIColoredPrinters.jl:v0.0.1:ansicoloredprinters \
	JuliaCollections:AbstractTrees.jl:6f9cd4ad60dc579f7a3271950d4846610c2f340d:abstracttrees \
	JuliaIO:CodecZlib.jl:v0.7.4:codeczlib \
	JuliaDocs:DocStringExtensions.jl:v0.9.3:docstringextensions \
	JuliaDocs:DocumenterInventoryWritingBackport.jl:v0.1.0:documenterinventorywritingbackport \
	JuliaBinaryWrappers:Expat_jll.jl:Expat-v2.6.2+0:expatjll \
	JuliaVersionControl:Git.jl:v1.3.1:git \
	JuliaBinaryWrappers:Git_jll.jl:Git-v2.44.0+2:gitjll \
	JuliaDocs:IOCapture.jl:v0.2.4:iocapture \
	JuliaPackaging:JLLWrappers.jl:v1.5.0:jllwrappers \
	JuliaIO:JSON.jl:v0.21.4:json \
	KristofferC:LazilyInitializedFields.jl:3b6cc53c8780ebbe3ee209b8a8e6b8844ce284f2:lazilyinitializedfields \
	JuliaBinaryWrappers:Libiconv_jll.jl:Libiconv-v1.17.0+0:libiconvjll \
	JuliaDocs:MarkdownAST.jl:v0.1.2:markdownast \
	JuliaBinaryWrappers:OpenSSL_jll.jl:OpenSSL-v3.0.13+1:openssljll \
	JuliaData:Parsers.jl:v2.8.1:parsers \
	JuliaLang:PrecompileTools.jl:v1.2.1:precompiletools \
	JuliaPackaging:Preferences.jl:v1.4.3:preferences \
	GunnarFarneback:RegistryInstances.jl:2796d959014475bc19e2dfa174179cdf02642d28:registryinstances \
	JuliaIO:TranscodingStreams.jl:v0.10.8:transcodingstreams
DOCPKGDIR_documenter=	Documenter
DOCPKGDIR_abstracttrees=	AbstractTrees
DOCPKGDIR_ansicoloredprinters=	ANSIColoredPrinters
DOCPKGDIR_codeczlib=	CodecZlib
DOCPKGDIR_docstringextensions=	DocStringExtensions
DOCPKGDIR_documenterinventorywritingbackport=	DocumenterInventoryWritingBackport
DOCPKGDIR_expatjll=	Expat_jll
DOCPKGDIR_git=		Git
DOCPKGDIR_gitjll=	Git_jll
DOCPKGDIR_iocapture=	IOCapture
DOCPKGDIR_jllwrappers=	JLLWrappers
DOCPKGDIR_json=		JSON
DOCPKGDIR_lazilyinitializedfields=	LazilyInitializedFields
DOCPKGDIR_libiconvjll=	Libiconv_jll
DOCPKGDIR_markdownast=	MarkdownAST
DOCPKGDIR_openssljll=	OpenSSL_jll
DOCPKGDIR_parsers=	Parsers
DOCPKGDIR_precompiletools=	PrecompileTools
DOCPKGDIR_preferences=	Preferences
DOCPKGDIR_registryinstances=	RegistryInstances
DOCPKGDIR_transcodingstreams=	TranscodingStreams
JPKGUUID=	23338594-aafe-5451-b93e-139f81909106
JPKGSHA1=	151ade91c9c8fcadd03fda2a9df961a173dae33d
ADIR_afexpat=	f6cac9c7c81901bdea8226624199290c849eb8fd
ADIR_afgit=	9d10e86e65fcea93f0a73ac9ab7efbc9507ef246
ADIR_aflibiconv=	7f55b73b331bc9ab70cbd95a194c89feb3650f16
ADIR_afopenssl=	f87ab68c6b682f7ab08df0745d5e38edb8e5bded
DARC_afexpat=	Expat.v2.6.2.x86_64-unknown-freebsd.tar.gz
DARC_afgit=	Git.v2.44.0.x86_64-unknown-freebsd.tar.gz
DARC_aflibiconv=	Libiconv.v1.17.0.x86_64-unknown-freebsd.tar.gz
DARC_afopenssl=	OpenSSL.v3.0.13.x86_64-unknown-freebsd.tar.gz
.endif

LATE_PATCHES=	stdlib_SparseArrays_test_fixed.jl.patch \
		stdlib_SparseArrays_test_testgroups.patch \
		stdlib_Tar_test_runtest.jl.patch

post-extract:
	@${MKDIR} ${WRKSRC}/deps/srccache
	${CP} ${FILESDIR}/llvm-patch-backport-version-fixes \
		${WRKSRC}/deps/patches/llvm-version-fixes.patch

post-extract-DOCS-on:
	@${MKDIR} ${WRKSRC}/doc/deps/registries
	${CP} ${DISTDIR}/UnicodeData.txt \
		${WRKSRC}/deps/srccache/UnicodeData-${UNICODE_DATA_VERSION}.txt
.for pkg in documenter ansicoloredprinters abstracttrees codeczlib \
	docstringextensions documenterinventorywritingbackport expatjll \
	git gitjll iocapture jllwrappers json lazilyinitializedfields \
       	libiconvjll markdownast openssljll parsers precompiletools \
	preferences registryinstances transcodingstreams
	@${MKDIR} ${WRKSRC}/doc/deps/packages/${DOCPKGDIR_${pkg}}
	${TAR} -C ${WRKSRC}/doc/deps/packages/${DOCPKGDIR_${pkg}} \
		--strip-components 1 \
		-xf ${DISTDIR}/${DISTFILE_${pkg}}
.endfor
.for af in afexpat afgit aflibiconv afopenssl
	@${MKDIR} ${WRKSRC}/doc/deps/artifacts/${ADIR_${af}}
	${TAR} -C ${WRKSRC}/doc/deps/artifacts/${ADIR_${af}} \
		-xf ${DISTDIR}/${DARC_${af}}
.endfor
	${CP} ${DISTDIR}/${JPKGSHA1} \
		${WRKSRC}/doc/deps/registries/General.tar.gz
	${CAT} ${FILESDIR}/General.toml.in | \
		${SED} 's/%%UUID%%/${JPKGUUID}/' | \
		${SED} 's/%%SHA1%%/${JPKGSHA1}/' \
		> ${WRKSRC}/doc/deps/registries/General.toml

pre-configure:
	echo "override TAGGED_RELEASE_BANNER=\"FreeBSD port lang/${PORTNAME} build\"" >> ${WRKSRC}/Make.user
	# unset ARCH for auto-detection
	# Julia build script uses the name x86_86/x86, which are different from ports framework
	echo "ARCH=" >> ${WRKSRC}/Make.user
	echo "LIBBLAS= -L${LOCALBASE}/lib -lopenblas" >> ${WRKSRC}/Make.user
	echo "LIBBLASNAME=libopenblas" >> ${WRKSRC}/Make.user
	echo 'LIBLAPACK= $$(LIBBLAS)' >> ${WRKSRC}/Make.user
	echo 'LIBLAPACKNAME= $$(LIBBLASNAME)' >> ${WRKSRC}/Make.user
	${CC} ${CFLAGS} -lopenblas ${LDFLAGS} -o ${WRKSRC}/check_openblas \
		${FILESDIR}/check_openblas.c
	${WRKSRC}/check_openblas && ( \
		echo "USE_BLAS64=1" >> ${WRKSRC}/Make.user \
	) || ( \
		echo "USE_BLAS64=0" >> ${WRKSRC}/Make.user \
	)
	${REINPLACE_CMD} -e 's|%%GMP_VER%%|${GMP_VER}|'		\
		${WRKSRC}/stdlib/GMP_jll/test/runtests.jl
	${REINPLACE_CMD} -e 's|%%MPFR_VER%%|${MPFR_VER}|'	\
		${WRKSRC}/stdlib/MPFR_jll/test/runtests.jl

pre-install:
	${MAKE} SHEBANG_GLOB="${LATE_SHEBANG_GLOB}" fix-shebang
	${CP} ${WRKSRC}/deps/srccache/cacert-2023-01-10.pem ${WRKSRC}/usr/share/julia/cert.pem
.for patch in ${LATE_PATCHES}
	${PATCH} -d ${WRKSRC} -p0 < ${PATCHDIR}/${patch}
.endfor

pre-install-DEBUG-on:
	@(cd ${INSTALL_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${FAKEROOT} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} \
		MAKECMDGOALS=debug install)

pre-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}

post-install:
.for file in .codecov.yml .travis.yml appveyor.yml bors.toml .gitignore source-extracted *.orig
	${FIND} ${STAGEDIR}${DATADIR} -name "${file}" -delete
.endfor
.for dir in .ci .devcontainer .github
	${FIND} ${STAGEDIR}${DATADIR} -name "${dir}" -type d -exec ${RM} -fr {} +
.endfor
	${RM} ${STAGEDIR}${DATADIR}/base.cache

	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/julia
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libjulia.so*
.for dir in lib/${PORTNAME} share/${PORTNAME}/compiled/v${PORTVERSION:R}
	${FIND} ${STAGEDIR}${PREFIX}/${dir} \
		\( -name *.so.* -o -name *.so \) -a -not \
		\( -name *-debug.so.* -o -name *-debug.so \) \
		-a -not -type l -exec ${STRIP_CMD} {} +
.endfor
.for bin in lld dsymutil
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/julia/${bin}
.endfor

	@${MV} ${STAGEDIR}${ETCDIR}/startup.jl \
		${STAGEDIR}${ETCDIR}/startup.jl.sample

post-stage:
	cd ${STAGEDIR}${PREFIX} && ${FIND} ${DATADIR_REL}/compiled -type f -o -type l > ${WRKDIR}/PLIST.compiled
	cd ${WRKDIR} && ${SED} -i -e "/PLIST.compiled/r PLIST.compiled" ${TMPPLIST}

.include <bsd.port.post.mk>
