# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	metpy
PORTVERSION=	0.7.0
CATEGORIES=	astro python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	MetPy-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of tools for processing weather data

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${ENUM34} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.4:math/py-matplotlib@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.10.0:math/py-numpy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pint>=0.8:converters/py-pint@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproj>=1.9.4:graphics/py-pyproj@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.14:science/py-scipy@${FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python

.include <bsd.port.mk>
