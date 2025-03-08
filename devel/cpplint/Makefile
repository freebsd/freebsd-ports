PORTNAME=	cpplint
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Static code checker for C++
WWW=		https://github.com/cpplint/cpplint

LICENSE=	BSD3CLAUSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}testfixtures>0:devel/py-testfixtures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR}

USE_GITHUB=	yes

USES=		pytest python
USE_PYTHON=	distutils noflavors

NO_ARCH=	yes

.include <bsd.port.mk>
