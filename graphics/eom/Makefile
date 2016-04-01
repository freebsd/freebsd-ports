# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eom
PORTVERSION=	1.12.2
CATEGORIES=	graphics mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Eye of MATE image viewer

BUILD_DEPENDS=	itstool:textproc/itstool

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake jpeg libtool pathfix pkgconfig \
		tar:xz
USE_MATE=	desktop icontheme
USE_XORG=	x11
USE_GNOME=	gdkpixbuf2 glib20 gtk20 intltool librsvg2 libxml2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc \
		--disable-introspection \
		--with-gtk=2.0 \
		--disable-python \
		--without-cms
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.eom.gschema.xml \
		org.mate.eom.enums.xml

OPTIONS_DEFINE=	EXIF EXEMPI
OPTIONS_DEFAULT=EXIF EXEMPI
EXIF_DESC=	Digital camera file meta-data support
EXEMPI_DESC=	XMP support

.include <bsd.port.options.mk>

_WITH_EXIF=	no
_WITH_EXEMPI=	no

.if ${PORT_OPTIONS:MEXIF}
CONFIGURE_ARGS+=--with-libexif
LIB_DEPENDS+=	libexif.so:graphics/libexif
PLIST_SUB+=	EXIF=""
_WITH_EXIF=	yes
.else
CONFIGURE_ARGS+=--without-libexif
PLIST_SUB+=	EXIF="@comment "
.endif

.if ${PORT_OPTIONS:MEXEMPI}
CONFIGURE_ARGS+=--with-xmp
LIB_DEPENDS+=	libexempi.so:textproc/exempi
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
