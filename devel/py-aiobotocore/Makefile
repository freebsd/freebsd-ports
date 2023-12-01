PORTNAME=	aiobotocore
PORTVERSION=	2.8.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Async client for aws services using botocore and aiohttp
WWW=		https://aiobotocore.readthedocs.io/en/latest/ \
		https://github.com/aio-libs/aiobotocore

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.7.4<4.0.0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aioitertools>=0.5.1<1.0.0:devel/py-aioitertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}botocore>=1.32.4:devel/py-botocore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wrapt>=1.10.10<2.0.0:devel/py-wrapt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	AWSCLI BOTO3
AWSCLI_DESC=	Use awscli
BOTO3_DESC=	Use boto3

AWSCLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}awscli>=1.29.16:devel/py-awscli@${PY_FLAVOR}
BOTO3_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.28.16:www/py-boto3@${PY_FLAVOR}

.include <bsd.port.mk>
