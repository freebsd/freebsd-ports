PORTNAME=	financedatabase
PORTVERSION=	1.0.2
CATEGORIES=	finance python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Database of 300.000+ symbols containing Equities, ETFs, Funds, Indices
WWW=		https://github.com/JerBouma/FinanceDatabase

LICENSE=	MIT

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dill>=0.3.3:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fundamentalanalysis>=0.2.10:finance/py-fundamentalanalysis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=3.3.2:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.1.2:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tablib>=3.0.0:textproc/py-tablib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.56.0:misc/py-tqdm@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

do-test:
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/test.py

.include <bsd.port.mk>
