# $FreeBSD$

PKGNAMEPREFIX=	arm-none-eabi-
GCC_TARGET=	arm-none-eabi
PLIST=	${.CURDIR}/pkg-plist

# libstdcxx won't build, but we don't need it or multiple float-abi libs.
CONFIGURE_ARGS=	--disable-libstdcxx \
		--disable-multilib

MASTERDIR=	${.CURDIR}/../aarch64-none-elf-gcc

.include "${MASTERDIR}/Makefile"
