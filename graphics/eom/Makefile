PORTNAME=	eom
DISTVERSION=	1.28.1
CATEGORIES=	graphics mate
MASTER_SITES=	https://github.com/mate-desktop/${PORTNAME}/releases/download/v${DISTVERSION}/
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Eye of MATE image viewer
WWW=		https://mate-desktop.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libpeas-gtk-1.0.so:devel/libpeas1

USES=		desktop-file-utils gettext gnome jpeg localbase mate meson \
		pathfix pkgconfig tar:xz xorg
USE_MATE=	common desktop icontheme
USE_XORG=	x11
USE_GNOME=	cairo glib20 gtk30 intltool introspection \
		librsvg2 libxml2
PORTSCOUT=	limitw:1,even
MESON_ARGS=	-Dcms=disabled

GLIB_SCHEMAS=	org.mate.eom.gschema.xml \
		org.mate.eom.enums.xml

OPTIONS_DEFINE=	EXIF EXEMPI DOCS
OPTIONS_DEFAULT=EXIF EXEMPI

EXEMPI_DESC=		XMP support
EXEMPI_MESON_ENABLE=	xmp
EXEMPI_LIB_DEPENDS=	libexempi.so:textproc/exempi

EXIF_DESC=		Digital camera file meta-data support
EXIF_MESON_ENABLE=	libexif
EXIF_LIB_DEPENDS=	libexif.so:graphics/libexif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXIF} || ${PORT_OPTIONS:MEXEMPI}
PLIST_SUB+=	EXIFEXEMPI=""
.else
PLIST_SUB+=	EXIFEXEMPI="@comment "
.endif

.include <bsd.port.mk>
