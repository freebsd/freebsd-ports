PORTNAME=	scheduler
DISTVERSION=	0.8.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python scheduler library
WWW=		https://gitlab.com/DigonIO/scheduler

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}typeguard>=3.0.0:devel/py-typeguard@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
