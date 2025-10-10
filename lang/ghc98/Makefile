PORTREVISION=		0
PKGNAMESUFFIX=		98

OPTIONS_DEFINE=		DYNAMIC GMP PROFILE

GHC_VERSION=		9.8.4
LLVM_VERSION=		15
BASE_PACKAGES=		Cabal-3.10.3.0 array-0.5.8.0 base-4.19.2.0 binary-0.8.9.1 \
			bytestring-0.12.1.0 containers-0.6.8 deepseq-1.5.1.0 \
			directory-1.3.8.5 exceptions-0.10.7 filepath-1.4.301.0 \
			ghc-${GHC_VERSION} ghc-bignum-1.3 ghc-compact-0.1.0.0 \
			ghc-prim-0.11.0 haskeline-0.8.2.1 hpc-0.7.0.0 \
			integer-gmp-1.1 mtl-2.3.1 parsec-3.1.17.0 pretty-1.1.3.6 \
			process-1.6.25.0 stm-2.5.3.1 semaphore-compat-1.0.0 \
			template-haskell-2.21.0.0 terminfo-0.4.1.6 text-2.1.1 \
			time-1.12.2 transformers-0.6.1.0 unix-2.8.6.0 \
			xhtml-3000.2.2.1
BOOT_GHC_VERSION=	9.6.7
BOOT_LLVM_VERSION=	12

MASTERDIR=	${.CURDIR}/../ghc
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

.include	"${MASTERDIR}/Makefile"
