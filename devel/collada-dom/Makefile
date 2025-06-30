PORTNAME=	collada-dom
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
PORTREVISION=	15
CATEGORIES=	devel

MAINTAINER=	trueos@norwegianrockcat.com
COMMENT=	COLLADA Document Object Model (DOM) C++ Library
WWW=		https://github.com/rdiankov/collada-dom

LICENSE=	MIT

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libboost_filesystem.so:devel/boost-libs \
		libboost_system.so:devel/boost-libs

USES=		cmake gnome minizip pkgconfig
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	rdiankov
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

# LLVM15+ workaround
CFLAGS=		-Wno-int-conversion

.include <bsd.port.mk>
