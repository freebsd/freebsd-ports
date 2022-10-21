PORTNAME=	types-xxhash
PORTVERSION=	3.0.5.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Typing stubs for xxhash
WWW=		https://pypi.org/project/types-xxhash/

LICENSE=	APACHE20

# XXX: no longer needed with xxhash>=3.1.0, remove after its update
CONFLICTS=	${PYTHON_PKGNAMEPREFIX}xxhash-3.[123456789]*

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
