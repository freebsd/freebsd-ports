PORTNAME=	banal
DISTVERSION=	1.1.2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Commons of banal micro-functions for Python
WWW=		https://github.com/pudo/banal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	pudo
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
