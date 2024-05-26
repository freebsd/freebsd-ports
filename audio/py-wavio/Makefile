PORTNAME=	wavio
DISTVERSION=	0.0.9
CATEGORIES=	audio python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python module for reading and writing WAV files using numpy arrays
WWW=		https://github.com/WarrenWeckesser/wavio/

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYNUMPY}

USES=		python
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>
