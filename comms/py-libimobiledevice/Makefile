# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Python bindings for libimobiledevice

LIB_DEPENDS=	libimobiledevice.so:${MASTER_PORT}
BUILD_DEPENDS=	cython:lang/cython \
		${PYTHON_SITELIBDIR}/plist.so:devel/py-libplist
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/plist.so:devel/py-libplist

USES=		python
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
