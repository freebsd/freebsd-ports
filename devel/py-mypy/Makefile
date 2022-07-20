PORTNAME=	mypy
PORTVERSION=	0.961
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Optional static typing for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mypy_extensions>=0.4.3:devel/py-mypy_extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.10:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>=0:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typed-ast>=1.4.0<2:devel/py-typed-ast@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes
PYTEST_BROKEN_TESTS=test_c_unit_test  # https://github.com/python/mypy/issues/12634

OPTIONS_DEFINE=	DMYPY REPORTS
OPTIONS_DEFAULT=DMYPY REPORTS
DMYPY_DESC=	Daemon mode
REPORTS_DESC=	Coverage reports

DMYPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=4.0:sysutils/py-psutil@${PY_FLAVOR}
REPORTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typed-ast>=1.4.0<2:devel/py-typed-ast@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=1.1.0:textproc/py-tomli@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
