# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
PKGNAMESUFFIX=	-x86

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Infrastructure for C/Ada Android cross-compiler (x86)

BRANCH2=	x86_32
XCCTARGET=	i686-aux-linux-android
PREFIX=		${LOCALBASE}/android-x86
SYSROOT=	gnatdroid-sysroot-x86
MASTERDIR=	${.CURDIR}/../../lang/gnatdroid-binutils
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
