PORTNAME=	marshmallow
PORTVERSION=	3.17.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simplified object serialization for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=17.0:devel/py-packaging@${PY_FLAVOR}

USES=		cpe python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

CPE_VENDOR=	marshmallow_project

.include <bsd.port.mk>
