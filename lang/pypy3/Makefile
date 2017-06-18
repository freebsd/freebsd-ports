# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pypy3
DISTNAME=	${PORTNAME}-v${DISTVERSION}-src

MASTERDIR=	${.CURDIR}/../pypy

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	pypy3 is in beta development and upstream only supported amd64 for now

WRKSRC=		${WRKDIR}/${PORTNAME}-v${DISTVERSION:C/-.*//}-src
BUILD_WRKSRC?=	${WRKDIR}/build/usession-release-${PORTNAME}.5-v${DISTVERSION:C/-.*//}-0/testing_1

SHEBANG_FILES=	lib-python/3/encodings/rot_13.py \
		lib-python/3/lib2to3/tests/data/different_encoding.py \
		lib-python/3/lib2to3/tests/data/false_encoding.py \
		lib-python/3/cgi.py

PACKAGE_ARGS=	--without-_gdbm --without-sqlite3 --without-tk

PYPY_CFFI_VER=	${PORTNAME}-${DISTVERSION:C/.[^.]+$//:S/.//}-${ARCH}-${OPSYS:tl}${OSREL:C/\..*//}

pre-install:
	${FIND} ${WRKSRC} -name '*.pyc' -delete
	#${CHMOD} -R a-w ${WRKSRC}
	#${CHMOD} -R u+w ${WRKSRC}/lib_pypy

.include "${MASTERDIR}/Makefile"
