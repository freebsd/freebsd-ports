PORTNAME=	tileworld
PORTVERSION=	1.3.0
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.muppetlabs.com/~breadbox/pub/software/tworld/
DISTNAME=	tworld-${PORTVERSION}

MAINTAINER=	sec@42.org
COMMENT=	Emulation of the game "Chip's Challenge"
WWW=		https://www.muppetlabs.com/~breadbox/software/tworld/

USE_SDL=	sdl
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

USES=		gmake sdl
ALL_TARGET=	tworld
DATADIR=	share/tworld

post-patch:
	@${REINPLACE_CMD} -e 's|make|$${MAKE}|g; s|cp -i|cp|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
