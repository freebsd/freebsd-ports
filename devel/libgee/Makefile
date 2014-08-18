# Created by: Frank Steinborn <steinex@nognu.de>
# $FreeBSD$
#    $MCom: ports/trunk/devel/libgee/Makefile 19813 2014-08-15 19:44:33Z gusi $

PORTNAME=	libgee
PORTVERSION=	0.14.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GObject collection library

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
USES=		gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomehier introspection:build
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
