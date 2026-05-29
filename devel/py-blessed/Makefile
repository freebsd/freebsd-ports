PORTNAME=	blessed
DISTVERSION=	1.44.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Easy, practical library for making terminal apps
WWW=		https://github.com/jquast/blessed

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jinxed>=2.0:devel/py-jinxed@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wcwidth>=0.7:devel/py-wcwidth@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test:
	@cd ${TEST_WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest \
		-p no:checkdocs -p no:xdist -v -rs -o addopts=

# tests as of 1.44.0: 1633 passed, 162 skipped

.include <bsd.port.mk>
