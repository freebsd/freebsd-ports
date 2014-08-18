# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/graphics/eog/Makefile 19814 2014-08-15 20:17:00Z gusi $

PORTNAME=	eog
PORTVERSION=	3.12.2
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The Eye Of Gnome image viewer

BUILD_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		itstool:${PORTSDIR}/textproc/itstool \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libpeas-gtk-1.0.so:${PORTSDIR}/devel/libpeas \
		liblcms.so:${PORTSDIR}/graphics/lcms
RUN_DEPENDS=	gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

USES=		desktop-file-utils gettext gmake libtool pathfix \
		pkgconfig tar:xz
USE_GNOME=	gnomeprefix intlhack librsvg2 gtk30 gnomedesktop3 \
		introspection:build
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.eog.enums.xml \
		org.gnome.eog.gschema.xml

PLIST_SUB+=	VERSION=3.0

OPTIONS_DEFINE=	EXIF EXEMPI
OPTIONS_DEFAULT=EXIF EXEMPI
EXIF_DESC=	Digital camera file meta-data support
EXEMPI_DESC=	XMP support

.include <bsd.port.options.mk>

_WITH_EXIF=	no
_WITH_EXEMPI=	no

.if ${PORT_OPTIONS:MEXIF}
CONFIGURE_ARGS+=--with-libexif
LIB_DEPENDS+=	libexif.so:${PORTSDIR}/graphics/libexif
PLIST_SUB+=	EXIF=""
_WITH_EXIF=	yes
.else
CONFIGURE_ARGS+=--without-libexif
PLIST_SUB+=	EXIF="@comment "
.endif

.if ${PORT_OPTIONS:MEXEMPI}
CONFIGURE_ARGS+=--with-xmp
LIB_DEPENDS+=	libexempi.so:${PORTSDIR}/textproc/exempi
_WITH_EXEMPI=	yes
.else
CONFIGURE_ARGS+=--without-xmp
.endif

.if ${_WITH_EXIF}=="yes" || ${_WITH_EXEMPI}=="yes"
PLIST_SUB+=	EXIFEXEMPI=""
.else
PLIST_SUB+=	EXIFEXEMPI="@comment "
.endif

.include <bsd.port.mk>
