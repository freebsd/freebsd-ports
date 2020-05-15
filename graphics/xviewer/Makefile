# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xviewer
PORTVERSION=	2.6.0
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Fast and functional image viewer

LICENSE=	GPLv2+

PORTSCOUT=	limit:^[0-9.]+$$	# ignore master.mint* tags

BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/gtk-doc.m4:textproc/gtk-doc \
		intltool-update:textproc/intltool \
		itstool:textproc/itstool \
		${LOCALBASE}/share/aclocal/yelp.m4:textproc/yelp-tools
LIB_DEPENDS=	libcinnamon-desktop.so:x11/cinnamon-desktop \
		libpeas-1.0.so:devel/libpeas

USES=		autoreconf compiler:c++11-lang desktop-file-utils gettext-tools \
		gmake gnome libtool localbase pkgconfig xorg
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_GNOME=	atk cairo gdkpixbuf2 gtk30 introspection pango
USE_XORG=	x11
GLIB_SCHEMAS=	org.x.viewer.enums.xml org.x.viewer.gschema.xml
INSTALLS_ICONS=	yes

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

post-patch:
	@${REINPLACE_CMD} -e '/CINNAMON_DESKTOP_REQUIRED/s,3\.2\.0,2.4.2,' \
		${WRKSRC}/configure.ac

.include <bsd.port.mk>
