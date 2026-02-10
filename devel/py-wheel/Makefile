PORTNAME=	wheel
PORTVERSION=	0.46.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Built-package format for Python
WWW=		https://github.com/pypa/wheel

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.8:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=24.0:devel/py-packaging@${PY_FLAVOR}

USES=		python
USE_PYTHON=	allflavors autoplist concurrent pep517

# see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=268500
EXTRACT_CMD=	${SETENV} LC_ALL=en_US.UTF-8 ${TAR}
NO_ARCH=	yes

.include <bsd.port.mk>
