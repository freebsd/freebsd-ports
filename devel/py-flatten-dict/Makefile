PORTNAME=	flatten-dict
DISTVERSION=	0.5.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utility for flattening and unflattening dict-like objects in Python
WWW=		https://github.com/ianlini/flatten-dict

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

WRKSRC=		${WRKDIR}/flatten_dict-${DISTVERSION}

MAKE_ENV=	GIT_DIR=${WRKSRC} # workaround for the Poetry bug
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

# tests as of 0.5.0:
# Results (0.20s):
#        153 passed

.include <bsd.port.mk>
