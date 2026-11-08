PORTNAME=	zope.testbrowser
PORTVERSION=	5.5.1
PORTREVISION=	4
CATEGORIES=	devel python zope
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Programmable browser for functional black-box tests
WWW=		https://pypi.org/project/zope.testbrowser/

LICENSE=	ZPL21

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=0:www/py-beautifulsoup4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}soupsieve>=1.9.0:www/py-soupsieve@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webtest>=0:www/py-webtest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}WSGIProxy2>=0:www/py-wsgiproxy2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
