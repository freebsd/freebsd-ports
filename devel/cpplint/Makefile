PORTNAME=	cpplint
PORTVERSION=	1.6.1
CATEGORIES=	devel

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Static code checker for C++
WWW=		https://github.com/cpplint/cpplint

LICENSE=	BSD3CLAUSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}zipp>0:devel/py-zipp@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}configparser>0:devel/py-configparser@${PY_FLAVOR}	\
		${PYTHON_PKGNAMEPREFIX}testfixtures>0:devel/py-testfixtures@${PY_FLAVOR}

USE_GITHUB=	yes

USES=		python
USE_PYTHON=	distutils noflavors

NO_ARCH=	yes

do-test:
	(cd ${WRKSRC} && py.test)

.include <bsd.port.mk>
