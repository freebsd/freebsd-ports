PORTNAME=	giddy
PORTVERSION=	2.3.5
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GeospatIal Distribution DYnamics (GIDDY)
WWW=		https://pysal.org/giddy/ \
		https://github.com/pysal/giddy

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}esda>=2.1.1:science/py-esda@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libpysal>=4.0.1:science/py-libpysal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}quantecon>=0.4.7:finance/py-quantecon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.3:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
