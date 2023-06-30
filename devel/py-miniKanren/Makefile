PORTNAME=	miniKanren
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
#MASTER_SITES=	PYPI # no tests
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Logic/relational programming in Python
WWW=		https://github.com/pythological/kanren

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cons>=0.4.0:devel/py-cons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}etuples>=0.3.1:devel/py-etuples@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}logical-unification>=0.4.1:math/py-logical-unification@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multipledispatch>0:devel/py-multipledispatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toolz>0:devel/py-toolz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail due to etuples problems

USE_GITHUB=	yes
GH_ACCOUNT=	pythological
GH_PROJECT=	kanren

NO_ARCH=	yes

.include <bsd.port.mk>
