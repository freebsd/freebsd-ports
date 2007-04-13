# New ports collection makefile for:	libcoyotl
# Date created:		2006-08-01
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	libcoyotl
PORTVERSION=	3.1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.coyotegulch.com/distfiles/

MAINTAINER=	trasz@freebsd.org
COMMENT=	Collection of useful C++ classes

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS=-I${PREFIX}/include/ LDFLAGS=-L${PREFIX}/lib/

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not build on 4.x
.endif

.include <bsd.port.post.mk>
