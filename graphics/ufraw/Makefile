# Created by: Mark Murray <markm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ufraw
PORTVERSION=	0.22
PORTREVISION=	14
CATEGORIES=	graphics

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Read and manipulate raw images from various digital cameras

LICENSE=	GPLv2

LIB_DEPENDS=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		liblcms2.so:graphics/lcms2 \
		libjasper.so:graphics/jasper \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-extras
USES=		compiler:c++11-lang gettext gmake jpeg pkgconfig autoreconf gnome

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

OPTIONS_DEFINE=	CONTRAST DST EXIV2 LENSFUN FITS GIMP GTK2 GNOME
OPTIONS_DEFAULT=CONTRAST EXIV2 LENSFUN GTK2
OPTIONS_SUB=	yes

CONTRAST_DESC=	Enable contrast setting option
DST_DESC=	Use local time for timestamps
FITS_DESC=	FITS output support
GIMP_DESC=	Install GIMP plugin

USE_GITHUB=	yes
GH_ACCOUNT=	sergiomb2
GH_PROJECT=	ufraw
GH_TAGNAME=	6d3259a

USE_GNOME+=glib20 gtk20 cairo gdkpixbuf2

CONTRAST_CONFIGURE_ENABLE=	contrast
DST_CONFIGURE_ENABLE=	dst-correction
EXIV2_LIB_DEPENDS=	libexiv2.so:graphics/exiv2
EXIV2_VARS_OFF=		PC_FALSE+=exiv2
LENSFUN_LIB_DEPENDS=	liblensfun.so:graphics/lensfun
LENSFUN_VARS_OFF=	PC_FALSE+=lensfun
FITS_LIB_DEPENDS=	libcfitsio.so:astro/cfitsio
FITS_VARS_OFF=		PC_FALSE+=cfitsio
GIMP_LIB_DEPENDS=	libgimp-2.0.so:graphics/gimp-app
GIMP_CONFIGURE_WITH=	gimp
GIMP_VARS_OFF=		PC_FALSE+=gimp
GIMP_IMPLIES=		GTK2
GTK2_LIB_DEPENDS=	libgtkimageview.so:x11-toolkits/gtkimageview
GTK2_CONFIGURE_WITH=	gtk
GNOME_USE=		GNOME=gconf2
GNOME_CONFIGURE_ENABLE=	mime
GNOME_VARS=		CATEGORIES+=gnome GCONF_SCHEMAS=${PORTNAME}.schemas

post-install:
	${INSTALL_DATA} ${WRKSRC}/ufraw.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
