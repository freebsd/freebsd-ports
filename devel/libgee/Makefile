# Created by: Frank Steinborn <steinex@nognu.de>
# $FreeBSD$
#    $MCom: ports/trunk/devel/libgee/Makefile 19007 2014-02-16 10:11:57Z kwm $

PORTNAME=	libgee
PORTVERSION=	0.12.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GObject collection library

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-introspection=yes
USE_XZ=		yes
USES=		gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	glib20 gnomehier introspection:build
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
