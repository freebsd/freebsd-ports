PORTREVISION=	0
CATEGORIES=	comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Python bindings for libimobiledevice

MASTERDIR=	${.CURDIR:H:H}/comms/libimobiledevice
PORTSCOUT=	ignore:1

PLIST=		${.CURDIR}/pkg-plist
PLIST_FILES=	include/imobiledevice/cython/imobiledevice.pxd \
		${PYTHONPREFIX_SITELIBDIR:S|^${PREFIX}/||}/imobiledevice.a \
		${PYTHONPREFIX_SITELIBDIR:S|^${PREFIX}/||}/imobiledevice.so

_LIMD_BINDING=	py

.include "${MASTERDIR}/Makefile"
