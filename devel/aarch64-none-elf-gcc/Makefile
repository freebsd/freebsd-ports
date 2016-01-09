# $FreeBSD$

PKGNAMEPREFIX=	aarch64-none-elf-
COMMENT=	GNU Compiler Collection for bare metal arm cross-development
GCC_TARGET=	aarch64-none-elf
PLIST=	${.CURDIR}/pkg-plist

# U-Boot requires libgcc, crossbuild and install it along with the compiler.
ALL_TARGET=	all-gcc all-target-libgcc
INSTALL_TARGET=	install-gcc install-target-libgcc

MASTERDIR=	${.CURDIR}/../powerpc64-gcc

.include "${MASTERDIR}/Makefile"

# The following is required for clang to bootstrap gcc.
.if ${COMPILER_TYPE} == clang
MAKE_ARGS+=	CXXFLAGS=-fbracket-depth=512
.endif
