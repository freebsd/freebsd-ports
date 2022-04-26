# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	eog
DISTVERSION=	42.0
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Eye Of Gnome image viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool
LIB_DEPENDS=	libexif.so:graphics/libexif \
		libhandy-1.so:x11-toolkits/libhandy \
		liblcms2.so:graphics/lcms2 \
		libpeas-gtk-1.0.so:devel/libpeas
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lang desktop-file-utils gettext gnome jpeg \
		localbase meson pkgconfig python:build,3.6+ shebangfix tar:xz \
		xorg
USE_GNOME=	cairo gnomedesktop3 gtk30 introspection librsvg2
USE_XORG=	x11

MESON_ARGS=	-Dlibexif=true \
		-Dlibportal=false

GLIB_SCHEMAS=	org.gnome.eog.enums.xml \
		org.gnome.eog.gschema.xml

PLIST_SUB+=	VERSION=3.0

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		EXEMPI
OPTIONS_DEFAULT=	EXEMPI

EXEMPI_DESC=		XMP support
EXEMPI_MESON_TRUE=	xmp
EXEMPI_LIB_DEPENDS=	libexempi.so:textproc/exempi

.include <bsd.port.mk>
