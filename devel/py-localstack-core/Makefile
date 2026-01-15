PORTNAME=	localstack-core
PORTVERSION=	4.12.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	localstack_core-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Core library and runtime of LocalStack
WWW=		https://www.localstack.cloud/ \
		https://docs.localstack.cloud/ \
		https://github.com/localstack/localstack/tree/main/localstack-core \
		https://github.com/localstack/localstack

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}plux>=1.12:devel/py-plux@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>=1.5.1:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachetools>=5.0:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.1.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dill>=0.3.6:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnslib>=0.9.10:dns/py-dnslib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=1.16.0,1:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}plux>=1.10:devel/py-plux@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.4.8:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=0.19.1:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.20.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=12.3.0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semver>=2.10:devel/py-semver@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

.include <bsd.port.mk>
