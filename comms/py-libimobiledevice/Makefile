PORTREVISION=	1
CATEGORIES=	comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Python bindings for libimobiledevice

LIB_DEPENDS=	libimobiledevice-1.0.so:${MASTER_PORT} \
		libplist-2.0.so:devel/libplist
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libplist>=2.2.0:devel/py-libplist@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libplist>=2.2.0:devel/py-libplist@${PY_FLAVOR}

USES+=		python
USE_PYTHON=	cython3 flavors

CONFIGURE_ENV=	PYTHON_LDFLAGS="`pkg-config --libs python-${PYTHON_VER}`"

BINARY_ALIAS=	cython=cython-${PYTHON_VER}
MASTERDIR=	${.CURDIR:H:H}/comms/libimobiledevice
PORTSCOUT=	ignore:1

BUILD_WRKSRC=	${WRKSRC}/cython
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST=		${.CURDIR}/pkg-plist
PLIST_FILES=	include/imobiledevice/cython/imobiledevice.pxd \
		${PYTHONPREFIX_SITELIBDIR:S|^${PREFIX}/||}/imobiledevice.a \
		${PYTHONPREFIX_SITELIBDIR:S|^${PREFIX}/||}/imobiledevice.so

_USES_configure+=	471:post-autoreconf

SLAVE_PORT=	yes

post-autoreconf:
	@${REINPLACE_CMD} \
		-e 's|$$(top_builddir)/src/libimobiledevice-1.0.la|-limobiledevice-1.0|' \
		-e 's|$$(imobiledevice_la_DEPENDENCIES)||' \
		${BUILD_WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/imobiledevice/cython
	${INSTALL_DATA} ${INSTALL_WRKSRC}/imobiledevice.pxd \
		${STAGEDIR}${PREFIX}/include/imobiledevice/cython

.include "${MASTERDIR}/Makefile"
