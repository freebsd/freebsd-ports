PORTNAME=	hypatia_engine
PORTVERSION=	0.3.1
PORTREVISION=	8
CATEGORIES=	games python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lillian.lynn.lemmer@gmail.com
COMMENT=	Game engine for 2D top-down, tile-based action RPGs
WWW=		http://hypatia-engine.github.io/

LICENSE=	MIT

RUN_DEPENDS=	${PYGAME} \
		${PYTHON_PKGNAMEPREFIX}pyganim>0:graphics/py-pyganim@${PY_FLAVOR} \
		${PY_PILLOW}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
