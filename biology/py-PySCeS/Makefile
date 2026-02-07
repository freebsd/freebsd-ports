PORTNAME=	pysces
DISTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Simulator for Cellular Systems
WWW=		https://pysces.github.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}meson-python>0:devel/meson-python@${PY_FLAVOR} \
		${PYNUMPY}
PY_EXTRA=	${PYTHON_PKGNAMEPREFIX}python-libsbml>0:biology/py-python-libsbml@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PY_EXTRA}

USES=		fortran localbase:ldflags python
USE_PYTHON=	pep517 autoplist pytest

LDFLAGS+=	-lpython${PYTHON_VER}

BINARY_ALIAS=	python3=${PYTHON_CMD}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pysces/pitcon/pitcon.cpython-${PYTHON_SUFFIX}.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pysces/nleq2/nleq2.cpython-${PYTHON_SUFFIX}.so

do-test: # from section 2.1 Loading PySCeS in http://pysces.sourceforge.net/pdf/userguide.pdf
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} -c "import pysces; pysces.test();"

.include <bsd.port.mk>
