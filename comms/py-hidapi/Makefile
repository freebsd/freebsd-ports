PORTNAME=	hidapi
DISTVERSION=	0.11.0.post2
CATEGORIES=	comms python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cython interface to comms/hidapi
WWW=		https://pypi.org/project/hidapi/

LICENSE=	GPLv3

LIB_DEPENDS=	libhidapi.so:comms/hidapi

USES=		python
USE_PYTHON=	autoplist cython distutils

MAKE_ENV+=	DISTUTILS_DEBUG=1

post-patch:
	@${REINPLACE_CMD} -e 's|usb-1.0|usb|g' ${WRKSRC}/setup.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/hid*.so

.include <bsd.port.mk>
