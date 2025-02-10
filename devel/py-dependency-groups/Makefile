PORTNAME=	dependency-groups
PORTVERSION=	1.3.0
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # no tarball
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool for resolving PEP 735 Dependency Group data
WWW=		https://github.com/pypa/dependency-groups

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	pypa

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 1.3.0: 31 passed in 6.85s

.include <bsd.port.mk>
