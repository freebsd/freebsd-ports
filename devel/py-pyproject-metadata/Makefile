PORTNAME=	pyproject-metadata
PORTVERSION=	0.12.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyproject_metadata-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEP 621 metadata parsing
WWW=		https://pep621.readthedocs.io/en/stable/ \
		https://github.com/pypa/pyproject-metadata

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=23.2:devel/py-packaging@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=4:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
