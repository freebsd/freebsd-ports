# Created by: Ashley Chase <erisianash@gmail.com>
# $FreeBSD$

PORTNAME=	gmusicproxy
PORTVERSION=	1.0.8
DISTVERSIONPREFIX= v
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	erisianash@gmail.com
COMMENT=	Proxy for streaming Google Play Music using any media-player

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.3.0:devel/py-appdirs \
		${PYTHON_PKGNAMEPREFIX}gmusicapi>=10.1.0:audio/py-gmusicapi \
		${PYTHON_PKGNAMEPREFIX}netifaces>=-0.10.4:net/py-netifaces \
		${PYTHON_PKGNAMEPREFIX}xdg>=0.25:devel/py-xdg \
		${PYTHON_PKGNAMEPREFIX}eyed3>=0.7.8:audio/py-eyed3 \
		${PYTHON_PKGNAMEPREFIX}daemon>=2.0.5:devel/py-daemon

USES=		python
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	diraimondo

NO_ARCH=	yes

.include <bsd.port.mk>
