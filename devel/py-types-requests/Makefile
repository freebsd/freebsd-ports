PORTNAME=	types-requests
PORTVERSION=	2.27.10
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Typing stubs for requests

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}types-urllib3>=0:devel/py-types-urllib3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
