PORTNAME=	gconfmm
PORTVERSION=	2.28.3
PORTREVISION=	3
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C++ wrapper for gconf2 API library
WWW=		http://gtkmm.sourceforge.net/

DEPRECATED=	Gconf has been replaced with gsettings
EXPIRATION_DATE=	2025-08-24

LIB_DEPENDS=	libglibmm-2.4.so:devel/glibmm

USES=		compiler:c++11-lang gmake gnome libtool pathfix \
		pkgconfig tar:bzip2 xorg
USE_CXXSTD=	c++11
USE_XORG=	x11
USE_GNOME=	gconf2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static --disable-documentation
INSTALL_TARGET=	install-strip
BINARY_WRAPPERS=	gm4

PLIST_SUB=	VERSION="2.6" API_VERSION="2.6"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
