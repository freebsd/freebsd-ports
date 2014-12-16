# $FreeBSD$

PORTREVISION=1
PKGNAMEPREFIX=	arm-none-eabi-
COMMENT=	GNU Compiler Collection for bare metal arm cross-development
GCC_TARGET=	arm-none-eabi
PLIST=	${.CURDIR}/pkg-plist

MASTERDIR=	${.CURDIR}/../powerpc64-gcc

.include "${MASTERDIR}/Makefile"

# U-Boot requires libgcc, crossbuild and install it.
ALL_TARGET+=	all-target-libgcc
INSTALL_TARGET+=	install-target-libgcc

# libstdcxx won't build, but we don't need it or multiple float-abi libs.
CONFIGURE_ARGS+=	--disable-libstdcxx --disable-multilib

# The following is required for clang to bootstrap gcc.
.if ${COMPILER_TYPE} == clang
MAKE_ARGS+=	CXXFLAGS=-fbracket-depth=512
.endif
