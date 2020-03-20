# $FreeBSD$

PORTNAME=	glooey
PORTVERSION=	0.3.0
CATEGORIES=	graphics x11-toolkits python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Cross-platform windowing and multimedia library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyglet>0:graphics/py-pyglet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vecrec>0:graphics/py-vecrec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}autoprop>0:devel/py-autoprop@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}debugtools>0:devel/py-debugtools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
