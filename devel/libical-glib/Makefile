# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libical-glib
PORTVERSION=	1.0.4
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Introspection bindings for libical

LIB_DEPENDS=	libical.so:devel/libical

USES=		compiler:c11 gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=install-strip

.include <bsd.port.mk>
