PORTNAME=	glooey
PORTVERSION=	0.3.3
PORTREVISION=	2
CATEGORIES=	graphics x11-toolkits python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Cross-platform windowing and multimedia library
WWW=		https://pypi.org/project/glooey

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# see https://github.com/kxgames/glooey/issues/56 regarding pyglet2 support
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyglet1>0:graphics/py-pyglet1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vecrec>0:graphics/py-vecrec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}autoprop>0:devel/py-autoprop@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}debugtools>0:devel/py-debugtools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		display:test python
USE_PYTHON=	autoplist distutils pytest
NO_ARCH=	yes

.include <bsd.port.mk>
