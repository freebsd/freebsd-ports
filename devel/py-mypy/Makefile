PORTNAME=	mypy
PORTVERSION=	1.17.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Optional static typing for Python
WWW=		https://www.mypy-lang.org/ \
		https://github.com/python/mypy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mypy_extensions>=1.0.0:devel/py-mypy_extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=0.9.0:devel/py-pathspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}types-psutil>=0:devel/py-types-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-setuptools>=0:devel/py-types-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.30.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mypy_extensions>=1.0.0:devel/py-mypy_extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=0.9.0:devel/py-pathspec@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.6.0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=18.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=3.3.0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4.6.1<5.0.0:devel/py-importlib-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.4.0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=4.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py>=1.5.2:devel/py-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.9.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-forked>=1.3.0<2.0.0:devel/py-pytest-forked@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=1.34.0,1:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes
PYTEST_BROKEN_TESTS=	test_c_unit_test	# https://github.com/python/mypy/issues/12634

OPTIONS_DEFINE=	DMYPY FASTER_CACHE INSTALL_TYPES MYPYC REPORTS
OPTIONS_DEFAULT=DMYPY FASTER_CACHE INSTALL_TYPES MYPYC REPORTS
DMYPY_DESC=	Daemon mode
FASTER_CACHE_DESC=	Faster cache support
INSTALL_TYPES_DESC=	Install support
MYPYC_DESC=	Mypypc support
REPORTS_DESC=	Coverage reports

DMYPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=4.0:sysutils/py-psutil@${PY_FLAVOR}
FASTER_CACHE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}orjson>=0:devel/py-orjson@${PY_FLAVOR}
INSTALL_TYPES_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>=0:devel/py-pip@${PY_FLAVOR}
MYPYC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=50:devel/py-setuptools@${PY_FLAVOR}
REPORTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}

.include <bsd.port.mk>
