PORTNAME=	black
PORTVERSION=	22.6.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Uncompromising code formatter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=6.3.1:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.0.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy_extensions>=0.4.3:devel/py-mypy_extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=0.9.0:devel/py-pathspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=2020.1.8:textproc/py-regex@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=5.3:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=7.8.0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pre-commit>=0:devel/py-pre-commit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.9.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=2.2.1:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tokenize-rt>=3.2.0:devel/py-tokenize-rt@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

OPTIONS_DEFINE=	COLORAMA D JUPYTER UVLOOP
OPTIONS_DEFAULT=COLORAMA
COLORAMA_DESC=	Color support
D_DESC=		Blackd HTTP server
JUPYTER_DESC=	Jupyter support
UVLOOP_DESC=	Event loop support

COLORAMA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.4.3:devel/py-colorama@${PY_FLAVOR}
D_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}aiohttp>=3.7.4:www/py-aiohttp@${PY_FLAVOR}
JUPYTER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=7.8.0:devel/ipython@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tokenize-rt>=3.2.0:devel/py-tokenize-rt@${PY_FLAVOR}
UVLOOP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uvloop>=0.15.2:devel/py-uvloop@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typed-ast>=1.4.2:devel/py-typed-ast@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.10.0.0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}tomli>=1.1.0:textproc/py-tomli@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
