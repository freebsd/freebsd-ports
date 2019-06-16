# Created by: gahr
# $FreeBSD$

PORTNAME=	aeskulap
DISTVERSION=	0.2.2.20181229
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Medical image viewer

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
GH_ACCOUNT=	stefanhusmann
GH_TAGNAME=	26ad27a
USE_CXXSTD=	c++11
USE_GNOME=	gconfmm26 gtkmm24 intltool libglade2
USE_LDCONFIG=	${PREFIX}/lib/aeskulap

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
