# Created by: Mark Murray <markm@FreeBSD.org>

PORTNAME=	ufraw
PORTVERSION=	0.22.20210424
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Read and manipulate raw images from various digital cameras

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libjasper.so:graphics/jasper \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		autoreconf compiler:c++11-lang desktop-file-utils gettext gmake \
		gnome jpeg pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	sergiomb2
GH_PROJECT=	ufraw
GH_TAGNAME=	f34669b
USE_GNOME+=	cairo gdkpixbuf2 glib20 gtk20

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-extras \
		--enable-jasper

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib

OPTIONS_DEFINE=		CONTRAST DST EXIV2 FITS GIMP GNOME GTK2 LENSFUN
OPTIONS_DEFAULT=	CONTRAST EXIV2 GTK2 LENSFUN
OPTIONS_SUB=		yes

CONTRAST_DESC=	Enable contrast setting option
DST_DESC=	Use local time for timestamps
FITS_DESC=	FITS output support
GIMP_DESC=	Install GIMP plugin

CONTRAST_CONFIGURE_ENABLE=	contrast
DST_CONFIGURE_ENABLE=		dst-correction
EXIV2_LIB_DEPENDS=		libexiv2.so:graphics/exiv2
FITS_LIB_DEPENDS=		libcfitsio.so:astro/cfitsio
FITS_CONFIGURE_WITH=		cfitsio
GIMP_IMPLIES=			GTK2
GIMP_LIB_DEPENDS=		libbabl-0.1.so:x11/babl \
				libgegl-0.4.so:graphics/gegl \
				libgimp-2.0.so:graphics/gimp-app \
				libjson-glib-1.0.so:devel/json-glib
GIMP_CONFIGURE_WITH=		gimp
GNOME_USE=			GNOME=gconf2
GNOME_CONFIGURE_ENABLE=		mime
GNOME_VARS=			CATEGORIES+=gnome \
				GCONF_SCHEMAS=${PORTNAME}.schemas
GTK2_LIB_DEPENDS=		libgtkimageview.so:x11-toolkits/gtkimageview
GTK2_CONFIGURE_WITH=		gtk
LENSFUN_LIB_DEPENDS=		liblensfun.so:graphics/lensfun

post-patch:
	${GREP} -Ilrs 'default(none)' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e 's/default(none)//g'
	@${REINPLACE_CMD} -e 's|$$(datadir)/gconf/schemas|${PREFIX}/etc/gconf/schemas|g' \
		${WRKSRC}/Makefile.am

post-patch-EXIV2-off:
	@${REINPLACE_CMD} -e 's|exiv2 >= 0.20|exiv2 < 0|g' \
		${WRKSRC}/configure.ac

post-patch-LENSFUN-off:
	@${REINPLACE_CMD} -e 's|lensfun >= 0.2.5|lensfun < 0|g' \
		${WRKSRC}/configure.ac

post-install:
	${INSTALL_DATA} ${WRKSRC}/ufraw.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
