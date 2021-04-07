PORTNAME=	${_PYPI_NAME:tl}
PORTVERSION=	2.7.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${_PYPI_NAME}-${PORTVERSION}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Parse C++ header files and generate a data structure representing the class

# There is no license file,
# the license is specified directly in the source file.
LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=0:devel/py-ply@${PY_FLAVOR}

USES=		python:3.6+ shebangfix
USE_PYTHON=	autoplist distutils
SHEBANG_GLOB=	*.py

_PYPI_NAME=	CppHeaderParser

.include <bsd.port.mk>
