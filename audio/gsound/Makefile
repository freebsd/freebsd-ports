# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	gsound
PORTVERSION=	1.0.3
CATEGORIES=	audio
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject library for playing system sounds

BUILD_DEPENDS=	vala:lang/vala
LIB_DEPENDS=	libcanberra.so:audio/libcanberra

USES=		gnome meson pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build

.include <bsd.port.mk>
