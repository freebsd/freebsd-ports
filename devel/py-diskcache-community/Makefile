PORTNAME=	diskcache-community
DISTVERSIONPREFIX=	v
DISTVERSION=	5.8.5
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Disk and file backed persistent cache (community fork of diskcache)
WWW=		https://github.com/secondwindoss/diskcache-community

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>0:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-django>0:devel/py-pytest-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	secondwindoss

TEST_ARGS=	--disable-plugin-autoload -p xdist -p pytest_django
TEST_ENV=	${MAKE_ENV} DJANGO_SETTINGS_MODULE=tests.settings PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

# tests as of 5.8.5: 1004 passed, 1 skipped, 12 subtests passed in 49.30s

.include <bsd.port.mk>
