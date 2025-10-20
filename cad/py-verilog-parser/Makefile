PORTNAME=	verilog_parser
DISTVERSION=	0.0.7
CATEGORIES=	cad python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	spaciouscoder78@disroot.org
COMMENT=	Lark-based parser for structural Verilog netlists
WWW=		https://codeberg.org/tok/py-verilog-parser

LICENSE=	AGPLv3+

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}lark>=1.2.2<2:devel/py-lark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.45.1:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
