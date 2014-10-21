# $FreeBSD$

PKGNAMEPREFIX=	arm-none-eabi-
COMMENT=	GNU Compiler Collection for bare metal arm cross-development
GCC_TARGET=	arm-none-eabi
PLIST=	${.CURDIR}/pkg-plist
CFLAGS+=	-fbracket-depth=512

MASTERDIR=	${.CURDIR}/../powerpc64-gcc

.include "${MASTERDIR}/Makefile"
