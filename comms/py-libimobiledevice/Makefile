# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	comms python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Python bindings for libimobiledevice

LIB_DEPENDS=	libimobiledevice.so:${PORTSDIR}/${MASTER_PORT}
BUILD_DEPENDS=	cython:${PORTSDIR}/lang/cython \
		${PYTHON_SITELIBDIR}/plist.so:${PORTSDIR}/devel/py-libplist
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/plist.so:${PORTSDIR}/devel/py-libplist

USE_PYTHON=	yes
SLAVE_PORT=	yes
MASTERDIR=	${.CURDIR:H:H}/comms/libimobiledevice

PLIST=		${.CURDIR}/pkg-plist
BUILD_WRKSRC=	${WRKSRC}/cython
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST_FILES=	${PYTHONPREFIX_SITELIBDIR:S,^${PREFIX}/,,}/imobiledevice.a \
		${PYTHONPREFIX_SITELIBDIR:S,^${PREFIX}/,,}/imobiledevice.la \
		${PYTHONPREFIX_SITELIBDIR:S,^${PREFIX}/,,}/imobiledevice.so

post-patch:
	@${REINPLACE_CMD} -e 's,../src/libimobiledevice.la,${LOCALBASE}/lib/libimobiledevice.la,' \
		${BUILD_WRKSRC}/Makefile.in

.include "${MASTERDIR}/Makefile"
