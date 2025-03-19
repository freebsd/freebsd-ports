PORTNAME=	validate-pyproject
PORTVERSION=	0.24
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	validate_pyproject-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Validation library and CLI tool for checking on pyproject.toml files using JSON schema
WWW=		https://github.com/abravalheri/validate-pyproject

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7.1:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastjsonschema>=2.16.2<3_99:devel/py-fastjsonschema@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ALL STORE
OPTIONS_DEFAULT=ALL STORE
ALL_DESC=	All functions
STORE_DESC=	Schema stores

ALL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=24.2:devel/py-packaging@${PY_FLAVOR} \
			${PY_TOMLI} \
			${PYTHON_PKGNAMEPREFIX}trove-classifiers>=2021.10.20:devel/py-trove-classifiers@${PY_FLAVOR}
STORE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}validate-pyproject-schema-store>=0:devel/py-validate-pyproject-schema-store@${PY_FLAVOR}

.include <bsd.port.mk>
