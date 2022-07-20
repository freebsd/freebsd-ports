PORTNAME=	cluttermm
PORTVERSION=	1.17.3
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ interfaces for clutter

LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter

USES+=		compiler:c++11-lang gettext gmake gnome libtool pathfix perl5 \
		pkgconfig tar:xz
USE_CXXSTD=	c++11
USE_GNOME=	atkmm glib20 gtkmm30 libsigc++20 pangomm
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-documentation
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
