PORTNAME=	hypatia_engine
PORTVERSION=	0.3.1
PORTREVISION=	4
CATEGORIES=	games python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lillian.lynn.lemmer@gmail.com
COMMENT=	Game engine for 2D top-down, tile-based action RPGs

LICENSE=	MIT

RUN_DEPENDS=	${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}pyganim>0:graphics/py-pyganim@${PY_FLAVOR} \
		${PY_PILLOW}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
