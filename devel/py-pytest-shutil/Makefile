PORTNAME=	pytest-shutil
DISTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Collection of unix shell and environment tools for py.test
WWW=		https://github.com/manahl/pytest-plugins/tree/master/pytest-shutil

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-git>=0:devel/py-setuptools-git@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}contextlib2>0:devel/py-contextlib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}execnet>=0:sysutils/py-execnet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}path.py>=0:devel/py-path.py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:devel/py-termcolor@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes
PORTSCOUT=	skipv:1.8.1

.include <bsd.port.mk>
