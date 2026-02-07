PORTNAME=	aeskulap
PORTVERSION=	0.2.2.20190120
PORTREVISION=	6
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Medical image viewer and DICOM network client
WWW=		https://aeskulap.nongnu.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdcmimage.so:graphics/dcmtk \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libglademm-2.4.so:devel/libglademm24 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		compiler:c++11-lang autoreconf desktop-file-utils gettext \
		gmake gnome jpeg libtool localbase pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --with-gsettings
GLIB_SCHEMAS=	org.gnu.aeskulap.gschema.xml
INSTALL_TARGET=	install-strip
USE_GITHUB=	yes
GH_ACCOUNT=	mikhailnov
GH_TAGNAME=	e43334e
USE_CXXSTD=	c++11
USE_GNOME=	gtkmm24 intltool libglade2
USE_LDCONFIG=	${PREFIX}/lib/aeskulap

post-patch:
	@${REINPLACE_CMD} -e '/^AM_GCONF_SOURCE_2/,+1d' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e '/^if GCONF_SCHEMAS_INSTALL/,+3d' \
		${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
