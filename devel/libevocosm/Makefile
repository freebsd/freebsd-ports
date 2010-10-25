# New ports collection makefile for:	libevocosm
# Date created:		2006-08-01
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	libevocosm
PORTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.coyotegulch.com/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of tools for creating a variety of evolutionary algorithms

LIB_DEPENDS=	coyotl-3.1.4:${PORTSDIR}/devel/libcoyotl \
		png.6:${PORTSDIR}/graphics/png

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS=-I${PREFIX}/include/ LDFLAGS=-L${PREFIX}/lib/

.include <bsd.port.mk>
