PORTNAME=	apscheduler
PORTVERSION=	3.7.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	APScheduler-${DISTVERSION}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	In-process task scheduler with Cron-like capabilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzlocal>=1.2<3:devel/py-tzlocal@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.3<6:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-tornado>0:devel/py-pytest-tornado@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.6+
USE_PYTHON=	autoplist distutils
TEST_ENV=	${MAKE_ENV} TZ=UTC

post-patch:
	@${REINPLACE_CMD} -e 's/ --cov//' ${WRKSRC}/${PYSETUP:R}.cfg
	@${REINPLACE_CMD} -e 's/set_level/setLevel/' \
		-e 's/\.records/&()/' \
		-e '/records/s/== 1/== 2/' \
		-e '/message/s/\[0]./[1]./' \
		${WRKSRC}/tests/test_schedulers.py

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>
