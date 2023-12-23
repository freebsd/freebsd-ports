PORTNAME=	lazy_loader
PORTVERSION=	0.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Load subpackages and functions on demand easily
WWW=		https://scientific-python.org/specs/spec-0001/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.7<4:devel/py-flit-core@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}codecov>=2.1:devel/py-codecov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>
