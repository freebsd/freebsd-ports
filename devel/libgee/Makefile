# Created by: Frank Steinborn <steinex@nognu.de>
# $FreeBSD$

PORTNAME=	libgee
PORTVERSION=	0.18.0
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GObject collection library

BUILD_DEPENDS=	valac:lang/vala

PORTSCOUT=	limitw:1,even

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
USES=		gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
