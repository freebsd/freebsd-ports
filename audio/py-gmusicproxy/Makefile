# Created by: Ashley Chase <erisianash@gmail.com>
# $FreeBSD$

PORTNAME=	gmusicproxy
PORTVERSION=	1.0.8
DISTVERSIONPREFIX=	v
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	erisianash@gmail.com
COMMENT=	Proxy for streaming Google Play Music using any media-player

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=1.3.0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gmusicapi>=10.1.0:audio/py-gmusicapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>=-0.10.4:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>=0.25:devel/py-xdg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}eyed3>=0.7.8:audio/py-eyed3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}daemon>=2.0.5:devel/py-daemon@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	diraimondo

NO_ARCH=	yes

.include <bsd.port.mk>
