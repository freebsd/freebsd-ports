PORTNAME=	PySCeS
DISTVERSION=	1.0.1
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Simulator for Cellular Systems

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE.txt

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-libsbml>0:biology/py-python-libsbml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		fortran python
USE_PYTHON=	distutils autoplist

LDFLAGS+=	-lpython${PYTHON_VER} -shared # see https://github.com/PySCeS/pysces/issues/29

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pysces/pitcon/pitcon.cpython-38.so \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pysces/nleq2/nleq2.cpython-38.so

do-test: install # from section 2.1 Loading PySCeS in http://pysces.sourceforge.net/pdf/userguide.pdf
	@${PYTHON_CMD} -c "import pysces; pysces.test();"

.include <bsd.port.mk>
