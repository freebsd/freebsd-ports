# $FreeBSD$

PORTNAME=	keystoneauth1
PORTVERSION=	2.17.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dave@gufi.org
COMMENT=	Authentication Library for OpenStack Identity

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8:devel/py-pbr@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}positional>=1.0.1:devel/py-positional@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.16.0:devel/py-stevedore@${FLAVOR}

NO_ARCH=	yes

USES=		python:2.7+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
