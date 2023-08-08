PORTNAME=	PYB11Generator
DISTVERSION=	1.0.12
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Code generator for the pybind11 C++ <-> Python language binding tool
WWW=		https://github.com/LLNL/PYB11Generator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>=0:devel/py-pybind11@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils # autoplist is broken - it prints __pycache__ items that aren't installed

NO_ARCH=	yes

.include <bsd.port.mk>
