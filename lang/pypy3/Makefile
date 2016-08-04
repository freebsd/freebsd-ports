# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pypy3
DISTVERSION=	5.2.0-alpha1
DISTNAME=	${PORTNAME}.3-v${DISTVERSION}-src

MASTERDIR=	${.CURDIR}/../pypy

BUILD_WRKSRC?=	${WRKDIR}/build/usession-release-pypy3.3-v5.2-0/testing_1

PACKAGE_ARGS=	--without-_gdbm --without-sqlite3 --without-tk

PYPY_CFFI_VER=	pypy3-52

.include "${MASTERDIR}/Makefile"
