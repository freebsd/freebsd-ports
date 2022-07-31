PKGNAMESUFFIX=		810

LIB_DEPENDS=		${GMP_LIB_DEPENDS}

CONFIGURE_ARGS=		${GMP_CONFIGURE_WITH:C/^/--with-/}

OPTIONS_DEFINE=		DYNAMIC PROFILE

SLAVE_BUILD_MK=		BUILD_SPHINX_HTML=NO

GHC_VERSION=		8.10.7
LLVM_VERSION=		10
BASE_PACKAGES=		Cabal-3.2.1.0 array-0.5.4.0 base-4.14.3.0 binary-0.8.8.0 \
			bytestring-0.10.12.0 containers-0.6.5.1 deepseq-1.4.4.0 \
			directory-1.3.6.0 exceptions-0.10.4 filepath-1.4.2.1 \
			ghc-${GHC_VERSION} ghc-compact-0.1.0.0 \
			ghc-prim-0.6.1 haskeline-0.8.2 hpc-0.6.1.0 \
			integer-gmp-1.0.3.0 mtl-2.2.2 parsec-3.1.14.0 pretty-1.1.3.6 \
			process-1.6.13.2 stm-2.5.0.1 template-haskell-2.16.0.0 \
			terminfo-0.4.1.4 text-1.2.4.1 time-1.9.3 \
			transformers-0.5.6.2 unix-2.7.2.2 xhtml-3000.2.2.1

EXTRA_PATCHES=	${MASTERDIR}/files/extra-utils_llvm-targets_gen-data-layout.sh \
		${MASTERDIR}/files/patch-llvm-targets

MASTERDIR=	${.CURDIR}/../ghc
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

.include	"${MASTERDIR}/Makefile"
