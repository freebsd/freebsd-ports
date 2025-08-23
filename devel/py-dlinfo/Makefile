PORTNAME=	dlinfo
DISTVERSION=	2.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python wrapper for libc's dlinfo
WWW=		https://github.com/cloudflightio/python-dlinfo

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

# tests as of 2.0.0: 2 failed, 2 passed, 3 xfailed in 6.82s, see https://github.com/cloudflightio/python-dlinfo/issues/98

.include <bsd.port.mk>
