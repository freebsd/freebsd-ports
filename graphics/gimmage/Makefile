# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gimmage
PORTVERSION=	0.2.3
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple image viewer

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		desktop-file-utils gettext pkgconfig
USE_GNOME=	gtkmm24
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}

.include <bsd.port.mk>
