PORTNAME=	cons
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.6
#MASTER_SITES=	PYPI # no tests
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of Lisp/Scheme-like cons in Python
WWW=		https://github.com/pythological/python-cons/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}versioneer>=0:devel/py-versioneer@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}logical-unification>=0.4.0:math/py-logical-unification@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # tests fail intermittently, see https://github.com/pythological/python-cons/issues/15

USE_GITHUB=	yes
GH_ACCOUNT=	pythological
GH_PROJECT=	python-cons

NO_ARCH=	yes

.include <bsd.port.mk>
