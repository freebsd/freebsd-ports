# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libical-glib
PORTVERSION=	1.0.0
CATEGORIES=	devel
#MASTER_SITES=	GNOME
MASTER_SITES=	LOCAL/kwm

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Introspection bindings for libical

LIB_DEPENDS=	libical.so:${PORTSDIR}/devel/libical

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=install-strip

.include <bsd.port.mk>
