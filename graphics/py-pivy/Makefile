PORTNAME=	pivy
PORTVERSION=	0.6.8
PORTREVISION=	1
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Python binding for Coin
WWW=		https://github.com/coin3d/pivy

LICENSE=	MIT

BUILD_DEPENDS=	cmake:devel/cmake-core \
		swig:devel/swig
LIB_DEPENDS=	libCoin.so:graphics/Coin \
		libSoQt.so:x11-toolkits/soqt

USES=		compiler:c11 python qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	coin3d
USE_PYTHON=	distutils
USE_QT=		core gui opengl widgets

PLIST_SUB+=	DISTVERSION=${DISTVERSION}

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
