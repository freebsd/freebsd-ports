PORTNAME=	gnome-font-viewer
PORTVERSION=	43.0
PORTREVISION=	2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME font viewer utility
WWW=		https://github.com/GNOME/gnome-font-viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libadwaita-1.so:x11-toolkits/libadwaita \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libhandy-1.so:x11-toolkits/libhandy \
		libharfbuzz.so:print/harfbuzz

CONFLICTS=	gnome-utils-2.[0-9]*
PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gettext gnome localbase meson \
		pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo gnomedesktop3 gtk30

.include <bsd.port.mk>
