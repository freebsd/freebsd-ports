PORTNAME=	chinese-calendar
PORTVERSION=	1.12.1
CATEGORIES=	chinese python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	chinese_calendar-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Check if some day is holiday in China
WWW=		https://github.com/liriansu-opus/chinese-calendar

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

NO_ARCH=	yes

TEST_ARGS=	--disable-plugin-autoload --ignore=tests/test_generation.py # the scripts module is not in the sdist

# tests as of 1.12.1: 22 passed in 0.04s

.include <bsd.port.mk>
