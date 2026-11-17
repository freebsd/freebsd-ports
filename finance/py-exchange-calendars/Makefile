PORTNAME=	exchange-calendars
DISTVERSION=	4.13.3
CATEGORIES=	finance python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Calendars for securities exchanges
WWW=		https://github.com/gerrymanoim/exchange_calendars

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}korean-lunar-calendar>=0.3.1:korean/py-korean-lunar-calendar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26.4:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.5.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyluach>=2.3.0:hebrew/py-pyluach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toolz>=1.0.0:devel/py-toolz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>=2025.2:devel/py-tzdata@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=6.140.3:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.8.0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ARGS=	--disable-plugin-autoload -p hypothesis.extra.pytestplugin -p xdist.plugin -n auto

# tests as of 4.13.3: 10185 passed, 1 xfailed in 155.15s (0:02:35)

.include <bsd.port.mk>
