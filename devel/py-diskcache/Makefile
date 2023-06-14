PORTNAME=	diskcache
DISTVERSIONPREFIX=	v
DISTVERSION=	5.6.1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Disk and file backed persistent cache
WWW=		https://grantjenks.com/docs/diskcache/

LICENSE=	APACHE20

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django41>0:www/py-django41@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist unittest # 1 test fails, see https://github.com/grantjenks/python-diskcache/issues/262

USE_GITHUB=	yes
GH_ACCOUNT=	grantjenks
GH_PROJECT=	python-diskcache

NO_ARCH=	yes

.include <bsd.port.mk>
