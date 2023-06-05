PORTNAME=	azure-core
PORTVERSION=	1.27.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Microsoft Azure Core Library for Python
WWW=		https://github.com/Azure/azure-sdk-for-python/tree/master/sdk/core/azure-core

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.18.4:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.3.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.7+ zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	AIO
OPTIONS_DEFAULT=AIO
AIO_DESC=	Async transport support

AIO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.0:www/py-aiohttp@${PY_FLAVOR}

.include <bsd.port.mk>
