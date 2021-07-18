PORTNAME=	pydocstyle
PORTVERSION=	6.1.1
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Python docstring style checker

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}snowballstemmer>0:textproc/py-snowballstemmer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}toml>=0:textproc/py-toml@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

.include <bsd.port.mk>
