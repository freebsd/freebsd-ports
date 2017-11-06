# $FreeBSD$

COMMENT=	GNU binutils for AArch64 cross-development
PKGNAMEPREFIX=	aarch64-
PLIST=	${.CURDIR}/pkg-plist

BROKEN_mips=		fails to configure: error: C compiler cannot create executables
BROKEN_mips64=		fails to configure: error: C compiler cannot create executables
BROKEN_powerpc64=	fails to configure: error: C compiler cannot create executables

MASTERDIR=	${.CURDIR}/../binutils
OPTIONS_DEFAULT=	STATIC

.include "${MASTERDIR}/Makefile"
