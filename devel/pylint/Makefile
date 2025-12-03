PORTNAME=	pylint
PORTVERSION=	4.0.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/pylint-dev/pylint/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Analyzes python source code looking for bugs and signs of poor quality
WWW=		https://www.pylint.org/ \
		https://pylint.readthedocs.io/en/latest/ \
		https://github.com/pylint-dev/pylint

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=62.6:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.37.1:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astroid>=4.0.2<4.1_99:devel/py-astroid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dill>=0.3.7:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>=5<8:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mccabe>=0.6<0.8:devel/py-mccabe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2.2:devel/py-platformdirs@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.10.1:textproc/py-tomlkit@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
