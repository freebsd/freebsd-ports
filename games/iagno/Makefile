# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$

PORTNAME=	iagno
PORTVERSION=	3.38.1
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Iagno

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala \
		itstool:textproc/itstool \
		appstream-util:devel/appstream-glib

LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase meson \
		pathfix pkgconfig tar:xz xorg
USE_GNOME=	cairo gsound gtk30 intlhack librsvg2 libxml2:build
USE_XORG=	x11
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	org.gnome.Reversi.gschema.xml

.include <bsd.port.mk>
