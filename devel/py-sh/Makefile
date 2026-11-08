PORTNAME=	sh
PORTVERSION=	2.4.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/amoffat/sh/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python subprocess replacement
WWW=		https://sh.readthedocs.io/en/latest/ \
		https://github.com/amoffat/sh

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
