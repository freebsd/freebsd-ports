PORTNAME=	huey
DISTVERSION=	3.5.3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Little task queue for Python
WWW=		https://huey.readthedocs.io \
		https://github.com/coleifer/huey

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

pre-test:
	@${RM} -rf ${WRKSRC}/build

# tests as of 3.5.3: 292 passed, 137 skipped, 2 warnings in 24.58s

.include <bsd.port.mk>
