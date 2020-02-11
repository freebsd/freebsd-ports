# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hidapi
PORTVERSION=	0.9.0
DISTVERSIONSUFFIX=	.post2
CATEGORIES=	comms python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Cython interface to comms/hidapi

LICENSE=	GPLv3

LIB_DEPENDS=	libhidapi.so:comms/hidapi

USES=		python
USE_PYTHON=	autoplist distutils cython

post-patch:
	@${REINPLACE_CMD} -e 's|usb-1.0|usb|g' ${WRKSRC}/setup.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/hid.so

.include <bsd.port.mk>
