# New ports collection makefile for:	libevocosm
# Date created:		2006-08-01
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	libevocosm
PORTVERSION=	3.1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.coyotegulch.com/distfiles/

MAINTAINER=	trasz@freebsd.org
COMMENT=	Collection of tools for creating a variety of evolutionary algorithms

LIB_DEPENDS=	coyotl-3.1.4:${PORTSDIR}/devel/libcoyotl \
		png.5:${PORTSDIR}/graphics/png

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS=-I${PREFIX}/include/ LDFLAGS=-L${PREFIX}/lib/

.include <bsd.port.mk>
