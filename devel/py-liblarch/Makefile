# $FreeBSD$

PORTNAME=	liblarch
PORTVERSION=	2.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python library to easily handle data structures

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USES=		gnome python:2.7
USE_GITHUB=	yes
USE_GNOME=	pygobject
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes
PORTSCOUT=	ignore:v3.0

.include <bsd.port.mk>
