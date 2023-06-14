PORTNAME=	pyls-black
PORTVERSION=	0.4.7
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Black plugin for the Python Language Server
WWW=		https://github.com/rupert/pyls-black

LICENSE=	MIT

# Per PEP-518, the default [build-system] section when not defined is:
# requires = ["setuptools", "wheel"]  # PEP 508 specifications.
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}black>0:devel/py-black@${PY_FLAVOR}

# No tests because they are not in the release tarball
USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
