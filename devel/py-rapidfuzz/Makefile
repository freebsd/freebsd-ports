PORTNAME=	rapidfuzz
DISTVERSION=	3.14.5
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rapid fuzzy string matching in Python
WWW=		https://github.com/rapidfuzz/RapidFuzz

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		ninja:devel/ninja \
		rapidfuzz-cpp>0:devel/rapidfuzz-cpp \
		taskflow>0:devel/taskflow \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz-capi>=1.0.5:devel/py-rapidfuzz-capi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.10.7:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>=0.13.0:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR}

USES=		compiler:c++14-lang python pytest # PYTEST_ARGS is not respected by USE_PYTHON=pytest, so we set it here instead
USE_PYTHON=	pep517 autoplist

PYTEST_ARGS=	-p no:randomly -p no:ruff
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@cd ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} && \
		${STRIP_CMD} \
			${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/*.so \
			${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/distance/*.so
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}

# tests as of 3.14.5: 388 passed, 2 warnings in 13.45s

.include <bsd.port.mk>
