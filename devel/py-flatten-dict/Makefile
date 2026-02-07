PORTNAME=	flatten-dict
DISTVERSION=	0.4.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utility for flattening and unflattening dict-like objects in Python
WWW=		https://github.com/ianlini/flatten-dict

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.12:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

MAKE_ENV=	GIT_DIR=${WRKSRC} # workaround for the Poetry bug
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
