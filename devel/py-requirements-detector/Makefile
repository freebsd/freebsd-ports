PORTNAME=	requirements-detector
PORTVERSION=	1.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	requirements_detector-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Find and list requirements of a Python project
WWW=		https://github.com/landscapeio/requirements-detector

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astroid>=2.0<3.0:devel/py-astroid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=21.3:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}poetry-semver>=0.1.0<0.2.0:devel/py-poetry-semver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0.10.2<0.11.0:textproc/py-toml@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
