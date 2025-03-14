PORTNAME=	typing-inspection
PORTVERSION=	0.4.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	typing_inspection-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Runtime typing introspection tools
WWW=		https://typing-inspection.pydantic.dev/latest/ \
		https://github.com/pydantic/typing-inspection

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.12.0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
