PORTNAME=	mss
DISTVERSION=	10.1.0
CATEGORIES=	deskutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cross-platform multiple screenshots module in pure python using ctypes
WWW=		https://ultrafunkamsterdam.github.io/nodriver \
		https://github.com/UltrafunkAmsterdam/nodriver

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
