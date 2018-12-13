# Created by: gahr
# $FreeBSD$

PORTNAME=	aeskulap
DISTVERSION=	0.2.2.20180219
CATEGORIES=	graphics

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Medical image viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdcmimage.so:graphics/dcmtk \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libglademm-2.4.so:devel/libglademm24 \
		libpng16.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		compiler:c++11-lang autoreconf desktop-file-utils gettext \
		gmake gnome jpeg libtool localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	jenslody # was pipelka
GH_TAGNAME=	8787e95
USE_CXXSTD=	c++11
USE_GNOME=	gconfmm26 gtkmm24 intltool libglade2
USE_LDCONFIG=	${PREFIX}/lib/aeskulap

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
