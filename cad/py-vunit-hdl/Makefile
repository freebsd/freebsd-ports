PORTNAME=	vunit-hdl
DISTVERSIONPREFIX=	v
DISTVERSION=	4.7.0
CATEGORIES=	cad python
#MASTER_SITES=	PYPI # some files are missing during tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open source unit testing framework for VHDL/SystemVerilog
WWW=		https://vunit.github.io/

LICENSE=	MPL20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	ghdl:cad/ghdl
TEST_DEPENDS=	pylint:devel/pylint@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # 1 test fails, see https://github.com/VUnit/vunit/issues/982

USE_GITHUB=	yes
GH_ACCOUNT=	VUnit
GH_PROJECT=	vunit
GH_TUPLE=	Paebbels:JSON-for-VHDL:95e848b:j4v/vunit/vhdl/JSON-for-VHDL \
		OSVVM:OSVVM:2104430:osvvm/vunit/vhdl/osvvm

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
