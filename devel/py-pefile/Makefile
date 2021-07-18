# Created by: Antoine Brodin <antoine@FreeBSD.org>

PORTNAME=	pefile
PORTVERSION=	2021.5.24
CATEGORIES=	devel python
MASTER_SITES=	https://github.com/erocarrera/pefile/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Python module to read and work with PE files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.6+
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
