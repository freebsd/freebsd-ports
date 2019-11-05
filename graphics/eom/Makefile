# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eom
PORTVERSION=	1.22.1
PORTREVISION=	1
CATEGORIES=	graphics mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Eye of MATE image viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libstartup-notification-1.so:x11/startup-notification \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libpeas-gtk-1.0.so:devel/libpeas

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gettext gmake gnome \
		jpeg libtool localbase mate pathfix pkgconfig tar:xz xorg
USE_MATE=	desktop icontheme
USE_XORG=	x11
USE_GNOME=	cairo gnomeprefix gtk30 intltool introspection \
		librsvg2 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-cms
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.eom.gschema.xml \
		org.mate.eom.enums.xml

OPTIONS_DEFINE=	EXIF EXEMPI DOCS
OPTIONS_DEFAULT=EXIF EXEMPI

EXEMPI_DESC=		XMP support
EXEMPI_CONFIGURE_WITH=	xmp
EXEMPI_LIB_DEPENDS=	libexempi.so:textproc/exempi

EXIF_DESC=		Digital camera file meta-data support
EXIF_CONFIGURE_WITH=	libexif
EXIF_LIB_DEPENDS=	libexif.so:graphics/libexif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXIF} || ${PORT_OPTIONS:MEXEMPI}
PLIST_SUB+=	EXIFEXEMPI=""
.else
PLIST_SUB+=	EXIFEXEMPI="@comment "
.endif

.include <bsd.port.mk>
