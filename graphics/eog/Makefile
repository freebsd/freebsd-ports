# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	eog
DISTVERSION=	40.2
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Eye Of Gnome image viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libpeas-gtk-1.0.so:devel/libpeas \
		liblcms2.so:graphics/lcms2 \
		libexif.so:graphics/libexif
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lang desktop-file-utils gettext gnome jpeg \
		localbase meson pkgconfig python:build,3.6+ shebangfix tar:xz \
		xorg
USE_GNOME=	cairo librsvg2 gtk30 gnomedesktop3 introspection
USE_XORG=	x11
INSTALLS_ICONS=	yes
SHEBANG_FILES=	${WRKSRC}/meson_post_install.py

MESON_ARGS=	-Dlibportal=false -Dlibexif=true

GLIB_SCHEMAS=	org.gnome.eog.enums.xml \
		org.gnome.eog.gschema.xml

PLIST_SUB+=	VERSION=3.0

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	EXEMPI
OPTIONS_DEFAULT=EXEMPI

EXEMPI_DESC=	XMP support
EXEMPI_MESON_TRUE=	xmp
EXEMPI_LIB_DEPENDS=	libexempi.so:textproc/exempi

.include <bsd.port.mk>
