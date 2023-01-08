PORTNAME=	vunit-hdl
DISTVERSION=	4.6.0
CATEGORIES=	cad python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open source unit testing framework for VHDL/SystemVerilog
WWW=		https://vunit.github.io/

LICENSE=	MPL20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist pytest # 2 tests fail, see https://github.com/VUnit/vunit/issues/886

NO_ARCH=	yes

.include <bsd.port.mk>
