# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

COMMENT=	32bit Wine built with the compholio patchset for 64bit FreeBSD

SLAVE_PORT=	i386-wine-devel

CONFLICTS=	i386-wine-[0-9]* wine-[0-9]* wine-compholio-[0-9]* i386-wine-devel-[0-9]* wine-devel-[0-9]*

OPTIONS_SET=	COMPHOLIO LIBXSLT GNUTLS HAL X11

SLAVEDIR=	${.CURDIR}/../i386-wine-devel
PLIST=		${MASTERDIR}/pkg-plist

.if !defined(ARCH)
ARCH!=          uname -p
.endif

.if ${ARCH} == i386
.include "${SLAVEDIR}/Makefile.i386"
PKGNAMESUFFIX=	-compholio
.else
MASTERDIR=	${SLAVEDIR}
PKGNAMESUFFIX=	-compholio
.include "${SLAVEDIR}/Makefile.inc"
.endif

