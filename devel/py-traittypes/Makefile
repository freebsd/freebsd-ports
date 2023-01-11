PORTNAME=	traittypes
DISTVERSION=	0.2.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Traitlets types for NumPy, SciPy and friends
WWW=		https://github.com/jupyter-widgets/traittypes

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}traitlets>=4.2.2:devel/py-traitlets@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xarray>0:devel/py-xarray@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # 1 test fails due to nose issues: ModuleNotFoundError: No module named 'ConfigParser

NO_ARCH=	yes

.include <bsd.port.mk>
