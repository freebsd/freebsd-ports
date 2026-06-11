PORTNAME=	vunit-hdl
DISTVERSIONPREFIX=	v
DISTVERSION=	4.7.1
CATEGORIES=	cad python
#MASTER_SITES=	PYPI # some files are missing during tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open source unit testing framework for VHDL/SystemVerilog
WWW=		https://vunit.github.io/

LICENSE=	MPL20

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	ghdl:cad/ghdl
TEST_DEPENDS=	pylint:devel/pylint@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 1 test fails, see https://github.com/VUnit/vunit/issues/982

USE_GITHUB=	yes
GH_ACCOUNT=	VUnit
GH_PROJECT=	vunit
GH_TUPLE=	Paebbels:JSON-for-VHDL:95e848b:j4v/vunit/vhdl/JSON-for-VHDL \
		OSVVM:OSVVM:871f509:osvvm/vunit/vhdl/osvvm

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

# tests as of 4.7.1: 512 passed, 49 failed, 7 skipped

.include <bsd.port.mk>
