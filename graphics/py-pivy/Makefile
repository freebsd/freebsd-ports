# Created by: Pedro Giffuni <pfg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pivy
PORTVERSION=	0.5.0
CATEGORIES=	graphics python
MASTER_SITES=	https://bitbucket.org/Coin3D/pivy/get/
DISTNAME=	8eab90908f2a

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Python binding for Coin

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/bin/swig:devel/swig13
LIB_DEPENDS=	libSoQt.so:x11-toolkits/soqt

USES=		zip python:2
USE_PYTHON=	autoplist distutils

WRKSRC=		${WRKDIR}/Coin3D-pivy-${DISTNAME}

.include <bsd.port.mk>
