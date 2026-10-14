PORTNAME=	pyproject-fmt
PORTVERSION=	2.29.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	pyproject_fmt-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Format pyproject.toml files
WWW=		https://pyproject-fmt.readthedocs.io/en/latest/ \
		https://github.com/tox-dev/toml-fmt/tree/main/pyproject-fmt \
		https://github.com/tox-dev/toml-fmt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}maturin>=1.15:devel/py-maturin@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}covdefaults>=2.3:devel/py-covdefaults@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=7.1:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.15.1:devel/py-pytest-mock@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}trove-classifiers>=2026.6.1.19:devel/py-trove-classifiers@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist concurrent pep517 pytest

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}
WRKSRC=		${WRKDIR}/pyproject_fmt-${PORTVERSION}

.include <bsd.port.mk>
