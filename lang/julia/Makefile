PORTNAME=	julia
DISTVERSION=	1.13.3
DISTVERSIONSUFFIX=	-full
CATEGORIES=	lang math science
MASTER_SITES=	https://github.com/JuliaLang/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	julia-${PORTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of Julia, a language for technical computing
WWW=		https://julialang.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	Has not been ported to this platform for freebsd

BUILD_RUN_DEPENDS=	\
		7zz:archivers/7-zip \
		ca_root_nss>=0:security/ca_root_nss \
		gfortran${_GCC_VER}:lang/gcc${_GCC_VER}
BUILD_DEPENDS=	gawk:lang/gawk \
		patchelf:sysutils/patchelf \
		gsed:textproc/gsed
LIB_DEPENDS=	libamd.so:math/suitesparse-amd \
		libbtf.so:math/suitesparse-btf \
		libcamd.so:math/suitesparse-camd \
		libccolamd.so:math/suitesparse-ccolamd \
		libcholmod.so:math/suitesparse-cholmod \
		libcolamd.so:math/suitesparse-colamd \
		libcurl.so:ftp/curl \
		libdSFMT.so:math/dsfmt \
		libelf.so:devel/elfutils \
		libgit2.so:devel/libgit2 \
		libgmp.so:math/gmp \
		libklu.so:math/suitesparse-klu \
		libldl.so:math/suitesparse-ldl \
		libnghttp2.so:www/libnghttp2 \
		libmbedcrypto.so:security/mbedtls3 \
		libmpfr.so:math/mpfr \
		libopenlibm.so:math/openlibm \
		libpcre2-8.so:devel/pcre2 \
		librbio.so:math/suitesparse-rbio \
		libssh2.so:security/libssh2 \
		libspqr.so:math/suitesparse-spqr \
		libumfpack.so:math/suitesparse-umfpack \
		libunwind.so:devel/libunwind \
		libutf8proc.so:textproc/utf8proc \
		libzstd.so:archivers/zstd

BUILD_DEPENDS_amd64=	ittapi>0:devel/ittapi
BUILD_DEPENDS_i386=	ittapi>0:devel/ittapi

# Do not set USES=fortran to avoid extra-linkage
USES=		blaslapack:openblas cmake:indirect compiler:c++17-lang cpe elfctl \
		gmake libedit llvm:min=20,lib perl5 python shebangfix
#USES+=	ssl	# Not supported by some artifacts
_GCC_VER=	${GCC_DEFAULT:S/.//}

DOCS_DISTFILES=	UnicodeData.txt:unicode \
		${DARC_afexpat}:afexpat \
		${DARC_afgit}:afgit \
		${DARC_afgitlfs}:afgitlfs \
		${DARC_aflibiconv}:aflibiconv \
		${DARC_afopenssh}:afopenssh \
		${JPKGSHA1}:jpkg
DOCS_MASTER_SITES=	\
		https://www.unicode.org/Public/${UNICODE_DATA_VERSION}/ucd/:unicode \
		https://jp.pkg.julialang.org/registry/${JPKGUUID}/:jpkg \
		https://github.com/JuliaBinaryWrappers/Expat_jll.jl/releases/download/Expat-v2.8.3+0/:afexpat \
		https://github.com/JuliaBinaryWrappers/Git_jll.jl/releases/download/Git-v2.55.0+0/:afgit \
		https://github.com/JuliaBinaryWrappers/Git_LFS_jll.jl/releases/download/Git_LFS-v3.7.1+0/:afgitlfs \
		https://github.com/JuliaBinaryWrappers/Libiconv_jll.jl/releases/download/Libiconv-v1.18.0+0/:aflibiconv \
		https://github.com/JuliaBinaryWrappers/OpenSSH_jll.jl/releases/download/OpenSSH-v10.5.1+0/:afopenssh

CPE_VENDOR=	julialang

ELF_FEATURES=	+wxneeded:usr/bin/julia

USE_LDCONFIG=	${PREFIX}/lib/julia

GMP_VER=	6.3.0	# Version of math/gmp
MPFR_VER=	4.2.2	# Version of math/mpfr

# Warning if you set USE_SYSTEM_ZLIB=1, the artifacts are linked against libz.so.1, not libz.so.6
# Same for USE_SYSTEM_OPENSSL=1 and libssl.so.3 != /usr/lib/libssl.so.35
# /!\ Julia could be vulnerable in case of SSL issues.
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
		USE_SYSTEM_LAPACK=1 \
		USE_SYSTEM_LIBGIT2=1 \
		USE_SYSTEM_LIBM=0 \
		USE_SYSTEM_LIBSSH2=1 \
		USE_SYSTEM_LIBUNWIND=1 \
		USE_SYSTEM_LIBUV=0 \
		USE_SYSTEM_LLD=1 \
		USE_SYSTEM_LIBSUITESPARSE=1 \
		USE_SYSTEM_LLVM=1 \
		USE_LLVM_SHLIB=1 \
		USE_SYSTEM_MPFR=1 \
		USE_SYSTEM_NGHTTP2=1 \
		USE_SYSTEM_OPENLIBM=1 \
		USE_SYSTEM_OPENSSL=0 \
		USE_SYSTEM_P7ZIP=1 \
		USE_SYSTEM_PATCHELF=1 \
		USE_SYSTEM_PCRE=1 \
		USE_SYSTEM_UTF8PROC=1 \
		USE_SYSTEM_ZLIB=0 \
		USE_SYSTEM_ZSTD=1 \
		CC=${CC} \
		CXX=${CXX}
ALL_TARGET=	default
INSTALL_TARGET=	install
TEST_TARGET=	test
TESTING_UNSAFE=	yes # It would prefer openblas64 + others to be investigated

CFLAGS+=	-fpic

BINARY_ALIAS=	awk=gawk sed=gsed	\
		dsymutil=dsymutil${LLVM_VERSION} \
		lld=lld${LLVM_VERSION} \
		llvm-config=${LLVM_CONFIG} \
		python3=${PYTHON_CMD}	\
		gfortran=gfortran${_GCC_VER}

WRKSRC=		${WRKDIR}/julia-${DISTVERSION}

PLIST_SUB=	VERSION="${PORTVERSION}" \
		MINOR="${PORTVERSION:R}"
PORTDOCS=	html

OPTIONS_DEFINE=		DEBUG DOCS NATIVE
OPTIONS_DEFAULT=	DOCS
OPTIONS_SUB=		yes

NATIVE_DESC=		Build with native CPU JIT tuning
NATIVE_MAKE_ARGS=	JULIA_CPU_TARGET=native

DEBUG_VARS=		ALL_TARGET=all \
			WITH_DEBUG=yes
DEBUG_MAKE_ARGS=	FORCE_ASSERTIONS=1 \
			BUNDLE_DEBUG_LIBS=1 \
			MAKECMDGOALS=debug

DOCS_MAKE_ENV+=		JULIA_PKG_OFFLINE="true"
DOCS_VARS=		ALL_TARGET+=docs  \
			INSTALL_TARGET+=install-docs

TEST_ENV+=		OMP_NUM_THREADS=1

LATE_SHEBANG_GLOB=	compile.jl generator.jl

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
MAKE_ARGS+=	USE_SYSTEM_ITTAPI=1
.endif

USE_GITHUB=	nodefault
SHA1_JULIA=	b21d6d84e46f6c97ecbc8e4e8a8ea6ad98049ea8
# LIBUV not compatible with the port devel/libuv
GH_TUPLE=	\
	JuliaLang:libuv:${SHA1_JULIA}:libuv

.if ${PORT_OPTIONS:MDOCS}
UNICODE_DATA_VERSION=	17.0.0
# See files/gen-docs-stuff.sh to regenerate GH_TUPLE
GH_TUPLE+=	\
	JuliaCollections:AbstractTrees.jl:6f9cd4ad60dc579f7a3271950d4846610c2f340d:abstracttrees \
	JuliaDocs:ANSIColoredPrinters.jl:v0.0.1:ansicoloredprinters \
	JuliaIO:CodecZlib.jl:v0.7.9:codeczlib \
	JuliaDocs:DocStringExtensions.jl:v0.9.5:docstringextensions \
	JuliaDocs:Documenter.jl:v1.19.0:documenter \
	JuliaBinaryWrappers:Expat_jll.jl:Expat-v2.8.3+0:expatjll \
	JuliaVersionControl:Git.jl:eb038049fdc4fc7da8410d3e8d5af5bfbe235248:git \
	JuliaBinaryWrappers:Git_jll.jl:Git-v2.55.0+0:gitjll \
	JuliaBinaryWrappers:Git_LFS_jll.jl:Git_LFS-v3.7.1+0:gitlfsjll \
	JuliaDocs:IOCapture.jl:v1.0.0:iocapture \
	JuliaPackaging:JLLWrappers.jl:v1.8.0:jllwrappers \
	JuliaIO:JSON.jl:v1.7.1:json \
	KristofferC:LazilyInitializedFields.jl:a8776608095f107a601b47bbc27c86caa3c612fc:lazilyinitializedfields \
	JuliaBinaryWrappers:Libiconv_jll.jl:Libiconv-v1.18.0+0:libiconvjll \
	JuliaDocs:MarkdownAST.jl:v0.1.3:markdownast \
	JuliaBinaryWrappers:OpenSSH_jll.jl:OpenSSH-v10.5.1+0:opensshjll \
	JuliaData:Parsers.jl:v2.8.7:parsers \
	JuliaLang:PrecompileTools.jl:v1.3.4:precompiletools \
	JuliaPackaging:Preferences.jl:v1.5.2:preferences \
	JuliaRegistries:RegistryInstances.jl:v0.1.0:registryinstances \
	JuliaServices:StructUtils.jl:v2.8.5:structutils \
	JuliaIO:TranscodingStreams.jl:v0.11.3:transcodingstreams
DOCPKGDIR_abstracttrees=	AbstractTrees
DOCPKGDIR_ansicoloredprinters=	ANSIColoredPrinters
DOCPKGDIR_codeczlib=	CodecZlib
DOCPKGDIR_docstringextensions=	DocStringExtensions
DOCPKGDIR_documenter=	Documenter
DOCPKGDIR_expatjll=	Expat_jll
DOCPKGDIR_git=		Git
DOCPKGDIR_gitjll=	Git_jll
DOCPKGDIR_gitlfsjll=	Git_LFS_jll
DOCPKGDIR_iocapture=	IOCapture
DOCPKGDIR_jllwrappers=	JLLWrappers
DOCPKGDIR_json=		JSON
DOCPKGDIR_lazilyinitializedfields=	LazilyInitializedFields
DOCPKGDIR_libiconvjll=	Libiconv_jll
DOCPKGDIR_markdownast=	MarkdownAST
DOCPKGDIR_opensshjll=	OpenSSH_jll
DOCPKGDIR_parsers=	Parsers
DOCPKGDIR_precompiletools=	PrecompileTools
DOCPKGDIR_preferences=	Preferences
DOCPKGDIR_registryinstances=	RegistryInstances
DOCPKGDIR_structutils=	StructUtils
DOCPKGDIR_transcodingstreams=	TranscodingStreams
JPKGUUID=	23338594-aafe-5451-b93e-139f81909106
JPKGSHA1=	1edcb1202670b2a845eca32c6b3b838a80785c8f
ADIR_afexpat=	a764c804bdcc4e2d454b972688bf8b3b8f527ab0
ADIR_afgit=	809f55a48211bb703df70cf2f348ea2b10253bb6
ADIR_afgitlfs=	407b2d6a1112f15186d59fdebe33c77aa9c669ed
ADIR_aflibiconv=06ea3cc0c9925172aafee4b52f98b99ec11b04ff
ADIR_afopenssh=	83aff31b530088d4cd29a289450cda08a588bcc7
DARC_afexpat=	Expat.v2.8.3.x86_64-unknown-freebsd.tar.gz
DARC_afgit=	Git.v2.55.0.x86_64-unknown-freebsd.tar.gz
DARC_afgitlfs=	Git_LFS.v3.7.1.x86_64-unknown-freebsd.tar.gz
DARC_aflibiconv=Libiconv.v1.18.0.x86_64-unknown-freebsd.tar.gz
DARC_afopenssh=	OpenSSH.v10.5.1.x86_64-unknown-freebsd.tar.gz
.endif

LATE_PATCHES=	stdlib_SparseArrays_test_fixed.jl.patch \
		stdlib_Tar_test_runtest.jl.patch

.if ${OSVERSION} >= 1500000
# Some artifacts depend on libgssapi.so.10, e.g. libQt6Network.so for Plots
RUN_DEPENDS+=	${LOCALBASE}/lib/compat/libgssapi.so.10:misc/compat14x
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/deps/srccache
	#${CP} ${FILESDIR}/llvm-patch-backport-version-fixes \
		${WRKSRC}/deps/patches/llvm-version-fixes.patch
	${CP} ${DISTDIR}/${DIST_SUBDIR}/JuliaLang-libuv-${SHA1_JULIA}_GH0.tar.gz	\
		${WRKSRC}/deps/libuv-${SHA1_JULIA}.tar.gz

post-extract-DOCS-on:
	@${MKDIR} ${WRKSRC}/doc/deps/registries
	${CP} ${DISTDIR}/${DIST_SUBDIR}/UnicodeData.txt \
		${WRKSRC}/deps/srccache/UnicodeData-${UNICODE_DATA_VERSION}.txt
.for pkg in abstracttrees ansicoloredprinters codeczlib docstringextensions \
	documenter expatjll git gitjll gitlfsjll iocapture jllwrappers json \
	lazilyinitializedfields libiconvjll markdownast opensshjll parsers \
	precompiletools preferences registryinstances structutils transcodingstreams
	@${MKDIR} ${WRKSRC}/doc/deps/packages/${DOCPKGDIR_${pkg}}
	${TAR} -C ${WRKSRC}/doc/deps/packages/${DOCPKGDIR_${pkg}} \
		--strip-components 1 \
		-xf ${DISTDIR}/${DIST_SUBDIR}/${DISTFILE_${pkg}}
.endfor
.for af in afexpat afgit afgitlfs aflibiconv afopenssh
	@${MKDIR} ${WRKSRC}/deps/jlutilities/depot/artifacts/${ADIR_${af}}
	${TAR} -C ${WRKSRC}/deps/jlutilities/depot/artifacts/${ADIR_${af}} \
		-xf ${DISTDIR}/${DIST_SUBDIR}/${DARC_${af}}
.endfor
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${JPKGSHA1} \
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
	${CP} ${WRKSRC}/deps/srccache/cacert-2026-10-20.pem ${WRKSRC}/usr/share/julia/cert.pem
.for patch in ${LATE_PATCHES}
	${PATCH} -d ${WRKSRC} -p0 < ${PATCHDIR}/${patch}
.endfor

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
	(cd ${STAGEDIR}${PREFIX}/lib/julia &&	\
	${LN} -fs libLLVM.so libLLVM-${LLVM_VERSION}jl.so)
.for bin in lld dsymutil
	(cd ${STAGEDIR}${PREFIX}/libexec/julia &&	\
	${LN} -fs ${LLVM_PREFIX}/bin/${bin})
.endfor
	@${MV} ${STAGEDIR}${ETCDIR}/startup.jl \
		${STAGEDIR}${ETCDIR}/startup.jl.sample

post-stage:
	cd ${STAGEDIR}${PREFIX} && ${FIND} ${DATADIR_REL}/compiled -type f -o -type l > ${WRKDIR}/PLIST.compiled
	cd ${WRKDIR} && ${SED} -i -e "/PLIST.compiled/r PLIST.compiled" ${TMPPLIST}

.include <bsd.port.post.mk>
