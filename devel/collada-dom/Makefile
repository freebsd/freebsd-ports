PORTNAME=	collada-dom
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	COLLADA Document Object Model (DOM) C++ Library

LICENSE=	MIT

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libboost_filesystem.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs

USES=		cmake gnome minizip
USE_LDCONFIG=	yes
USE_GNOME=	libxml2
USE_GITHUB=	yes
GH_ACCOUNT=	rdiankov

.include <bsd.port.mk>
