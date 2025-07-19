PORTREVISION=		1
PKGNAMESUFFIX=		94

LIB_DEPENDS=		${GMP_LIB_DEPENDS}

CONFIGURE_ARGS=		${GMP_CONFIGURE_ON}

OPTIONS_DEFINE=		DYNAMIC PROFILE

GHC_VERSION=		9.4.8
LLVM_VERSION=		13
BASE_PACKAGES=		Cabal-3.8.1.0 array-0.5.4.0 base-4.17.2.1 binary-0.8.9.1 \
			bytestring-0.11.5.3 containers-0.6.7 deepseq-1.4.8.0 \
			directory-1.3.7.1 exceptions-0.10.5 filepath-1.4.2.2 \
			ghc-${GHC_VERSION} ghc-bignum-1.3 ghc-compact-0.1.0.0 \
			ghc-prim-0.9.1 haskeline-0.8.2 hpc-0.6.1.0 \
			integer-gmp-1.1 mtl-2.2.2 parsec-3.1.16.1 pretty-1.1.3.6 \
			process-1.6.18.0 stm-2.5.1.0 template-haskell-2.19.0.0 \
			terminfo-0.4.1.5 text-2.0.2 time-1.12.2 \
			transformers-0.5.6.2 unix-2.7.3 xhtml-3000.2.2.1
BOOT_GHC_VERSION=	9.2.8
BOOT_LLVM_VERSION=	12

MASTERDIR=	${.CURDIR}/../ghc
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

.include	"${MASTERDIR}/Makefile"
