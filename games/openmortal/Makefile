# New ports collection makefile for:  	openmortal
# Date created:       		20 Apr 2004
# Whom:  			krion@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	openmortal
PORTVERSION=	0.7
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A parody of the once popular coin-up fighting game, Mortal Kombat

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_PERL5=	yes
USE_SDL=	mixer image sdl net

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
