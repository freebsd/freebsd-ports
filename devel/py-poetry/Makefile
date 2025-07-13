PORTNAME=	poetry
PORTVERSION=	2.1.3
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/python-poetry/poetry/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python dependency management and packaging made easy
WWW=		https://python-poetry.org/ \
		https://github.com/python-poetry/poetry

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=2.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>=1.2.1<2.0.0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachecontrol>=0.14.0<0.15.0:www/py-cachecontrol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cleo>=2.1.0<3.0.0:devel/py-cleo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dulwich>=0.22.6<0.23.0:devel/py-dulwich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastjsonschema>=2.18.0<3.0.0:devel/py-fastjsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}findpython>=0.6.2:devel/py-findpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}installer>=0.7.0<0.8.0:devel/py-installer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keyring>=25.1.0,1<26.0.0,1:security/py-keyring@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=24.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pbs-installer>=2025.1.6<2026.0.0:devel/py-pbs-installer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkginfo>=1.12<2.0:sysutils/py-pkginfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=3.0.0<5:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry-core>=${PORTVERSION}<${PORTVERSION}_99:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-hooks>=1.0.0<2.0.0:devel/py-pyproject-hooks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.26<3.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=1.0.0<2.0.0:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}shellingham>=1.5<2.0:devel/py-shellingham@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}tomlkit>=0.11.4<1.0.0:textproc/py-tomlkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trove-classifiers>=2022.5.19:devel/py-trove-classifiers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=20.26.6<21.0.0:devel/py-virtualenv@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=7.2.0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deepdiff>=6.3:devel/py-deepdiff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpretty>=1.1:www/py-httpretty@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.classes>=3.3.1:devel/py-jaraco.classes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.9:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-randomly>=3.12:devel/py-pytest-randomly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.1,1:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=0,1<2.3,1:net/py-urllib3@${PY_FLAVOR}

USES=		python:3.10+
USE_PYTHON=	autoplist concurrent pep517 pytest

BINARY_ALIAS=	git=false
NO_ARCH=	yes
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=4.4<8.7:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
