# Created by: krion@FreeBSD.org
# $FreeBSD$

PORTNAME=	openmortal
PORTVERSION=	0.7
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A parody of the once popular coin-up fighting game, Mortal Kombat

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		perl5
USE_SDL=	mixer image sdl net
USE_DOS2UNIX=	src/gfx.cpp

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

.include <bsd.port.mk>
