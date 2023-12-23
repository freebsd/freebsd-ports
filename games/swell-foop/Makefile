PORTNAME=	swell-foop
PORTVERSION=	41.1
PORTREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome swell-foop
WWW=		https://wiki.gnome.org/Swell%20Foop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libgnome-games-support-1.so:games/libgnome-games-support

PORTSCOUT=	limitw:1,even

USES=		gettext gnome localbase meson pkgconfig python:build \
		tar:xz vala:build
USE_GNOME=	gtk30
GLIB_SCHEMAS=	org.gnome.SwellFoop.gschema.xml
BINARY_ALIAS=	python3=${PYTHON_VERSION}

.include <bsd.port.mk>
