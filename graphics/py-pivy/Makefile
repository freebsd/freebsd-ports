PORTNAME=	pivy
PORTVERSION=	0.6.6
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Python binding for Coin

LICENSE=	MIT

BUILD_DEPENDS=	cmake:devel/cmake \
		swig:devel/swig
LIB_DEPENDS=	libCoin.so:graphics/Coin \
		libSoQt.so:x11-toolkits/soqt

USES=		compiler:c11 python:3.6+ qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	coin3d
USE_PYTHON=	autoplist distutils
USE_QT=		core gui opengl widgets

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
