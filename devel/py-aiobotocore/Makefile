PORTNAME=	aiobotocore
PORTVERSION=	2.23.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Async client for aws services using botocore and aiohttp
WWW=		https://aiobotocore.readthedocs.io/en/latest/ \
		https://github.com/aio-libs/aiobotocore

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.9.2<4.0.0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aioitertools>=0.5.1<1.0.0:devel/py-aioitertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}botocore>=1.38.23:devel/py-botocore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>=0.7.1<2.0.0:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multidict>=6.0.0<7.0.0:www/py-multidict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.1<3.0.0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.25.4,1<3,1:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.10.10<2.0.0:devel/py-wrapt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	AWSCLI BOTO3
AWSCLI_DESC=	Use awscli
BOTO3_DESC=	Use boto3

AWSCLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}awscli>=1.29.81:devel/py-awscli@${PY_FLAVOR}
BOTO3_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.38.23:www/py-boto3@${PY_FLAVOR}

.include <bsd.port.mk>
