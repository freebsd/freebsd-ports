# $FreeBSD$

PKGNAMEPREFIX=	amd64-
PLIST=	${.CURDIR}/pkg-plist

MASTERDIR=	${.CURDIR}/../powerpc64-gcc
GCC_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
BU_PREFIX=	x86_64-${OPSYS:tl}
FREEBSD_EXTENSION=	yes

BROKEN_powerpc64=	Does not build

.include "${MASTERDIR}/Makefile"
