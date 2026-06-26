PORTNAME=	simpleeval
PORTVERSION=	1.0.7
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, safe single expression evaluator library
WWW=		https://github.com/danthedeckie/simpleeval

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

CPE_VENDOR=	danthedeckie

.include <bsd.port.mk>
