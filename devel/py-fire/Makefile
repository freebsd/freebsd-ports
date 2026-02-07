PORTNAME=	fire
DISTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	devel science
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for automatically generating command line interfaces (CLIs)
WWW=		https://github.com/google/python-fire

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}termcolor>0:devel/py-termcolor@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils flavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
