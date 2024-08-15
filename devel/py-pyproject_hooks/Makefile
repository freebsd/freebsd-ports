PORTNAME=	pyproject_hooks
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/pypa/pyproject-hooks/commit/
PATCHFILES=	282b8735e59df938a210e46b8cd5cd1d99344816.patch:-p1 # https://github.com/pypa/pyproject-hooks/pull/199

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrappers to call pyproject.toml-based build backend hooks
WWW=		https://pyproject-hooks.readthedocs.io/en/latest/ \
		https://github.com/pypa/pyproject-hooks

LICENSE=	MIT

USES=		python
USE_PYTHON=	allflavors autoplist concurrent pep517

NO_ARCH=	yes

PEP517_BUILD_CMD=	${PYTHON_CMD} -m flit_core.wheel
PEP517_BUILD_DEPEND=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}

.include <bsd.port.mk>
