# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	astLib
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Astronomy modules for Python

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PKGNAMEPREFIX}astropy>=1.1:astro/py-astropy@${FLAVOR} \
		${PKGNAMEPREFIX}matplotlib>=0.98:math/py-matplotlib@${FLAVOR} \
		${PYNUMPY} \
		${PKGNAMEPREFIX}pillow>=0:graphics/py-pillow@${FLAVOR} \
		${PKGNAMEPREFIX}scipy>=0.7.0:science/py-scipy@${FLAVOR}

PORTSCOUT=	skipv:0.15,0.17,0.17.1 # incorrect versioning upstream

USES=		python:2.7
USE_PYTHON=	autoplist distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyWCSTools/*.so

.include <bsd.port.mk>
