PORTNAME=	noson-app
DISTVERSION=	5.7.3
CATEGORIES=	audio net

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Fast and smart SONOS controller
WWW=		https://janbar.github.io/noson-app/index.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libnoson.so:audio/noson \
		libGLX.so:graphics/libglvnd

USES=		cmake compiler:c++11-lang qt:6 ssl
USE_QT=		5compat base declarative svg
USE_GITHUB=	yes
GH_ACCOUNT=	janbar
CMAKE_OFF =	BUILD_LIBNOSON

.include <bsd.port.mk>
