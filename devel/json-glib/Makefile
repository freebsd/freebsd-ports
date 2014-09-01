# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/json-glib/Makefile,v 1.22 2012/09/01 23:02:09 mezz Exp $

PORTNAME=	json-glib
PORTVERSION=	0.14.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	JSON (RFC 4627) interface for Glib

BUILD_DEPENDS=	${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection
RUN_DEPENDS=	${LOCALBASE}/share/gir-1.0/GLib-2.0.gir:${PORTSDIR}/devel/gobject-introspection

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomeprefix introspection:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
