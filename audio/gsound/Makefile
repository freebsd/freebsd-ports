PORTNAME=	gsound
PORTVERSION=	1.0.3
CATEGORIES=	audio
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject library for playing system sounds
WWW=		https://wiki.gnome.org/Projects/GSound

LIB_DEPENDS=	libcanberra.so:audio/libcanberra

USES=		gnome meson pkgconfig tar:xz vala:build
USE_GNOME=	glib20 introspection:build

.include <bsd.port.mk>
