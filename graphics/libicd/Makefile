PORTNAME=	libicd
PORTVERSION=	0.0.0.20250416
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Image codec library
WWW=		https://github.com/lucianpls/libicd

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng.so:graphics/png

USES=		cmake:testing compiler:c++11-lang jpeg

CMAKE_OFF=	BUILD_TESTING \
		USE_QB3
CMAKE_ON=	BUILD_SHARED_LIBS

USE_GITHUB=	yes
GH_ACCOUNT=	lucianpls
GH_TAGNAME=	ebc3a80

.include <bsd.port.mk>
