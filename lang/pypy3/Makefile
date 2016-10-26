# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pypy3
PORTREVISION=	1
DISTVERSION=	5.5.0-alpha
DISTNAME=	${PORTNAME}.3-v${DISTVERSION}-src

MASTERDIR=	${.CURDIR}/../pypy

WRKSRC=		${WRKDIR}/${PORTNAME}-v${DISTVERSION:C/-.*//}-src
BUILD_WRKSRC?=	${WRKDIR}/build/usession-release-${PORTNAME}.3-${DISTVERSION:C/-.*//}-0/testing_1

PACKAGE_ARGS=	--without-_gdbm --without-sqlite3 --without-tk

PYPY_CFFI_VER=	pypy3-55

.include "${MASTERDIR}/Makefile"
