PORTNAME=	bandit
DISTVERSION=	1.7.10
PORTREVISION=	1
CATEGORIES=	devel security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for finding common security issues in Python code
WWW=		https://github.com/PyCQA/bandit

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gitpython>=3.1.30:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.20.0:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3.1:devel/py-pyyaml@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}jschema-to-python>=1.2.3:devel/py-jschema-to-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sarif-om>=1.0.4:devel/py-sarif-om@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.8.0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=4.5.4:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fixtures>=3.0.0:devel/py-fixtures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=4.0.0:devel/py-flake8@${PY_FLAVOR} \
		pylint${PYTHON_PKGNAMESUFFIX}>=1.9.4:devel/pylint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testscenarios>=0.5.0:devel/py-testscenarios@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}testtools>=2.3.0:devel/py-testtools@${PY_FLAVOR} \
		${PY_TOMLI}

USES=		python
USE_PYTHON=	autoplist distutils pytest # 1 test fails, see https://github.com/PyCQA/bandit/issues/1083

NO_ARCH=	yes

MAKE_ENV+=	PBR_VERSION=${PORTVERSION}
TEST_ENV=	${MAKE_ENV} \
		PATH=${STAGEDIR}${PREFIX}/bin:${PATH} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
