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

USES=		python:3.7+
USE_PYTHON=	pep517 autoplist pytest # 42 tests fail, see https://github.com/VUnit/vunit/issues/941

USE_GITHUB=	yes
GH_ACCOUNT=	VUnit
GH_PROJECT=	vunit

NO_ARCH=	yes

.include <bsd.port.mk>
