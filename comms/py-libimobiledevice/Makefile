# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for libimobiledevice

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LIB_DEPENDS=	libimobiledevice.so:${MASTER_PORT}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libplist>0:devel/py-libplist@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libplist>0:devel/py-libplist@${PY_FLAVOR}

PORTSCOUT=	ignore:1

USES=		python:2.7
USE_PYTHON=	flavors cython
BINARY_ALIAS=	cython=cython-${PYTHON_VER}
CONFIGURE_ENV=	PYTHON_LDFLAGS="`pkg-config --libs python-${PYTHON_VER}`"
SLAVE_PORT=	yes
MASTERDIR=	${.CURDIR:H:H}/comms/libimobiledevice

PLIST=		${.CURDIR}/pkg-plist
BUILD_WRKSRC=	${WRKSRC}/cython
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST_FILES=	include/imobiledevice/cython/imobiledevice.pxd \
		${PYTHONPREFIX_SITELIBDIR:S,^${PREFIX}/,,}/imobiledevice.a \
		${PYTHONPREFIX_SITELIBDIR:S,^${PREFIX}/,,}/imobiledevice.so

post-patch:
	@${REINPLACE_CMD} \
		-e 's,../src/libimobiledevice.la,-limobiledevice,' \
		-e 's/$$(imobiledevice_la_DEPENDENCIES)//' \
		${BUILD_WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/imobiledevice/cython
	${INSTALL_DATA} ${INSTALL_WRKSRC}/imobiledevice.pxd \
		${STAGEDIR}${PREFIX}/include/imobiledevice/cython

.include "${MASTERDIR}/Makefile"
