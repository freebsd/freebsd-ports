# New ports collection makefile for: gif2png
# Date created:         30 Aug 1999
# Whom:                 saper@system.pl
#
# $FreeBSD$
#

PORTNAME=	gif2png
PORTVERSION=	2.4.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.tuxedo.org/~esr/gif2png/

MAINTAINER=	saper@system.pl

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"
USE_GMAKE=	yes

MAN1=		gif2png.1 web2png.1

.include <bsd.port.mk>
