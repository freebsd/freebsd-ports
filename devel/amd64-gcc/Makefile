# $FreeBSD$

PKGNAMEPREFIX=	amd64-
PLIST=	${.CURDIR}/pkg-plist

MASTERDIR=	${.CURDIR}/../powerpc64-gcc
GCC_TARGET=	x86_64-unknown-${OPSYS:tl}${OSREL}
BU_PREFIX=	x86_64-${OPSYS:tl}
FREEBSD_EXTENSION=	yes

BROKEN_aarch64=		error: invalid output constraint '=a' in asm
BROKEN_armv6=		fails to package
BROKEN_armv7=		fails to package
BROKEN_mips=		configure: error: cannot compute suffix of object files: cannot compile
BROKEN_mips64=		configure: error: cannot compute suffix of object files: cannot compile
BROKEN_powerpc64=	error: invalid output constraint in asm

.include "${MASTERDIR}/Makefile"
