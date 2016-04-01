# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gsound
PORTVERSION=	1.0.2
CATEGORIES=	audio
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GObject library for playing system sounds

BUILD_DEPENDS=	vala:lang/vala
LIB_DEPENDS=	libcanberra.so:audio/libcanberra

USES=		gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
