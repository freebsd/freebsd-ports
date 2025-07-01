PORTNAME=	pytest-datadir
PORTVERSION=	1.7.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/-/_/}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	pytest plugin for test data directories and files
WWW=		https://pypi.org/project/pytest-datadir/ \
		https://github.com/gabrielcnr/pytest-datadir

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils pytest
NO_ARCH=	yes

.include <bsd.port.mk>
