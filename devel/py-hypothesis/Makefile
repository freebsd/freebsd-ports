# Created by: Brendan Molloy <brendan+freebsd@bbqsrc.net>
# $FreeBSD$

PORTNAME=	hypothesis
PORTVERSION=	5.49.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for property based testing

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=19.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2.1.0<3.0.0:devel/py-sortedcontainers@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	CLI CODEMODS DATEUTIL DJANGO DPCONTRACTS GHOSTWRITER LARK NUMPY PANDAS PYTEST PYTZ REDIS
CLI_DESC=		Command-line interface support
CODEMODS_DESC=		Refactor deprecated or inefficient code
DATEUTIL_DESC=		Provide dateutil timezones
DJANGO_DESC=		Django support
DPCONTRACTS_DESC=	Contracts support
GHOSTWRITER_DESC=	Ghostwriter support
LARK_DESC=		Lark parser support
NUMPY_DESC=		NumPy support
PANDAS_DESC=		Pandas support
PYTEST_DESC=		pytest support
PYTZ_DESC=		Timezone support
REDIS_DESC=		Redis support

CLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>=19.10b0:devel/py-black@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}click>=7.0:devel/py-click@${PY_FLAVOR}
CODEMODS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libcst>=0.3.16:devel/py-libcst@${PY_FLAVOR}
DATEUTIL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=1.4:devel/py-dateutil@${PY_FLAVOR}
DJANGO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=2.2:www/py-django22@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pytz>=2014.1,1:devel/py-pytz@${PY_FLAVOR}
DPCONTRACTS_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}dpcontracts>=0.4:devel/py-dpcontracts@${PY_FLAVOR}
GHOSTWRITER_RUN_DEPENDS=${PYTHON_PKGNAMEPREFIX}black>=19.10b0:devel/py-black@${PY_FLAVOR}
LARK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lark-parser>=0.6.5:devel/py-lark-parser@${PY_FLAVOR}
NUMPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.9.0,1:math/py-numpy@${PY_FLAVOR}
PANDAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pandas>=0.25,1:math/py-pandas@${PY_FLAVOR}
PYTEST_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=4.3:devel/py-pytest@${PY_FLAVOR}
PYTZ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>=2014.1,1:devel/py-pytz@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=3.0.0:databases/py-redis@${PY_FLAVOR}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
