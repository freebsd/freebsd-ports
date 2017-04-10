# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pypy3
DISTVERSION=	5.7.1
DISTNAME=	${PORTNAME}-v${DISTVERSION}-src

MASTERDIR=	${.CURDIR}/../pypy

ONLY_FOR_ARCHS=	amd64

WRKSRC=		${WRKDIR}/${PORTNAME}-v${DISTVERSION:C/-.*//}-src
BUILD_WRKSRC?=	${WRKDIR}/build/usession-release-${PORTNAME}.5-v${DISTVERSION:C/-.*//}-0/testing_1

PACKAGE_ARGS=	--without-_gdbm --without-sqlite3 --without-tk

PYPY_CFFI_VER=	${PORTNAME}-${DISTVERSION:C/.[^.]+$//:S/.//}-${ARCH}-${OPSYS:tl}${OSREL:C/\..*//}

pre-install:
	${FIND} ${WRKSRC} -name '*.pyc' -delete
	#${CHMOD} -R a-w ${WRKSRC}
	#${CHMOD} -R u+w ${WRKSRC}/lib_pypy

.include "${MASTERDIR}/Makefile"
