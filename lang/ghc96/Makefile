PORTREVISION=		0
PKGNAMESUFFIX=		96

LIB_DEPENDS=		${GMP_LIB_DEPENDS}

CONFIGURE_ARGS=		${GMP_CONFIGURE_ON}

OPTIONS_DEFINE=		DYNAMIC PROFILE

GHC_VERSION=		9.6.7
LLVM_VERSION=		15
BASE_PACKAGES=		Cabal-3.10.3.0 array-0.5.8.0 base-4.18.3.0 binary-0.8.9.1 \
			bytestring-0.11.5.4 containers-0.6.7 deepseq-1.4.8.1 \
			directory-1.3.8.5 exceptions-0.10.7 filepath-1.4.301.0 \
			ghc-${GHC_VERSION} ghc-bignum-1.3 ghc-compact-0.1.0.0 \
			ghc-prim-0.10.0 haskeline-0.8.2.1 hpc-0.6.2.0 \
			integer-gmp-1.1 mtl-2.3.1 parsec-3.1.16.1 pretty-1.1.3.6 \
			process-1.6.19.0 stm-2.5.1.0 template-haskell-2.20.0.0 \
			terminfo-0.4.1.6 text-2.0.2 time-1.12.2 \
			transformers-0.6.1.0 unix-2.8.6.0 xhtml-3000.2.2.1
BOOT_GHC_VERSION=	9.2.8
BOOT_LLVM_VERSION=	12

MASTERDIR=	${.CURDIR}/../ghc
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

.include	"${MASTERDIR}/Makefile"
