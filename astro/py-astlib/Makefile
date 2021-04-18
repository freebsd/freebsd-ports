# Created by: Wen Heping <wenheping@gmail.com>

PORTNAME=	astlib
PORTVERSION=	0.11.6
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	astLib-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Astronomy modules for Python

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}astropy>=1.1:astro/py-astropy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0.98:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0.1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.7.0:science/py-scipy@${PY_FLAVOR}

USES=		python:3.5+
USE_PYTHON=	autoplist concurrent distutils

PORTSCOUT=	skipv:0.15,0.17,0.17.1 # incorrect versioning upstream

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/PyWCSTools/*.so

.include <bsd.port.mk>
