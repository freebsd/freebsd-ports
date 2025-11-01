PORTNAME=	pytest-plus
PORTVERSION=	0.8.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Pytest plus plugin :: extends pytest functionality
WWW=		https://github.com/pytest-dev/pytest-plus

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7.0.5:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=7.4.2:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	LC_ALL=C.UTF-8 PYTHONPATH=${WRKSRC}/src TMPDIR=${WRKDIR}/
NO_ARCH=	yes

.include <bsd.port.mk>
