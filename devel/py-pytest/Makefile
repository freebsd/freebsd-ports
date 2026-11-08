PORTNAME=	pytest
PORTVERSION=	9.1.1
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Simple powerful testing with Python
WWW=		https://docs.pytest.org/en/latest/ \
		https://github.com/pytest-dev/pytest

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2.3:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_EXCEPTIONGROUP} \
		${PYTHON_PKGNAMEPREFIX}iniconfig>=1.0.1:devel/py-iniconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=22:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>=1.5<2.0:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.7.2:textproc/py-pygments@${PY_FLAVOR} \
		${PY_TOMLI}
TEST_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}argcomplete>=0:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=19.2:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>=3.56:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmlschema>=0:textproc/py-xmlschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0:devel/py-pytest-xdist@${PY_FLAVOR}
#		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${PY_FLAVOR} # zope errors

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
