# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	1
PKGNAMEPREFIX=	gnatcross-
PKGNAMESUFFIX=	-aarch64

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Infrastructure for C/Ada FreeBSD cross-compiler (aarch64)

BRANCH2=	# Assume aarch64 will always be only CPU for FreeBSD/ARM64
XCCTARGET=	aarch64-aux-freebsd11.3
PREFIX=		${LOCALBASE}/FreeBSD_ARM64
SRPREFIX=	${PREFIX}/sysroot
SYSROOT=	gnatcross-sysroot-aarch64
MASTERDIR=	${.CURDIR}/../../lang/gnatdroid-binutils
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr

PLIST_SUB=	AMD64=${ARCH:S/i386/"@comment "/:S/${ARCH}/""/}

.include "${MASTERDIR}/Makefile"
