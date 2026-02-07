PORTNAME=	autoray
DISTVERSION=	0.8.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Abstract your array operations
WWW=		https://autoray.readthedocs.io/en/latest/ \
		https://github.com/jcmgray/autoray

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
# more backend dependencies are defined but not ported yet
BE_DEPENDS=	${PYTHON_PKGNAMEPREFIX}autograd>0:math/py-autograd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sparse>0:devel/py-sparse@${PY_FLAVOR}
#BE_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tensorflow>0:science/py-tensorflow@${PY_FLAVOR} # tests crash with tensorflow
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${BE_DEPENDS}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent pytest

NO_ARCH=	yes

# tests as of 0.8.4: 1720 passed, 1286 skipped, 68 xfailed, 12 warnings in 8.02s

.include <bsd.port.mk>
