# New ports collection makefile for:    yape
# Date created:         31.10.2002
# Whom:                 Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	yape
PORTVERSION=	0.32.3
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	http://yape.homeserver.hu/download/
DISTNAME=	yapeSDL-${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Yet Another Commodore +4 Emulator

USE_SDL=	sdl
NO_WRKSUBDIR=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
ALL_TARGET=	yape

post-patch:
	@${REINPLACE_CMD} -e "s|sdl-config|${SDL_CONFIG}|" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yape ${PREFIX}/bin

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.Linux ${DOCSDIR}
.endif

.include <bsd.port.mk>
