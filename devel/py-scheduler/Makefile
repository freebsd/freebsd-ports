PORTNAME=	scheduler
DISTVERSION=	0.8.11
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python scheduler library
WWW=		https://gitlab.com/DigonIO/scheduler

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typeguard>=3.0.0:devel/py-typeguard@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}:${WRKSRC}
TEST_ARGS=	-p no:relaxed \
		--ignore=tests/test_jobtimer.py \
		--ignore=tests/test_misc.py \
		--ignore=tests/test_readme.py \
		tests/

pre-test:
	@${TOUCH} ${WRKSRC}/tests/__init__.py

# tests as of 0.8.11: 34 passed in 0.39s (after ignoring tests that need helpers.py missing from the sdist)

.include <bsd.port.mk>
