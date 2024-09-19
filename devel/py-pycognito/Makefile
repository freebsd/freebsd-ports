PORTNAME=	pycognito
PORTVERSION=	2024.5.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Integrate Boto3's Cognito client so it is easy to login users
WWW=		https://github.com/NabuCasa/pycognito

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.10.49:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}envs>=1.3:devel/py-envs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.8.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.22.0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
