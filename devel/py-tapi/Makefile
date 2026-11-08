PORTNAME=	tapi
PORTVERSION=	0.2.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework for testing APIs
WWW=		https://tapi.readthedocs.io/en/latest/ \
		https://github.com/1Doomdie1/Tapi

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=4.13.0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2026.2.25:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h11>=0.16.0:net/py-h11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpcore>=1.0.9:www/py-httpcore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=3.11:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.2.2:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.15.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=2.6.3,1:net/py-urllib3@${PY_FLAVOR}

USES=		dos2unix python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
