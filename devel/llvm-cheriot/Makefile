# llvm-cheriot

LLVM_SUFFIX=	-cheriot

COMMENT=	LLVM and Clang with support the CHERIoT microcontroller
WWW=		https://www.microsoft.com/en-us/research/publication/cheriot-rethinking-security-for-low-cost-embedded-systems/

DISTINFO_FILE=	${.CURDIR}/distinfo
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

OPTIONS_EXCLUDE=	XTOOLCHAIN

LLVM_TARGETS=          RISCV
CMAKE_FLAGS+=	-DLLVM_DEFAULT_TARGET_TRIPLE=riscv32-unknown-unknown

.include "${.CURDIR}/Makefile.snapshot"

MASTERDIR=	${.CURDIR}/../llvm-cheri

.include "${MASTERDIR}/Makefile"
