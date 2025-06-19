PORTNAME=	line-profiler
DISTVERSION=	4.1.3
PORTREVISION=	1
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
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=3.0.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ubelt>=1.3.4:devel/py-ubelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdoctest>=1.1.3:devel/py-xdoctest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cython3 distutils pytest # 7 tests fail, see https://github.com/pyutils/line_profiler/issues/266

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/line_profiler/_line_profiler${PYTHON_TAG}.so

.include <bsd.port.mk>
