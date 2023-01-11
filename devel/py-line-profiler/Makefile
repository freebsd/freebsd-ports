PORTNAME=	line-profiler
DISTVERSION=	3.5.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Line-by-line profiler for Python
WWW=		https://github.com/pyutils/line_profiler

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR} \
		cmake:devel/cmake-core
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=5.3:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=0.13:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ubelt>=1.0.1:devel/py-ubelt@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	distutils cython autoplist pytest # 1 test fails, see https://github.com/pyutils/line_profiler/issues/159

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/line_profiler/_line_profiler${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
