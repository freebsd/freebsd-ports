# Created by: FreeBSD GNOME Team <gnome@freebsd.org>
# $FreeBSD$

PORTNAME=	four-in-a-row
PORTVERSION=	3.22.1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Make lines of the same color

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		vala:lang/vala \
		appstream-util:devel/appstream-glib
LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libcanberra-gtk3.so:audio/libcanberra-gtk3

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome localbase pathfix pkgconfig tar:xz
INSTALLS_ICONS=	yes
USE_GNOME=	cairo gtk30 intlhack librsvg2 libxml2:build
USE_XORG=	x11
GNU_CONFIGURE=	yes

GLIB_SCHEMAS=	org.gnome.four-in-a-row.gschema.xml

.include <bsd.port.mk>
