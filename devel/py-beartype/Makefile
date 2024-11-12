PORTNAME=	beartype
DISTVERSION=	0.19.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast runtime type checking in pure Python
WWW=		https://beartype.readthedocs.io/en/latest/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyright>0:devel/py-pyright@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

BINARY_ALIAS=	gcc=${CC} # only for tests

.include <bsd.port.mk>
