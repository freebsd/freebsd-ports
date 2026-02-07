PORTNAME=	bencoder
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	converters python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple bencode decoder/encoder library in pure Python
WWW=		https://github.com/utdemir/bencoder

LICENSE=	CC0-1.0

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

USE_GITHUB=	yes
GH_ACCOUNT=	utdemir

NO_ARCH=	yes

.include <bsd.port.mk>
