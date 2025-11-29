PORTNAME=	black
PORTVERSION=	25.11.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Uncompromising code formatter
WWW=		https://black.readthedocs.io/en/stable/ \
		https://github.com/psf/black

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-fancy-pypi-readme>=0:devel/py-hatch-fancy-pypi-readme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.20.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=8.0.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy_extensions>=0.4.3:devel/py-mypy_extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=22.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathspec>=0.9.0:devel/py-pathspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}platformdirs>=2:devel/py-platformdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytokens>=0.3.0:devel/py-pytokens@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=2020.1.8:textproc/py-regex@${PY_FLAVOR} \
		${PY_TOMLI}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=5.3:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=7.8.0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pre-commit>=0:devel/py-pre-commit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.1.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.0.2,1:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tokenize-rt>=3.2.0:devel/py-tokenize-rt@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

OPTIONS_DEFINE=	COLORAMA D JUPYTER UVLOOP
OPTIONS_DEFAULT=COLORAMA
COLORAMA_DESC=	Color support
D_DESC=		Blackd HTTP server
JUPYTER_DESC=	Jupyter support
UVLOOP_DESC=	Event loop support

COLORAMA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.4.3:devel/py-colorama@${PY_FLAVOR}
D_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}aiohttp>=3.10:www/py-aiohttp@${PY_FLAVOR}
JUPYTER_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipython>=7.8.0:devel/ipython@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tokenize-rt>=3.2.0:devel/py-tokenize-rt@${PY_FLAVOR}
UVLOOP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uvloop>=0.15.2:devel/py-uvloop@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0.1:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
