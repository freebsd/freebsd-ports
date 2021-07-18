# Created by: FreeBSD GNOME Team <gnome@freebsd.org>

PORTNAME=	gnome-nibbles
PORTVERSION=	3.38.2
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome nibbles

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	vala:lang/vala \
		itstool:textproc/itstool \
		appstream-util:devel/appstream-glib
LIB_DEPENDS=	libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libclutter-1.0.so:graphics/clutter \
		libcogl.so:graphics/cogl \
		libjson-glib-1.0.so:devel/json-glib \
		libgee-0.8.so:devel/libgee \
		libgnome-games-support-1.so:games/libgnome-games-support

PORTSCOUT=	limitw:1,even

USES=		gettext gl gnome meson pathfix \
		pkgconfig tar:xz xorg
USE_GNOME=	cairo gsound gtk30 librsvg2 libxml2:build
INSTALLS_ICONS=	yes
USE_GL=		gl egl
USE_XORG=	x11 xcomposite xdamage xext xi xfixes xrandr

GLIB_SCHEMAS=	org.gnome.Nibbles.gschema.xml

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games

.include <bsd.port.mk>
