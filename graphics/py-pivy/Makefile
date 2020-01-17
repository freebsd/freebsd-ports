# Created by: Pedro Giffuni <pfg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pivy
PORTVERSION=	0.6.5
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Python binding for Coin

LICENSE=	MIT

BUILD_DEPENDS=	cmake:devel/cmake \
		swig3.0:devel/swig30
LIB_DEPENDS=	libCoin.so:graphics/Coin \
		libSoQt.so:x11-toolkits/soqt

USES=		compiler:c11 python qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	coin3d
USE_PYTHON=	autoplist distutils
USE_QT=		core gui opengl widgets

INSTALL_TARGET=	install-strip

BINARY_ALIAS=	swig=swig3.0

.include <bsd.port.mk>
