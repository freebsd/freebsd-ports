# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	keystonemiddleware
PORTVERSION=	4.14.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	Middleware for OpenStack Identity

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.8:devel/py-pbr@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}webob>=1.6.0:www/py-webob@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient>=3.8.0:net/py-python-keystoneclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycadf>=0:devel/py-pycadf@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}positional>=1.1.1:devel/py-positional@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.18.0:devel/py-oslo.utils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:devel/py-oslo.serialization@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.9.0:devel/py-oslo.context@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=3.14.0:devel/py-oslo.config@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=3.11.0:devel/py-oslo.log@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.17.0:devel/py-keystoneauth1@${FLAVOR}

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
