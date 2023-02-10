PORTNAME=	ctypesgen
PORTVERSION=	1.1.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper generator for ctypes
WWW=		https://github.com/ctypesgen/ctypesgen

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=3.4.3:devel/py-setuptools_scm@${PY_FLAVOR}

USES=		python:3.7+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

SHEBANG_FILES=	tests/testsuite.py

.include <bsd.port.mk>
