PORTNAME=	xviewer
PORTVERSION=	3.2.4
PORTREVISION=	4
CATEGORIES=	graphics gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Fast and functional image viewer
WWW=		https://github.com/linuxmint/xviewer

LICENSE=	GPLv2+

PORTSCOUT=	limit:^[0-9.]+$$	# ignore non-numeric tags

BUILD_DEPENDS=	itstool:textproc/itstool \
		${LOCALBASE}/share/aclocal/yelp.m4:textproc/yelp-tools
LIB_DEPENDS=	libcinnamon-desktop.so:x11/cinnamon-desktop \
		libxapp.so:x11/xapp \
		libpeas-1.0.so:devel/libpeas
RUN_DEPENDS=	yelp:x11/yelp

USES=		autoreconf compiler:c++11-lang desktop-file-utils gettext-tools \
		gmake gnome libtool localbase pkgconfig xorg
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_GNOME=	atk cairo gdkpixbuf2 gtk30 intltool introspection pango
USE_XORG=	x11
GLIB_SCHEMAS=	org.x.viewer.enums.xml org.x.viewer.gschema.xml

OPTIONS_DEFINE=	JPEG LCMS2 LIBEXIF LIBRSVG2 XMP
OPTIONS_DEFAULT=	JPEG LCMS2 LIBEXIF LIBRSVG2 XMP
XMP_DESC=	Adobe Extensible Metadata Platform support
OPTIONS_SUB=	yes

JPEG_USES=		jpeg
JPEG_CONFIGURE_OFF=	--without-libjpeg

LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2
LCMS2_CONFIGURE_OFF=	--without-cms

LIBEXIF_LIB_DEPENDS=	libexif.so:graphics/libexif
LIBEXIF_CONFIGURE_OFF=	--without-libexif

LIBRSVG2_USE=		GNOME=librsvg2
LIBRSVG2_CONFIGURE_OFF=	--without-librsvg

XMP_LIB_DEPENDS=	libexempi.so:textproc/exempi
XMP_CONFIGURE_OFF=	--without-xmp

.include <bsd.port.mk>
