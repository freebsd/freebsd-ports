# New ports collection makefile for:	entice
# Date created:		7 Oct 2001
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	entice
PORTVERSION=	0.9.3.004
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vanilla

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	An image viewer written using libraries for Enlightenment 0.17

LIB_DEPENDS=	esmart_thumb.0:${PORTSDIR}/graphics/esmart

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
