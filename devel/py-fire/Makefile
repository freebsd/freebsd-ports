PORTNAME=	fire
DISTVERSION=	0.6.0
CATEGORIES=	devel science
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for automatically generating command line interfaces (CLIs)
WWW=		https://github.com/google/python-fire

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>0:devel/py-termcolor@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils flavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
