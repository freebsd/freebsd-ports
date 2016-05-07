# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	json-glib
PORTVERSION=	1.1.2
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	JSON (RFC 4627) interface for Glib

OPTIONS_DEFINE=	GIR
OPTIONS_DEFAULT=GIR
OPTIONS_SUB=	yes
GIR_DESC=	Build introspection data
GIR_USE=	gnome=introspection
GIR_CONFIGURE_ENABLE=introspection

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gnomeprefix
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

PORTDOCS=	*

.include <bsd.port.mk>
