# Created by: FreeBSD GNOME Team <gnome@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-color-manager
PORTVERSION=	3.28.0
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session framework for the GNOME desktop to manage color profiles

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook2man:textproc/docbook-utils \
		itstool:textproc/itstool \
		docbook-sgml>0:textproc/docbook-sgml
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libcolord.so:graphics/colord \
		libcolord-gtk.so:graphics/colord-gtk \
		libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libtiff.so:graphics/tiff \
		libexif.so:graphics/libexif

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lang gettext gnome meson pkgconfig tar:xz
USE_GNOME=	cairo gtk30 vte3
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
MESON_ARGS=	-Dtests=false \
		-Dpackagekit=false

OPTIONS_DEFINE=	RAW
OPTIONS_DEFAULT=RAW
OPTIONS_SUB=	yes

RAW_DESC=	Enable RAW EXIF support
RAW_LIB_DEPENDS=	libexiv2.so:graphics/exiv2
RAW_MESON_TRUE=	exiv

post-patch:
	@${REINPLACE_CMD} -e "s|'share/man/man1'|'man/man1'|g" \
		${WRKSRC}/man/meson.build

.include <bsd.port.mk>
