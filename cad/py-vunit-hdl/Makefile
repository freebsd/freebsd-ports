PORTNAME=	vunit-hdl
DISTVERSION=	4.6.2
PORTREVISION=	1
CATEGORIES=	cad python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open source unit testing framework for VHDL/SystemVerilog
WWW=		https://vunit.github.io/

LICENSE=	MPL20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	pep517 autoplist pytest # 2 tests fail, see https://github.com/VUnit/vunit/issues/886

NO_ARCH=	yes

.include <bsd.port.mk>
