PORTNAME=	noson-app
DISTVERSION=	5.6.13
CATEGORIES=	audio net

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Fast and smart SONOS controller
WWW=		https://janbar.github.io/noson-app/index.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libnoson.so:audio/noson

USES=		cmake compiler:c++11-lang qt:5 ssl
USE_QT=		core dbus declarative graphicaleffects gui network \
		quickcontrols2 svg widgets xml buildtools:build qmake:build
USE_GITHUB=	yes
GH_ACCOUNT=	janbar
CMAKE_OFF =	BUILD_LIBNOSON

.include <bsd.port.mk>
