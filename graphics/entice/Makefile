# New ports collection makefile for:	entice
# Date created:		7 Oct 2001
# Whom:			Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	entice
PORTVERSION=	0.5.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.ny.us.rasterman.com/files/

MAINTAINER=	ishmael27x@yahoo.com

LIB_DEPENDS=	ecore.0:${PORTSDIR}/x11/ecore \
		evas.6:${PORTSDIR}/graphics/evas

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
