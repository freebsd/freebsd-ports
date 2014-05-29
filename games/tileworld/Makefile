# Created by: sec@42.org
# $FreeBSD$

PORTNAME=	tileworld
PORTVERSION=	1.3.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.muppetlabs.com/~breadbox/pub/software/tworld/
DISTNAME=	tworld-${PORTVERSION}

MAINTAINER=	sec@42.org
COMMENT=	An emulation of the game "Chip's Challenge"

USE_SDL=	sdl
GNU_CONFIGURE=	YES
USES=		gmake
ALL_TARGET=	tworld
DATADIR=	share/tworld

MAN6=		tworld.6

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|make|$${MAKE}|g; s|cp -i|cp|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
