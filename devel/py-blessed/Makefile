PORTNAME=	blessed
DISTVERSION=	1.52.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Easy, practical library for making terminal apps
WWW=		https://github.com/jquast/blessed

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jinxed>=2.1:devel/py-jinxed@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wcwidth>=0.9.2:devel/py-wcwidth@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test:
	@cd ${TEST_WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest \
		--disable-plugin-autoload -v -rs -o addopts= -o filterwarnings=

# tests as of 1.52.0: 1829 passed, 179 skipped in 27.25s

.include <bsd.port.mk>
