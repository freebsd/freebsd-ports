# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aarch64
PORTREVISION=	${ARM64_PR}
PKGNAMEPREFIX=	gnatcross-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C/Ada cross-compiler, target: ${LABEL_TARGET}

LABEL_TARGET=	FreeBSD/ARM64
DROID_TARGET=	aarch64-aux-freebsd11.3
ARG_ARCH=	# don't specify
ARG_FPU=	# don't specify
ARG_FLOATSOFT=	# don't specify
SRPREFIX=	${LOCALBASE}/FreeBSD_ARM64/sysroot
GNATPREFIX=	${LOCALBASE}/FreeBSD_ARM64
SYSROOT=	gnatcross-sysroot-aarch64
GDBINUTILS=	gnatcross-binutils-aarch64
MASTERDIR=	${.CURDIR}/../../lang/gnatdroid-armv7
PATCHDIR=	${.CURDIR}/files
DESCR=		${.CURDIR}/pkg-descr

ARG_TARGET_SPECIFIC=	# override ARM settings

.include "${MASTERDIR}/Makefile"
