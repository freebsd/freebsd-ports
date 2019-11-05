# Created by: FreeBSD GNOME Team <gnome@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnome-taquin
PORTVERSION=	3.28.0
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Move tiles so that they reach their places

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala \
		itstool:textproc/itstool
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase pathfix pkgconfig tar:xz xorg
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2:build
USE_XORG=	x11
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.gnome.taquin.gschema.xml

.include <bsd.port.mk>
