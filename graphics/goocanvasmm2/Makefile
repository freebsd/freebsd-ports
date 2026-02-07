PORTNAME=	goocanvasmm
PORTVERSION=	1.90.9
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ bindings for the goocanvas widget for GTK
WWW=		https://sourceforge.net/projects/goocanvas/

LIB_DEPENDS=	libgoocanvas-2.0.so:graphics/goocanvas2

USES=		compiler:c++11-lang gmake gnome libtool pathfix pkgconfig \
		tar:xz
USE_CXXSTD=	c++11
USE_GNOME=	gtkmm30
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
