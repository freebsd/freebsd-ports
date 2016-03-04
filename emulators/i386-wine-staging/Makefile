# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD$

COMMENT=	32bit Wine built with the Staging patchset for 64bit FreeBSD

SLAVE_PORT=	i386-wine-devel

CONFLICTS_INSTALL=	i386-wine-[0-9]* wine-[0-9]* wine-staging-[0-9]* i386-wine-devel-[0-9]* wine-devel-[0-9]*

OPTIONS_SLAVE=	STAGING
OPTIONS_SET=	LIBXSLT MPG123 HAL V4L X11

SLAVEDIR=	${.CURDIR}/../i386-wine-devel
PLIST=		${MASTERDIR}/pkg-plist

.if !defined(ARCH)
ARCH!=          uname -p
.endif

PKGNAMESUFFIX=	-staging
.if ${ARCH} == i386
.include "${SLAVEDIR}/Makefile.i386"
.else
MASTERDIR=	${SLAVEDIR}
.include "${SLAVEDIR}/Makefile.inc"
.endif

