# New ports collection makefile for:	libcoyotl
# Date created:		2006-08-01
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	libcoyotl
PORTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.coyotegulch.com/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of useful C++ classes

DEPRECATED=	Looks like an abandonware, no more public distfile
EXPIRATION_DATE=	2011-08-01

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS=-I${PREFIX}/include/ LDFLAGS=-L${PREFIX}/lib/

.include <bsd.port.mk>
