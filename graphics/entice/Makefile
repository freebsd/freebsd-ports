# New ports collection makefile for:	entice
# Date created:		7 Oct 2001
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	entice
PORTVERSION=	0.9.3.004
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	http://enlightenment.freedesktop.org/files/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	An image viewer written using libraries for Enlightenment 0.17 development

LIB_DEPENDS=	esmart_thumb.0:${PORTSDIR}/graphics/esmart

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=	15
USE_GNOME=	gnometarget
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
