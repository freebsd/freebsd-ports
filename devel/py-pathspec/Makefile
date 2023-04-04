PORTNAME=	pathspec
PORTVERSION=	0.11.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Utility library for pattern matching of file paths
WWW=		https://pypi.org/project/pathspec/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

PEP517_BUILD_CMD=       ${PYTHON_CMD} -m flit_core.wheel
PEP517_BUILD_DEPEND=    ${PYTHON_PKGNAMEPREFIX}flit-core>=3.2,<4:devel/py-flit-core@${PY_FLAVOR}

.include <bsd.port.mk>
