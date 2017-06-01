# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eog
PORTVERSION=	3.24.1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Eye Of Gnome image viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libpeas-gtk-1.0.so:devel/libpeas \
		liblcms2.so:graphics/lcms2
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake gnome jpeg libtool localbase \
		pathfix pkgconfig tar:xz
USE_GNOME=	cairo intltool librsvg2 gtk30 gnomedesktop3 introspection
USE_XORG=	x11
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.eog.enums.xml \
		org.gnome.eog.gschema.xml

PLIST_SUB+=	VERSION=3.0

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	EXIF EXEMPI
OPTIONS_DEFAULT=EXIF EXEMPI

EXIF_DESC=	Digital camera file meta-data support
EXIF_CONFIGURE_WITH=	libexif
EXIF_LIB_DEPENDS=	libexif.so:graphics/libexif

EXEMPI_DESC=	XMP support
EXEMPI_CONFIGURE_WITH=	xmp
EXEMPI_LIB_DEPENDS=	libexempi.so:textproc/exempi

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXIF} != "" || ${PORT_OPTIONS:MEXEMPI} != ""
PLIST_SUB+=	EXIFEXEMPI=""
.else
PLIST_SUB+=	EXIFEXEMPI="@comment "
.endif

.include <bsd.port.mk>
