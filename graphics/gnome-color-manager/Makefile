PORTNAME=	gnome-color-manager
PORTVERSION=	3.36.0
PORTREVISION=	4
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session framework for the GNOME desktop to manage color profiles
WWW=		https://git.gnome.org/browse/gnome-color-manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook2man:textproc/docbook-utils \
		itstool:textproc/itstool \
		docbook-sgml>0:textproc/docbook-sgml
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libcolord.so:graphics/colord \
		libcolord-gtk.so:graphics/colord-gtk \
		libtiff.so:graphics/tiff \
		libexif.so:graphics/libexif

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lang desktop-file-utils gettext gnome meson \
		pkgconfig tar:xz
USE_GNOME=	cairo gtk30 vte3
USE_LDCONFIG=	yes
MESON_ARGS=	-Dtests=false

post-patch:
	@${REINPLACE_CMD} -e "s|'share/man/man1'|'man/man1'|g" \
		${WRKSRC}/man/meson.build

.include <bsd.port.mk>
