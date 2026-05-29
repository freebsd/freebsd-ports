PORTNAME=	jinxed
DISTVERSION=	2.0.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pure-Python implementation of a subset of the Python curses library
WWW=		https://github.com/Rockhopper-Technologies/jinxed

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest \
		-p no:checkdocs -p no:xdist -v -rs -o addopts=

NO_ARCH=	yes

# tests as of 2.0.4: 209 passed in 0.81s

.include <bsd.port.mk>
