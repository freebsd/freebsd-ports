# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	gnome-font-viewer
PORTVERSION=	41.0
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	218166246e29.patch:-p1 # https://gitlab.gnome.org/GNOME/gnome-font-viewer/-/merge_requests/27

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 3 font viewer utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
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
