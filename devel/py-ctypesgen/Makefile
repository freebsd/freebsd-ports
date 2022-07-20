PORTNAME=	ctypesgen
PORTVERSION=	1.0.2
DISTVERSIONPREFIX=	ctypesgen-
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python wrapper generator for ctypes

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.6+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	davidjamesca

SHEBANG_FILES=	ctypesgen/test/testsuite.py

.include <bsd.port.mk>
