PORTREVISION=		1
PKGNAMESUFFIX=		92

OPTIONS_DEFINE=		DYNAMIC GMP

DYNAMIC_OFF_FLAVOUR=	+no_dynamic_ghc

GHC_VERSION=		9.2.8
LLVM_VERSION=		12
BASE_PACKAGES=		Cabal-3.6.3.0 array-0.5.4.0 base-4.16.4.0 binary-0.8.9.0 \
			bytestring-0.11.4.0 containers-0.6.5.1 deepseq-1.4.6.1 \
			directory-1.3.6.2 exceptions-0.10.4 filepath-1.4.2.2 \
			ghc-${GHC_VERSION} ghc-bignum-1.2 ghc-compact-0.1.0.0 \
			ghc-prim-0.8.0 haskeline-0.8.2 hpc-0.6.1.0 \
			integer-gmp-1.1 mtl-2.2.2 parsec-3.1.15.0 pretty-1.3.3.6 \
			process-1.6.16.0 stm-2.5.0.2 template-haskell-2.18.0.0 \
			terminfo-0.4.1.5 text-1.2.5.0 time-1.11.1.1 \
			transformers-0.5.6.2 unix-2.7.2.2 xhtml-3000.2.2.1
BOOT_SCRIPT=		./boot
BOOT_GHC_VERSION=	9.2.8
BOOT_LLVM_VERSION=	12

MASTERDIR=	${.CURDIR}/../ghc
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

.include	"${MASTERDIR}/Makefile"
