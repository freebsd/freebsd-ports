PORTNAME=	aeskulap
PORTVERSION=	0.2.2.20190120
PORTREVISION=	6
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Medical image viewer
WWW=		https://aeskulap.nongnu.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdcmimage.so:graphics/dcmtk \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libglademm-2.4.so:devel/libglademm24 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		compiler:c++11-lang autoreconf desktop-file-utils gettext \
		gmake gnome jpeg libtool localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	mikhailnov
GH_TAGNAME=	e43334e
USE_CXXSTD=	c++11
USE_GNOME=	gtkmm24 intltool libglade2
USE_LDCONFIG=	${PREFIX}/lib/aeskulap

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --with-gsettings
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
