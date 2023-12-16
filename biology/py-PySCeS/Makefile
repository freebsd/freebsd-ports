PORTNAME=	PySCeS
DISTVERSION=	1.1.1
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Simulator for Cellular Systems
WWW=		https://pysces.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE.txt

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
PY_EXTRA=	${PYTHON_PKGNAMEPREFIX}python-libsbml>0:biology/py-python-libsbml@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR} \
		cmake:devel/cmake-core \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS} \
		${PY_EXTRA}

USES=		fortran localbase:ldflags python
USE_PYTHON=	distutils autoplist pytest

LDFLAGS+=	-lpython${PYTHON_VER} -shared # see https://github.com/PySCeS/pysces/issues/29

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pysces/pitcon/pitcon.cpython-${PYTHON_SUFFIX}.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pysces/nleq2/nleq2.cpython-${PYTHON_SUFFIX}.so

do-test: # from section 2.1 Loading PySCeS in http://pysces.sourceforge.net/pdf/userguide.pdf
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} -c "import pysces; pysces.test();"

.include <bsd.port.mk>
