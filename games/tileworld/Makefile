# Created by: sec@42.org
# $FreeBSD$

PORTNAME=	tileworld
PORTVERSION=	1.3.0
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.muppetlabs.com/~breadbox/pub/software/tworld/
DISTNAME=	tworld-${PORTVERSION}

MAINTAINER=	sec@42.org
COMMENT=	Emulation of the game "Chip's Challenge"

USE_SDL=	sdl
GNU_CONFIGURE=	YES
USES=		gmake sdl
ALL_TARGET=	tworld
DATADIR=	share/tworld

post-patch:
	@${REINPLACE_CMD} -e 's|make|$${MAKE}|g; s|cp -i|cp|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
