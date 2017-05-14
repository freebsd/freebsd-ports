# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gimmage
PORTVERSION=	0.2.3
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	BERLIOS

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Simple image viewer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		fails to build

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		desktop-file-utils gettext pkgconfig
USE_GNOME=	gtkmm24
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}

.include <bsd.port.mk>
