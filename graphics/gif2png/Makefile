# New ports collection makefile for: gif2png
# Date created:         30 Aug 1999
# Whom:                 saper@system.pl
#
# $FreeBSD$
#

PORTNAME=	gif2png
PORTVERSION=	2.4.6
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.catb.org/~esr/gif2png/

MAINTAINER=	saper@system.pl
COMMENT=	Converts GIF images to a PNG format

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"
USE_GMAKE=	yes

MAN1=		gif2png.1 web2png.1

.include <bsd.port.mk>
