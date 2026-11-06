PORTNAME=       assertpy
PORTVERSION=    2.36.0
CATEGORIES=     devel python
MASTER_SITES=   PYPI
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}

MAINTAINER=     matthew@FreeBSD.org
COMMENT=        Simple assertions library for unit testing in Python
WWW=            https://github.com/assertpy/assertpy

LICENSE=        BSD3CLAUSE
LICENSE_FILE=   ${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}

USES=           python
USE_PYTHON=     pep517 autoplist concurrent

NO_ARCH=        yes

.include <bsd.port.mk>
