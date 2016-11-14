# Created by: Martin Blapp <mb@FreeBSD.org>
# $FreeBSD$

MASTERDIR=	${.CURDIR}/../open-vm-tools
PKGNAMESUFFIX=	-nox11
OPTIONS_EXCLUDE=	X11 LIBNOTIFY

BROKEN_mips64=		Does not configure: error: Unknown architecture
BROKEN_powerpc64=	Does not build

.include "${MASTERDIR}/Makefile"
