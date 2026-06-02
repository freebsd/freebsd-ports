PORTNAME=	zipstream-ng
DISTVERSION=	1.9.2
CATEGORIES=	archivers python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	zipstream_ng-${PORTVERSION}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Modern and easy to use streamable zip file generator
WWW=		https://github.com/pR0Ps/zipstream-ng/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist pep517 pytest

SHEBANG_FILES=	src/zipstream/server.py

NO_ARCH=	yes

.include <bsd.port.mk>
