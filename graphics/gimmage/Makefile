# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gimmage
PORTVERSION=	0.2.3
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	BERLIOS CENKES

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple image viewer

LIB_DEPENDS=	libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24 \
		libcurl.so:${PORTSDIR}/ftp/curl

USES=		gettext
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE}

.include <bsd.port.mk>
