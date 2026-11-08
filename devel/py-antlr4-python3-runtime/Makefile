PORTNAME=	antlr4-python3-runtime
PORTVERSION=	4.13.2
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	antlr4_python3_runtime-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ANother Tool for Language Recognition (ANTLR) runtime for Python 3
WWW=		https://www.antlr.org/ \
		https://github.com/antlr/antlr4/tree/dev/runtime/Python3 \
		https://github.com/antlr/antlr4

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
