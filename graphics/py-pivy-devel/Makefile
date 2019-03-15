# Created by: Pedro Giffuni <pfg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pivy
PORTVERSION=	0.6.4
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Python binding for Coin

LICENSE=	MIT

BUILD_DEPENDS=	cmake:devel/cmake \
		swig3.0:devel/swig30
LIB_DEPENDS=	libCoin.so:graphics/Coin \
		libSoQt.so:x11-toolkits/soqt-devel

USES=		compiler:c11 python qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	FreeCAD
USE_PYTHON=	autoplist distutils
USE_QT=		core gui opengl widgets

INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	py-pivy

BINARY_ALIAS=	swig=swig3.0

.include <bsd.port.mk>
