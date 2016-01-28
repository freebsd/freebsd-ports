# $FreeBSD$

PORTNAME=	oslo.serialization
PORTVERSION=	2.2.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dave@gufi.org
COMMENT=	Oslo Serialization library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:${PORTSDIR}/devel/py-pbr
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack-python>0:${PORTSDIR}/devel/py-msgpack-python \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>0:${PORTSDIR}/devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
