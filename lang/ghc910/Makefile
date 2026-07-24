PORTREVISION=		0
PKGNAMESUFFIX=		910

OPTIONS_DEFINE=		DYNAMIC GMP PROFILE

GHC_VERSION=		9.10.3
LLVM_VERSION=		15
BASE_PACKAGES=		Cabal-3.12.1.0 array-0.5.8.0 base-4.20.2.0 binary-0.8.9.3 \
			bytestring-0.12.2.0 containers-0.7 deepseq-1.5.0.0 \
			directory-1.3.8.5 exceptions-0.10.9 filepath-1.5.4.0 \
			ghc-${GHC_VERSION} ghc-bignum-1.3 ghc-compact-0.1.0.0 \
			ghc-experimental-9.1003.0 ghc-internal-9.1003.0 \
			ghc-platform-0.1.0.0 ghc-prim-0.12.0 ghc-toolchain-0.1.0.0 \
			haskeline-0.8.2.1 hpc-0.7.0.2 integer-gmp-1.1 mtl-2.3.1 \
			os-string-2.0.7 parsec-3.1.18.0 pretty-1.1.3.6 \
			process-1.6.26.1 stm-2.5.3.1 semaphore-compat-1.0.0 \
			template-haskell-2.22.0.0 terminfo-0.4.1.7 text-2.1.3 \
			time-1.12.2 transformers-0.6.1.1 unix-2.8.7.0 \
			xhtml-3000.2.2.1
BOOT_GHC_VERSION=	9.6.7
BOOT_LLVM_VERSION=	12

MASTERDIR=	${.CURDIR}/../ghc
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

.include	"${MASTERDIR}/Makefile"
