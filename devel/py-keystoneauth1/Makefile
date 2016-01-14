# $FreeBSD$

PORTNAME=	keystoneauth1
PORTVERSION=	2.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dave@gufi.org
COMMENT=	Authentication Library for OpenStack Identity

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=  ${PYTHON_PKGNAMEPREFIX}pbr>=1.6:${PORTSDIR}/devel/py-pbr
RUN_DEPENDS=    ${PYTHON_PKGNAMEPREFIX}argparse>0:${PORTSDIR}/devel/py-argparse \
		${PYTHON_PKGNAMEPREFIX}iso8601>0:${PORTSDIR}/devel/py-iso8601 \
		${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}stevedore>0:${PORTSDIR}/devel/py-stevedore

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
