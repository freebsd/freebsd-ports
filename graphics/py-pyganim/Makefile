PORTNAME=	pyganim
PORTVERSION=	0.9.2
PORTREVISION=	5
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pyganim-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sprite animation module for Pygame
WWW=		https://inventwithpython.com/pyganim/ \
		https://github.com/asweigart/pyganim

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}game>=0:devel/py-game@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
