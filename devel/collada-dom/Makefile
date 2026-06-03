PORTNAME=	collada-dom
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.2
CATEGORIES=	devel

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	COLLADA Document Object Model (DOM) C++ Library
WWW=		https://github.com/Gepetto/collada-dom

LICENSE=	MIT

LIB_DEPENDS=	liburiparser.so:net/uriparser \
		libboost_filesystem.so:devel/boost-libs

USES=		cmake gnome minizip pkgconfig
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Gepetto

.include <bsd.port.mk>
